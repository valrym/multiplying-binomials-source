// lil project i made for my math assignments

// project start: 4:04 AM, 4/13/17
// project end: 5:41, 4/13/17

// valrym / zach 
// borkgang.co

#include "stdafx.h"
#include <Windows.h>
#include <iostream>
#include <string>
#include <fstream>
#include <iterator>
#include <vector>
#include <sstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <exception>
#include <math.h>  

//defines and shit

std::string Input() {
	std::string fuck;
	getline(std::cin, fuck);
	return fuck;
}

std::vector<std::string> split(std::string s)
{
	std::vector<std::string> elems;
	std::stringstream ss(s);
	std::istream_iterator<std::string> begin(ss);
	std::istream_iterator<std::string> end;
	std::vector<std::string> vstrings(begin, end);
	return vstrings;
}

int round_int(float r) {
	return (r > 0.0) ? (r + 0.5) : (r - 0.5);
}

std::string firstanswerstr;
std::string secondanswerstr_positive;
std::string secondanswerstr_negative;
std::string secondanswerstr_negative_wonky;
std::string secondanswerstr_even_wonkier;
std::string thirdanswerstr_positive;
std::string thirdanswerstr_negative;
std::string fourthanswerstr;


//les start it
void main()
{
		printf("-- FORMATTING --\n");
		printf(" 5 h + 2 3 h - 3 \n\n");
		printf("-- EQUIVALENT TO --\n");
		printf(" (5h + 2) (3h - 3) \n\n");


		do { //start input loop so the shit doesnt do the shit for eternity
			std::cout << "\n>> ";
			//reset all values as to reduce memory takage & to get rid of nasty nasty bugs
			firstanswerstr = "";
			secondanswerstr_positive = "";
			secondanswerstr_negative = "";
			secondanswerstr_negative_wonky = "";
			secondanswerstr_even_wonkier = "";
			thirdanswerstr_negative = "";
			thirdanswerstr_positive = "";
			fourthanswerstr = "";

			std::vector<std::string> Arguments = split(Input());
			//math shit
			float firstval = atof(Arguments.at(0).c_str());
			float secondval = atof(Arguments.at(3).c_str());
			float firstval2 = atof(Arguments.at(4).c_str());
			float secondval2 = atof(Arguments.at(7).c_str());
			float firstanswer = firstval * firstval2;
			float scndclose = firstval * secondval2;
			float secondanswer_positive_negative = scndclose - scndclose - scndclose;
			float thirdanswer = secondval * secondval2;
			float fthclose = secondval * firstval2;
			float fourthanswer_positive_negative = fthclose - fthclose - fthclose;

			firstanswerstr.append("  "+std::to_string(round_int(firstanswer)) + Arguments.at(1).c_str() + "^2"+ " ");
			secondanswerstr_negative.append(std::to_string(round_int(secondanswer_positive_negative - fourthanswer_positive_negative)) + Arguments.at(5) + " ");
			secondanswerstr_negative_wonky.append(std::to_string(round_int(secondanswer_positive_negative + fourthanswer_positive_negative)) + Arguments.at(5) + " ");
			secondanswerstr_even_wonkier.append(std::to_string(round_int(scndclose + fthclose)) + Arguments.at(5) + " ");

			secondanswerstr_positive.append(std::to_string(round_int(scndclose + fourthanswer_positive_negative)) + Arguments.at(5) + " ");
			thirdanswerstr_negative.append(std::to_string(round_int(thirdanswer - thirdanswer - thirdanswer)));
			thirdanswerstr_positive.append(std::to_string(round_int(thirdanswer)));

				if (Arguments.at(2) == "+" && Arguments.at(6) == "-") {
						std::cout << firstanswerstr + secondanswerstr_negative + thirdanswerstr_negative;
				}
				else if (Arguments.at(2) == "-" && Arguments.at(6) == "+") {
					std::cout << firstanswerstr + secondanswerstr_positive + thirdanswerstr_negative;
				}
				else if (Arguments.at(2) == "-" && Arguments.at(6) == "-") {
					std::cout << firstanswerstr + secondanswerstr_negative_wonky + "+" + thirdanswerstr_positive;

				}
				else if (Arguments.at(2) == "+" && Arguments.at(6) == "+") {
					std::cout << firstanswerstr + secondanswerstr_even_wonkier + "+ " + thirdanswerstr_positive;
				}
				else {

				}
			
		} while (true);
}