#include <bits/stdc++.h>

using namespace std;

long long n,ls[2000069],inf=1e18;

int main()
{
	long long i,u,k,sm,mx=0,c=1;
	string s;
	
	cin>>s;
	n=s.length();
	for(i=0;i<=n*2;i++)
	{
		ls[i]=inf;
	}
	sm=n;
	ls[sm]=0;
	for(i=1;i<=n;i++)
	{
		u=(s[i-1]=='(')*2-1;
		sm+=u;
		ls[sm+1]=inf;
		k=i-ls[sm];
		if(k>mx)
		{
			mx=k;
			c=0;
		}
		c+=k==mx;
		ls[sm]=min(ls[sm],i);
	}
	printf("%lld %lld\n",mx,c);
}