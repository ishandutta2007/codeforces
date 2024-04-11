#include <bits/stdc++.h>

using namespace std;

long long n,ma=30,a[100069],dp[100069],inf=1e18;

int main()
{
	long long i,j,ii,u,sm,z=-inf;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=-ma;i<=ma;i++)
	{
		for(ii=0;ii<2;ii++)
		{
			u=!ii*2-1;
			sm=0;
			for(j=1+(n-1)*ii;j&&j<=n;j+=u)
			{
				if(a[j]==i)
				{
					dp[j]+=sm;
				}
				if(a[j]<=i)
				{
					sm=max(sm+a[j],0ll);
				}
				else
				{
					sm=0;
				}
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		z=max(z,dp[i]);
	}
	printf("%lld\n",z);
}