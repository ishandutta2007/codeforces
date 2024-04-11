#include <bits/stdc++.h>

using namespace std;

long long n,ttl=0,nn[2],a[2][200069],as[2][200069];

bool cmp(long long x,long long y)
{
	return a[0][x]<a[0][y];
}

bool cmp2(long long x,long long y)
{
	return a[1][x]<a[1][y];
}

int main()
{
	long long i,j,ii,k,l,e,mx,z=0;
	
	scanf("%lld",&n);
	for(ii=0;ii<2;ii++)
	{
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&a[ii][i]);
		}
	}
	for(i=1;i<=n;i++)
	{
		ttl+=abs(a[0][i]-a[1][i]);
		e=a[0][i]>a[1][i];
		nn[e]++;
		as[e][nn[e]]=i;
	}
	sort(as[0]+1,as[0]+nn[0]+1,cmp);
	sort(as[1]+1,as[1]+nn[1]+1,cmp2);
	for(ii=0;ii<2;ii++)
	{
		mx=0;
		for(j=1,i=1;i<=nn[ii];i++)
		{
			k=a[ii][as[ii][i]];
			l=a[!ii][as[ii][i]];
			for(;j<=nn[!ii]&&a[!ii][as[!ii][j]]<=k;j++)
			{
				mx=max(mx,a[ii][as[!ii][j]]);
			}
			z=max(z,min(mx,l)-k);
		}
	}
	printf("%lld\n",ttl-z*2);
}