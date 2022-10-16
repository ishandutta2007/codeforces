#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,dp[200069];
bitset<200069> a,vtd;
vector<pair<long long,long long>> al[200069];

void bd(long long x)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	dp[x]=a[x]*2-1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i].fr;
		if(!vtd[l])
		{
			bd(l);
			dp[x]+=max(dp[l],0ll);
		}
	}
}

void dfs(long long x,long long w)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i].fr;
		if(!vtd[l])
		{
			dfs(l,max(w+dp[x]-max(dp[l],0ll),0ll));
			al[x][i].sc=max(dp[l],0ll);
		}
		else
		{
			al[x][i].sc=w;
		}
	}
}

int main()
{
	long long i,j,k,l,ww,sz,z=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		a[i]=k;
	}
	for(i=0;i<n-1;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back({l,-1});
		al[l].push_back({k,-1});
	}
	bd(1);
	vtd.reset();
	dfs(1,0);
	for(i=1;i<=n;i++)
	{
		z=a[i]*2-1;
		sz=al[i].size();
		for(j=0;j<sz;j++)
		{
			ww=al[i][j].sc;
			z+=ww;
		}
		printf("%lld%c",z," \n"[i==n]);
	}
}