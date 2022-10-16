#include <bits/stdc++.h>

using namespace std;

long long n,m,dp[2069][2069],dv=1e9+7;

int main()
{
	long long i,j,k,sm=0,mn=0,z=0;
	string s;
	
	scanf("%lld%lld",&n,&m);
	cin>>s;
	for(i=1;i<=m;i++)
	{
		k=(s[i-1]=='(')*2-1;
		sm+=k;
		mn=min(mn,sm);
	}
	dp[0][0]=1;
	for(i=1;i<=n-m;i++)
	{
		for(j=0;j<=i;j++)
		{
			dp[i][j]=dp[i-1][j+1];
			if(j)
			{
				dp[i][j]=(dp[i][j]+dp[i-1][j-1])%dv;
			}
		}
	}
	for(i=0;i<=n-m;i++)
	{
		for(j=-mn;j<=i;j++)
		{
			if(j+sm<=n-m)
			{
				z=(z+dp[i][j]*dp[n-m-i][j+sm])%dv;
			}
		}
	}
	printf("%lld\n",z);
}