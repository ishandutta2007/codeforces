#include <bits/stdc++.h>
#define N 210
using namespace std;
int q,n,p[N];
bool counter(int x)
{
	int i;
	for(i=x+n-1;i>x;i--)
	{
		if(p[i%n]-1!=p[(i+1)%n])
		{
			return false;
		}
	}
	return true;
}
bool clock(int x)
{
	int i;
	for(i=x;i<x+n-1;i++)
	{
		if(p[i%n]+1!=p[(i+1)%n])
		{
			return false;
		}
	}
	return true;
}
int main(){
	int i,x;
	cin>>q;
	while(q--)
	{
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>p[i];
			if(p[i]==1)
			{
				x=i;
			}
		}
		if(counter(x)||clock(x))
		{
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}