#include <bits/stdc++.h>

using namespace std;

const long long ma=3e5;
long long n,fw[2][300069],fi;

void ud(long long xx,long long x,long long w)
{
	for(fi=x;fi<=ma;fi+=fi&-fi)
	{
		fw[xx][fi]+=w;
	}
}

long long qr(long long xx,long long lh,long long rh)
{
	long long z=0;
	
	for(fi=rh;fi;fi-=fi&-fi)
	{
		z+=fw[xx][fi];
	}
	for(fi=lh-1;fi;fi-=fi&-fi)
	{
		z-=fw[xx][fi];
	}
	return z;
}

int main()
{
	long long i,j,k,sm=0,z=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		z+=sm;
		for(j=0;j<=ma;j+=k)
		{
			z-=j*qr(0,max(j,1ll),min(j+k-1,ma));
		}
		ud(0,k,1);
		z+=k*(i-1)-qr(1,1,k);
		for(j=k;j<=ma;j+=k)
		{
			ud(1,j,k);
		}
		sm+=k;
		printf("%lld%c",z," \n"[i==n]);
	}
}