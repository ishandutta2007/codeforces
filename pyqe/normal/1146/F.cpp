#include <bits/stdc++.h>

using namespace std;

long long n,dp[200069][2],dv=998244353;
vector<long long> cd[200069];

void dfs(long long x)
{
	long long i,sz=cd[x].size(),l,sm=1,smm=0,ttl=1;
	
	for(i=0;i<sz;i++)
	{
		l=cd[x][i];
		dfs(l);
		smm=(smm*dp[l][0]+sm*dp[l][1])%dv;
		sm=sm*dp[l][0]%dv;
		ttl=ttl*(dp[l][0]+dp[l][1])%dv;
	}
	dp[x][0]=(ttl+dv-smm)%dv;
	dp[x][1]=(ttl+dv-sm)%dv;
	if(!sz)
	{
		dp[x][1]=1;
	}
}

int main()
{
	long long i,k;
	
	scanf("%lld",&n);
	for(i=2;i<=n;i++)
	{
		scanf("%lld",&k);
		cd[k].push_back(i);
	}
	dfs(1);
	printf("%lld\n",dp[1][0]);
}