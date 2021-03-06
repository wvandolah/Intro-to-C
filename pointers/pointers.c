#include <stdio.h>

/*
    Swaps the integer values being pointed at by a and b. Keep in
    mind when you need to access a pointer's actual value (the 
    address it's referring to) or the value at the address it's 
    pointing at.
*/
void swap(int* a, int* b)
{
    /*
        a and b are pointers. to access the value need *
        create a temp variable to hold the value of a
        assign the value of a to the value of b. 
        assign the value of b to temp
    */
    int temp = *a;
    *a = *b;
    *b = temp;
    printf("%d\n",*a);
}

/*
    Given a character pointer s, returns the number of characters
    it is pointing to. Think about how pointer arithmetic can 
    help you with this.
    
    Do not just use the `strlen` function from the standard library.
*/
int string_length(char *s)
{
    int counter = 0;
    while(s[counter] != '\0')
    {
        counter++;
    }
    // printf("counter %d\n", counter);
    return counter;
}

/*
    Given an empty (NULL) character pointer x and a character pointer y,
    copies the character contents of y over to x. Again, pointer arithmetic
    is necessary here. Also, make sure x points to a null character at its 
    end to terminate it properly. 
    
    Do not just use the `strcpy` function from the standard library.
*/
void string_copy(char *x, char *y)
{
    int index = 0;
    while(y[index] != '\0')
    {
        x[index] = y[index];
        index++;
    }
    x[index] = '\0';
}

/* 
    Compares the character strings m and n and returns negative,
    0, or positive if n is lexicographically less than, equal to,
    or greater than n. To calculate lexicographic difference, find
    the difference between the first characters in m and n that differ.
    
    For example, given matching strings, this function should 
    return 0. Given strings m = "hello world" and n = "goodbye",
    this function should return a positive value. Given strings
    m = "aardvark" and n = "zebra", should return a negative
    value.
    
    Do not just use the `strcmp` function from the standard library.
*/
int string_compare(char *m, char *n)
{
    int m_length = string_length(m);
    int n_length = string_length(n);
    // printf("outside loop m=%d n=%d\n",m_length, n_length);
    for(int i = 0; i <= m_length && i <= n_length; i++)
    {
        // printf("inside loop m=%c n=%c\n",m[i], n[i]);
        if(m[i] != n[i])
        {
            return m[i] - n[i];
        }
       
    }
    return 0;
}

#ifndef TESTING
int main(void)
{
    int x = 10, y = 20;
    swap(&x, &y);
    printf("x=%d, y=%d\n", x, y);

    char *hello = "Hello";
    char *world = "World";

    char buffer[1024];
    string_copy(buffer, hello);

    printf("Buffer is %s\n", buffer);
    printf("Length is %d\n", string_length(buffer));
    printf("Comparison is %d\n", string_compare(hello, world));
    
    char *s = "hello, world";
    char *t = "hiya";
    char *m = "goodbye";
    char *n = "see ya";

    char *firetruck = "firetruck";
    char *firetrucks = "firetrucks";
    printf("Comparison is %d\n", string_compare(s, t));
    
    return 0;
}
#endif
