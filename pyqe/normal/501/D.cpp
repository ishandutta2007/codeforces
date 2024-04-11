#include <bits/stdc++.h>

using namespace std;

long long n,a[200069],fw[200069],fwp;

void ud(long long x,long long w)
{
	x++;
	for(fwp=x;fwp<=n;fwp+=fwp&-fwp)
	{
		fw[fwp]+=w;
	}
}

long long qr(long long lh,long long rh)
{
	long long z=0;
	
	rh++;
	lh++;
	for(fwp=rh;fwp;fwp-=fwp&-fwp)
	{
		z+=fw[fwp];
	}
	for(fwp=lh-1;fwp;fwp-=fwp&-fwp)
	{
		z-=fw[fwp];
	}
	return z;
}

long long qrr(long long lh,long long rh)
{
	return rh-lh+1-qr(lh,rh);
}

int main()
{
	long long i,ii,k,lh,rh,md,zz;
	
	scanf("%lld",&n);
	for(ii=0;ii<2;ii++)
	{
		for(i=1;i<=n;i++)
		{
			fw[i]=0;
		}
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			a[i]+=qrr(0,k-1);
			ud(k,1);
		}
	}
	for(i=n;i;i--)
	{
		a[i-1]+=a[i]/(n+1-i);
		a[i]%=(n+1-i);
	}
	for(i=1;i<=n;i++)
	{
		fw[i]=0;
	}
	for(i=1;i<=n;i++)
	{
		for(lh=0,rh=n-1;lh<=rh;)
		{
			md=(lh+rh)/2;
			if(qrr(0,md-1)<=a[i])
			{
				zz=md;
				lh=md+1;
			}
			else
			{
				rh=md-1;
			}
		}
		ud(zz,1);
		printf("%lld%c",zz," \n"[i==n]);
	}
}