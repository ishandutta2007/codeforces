#include <bits/stdc++.h>

using namespace std;

long long n;

long long qr(long long lh,long long rh)
{
	if(lh<rh)
	{
		long long k;
		
		printf("? %lld %lld\n",lh,rh);
		fflush(stdout);
		scanf("%lld",&k);
		return k;
	}
	else
	{
		return -1;
	}
}

long long slv(long long lb,long long rb,long long x)
{
	long long p=(lb+rb)/2,lh,rh,md,zz;
	
	if(x<=p)
	{
		if(qr(lb,p)==x)
		{
			return slv(lb,p,x);
		}
		for(zz=rb,lh=p+1,rh=rb-1;lh<=rh;)
		{
			md=(lh+rh)/2;
			if(qr(lb,md)==x)
			{
				zz=md;
				rh=md-1;
			}
			else
			{
				lh=md+1;
			}
		}
		return zz;
	}
	else
	{
		if(qr(p+1,rb)==x)
		{
			return slv(p+1,rb,x);
		}
		for(zz=lb,lh=lb+1,rh=p;lh<=rh;)
		{
			md=(lh+rh)/2;
			if(qr(md,rb)==x)
			{
				zz=md;
				lh=md+1;
			}
			else
			{
				rh=md-1;
			}
		}
		return zz;
	}
}

int main()
{
	scanf("%lld",&n);
	printf("! %lld\n",slv(1,n,qr(1,n)));
	fflush(stdout);
}