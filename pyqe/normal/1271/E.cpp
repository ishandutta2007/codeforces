#include <bits/stdc++.h>

using namespace std;

long long n,d;

int main()
{
	long long i,lh,rh,md,mdd,zz=-1e18,k,z;
	
	scanf("%lld%lld",&n,&d);
	for(lh=1,rh=n/2;lh<=rh;)
	{
		md=(lh+rh)/2;
		mdd=md*2;
		z=0;
		for(k=n-mdd+1,i=1;k>0;i*=2)
		{
			z+=min(2*i,k);
			k-=mdd*i;
		}
		if(z>=d)
		{
			zz=max(zz,mdd);
			lh=md+1;
		}
		else
		{
			rh=md-1;
		}
	}
	for(lh=1,rh=(n+1)/2;lh<=rh;)
	{
		md=(lh+rh)/2;
		mdd=md*2-1;
		z=0;
		for(k=n-mdd+1,i=1;k>0;i*=2)
		{
			z+=min(i,k);
			k-=mdd*i;
		}
		if(z>=d)
		{
			zz=max(zz,mdd);
			lh=md+1;
		}
		else
		{
			rh=md-1;
		}
	}
	printf("%lld\n",zz);
}