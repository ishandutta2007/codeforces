#include<cstdio>
#include<iostream>
using namespace std;

long long x,y;

int main()
{
	cin>>x>>y;
	if(y==1)
		cout<<x;
	else
	{
		long long pos=0,ans=0;
		for(long long k=63;k>=0;k--)
			if(x&(1ll<<k))
			{
				pos=k;
				break;
			}
		cout<<(1ll<<(pos+1))-1ll;
	}
}