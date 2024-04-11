#include <bits/stdc++.h>

using namespace std;

long long n;

inline long long qr(long long lh,long long rh)
{
	long long k;
	
	printf("? %lld %lld\n",lh,rh);
	fflush(stdout);
	scanf("%lld",&k);
	return k;
}

inline long long tri(long long x)
{
	return x*(x-1)/2;
}

int main()
{
	long long t,rr,k,l,lh,rh,md,zz,z,z2,z3;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(lh=1,rh=n;lh<=rh;)
		{
			md=(lh+rh)/2;
			if(!qr(1,md))
			{
				zz=md;
				lh=md+1;
			}
			else
			{
				rh=md-1;
			}
		}
		z=zz;
		k=qr(1,n);
		l=qr(z+1,n);
		z2=z+k-l+1;
		for(lh=1,rh=n;lh<=rh;)
		{
			md=(lh+rh)/2;
			if(tri(md)<=k-tri(z2-z))
			{
				zz=md;
				lh=md+1;
			}
			else
			{
				rh=md-1;
			}
		}
		z3=z2+zz-1;
		printf("! %lld %lld %lld\n",z,z2,z3);
		fflush(stdout);
	}
}