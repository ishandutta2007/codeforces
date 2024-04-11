#include <bits/stdc++.h>

using namespace std;

long long n,m,ma=1e5,fq[2][100069],a[11],dp[569][5069],inf=1e18;

int main()
{
	long long i,j,r,k,z=0;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n*m;i++)
	{
		scanf("%lld",&k);
		fq[0][k]++;
		dp[0][i]=-inf;
	}
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		fq[1][k]++;
	}
	for(i=1;i<=m;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=1;i<=n;i++)
	{
		for(j=0;j<=n*m;j++)
		{
			dp[i][j]=dp[i-1][j];
			for(r=1;r<=min(m,j);r++)
			{
				dp[i][j]=max(dp[i][j],dp[i-1][j-r]+a[r]);
			}
		}
	}
	for(i=1;i<=ma;i++)
	{
		z+=dp[fq[1][i]][min(fq[0][i],fq[1][i]*m)];
	}
	printf("%lld\n",z);
}