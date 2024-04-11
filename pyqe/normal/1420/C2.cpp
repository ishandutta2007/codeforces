#include <bits/stdc++.h>

using namespace std;

long long n,a[300069],sm;

void chk(long long x,long long u)
{
	if(a[x]>a[x-1]&&a[x]>a[x+1])
	{
		sm+=a[x]*u;
	}
	else if(a[x]<a[x-1]&&a[x]<a[x+1])
	{
		sm-=a[x]*u;
	}
}

int main()
{
	long long tt,rrr,t,rr,i,j,ii,u,k,l;
	
	scanf("%lld",&tt);
	for(rrr=0;rrr<tt;rrr++)
	{
		scanf("%lld%lld",&n,&t);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		a[n+1]=0;
		sm=0;
		for(i=1;i<=n;i++)
		{
			chk(i,1);
		}
		for(rr=0;rr<=t;rr++)
		{
			if(rr)
			{
				scanf("%lld%lld",&k,&l);
				for(ii=0;ii<2;ii++)
				{
					u=!ii*2-1;
					if(ii)
					{
						swap(a[k],a[l]);
					}
					for(j=max(k-1,1ll);j<=min(k+1,n);j++)
					{
						chk(j,-u);
					}
					for(j=max(l-1,k+2);j<=min(l+1,n);j++)
					{
						chk(j,-u);
					}
				}
			}
			printf("%lld\n",sm);
		}
	}
}