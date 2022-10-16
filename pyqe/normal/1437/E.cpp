#include <bits/stdc++.h>

using namespace std;

long long n,m,a[500069],lis[500069],inf=1e18;
bitset<500069> spc;

int main()
{
	long long i,j,k,l=-inf,p,mx=0,z=0;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		a[i]-=i;
		lis[i]=inf;
	}
	for(i=0;i<m;i++)
	{
		scanf("%lld",&k);
		spc[k]=1;
	}
	for(i=1;i<=n;i++)
	{
		if(a[i]>=l)
		{
			p=upper_bound(lis+1,lis+n+1,a[i])-lis;
			if(!spc[i])
			{
				lis[p]=a[i];
				mx=max(mx,p);
			}
			else
			{
				z+=p;
				for(j=1;j<=mx;j++)
				{
					lis[j]=inf;
				}
				mx=0;
				l=a[i];
			}
		}
		else if(spc[i])
		{
			printf("-1\n");
			return 0;
		}
	}
	z+=mx;
	printf("%lld\n",n-z);
}