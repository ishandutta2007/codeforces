#include <bits/stdc++.h>

using namespace std;

long long n,dp[100069],mn=0,lz=0,inf=1e18;

int main()
{
	long long i,k,l=0,w;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		dp[i]=inf;
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		w=min(mn+1,dp[k])+lz;
		lz+=k!=l;
		dp[l]=min(dp[l],w-lz);
		mn=min(mn,w-lz);
		l=k;
	}
	printf("%lld\n",mn+lz);
}