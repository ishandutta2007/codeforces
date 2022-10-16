#include <bits/stdc++.h>

using namespace std;

long long n,mx=-1e18,dp[200069],sbt[200069];
vector<long long> al[200069];
bitset<200069> vtd;

void bf(long long x)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	dp[x]=0;
	sbt[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			bf(l);
			dp[x]+=dp[l];
			sbt[x]+=sbt[l];
		}
	}
	dp[x]+=sbt[x];
}

void dfs(long long x,long long c,long long w)
{
	long long i,sz=al[x].size(),l,cc,ww;
	
	vtd[x]=1;
	mx=max(mx,dp[x]+w+c);
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			cc=c+sbt[x]-sbt[l];
			ww=w+dp[x]-sbt[x]-dp[l]+cc;
			dfs(l,cc,ww);
		}
	}
}

int main()
{
	long long i,k,l;
	
	scanf("%lld",&n);
	for(i=0;i<n-1;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back(l);
		al[l].push_back(k);
	}
	bf(1);
	vtd.reset();
	dfs(1,0,0);
	printf("%lld\n",mx);
}