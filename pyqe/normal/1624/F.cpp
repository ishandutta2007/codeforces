#include <bits/stdc++.h>

using namespace std;

long long n,lz=0;

inline long long qr(long long x)
{
	long long k;
	
	printf("+ %lld\n",x);
	fflush(stdout);
	scanf("%lld",&k);
	lz+=x;
	return k;
}

int main()
{
	long long k,l,lh,rh,md;
	
	scanf("%lld",&n);
	for(lh=1,rh=n-1;lh<rh;)
	{
		md=(lh+rh)/2;
		k=(md+lz)/n;
		l=qr(k*n+n-1-(md+lz));
		if(l==k)
		{
			rh=md;
		}
		else
		{
			lh=md+1;
		}
	}
	printf("! %lld\n",lh+lz);
	fflush(stdout);
}