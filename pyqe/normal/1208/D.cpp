#include <bits/stdc++.h>

using namespace std;

long long n,a[200069],z[200069],fw[200069],fwp;

void ud(long long x,long long w)
{
	for(fwp=x;fwp<=n;fwp+=fwp&-fwp)
	{
		fw[fwp]+=w;
	}
}

long long qr(long long x)
{
	long long z=0;
	
	for(fwp=x;fwp>0;fwp-=fwp&-fwp)
	{
		z+=fw[fwp];
	}
	return z;
}

int main()
{
	long long i,lh,rh,md,zz;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		ud(i,i);
	}
	for(i=n;i>0;i--)
	{
		lh=1;
		rh=n;
		for(;lh<=rh;)
		{
			md=(lh+rh)/2;
			if(qr(md-1)<=a[i])
			{
				zz=md;
				lh=md+1;
			}
			else
			{
				rh=md-1;
			}
		}
		z[i]=zz;
		ud(zz,-zz);
	}
	for(i=1;i<=n;i++)
	{
		printf("%lld%c",z[i]," \n"[i==n]);
	}
}