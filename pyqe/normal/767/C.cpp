#include <bits/stdc++.h>

using namespace std;

long long n,rt,ttl=0,a[1000069],dp[1000069];
vector<long long> al[1000069];

void dfs(long long x)
{
	long long i,sz=al[x].size(),l;
	
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		dfs(l);
		a[x]+=a[l];
		if(dp[l])
		{
			if(dp[x])
			{
				printf("%lld %lld\n",dp[x],dp[l]);
				exit(0);
			}
			dp[x]=dp[l];
		}
	}
	if(x!=rt&&dp[x]&&a[x]==ttl/3*2)
	{
		printf("%lld %lld\n",dp[x],x);
		exit(0);
	}
	if(a[x]==ttl/3)
	{
		dp[x]=x;
	}
}

int main()
{
	long long i,k;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",&k,a+i);
		if(k)
		{
			al[k].push_back(i);
		}
		else
		{
			rt=i;
		}
		ttl+=a[i];
	}
	if(ttl%3)
	{
		printf("-1\n");
		return 0;
	}
	dfs(rt);
	printf("-1\n");
}