#include <bits/stdc++.h>

using namespace std;

const long long dv=1e9+7;
long long n,d,dp[2][1069];

int main()
{
	long long t,rr,i,j,ii,sm,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		for(ii=0;ii<2;ii++)
		{
			for(i=0;i<=n;i++)
			{
				dp[ii][i]=0;
			}
		}
		dp[0][0]=1;
		z=1;
		for(i=d-1;i;i--)
		{
			sm=0;
			for(j=1;j<=n;j++)
			{
				sm=(sm+dp[0][j-1])%dv;
				dp[1][j]=sm;
			}
			for(j=0;j<=n;j++)
			{
				dp[0][j]=dp[1][j];
				z=(z+dp[0][j])%dv;
			}
			for(j=1;j<n+1-j;j++)
			{
				swap(dp[0][j],dp[0][n+1-j]);
			}
		}
		printf("%lld\n",z);
	}
}