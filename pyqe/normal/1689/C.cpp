#include <bits/stdc++.h>

using namespace std;

const long long inf=1e18;
long long n,sbt[300069],dp[300069];
vector<long long> al[300069];
bitset<300069> vtd;

void dfs(long long x)
{
	long long i,sz=al[x].size(),l,mx=-inf;
	
	vtd[x]=1;
	sbt[x]=1;
	dp[x]=0;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			dfs(l);
			sbt[x]+=sbt[l];
			dp[x]+=dp[l];
			mx=max(mx,sbt[l]-1-dp[l]);
		}
	}
	if(mx!=-inf)
	{
		dp[x]+=mx;
	}
}

int main()
{
	long long t,rr,i,k,l;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			al[i].clear();
			vtd[i]=0;
		}
		for(i=0;i<n-1;i++)
		{
			scanf("%lld%lld",&k,&l);
			al[k].push_back(l);
			al[l].push_back(k);
		}
		dfs(1);
		printf("%lld\n",dp[1]);
	}
}