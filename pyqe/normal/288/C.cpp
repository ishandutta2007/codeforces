#include <bits/stdc++.h>

using namespace std;

long long n,sq[1000069];

long long mfu(long long x)
{
	long long i;
	
	for(i=0;i<20;i++)
	{
		if((x^1<<i)<1<<i)
		{
			return (1<<i+1)-1;
		}
	}
	return 0;
}

int main()
{
	long long i,mx,fu;
	
	scanf("%lld",&n);
	mx=n;
	fu=mfu(mx);
	for(i=n;i+1;i--)
	{
		if((fu^i)>mx)
		{
			mx=i;
			fu=mfu(mx);
		}
		sq[i]=fu^i;
	}
	printf("%lld\n",n*(n+1));
	for(i=0;i<=n;i++)
	{
		printf("%lld%c",sq[i]," \n"[i==n]);
	}
}