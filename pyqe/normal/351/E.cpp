#include <bits/stdc++.h>

using namespace std;

long long n,nn,a[2069],as[2069],vl[2069],inf=1e18;

int main()
{
	long long i,j,r,k,c,sm,mn,z=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		k=-abs(k);
		a[i]=k;
		as[i]=k;
	}
	sort(as+1,as+n+1);
	for(i=1;i<=n;i++)
	{
		if(i==n||as[i]!=as[i+1])
		{
			nn=0;
			c=0;
			for(j=1;j<=n;j++)
			{
				c+=a[j]>as[i];
				if(a[j]==as[i])
				{
					nn++;
					vl[nn]=c;
					c=0;
				}
			}
			nn++;
			vl[nn]=c;
			mn=inf;
			for(j=1;j<=nn;j++)
			{
				sm=0;
				for(r=1;r<=nn;r++)
				{
					sm+=vl[r]*abs(j-r);
				}
				mn=min(mn,sm);
			}
			z+=mn;
		}
	}
	printf("%lld\n",z);
}