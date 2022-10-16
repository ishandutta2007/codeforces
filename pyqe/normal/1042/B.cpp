#include <bits/stdc++.h>

using namespace std;

long long n,dp[2][1ll<<3],inf=1e18;

int main()
{
	long long ln,i,j,ii,k,w,mk,mkk,z;
	string s;
	
	scanf("%lld",&n);
	for(ii=0;ii<2;ii++)
	{
		for(mk=1;mk<1ll<<3;mk++)
		{
			dp[ii][mk]=inf;
		}
	}
	for(i=0;i<n;i++)
	{
		scanf("%lld",&w);
		cin>>s;
		ln=s.length();
		mkk=0;
		for(j=0;j<ln;j++)
		{
			k=s[j]-'A';
			mkk|=1ll<<k;
		}
		for(mk=0;mk<1ll<<3;mk++)
		{
			dp[1][mk|mkk]=min(dp[1][mk|mkk],dp[0][mk]+w);
		}
		for(mk=0;mk<1ll<<3;mk++)
		{
			dp[0][mk]=dp[1][mk];
		}
	}
	z=dp[0][(1ll<<3)-1];
	if(z==inf)
	{
		z=-1;
	}
	printf("%lld\n",z);
}