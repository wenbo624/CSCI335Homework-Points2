// Name: Wen Bo
// Date: 2/11/2019
// Assigment: Assignment 1
// This class describes a sequence of 2D points.

#ifndef CSCI335_HOMEWORK1_POINTS2_H_
#define CSCI335_HOMEWORK1_POINTS2_H_

#include <array>
#include <iostream>
#include <cstddef>
#include <string>
#include <sstream>

namespace teaching_project {
// Place comments that provide a brief explanation of the class,
// and its sample usage.
template<typename Object>
class Points2 {
 public:
  // Default "big five" -- you have to alter them for your assignment.
  // That means that you will remove the "= default" statement.
  //  and you will provide an implementation.

  // Zero-parameter constructor. 
  // Set size to 0.
 	Points2()
    {
        sequence_ = nullptr; 
        size_ = 0;
 	}

  // Copy-constructor.
  	Points2(const Points2 &rhs)
    {
  		size_ = rhs.size_;
  		sequence_ = new std::array<Object, 2> [rhs.size_];
  		for(size_t i = 0; i < size_; i++)
        {
            sequence_[i] = rhs.sequence_[i];
        } 		
  	}

  // Copy-assignment. If you have already written
  // the copy-constructor and the move-constructor
  // you can just use:
  // {
  // Points2 copy = rhs; 
  // std::swap(*this, copy);
  // return *this;
  // }
  	Points2& operator=(const Points2 &rhs)
  	{
  		Points2 copy = rhs;
  		std::swap(*this, copy);
  		return *this;
  	}

  // Move-constructor. 
  	Points2(Points2 &&rhs)
  	{    
        
  		size_ = rhs.size_;
        sequence_ = new std::array<Object, 2>[rhs.size_];
        
        for(size_t i = 0; i < size_; i++)
        {
            sequence_[i] = rhs.sequence_[i];
        }

  		rhs.sequence_ = nullptr;
  		rhs.size_ = 0;
  		
  	}

  // Move-assignment.
  // Just use std::swap() for all variables.
  	Points2& operator=(Points2 &&rhs)
  	{	
        
  		std::swap(sequence_,rhs.sequence_);
  		std::swap(size_, rhs.size_);
  		return *this;
  	}

	 ~Points2()
	{      
	 	delete[] sequence_;
	  	size_ = 0;
	}

  // End of big-five.

  // One parameter constructor.
  	Points2(const std::array<Object, 2>& item)
  	{
        sequence_ = new std::array<Object, 2>[1];
        sequence_[0] = item;
        size_ = 1;
  	}

  // Read a chain from standard input.
    void ReadPoints2() {
        // Part of code included (without error checking).
        std::string input_line;
        std::getline(std::cin, input_line); 
        std::stringstream input_stream(input_line);
        if (input_line.empty()) return;
        // Read size of sequence (an integer).
        int size_of_sequence;
        input_stream >> size_of_sequence;
        // Allocate space for sequence.
        // Add code here.
        size_ = size_of_sequence;
        sequence_ = new std::array<Object,2> [size_of_sequence];
        
        Object token;
        for (int i = 0 ;input_stream >> token; ++i) {
          // Read coordinates.
          // Fill sequence_ here.
            sequence_[i][0] = token;

            //read the second number of the point.
            input_stream >> token;
            sequence_[i][1] = token;
        }
    
    } 

  	size_t size() const {
    	 return size_;
  	}

  // @location: an index to a location in the sequence.
  // @returns the point at @location.
  // const version.
  // abort() if out-of-range.
    const std::array<Object, 2>& operator[](size_t location) const { 
        if(location >= size_)
            abort();
        else
            return sequence_[location];
    }

 //  @c1: A sequence.
 //  @c2: A second sequence.
 //  @return their sum. If the sequences are not of the same size, append the
 //    result with the remaining part of the larger sequence.
 friend Points2 operator+(const Points2 &c1, const Points2 &c2) {
    Points2 sum_of_point;
 
   if(c1.size_ == c2.size_)
   {
        sum_of_point.sequence_ = new std::array<Object, 2>[c1.size_];
        sum_of_point.size_ = c1.size_;
   
        for(size_t i = 0; i < c1.size_; i++)
        {
            sum_of_point.sequence_[i][0] = c1.sequence_[i][0] + c2.sequence_[i][0];
            sum_of_point.sequence_[i][1] = c1.sequence_[i][1] + c2.sequence_[i][1];        
        }
   }
   else if(c1.size_ > c2.size_)
   {
        sum_of_point.sequence_ = new std::array<Object, 2>[c1.size_];
        sum_of_point.size_ = c1.size_;

        for(size_t i = 0; i < c2.size_; i++)
        {
            sum_of_point.sequence_[i][0] = c1.sequence_[i][0] + c2.sequence_[i][0];
            sum_of_point.sequence_[i][1] = c1.sequence_[i][1] + c2.sequence_[i][1]; 
        }
        for(size_t x = c2.size_; x < c1.size_; x++)
        {    
            sum_of_point.sequence_[x][0] = c1.sequence_[x][0];
            sum_of_point.sequence_[x][1] = c1.sequence_[x][1];     
        }
    }
    else
    {
        sum_of_point.sequence_ = new std::array<Object, 2>[c2.size_];
        sum_of_point.size_ = c2.size_;

        for(size_t i = 0; i < c1.size_; i++)
        {
            sum_of_point.sequence_[i][0] = c1.sequence_[i][0] + c2.sequence_[i][0];
            sum_of_point.sequence_[i][1] = c1.sequence_[i][1] + c2.sequence_[i][1];
        }
        for(size_t x = c1.size_; x < c2.size_; x++)
        {
            sum_of_point.sequence_[x][0] = c1.sequence_[x][0];
            sum_of_point.sequence_[x][1] = c1.sequence_[x][1];    
        }
    }
    return sum_of_point;
            
 }

 // Overloading the << operator.
 friend std::ostream &operator<<(std::ostream &out, const Points2 &some_points2) {
    for(size_t i = 0; i < some_points2.size_; i++)
    {
        out << "(" << some_points2[i][0] << ", " << some_points2[i][1] << ")" << " ";    
    }
    //return () if points2 is empty
    if(some_points2.size_ == 0)
        out << "()";

    out << "\n";
    return out;
 }
 
 private:
  // Sequence of points. 
  std::array<Object, 2> *sequence_;
  // Size of sequence.
  size_t size_;

};

}  // namespace teaching_project
#endif // CSCI_335_HOMEWORK1_POINTS2_H_
