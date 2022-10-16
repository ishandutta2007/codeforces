#include <bits/stdc++.h>

using namespace std;

long long n,ma=1e6,fw[1000069],fi;

void ud(long long x,long long w)
{
	for(fi=x;fi<=ma;fi+=fi&-fi)
	{
		fw[fi]+=w;
	}
}

long long qr(long long x)
{
	long long z=0;
	
	for(fi=x;fi;fi-=fi&-fi)
	{
		z+=fw[fi];
	}
	return z;
}

int main()
{
	long long t,rr,i,k,lh,rh,md,zz;
	
	scanf("%lld%lld",&n,&t);
	for(rr=0;rr<n+t;rr++)
	{
		scanf("%lld",&k);
		if(k>0)
		{
			ud(k,1);
		}
		else
		{
			k*=-1;
			for(lh=1,rh=ma;lh<=rh;)
			{
				md=(lh+rh)/2;
				if(qr(md)>=k)
				{
					zz=md;
					rh=md-1;
				}
				else
				{
					lh=md+1;
				}
			}
			ud(zz,-1);
		}
	}
	zz=0;
	for(lh=1,rh=ma;lh<=rh;)
	{
		md=(lh+rh)/2;
		if(qr(md))
		{
			zz=md;
			rh=md-1;
		}
		else
		{
			lh=md+1;
		}
	}
	printf("%lld\n",zz);
}