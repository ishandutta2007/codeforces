#include <bits/stdc++.h>

using namespace std;

long long n,a[200069],as[200069],fw[200069],fi;

void ud(long long x,long long w)
{
	for(fi=x;fi<=n;fi+=fi&-fi)
	{
		fw[fi]+=w;
	}
}

long long qr(long long lh,long long rh)
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
	long long t,rr,i,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
			as[i]=a[i];
			fw[i]=0;
		}
		sort(as+1,as+n+1);
		z=0;
		for(i=1;i<=n;i++)
		{
			a[i]=lower_bound(as+1,as+n+1,a[i])-as;
			z+=min(qr(1,a[i]-1),qr(a[i]+1,n));
			ud(a[i],1);
		}
		printf("%lld\n",z);
	}
}