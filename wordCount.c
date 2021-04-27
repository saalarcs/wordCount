/*------------------------------------------------------------------------
# Word Count of Given File or Commmand Line (Stdin)
#
# Name: wordCount.c
#
# Written By: Saalar Faisal - 2021-02-14 
#
# Purpose: The purpose is to read a file/stdin and return the count of its bytes, words
#		   and new line characters.
#
# To compile: gcc -o wordCount wordCount.c
#
# Usage 1:  >> ./wordCount <fileName>
#  i.e. ./wordCount mickeyMouse.txt
#
# Usage 2:  >> cat /home/document.txt | ./wordCount
#  we can use on the command line of stdin
#   
# Usage 3:  >> ./wordCount
#			>> hello, hello testing
#  we can use on the command line of stdin
#-------------------------------------------------------------------------*/

#include <stdio.h>  // Input/output library
#include <stdlib.h> // C standard library

int main(int argc, char *argv[]) 
{ 
	FILE * file; // Our file pointer
    char ch; // This will hold our character
    int bytes, wordCount, lineCount; // Our counters
	
	// Determine if we are inside a word or not
	// 0 means we are not
	// 1 means we are inside word
    int hasWord = 0;
	
	// Initialize our counters
	bytes = wordCount = lineCount = 0; 
	
	// If no FILE was passed in parameter
	// we read from stdin	
	if (argc < 2) 
		file = stdin;

	// If a file parameter is passed
	if(argc > 1)
	{
		// Open file and read it
		file = fopen(argv[1], "r");

		// Check if file is not null
		if (file == NULL)
		{
			printf("\nFile did not open.\n");
			printf("Follow this structure: >> ./wordCount <file.txt>\n");

			exit(1); // exit failure code
		}	
	}
	
	// We will count and evaluate the characters as long it is not null
    while ((ch = fgetc(file)) != EOF)
    {
		// Increment the character/bytes
        bytes++;       

        // If there are spaces or tabs 
		// We set hasWord to 0
        if (ch == ' ' || ch == '\t') 
		{
            hasWord = 0;		
		}
			
		// Increment lineCount for a newline
		// Set hasWord to 0 since its not a word
        else if (ch == '\n')
		{
			lineCount++;
			hasWord = 0;
		}
		
		// If its not space or etc, then it must be a character!
		// If it was previously set to 0,
		// it means that we have a new word, hence we will increment it
		else
		{
			if(hasWord == 0)
			{
				wordCount++; // Increment the word count
			}
			
			hasWord = 1;
		}
    }

    // Printing count for file/stdin
    printf("\n");
	
	if(argc >1) // print file name if provided
	printf(" %d %d %d %s \n", lineCount, wordCount, bytes,argv[1]); 
	
	else {
	printf(" %d %d %d \n", lineCount, wordCount, bytes); 
	}
 
    // close the file
    fclose(file);

	// success message
    return 0;

} 