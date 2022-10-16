#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <set>
#include <string>
#include <sstream>
using namespace std;
#define for_(z,v) for(int i=z; i<v; i++)
#define for__(z,v) for(int j=z; j<v; j++) 
#define lli long long int
int main()
{
    int n,q;
    cin>>n>>q;
    int servers[n];
    for_(0,n)
    {
    	servers[i]=0;
    	
	}
    for_(0,q)
    {
    	int t,k,d;
    	cin>>t>>k>>d;
    	int say = 0;
    	for__(0,n)
    	{
    		if(servers[j]<=t)
    		{
    			++say;
			}
		}
		if(say>=k)
		{
			int sum = 0;
   		for__(0,n)
  		{
  			if(servers[j]<=t && k)
			{
				servers[j] = t+d;
				sum+=j+1;
				--k;
			}
		}
		cout<<sum<<endl;
	    }
	    else
	    cout<<-1<<endl;
	}
}