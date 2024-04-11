#include <bits/stdc++.h>

using namespace std;

long long n;

inline long long qr(long long lh,long long rh)
{
	long long i,k,c=0;
	
	printf("? %lld %lld\n",lh,rh);
	fflush(stdout);
	for(i=0;i<rh-lh+1;i++)
	{
		scanf("%lld",&k);
		c+=k<=rh-lh+1;
	}
	return c;
}

int main()
{
	long long t,rr,lh,rh,md,zz;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(zz=n,lh=1,rh=n-1;lh<=rh;)
		{
			md=(lh+rh)/2;
			if(qr(1,md)%2)
			{
				zz=md;
				rh=md-1;
			}
			else
			{
				lh=md+1;
			}
		}
		printf("! %lld\n",zz);
		fflush(stdout);
	}
}