#include <bits/stdc++.h>

using namespace std;

long long n=0,nn[3],a[200069],dp[200069];

int main()
{
	long long i,ii,k;
	
	for(ii=0;ii<3;ii++)
	{
		scanf("%lld",nn+ii);
		n+=nn[ii];
	}
	for(ii=0;ii<3;ii++)
	{
		for(i=0;i<nn[ii];i++)
		{
			scanf("%lld",&k);
			a[k]=ii;
		}
	}
	for(i=1;i<=n;i++)
	{
		dp[i]=1e18;
	}
	for(ii=0;ii<3;ii++)
	{
		for(i=1;i<=n;i++)
		{
			k=dp[i-1];
			if(a[i]!=ii)
			{
				k++;
			}
			dp[i]=min(dp[i],k);
		}
	}
	printf("%lld\n",dp[n]);
}