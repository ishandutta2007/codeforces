#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,fw[500069],fwp,dv=1e9+7;
pair<long long,long long> a[500069],aa[500069];

void ud(long long x,long long w)
{
	for(fwp=x;fwp<=n;fwp+=fwp&-fwp)
	{
		fw[fwp]=(fw[fwp]+w)%dv;
	}
}

long long qr(long long lh,long long rh)
{
	long long z=0;
	
	for(fwp=rh;fwp;fwp-=fwp&-fwp)
	{
		z=(z+fw[fwp])%dv;
	}
	for(fwp=lh-1;fwp;fwp-=fwp&-fwp)
	{
		z=(z+dv-fw[fwp])%dv;
	}
	return z;
}

int main()
{
	long long i,ii,k,p,z=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&a[i].fr);
		a[i].sc=i;
	}
	sort(a+1,a+n+1);
	for(ii=0;ii<2;ii++)
	{
		for(i=1;i<=n;i++)
		{
			fw[i]=0;
		}
		for(i=1;i<=n;i++)
		{
			k=a[i].fr;
			p=a[i].sc;
			aa[n+1-i]={(dv-k)%dv,n+1-p};
			if(!ii)
			{
				z=(z+k*(p*(p+1)/2%dv)%dv*(n+1-p))%dv;
			}
			z=(z+k*qr(p,n)%dv*p)%dv;
			ud(p,n+1-p);
		}
		for(i=1;i<=n;i++)
		{
			a[i]=aa[i];
		}
	}
	printf("%lld\n",z);
}