#include <bits/stdc++.h>

using namespace std;

long long n,dp[1000069][2],inf=1e18;
bitset<1000069> a;

int main()
{
	long long i,ii;
	string s;
	
	cin>>s;
	n=s.length();
	for(i=1;i<=n;i++)
	{
		a[i]=s[i-1]-'0';
	}
	dp[n+1][1]=1;
	for(i=n;i;i--)
	{
		for(ii=0;ii<2;ii++)
		{
			dp[i][ii]=dp[i+1][ii]+(a[i]^ii);
		}
		for(ii=0;ii<2;ii++)
		{
			dp[i][ii]=min(dp[i][ii],dp[i][!ii]+1);
		}
	}
	printf("%lld\n",dp[1][0]);
}