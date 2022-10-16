#include <bits/stdc++.h>

using namespace std;

long long n,a[100069],dp[100069],lis[2][100069],fq[100069],inf=1e18;

int main()
{
	long long i,ii,u,p,mx=-inf,z;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(ii=0;ii<2;ii++)
	{
		u=!ii*2-1;
		for(i=1;i<=n;i++)
		{
			dp[i]=inf;
		}
		for(i=1+(n-1)*ii;i&&i<=n;i+=u)
		{
			p=lower_bound(dp+1,dp+n+1,a[i]*u)-dp;
			dp[p]=a[i]*u;
			lis[ii][i]=p;
			mx=max(mx,p);
		}
	}
	for(i=1;i<=n;i++)
	{
		fq[lis[0][i]]+=lis[0][i]+lis[1][i]-1==mx;
	}
	for(i=1;i<=n;i++)
	{
		if(lis[0][i]+lis[1][i]-1<mx)
		{
			z=1;
		}
		else if(fq[lis[0][i]]>1)
		{
			z=2;
		}
		else
		{
			z=3;
		}
		printf("%lld",z);
	}
	printf("\n");
}