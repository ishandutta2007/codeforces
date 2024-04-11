#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
void fastscan(int &number)
{
    //variable to indicate sign of input number
    bool negative = false;
    register int c;
 
    number = 0;
 
    // extract current character from buffer
    c = getchar();
    if (c=='-')
    {
        // number is negative
        negative = true;
 
        // extract the next character from the buffer
        c = getchar();
    }
 
    // Keep on extracting characters if they are integers
    // i.e ASCII Value lies from '0'(48) to '9' (57)
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;
 
    // if scanned input has a negative sign, negate the
    // value of the input number
    if (negative)
        number *= -1;
}
int main()
{
	int n;
	int A[1000000];
	fastscan(n);
	for(int i=0;i<n;i++)
		fastscan(A[i]);
	int count=1;
	int max=A[n-1];
	for(int i=n-2;i>=0;i--)
	{
		if(!max)
			count++;
		if(max)
			max--;
		if(max<A[i])
			max=A[i];
	}
	cout<<count;
}