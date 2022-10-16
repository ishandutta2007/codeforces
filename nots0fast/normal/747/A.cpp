#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <set>
#include <string>
#include <sstream>
using namespace std;
#define for_(z,v) for(int i=z; i<=v; i++)
#define for__(z,v) for(int j=z; j<v; j++) 
#define lli long long int
int main()
{
    int n;
    cin>>n;
    int a , b;
    for_(1,sqrt(n))
    {
    	if(!(n%i))
    	{
    		a = i;
    		b= n/i;
		}
	}
	cout<<a<<" "<<b;
}