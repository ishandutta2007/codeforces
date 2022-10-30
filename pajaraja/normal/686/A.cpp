#include <iostream>
#include <stdio.h>
using namespace std;
int main(int argc, char** argv) 
{
	long long n,m,t,r=0;
	char c;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>c;
		cin>>t;
		if(c=='+') m+=t;
		else
		{
			if(m>=t) m-=t;
			else r++;
		}
	}
	cout<<m<<" "<<r;
	return 0;
}