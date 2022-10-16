#include <bits/stdc++.h>

using namespace std;

long long n;

long long qr(long long x)
{
	long long k;
	
	printf("? %lld\n",x);
	fflush(stdout);
	scanf("%lld",&k);
	return k;
}

int main()
{
	long long lh,rh,md;
	
	scanf("%lld",&n);
	for(lh=1,rh=n;lh<rh;)
	{
		md=(lh+rh)/2;
		if(qr(md)<qr(md+1))
		{
			rh=md;
		}
		else
		{
			lh=md+1;
		}
	}
	printf("! %lld\n",lh);
	fflush(stdout);
}