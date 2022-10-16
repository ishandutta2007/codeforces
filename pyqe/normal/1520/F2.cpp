#include <bits/stdc++.h>

using namespace std;

long long n,d,fw[2][200069],fi,lz[200069];

void ud(long long xx,long long x,long long w)
{
	for(fi=x;fi<=n;fi+=fi&-fi)
	{
		fw[xx][fi]+=w;
	}
}

long long qr(long long xx,long long x)
{
	long long z=0;
	
	for(fi=x;fi;fi-=fi&-fi)
	{
		z+=fw[xx][fi];
	}
	return z;
}

long long bl(long long xx,long long x)
{
	long long i,sm=0;
	
	fi=0;
	for(i=17;i+1;i--)
	{
		if((fi|1ll<<i)<=n&&sm+fw[xx][fi|1ll<<i]<x)
		{
			fi|=1ll<<i;
			sm+=fw[xx][fi];
		}
	}
	return fi+1;
}

int main()
{
	long long t,rr,i,k,lh,rh,md,zz;
	
	scanf("%lld%lld",&n,&t);
	for(i=1;i<=n;i++)
	{
		ud(0,i,1);
		lz[i]=-1;
	}
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&d);
		d=bl(0,d);
		for(lh=1,rh=n;lh<=rh;)
		{
			md=(lh+rh)/2;
			if(lz[md]==-1)
			{
				printf("? 1 %lld\n",md);
				fflush(stdout);
				scanf("%lld",&k);
				lz[md]=md-k+qr(1,md);
			}
			if(lz[md]>=d)
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
		ud(0,d,-1);
		ud(1,zz,1);
	}
}