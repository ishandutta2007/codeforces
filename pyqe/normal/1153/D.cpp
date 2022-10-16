#include <bits/stdc++.h>

using namespace std;

long long n,dp[300069],c=0;
bitset<300069> a;
vector<long long> cd[300069];

void dfs(long long x)
{
	long long i,sz=cd[x].size(),l;
	
	if(a[x])
	{
		dp[x]=1e18;
	}
	else
	{
		dp[x]=0;
	}
	for(i=0;i<sz;i++)
	{
		l=cd[x][i];
		dfs(l);
		if(a[x])
		{
			dp[x]=min(dp[x],dp[l]);
		}
		else
		{
			dp[x]+=dp[l];
		}
	}
	if(!sz)
	{
		dp[x]=1;
		c++;
	}
}

int main()
{
	long long i,k;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		a[i]=k;
	}
	for(i=2;i<=n;i++)
	{
		scanf("%lld",&k);
		cd[k].push_back(i);
	}
	dfs(1);
	printf("%lld\n",c+1-dp[1]);
}