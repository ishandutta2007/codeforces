#include <bits/stdc++.h>

using namespace std;

long long n,d,d2;

int main()
{
	long long k,l,lh,rh,md;
	
	scanf("%lld",&n);
	if(n/2%2)
	{
		printf("! -1\n");
		fflush(stdout);
		return 0;
	}
	printf("? 1\n");
	fflush(stdout);
	scanf("%lld",&d);
	printf("? %lld\n",1ll+n/2);
	fflush(stdout);
	scanf("%lld",&d2);
	if(d==d2)
	{
		printf("! 1\n");
		fflush(stdout);
		return 0;
	}
	for(lh=2,rh=n/2;lh<=rh;)
	{
		md=(lh+rh)/2;
		printf("? %lld\n",md);
		fflush(stdout);
		scanf("%lld",&k);
		printf("? %lld\n",md+n/2);
		fflush(stdout);
		scanf("%lld",&l);
		if(k==l)
		{
			printf("! %lld\n",md);
			fflush(stdout);
			return 0;
		}
		else if((k<l)==(d<d2))
		{
			lh=md+1;
		}
		else
		{
			rh=md-1;
		}
	}
}