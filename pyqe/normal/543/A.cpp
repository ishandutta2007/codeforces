#include <bits/stdc++.h>

using namespace std;

long long n,m,d,dp[569][569],dv;

int main()
{
	long long i,j,r,k,z=0;
	
	scanf("%lld%lld%lld%lld",&n,&m,&d,&dv);
	dp[0][0]=1;
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		for(j=1;j<=m;j++)
		{
			for(r=k;r<=d;r++)
			{
				dp[j][r]=(dp[j][r]+dp[j-1][r-k])%dv;
			}
		}
	}
	for(i=0;i<=d;i++)
	{
		z=(z+dp[m][i])%dv;
	}
	printf("%lld\n",z);
}