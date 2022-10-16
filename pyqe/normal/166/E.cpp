#include <bits/stdc++.h>

using namespace std;

long long n,dp[4],dv=1e9+7;

int main()
{
	long long i,j,sm;
	
	scanf("%lld",&n);
	dp[0]=1;
	for(i=0;i<n;i++)
	{
		sm=0;
		for(j=0;j<4;j++)
		{
			sm=(sm+dp[j])%dv;
		}
		for(j=0;j<4;j++)
		{
			dp[j]=(sm+dv-dp[j])%dv;
		}
	}
	printf("%lld\n",dp[0]);
}