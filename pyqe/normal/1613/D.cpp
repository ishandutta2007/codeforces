#include <bits/stdc++.h>

using namespace std;

const long long dv=998244353;
long long n,dp[2][500069];

int main()
{
	long long t,rr,i,ii,k,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(ii=0;ii<2;ii++)
		{
			for(i=0;i<=n+1;i++)
			{
				dp[ii][i]=0;
			}
		}
		dp[0][0]=1;
		dp[1][0]=1;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			dp[1][k+1]=(dp[1][k+1]+dp[1][k+1])%dv;
			if(k)
			{
				dp[1][k-1]=(dp[1][k-1]+dp[1][k-1])%dv;
			}
			dp[0][k+1]=(dp[0][k+1]+dp[0][k+1])%dv;
			dp[1][k+1]=(dp[1][k+1]+dp[0][k])%dv;
			dp[0][k+1]=(dp[0][k+1]+dp[0][k])%dv;
		}
		z=dv-1;
		for(i=0;i<=n+1;i++)
		{
			z=(z+dp[1][i])%dv;
		}
		printf("%lld\n",z);
	}
}