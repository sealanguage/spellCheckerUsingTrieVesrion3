// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

#define CHAR_TO_INDEX(c) ((int)c - (int)'a') 

// Represents number of children for each node in a trie
#define N 27
const int CASE = 'a';

// Represents a node in a trie
typedef struct trieNode
{
    bool is_word;
    struct trieNode *children[N];
    //  struct node* next is single list, struct node* children is the way to do the same thing for the trie
    struct trieNode* next;
    int occurrences;      //  probably will be misspellings later
}trieNode;

// Represents a trie ******* is this needed
trieNode *root;
// trieNode *nav
// trieNode *parent = NULL;
int occurrences = 0;    //  probably will be misspellings later


// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Initialize trie
    root = malloc(sizeof(trieNode));

    //  assign a traveller to the root
    trieNode* trav = root;
    if (root == NULL)
    {
        return false;
    }
    // set the is_word boolean to false for all the childern of the node
    root->is_word = false;
    //  create 27 children pointers of [N]
    for (int i = 0; i < N; i++)
    {
        //   all set to NULL
        root->children[i] = NULL;
    }

    // Open dictionary
    FILE *file = fopen(dictionary, "r");
//     printf("dictionary is here\n");
    if (file == NULL)
    {
        unload();
        return false;
    }
    printf("file %s\n", dictionary);

    // Buffer for a word  // // this is where the words are held
    char word[LENGTH + 1];
   
    // Insert words into trie
    while (fscanf(file, "%s", word) != EOF)   //  while the dictionary has words in it get words
    {
        printf("the word is %s\n", word);
        printf("get a letter from the word %s\n", word);
        // TODO
        int letterPosition; 
        int wordLength = strlen(word); 
        int pointerIndex = 0; 
        //  create a variable to create new nodes called newNode
//          trieNode *navig = root;
//         trieNode* newNode = (trieNode*)malloc(sizeof(trieNode));
        // for each word in dictionary iterate through the trie
        //  for each letter in the word   
        for(letterPosition = 0; letterPosition < wordLength; letterPosition++)
        {
            //////////
            printf("the letter is %c\n", word[letterPosition]);
            printf("letterPosition index is %d\n", letterPosition);
            //  assign a navigator to the root location
//             trieNode* trav = root;
            //  if no node exists at this location
            trieNode *newNode = malloc(sizeof(trieNode));     //  malloc a new trieNode
            newNode->children[pointerIndex] = NULL;        //  set all 27 pointers to null
            //  BROKEN HERE CLIFF SAYS OUT OF SCOPE, TRIENODE IS NOT VISIBLE TO THE
            if (newNode->children[pointerIndex] == NULL)
            {
                
                //  put the value of the letter position into the node
                
                trav = newNode->children[letterPosition];
                
                
                
//                     if (newNode->children[pointerIndex])
//                     {
//                         newNode = trav->children[letterPosition];
// //                         trav->children[pointerIndex] = newNode;
// //                         trav = trav->children[index];
//                     }
//                     
//                     
//                     
//                     
//                  mark word as true
//                     newNode->is_word = true;
                
//                 trav = trav->children[index];    //  Have children[i] point to it
            }
          
        //  

            
        }
            
    }
        
        
//      for every word in the dictionary
//          for each letter in the word
//              if (the lette points to NULL)
//                  malloc a new trieNode
//                      Have children[i] point to it
         

//             
// Inserting a key into Trie is a simple approach. 
// Every character of the input key is inserted as an individual Trie node.
// Note that the children is an array of pointers (or references) to next level trie nodes. 
// The key character acts as an index into the array children. 
// If the input key is new or an extension of the existing key, we need to construct non-existing nodes of the key, and mark end of the word for the last node. 
// If the input key is a prefix of the existing key in Trie, we simply mark the last node of the key as the end of a word. 
// The key length determines Trie depth.

//     }     

    // Close dictionary
    fclose(file);

    // Indicate success
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    
//     check should return true for words in the dictionary
    // TODO
    // Searching for a key is similar to insert operation, 
    // we only compare the characters and move down. 
    // search can terminate due to the end of a string if the isEndofWord field of the last node is true, then the key exists in the trie. 
    // 
    // search can terminate due to lack of key in the trie, the search terminates without examining all the characters of the key, since the key is not present in the trie.
    return false;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO

    return false;
}
