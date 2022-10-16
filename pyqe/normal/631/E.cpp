#include <bits/stdc++.h>

using namespace std;

long long n,ttl=0,nn,a[200069],ps[200069],sk[200069];

long long f(long long x,long long w)
{
	return x*w-ps[x-1];
}

bool cmp(long long x,long long y,long long x2,long long y2)
{
	return x*y2>=x2*y;
}

bool chk(long long x,long long y,long long y2)
{
	return cmp(ps[x-1]-ps[y2-1],x-y2,ps[x-1]-ps[y-1],x-y);
}

int main()
{
	long long i,ii,mx=0,lh,rh,md,zz;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		ttl+=a[i]*i;
	}
	for(ii=0;ii<2;ii++)
	{
		nn=0;
		for(i=1;i<=n;i++)
		{
			ps[i]=ps[i-1]+a[i];
			if(nn)
			{
				for(zz=1,lh=2,rh=nn;lh<=rh;)
				{
					md=(lh+rh)/2;
					if(f(sk[md],a[i])>=f(sk[md-1],a[i]))
					{
						zz=md;
						lh=md+1;
					}
					else
					{
						rh=md-1;
					}
				}
				mx=max(mx,f(sk[zz],a[i])+ps[i-1]-a[i]*i);
			}
			for(;nn>=2&&chk(i,sk[nn],sk[nn-1]);nn--);
			nn++;
			sk[nn]=i;
		}
		for(i=1;i<=n;i++)
		{
			a[i]*=-1;
		}
		for(i=1;i<n+1-i;i++)
		{
			swap(a[i],a[n+1-i]);
		}
	}
	printf("%lld\n",ttl+mx);
}