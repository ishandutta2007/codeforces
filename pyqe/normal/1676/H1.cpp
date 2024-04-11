#include <bits/stdc++.h>

using namespace std;

long long n,fw[200069],fi;

inline void ud(long long x,long long w)
{
	for(fi=x;fi<=n;fi+=fi&-fi)
	{
		fw[fi]+=w;
	}
}

inline long long qr(long long lh,long long rh)
{
	long long z=0;
	
	for(fi=rh;fi;fi-=fi&-fi)
	{
		z+=fw[fi];
	}
	for(fi=lh-1;fi;fi-=fi&-fi)
	{
		z-=fw[fi];
	}
	return z;
}

int main()
{
	long long t,rr,i,k,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			fw[i]=0;
		}
		z=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			z+=qr(k,n);
			ud(k,1);
		}
		printf("%lld\n",z);
	}
}