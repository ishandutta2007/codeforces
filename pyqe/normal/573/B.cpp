#include <bits/stdc++.h>

using namespace std;

long long n,aa[100069],dp[2][100069];

int main()
{
	long long i,ii,u,k,mx=-1e18;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",aa+i);
	}
	for(ii=0;ii<2;ii++)
	{
		u=!ii*2-1;
		dp[ii][(n+3)*ii-1]=1e18;
		for(i=(n+1)*ii;i!=n+2-(n+3)*ii;i+=u)
		{
			dp[ii][i]=min(dp[ii][i-u],aa[i]-i*u);
		}
	}
	for(i=0;i<=n+1;i++)
	{
		k=min(dp[0][i]+i,dp[1][i]-i);
		mx=max(mx,k);
	}
	printf("%lld\n",mx);
}