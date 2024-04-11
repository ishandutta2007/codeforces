#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,a=0,b=1023;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		char c;
		int t;
		cin>>c>>t;
		if(c=='|')
		{
			a |= t;
			b |= t;
		}
		if(c=='&')
		{
			a &= t;
			b &= t;
		}
		if(c=='^')
		{
			a ^= t;
			b ^= t;
		}
	}
	int da=0,ili=0, nili=0;
	for(int i=0;i<10;i++)
	{
		if(a%2==0 && b%2==1) da+=(1<<i);
		if(a%2==1 && b%2==1)
		{
			da+=(1<<i);
			ili+=(1<<i);
		}
		if(a%2==1 && b%2==0) 
		{
			da+=(1<<i);
			nili+=(1<<i);
		}
		a/=2;
		b/=2;
	}
	cout<<3<<endl<<"| "<<ili<<endl<<"& "<<da<<endl<<"^ "<<nili;
}