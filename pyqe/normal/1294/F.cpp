#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n;
vector<pair<pair<long long,long long>,long long>> al[200069];
bitset<200069> vtd;
pair<long long,long long> dp[200069];

void bf(long long x)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	dp[x]={0,x};
	for(i=0;i<sz;i++)
	{
		l=al[x][i].sc;
		if(!vtd[l])
		{
			bf(l);
			al[x][i].fr={dp[l].fr+1,dp[l].sc};
			dp[x]=max(dp[x],al[x][i].fr);
		}
	}
	sort(al[x].begin(),al[x].end(),greater<pair<pair<long long,long long>,long long>>());
}

void dfs(long long x,pair<long long,long long> we)
{
	long long i,sz=al[x].size(),l;
	pair<long long,long long> ww={-1e18,-1};
	
	vtd[x]=1;
	we=max(we,{0,x});
	for(i=0;i<sz;i++)
	{
		l=al[x][i].sc;
		if(sz>1)
		{
			ww=al[x][!i].fr;
		}
		if(!vtd[l])
		{
			dfs(l,max(mp(we.fr+1,we.sc),{ww.fr+1,ww.sc}));
		}
		else
		{
			al[x][i].fr=we;
		}
	}
	sort(al[x].begin(),al[x].end(),greater<pair<pair<long long,long long>,long long>>());
}

int main()
{
	long long i,j,k,l,sz,sm,mx,e;
	pair<long long,long long> mxe={-1e18,-1};
	
	scanf("%lld",&n);
	for(i=0;i<n-1;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back({{-1e18,-1},l});
		al[l].push_back({{-1e18,-1},k});
	}
	bf(1);
	vtd.reset();
	dfs(1,{-1e18,-1});
	for(i=1;i<=n;i++)
	{
		sz=al[i].size();
		sm=0;
		for(j=0;j<min(sz,3ll);j++)
		{
			sm+=al[i][j].fr.fr;
		}
		mxe=max(mxe,{sm,i});
	}
	mx=mxe.fr;
	e=mxe.sc;
	printf("%lld\n",mx);
	sz=al[e].size();
	vtd.reset();
	for(j=1,i=0;i<3;i++)
	{
		if(i<sz)
		{
			k=al[e][i].fr.sc;
		}
		else if(i==sz)
		{
			k=e;
		}
		else
		{
			for(;vtd[j];j++);
			k=j;
		}
		vtd[k]=1;
		printf("%lld%c",k," \n"[i==2]);
	}
}