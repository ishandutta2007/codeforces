#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,ttl=0,dp[100069][3],dp2[100069][2],dp3[100069],z=0;
vector<pair<long long,long long>> al[100069];
bitset<100069> vtd;
vector<long long> dpl[100069];

void dfs(long long x)
{
	long long i,j,sz=al[x].size(),k,l,w;
	
	vtd[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i].fr;
		w=al[x][i].sc;
		if(!vtd[l])
		{
			dfs(l);
			k=dp[l][0]+w;
			for(j=0;j<3;j++)
			{
				if(k>dp[x][j])
				{
					swap(dp[x][j],k);
				}
			}
			dp2[x][1]=max(dp2[x][1],min(dp2[x][0],dp3[l]));
			dp2[x][0]=max(dp2[x][0],dp3[l]);
		}
	}
	dp3[x]=max(dp2[x][0],dp[x][0]+dp[x][1]);
}

void dfs2(long long x,long long cw,long long cw2)
{
	long long i,sz=al[x].size(),k,k2,l,w,tw,tw2,e,e2;
	
	vtd[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i].fr;
		w=al[x][i].sc;
		if(!vtd[l])
		{
			dpl[x].push_back(dp[l][0]+w);
			e=dp[l][0]+w==dp[x][0];
			e2=1+(e||dp[l][0]+w==dp[x][1]);
			tw=max(cw,dp[x][e])+w;
			k=dp[x][e];
			k2=dp[x][e2];
			k2=max(k2,min(k,cw));
			k=max(k,cw);
			tw2=max({cw2,dp2[x][dp3[l]==dp2[x][0]],k+k2});
			dfs2(l,tw,tw2);
		}
		else
		{
			z=max(z,dp3[x]+w*2+cw2);
			dpl[x].push_back(cw);
		}
	}
}

int main()
{
	long long i,j,k,l,w,sz,sm;
	
	scanf("%lld",&n);
	for(i=0;i<n-1;i++)
	{
		scanf("%lld%lld%lld",&k,&l,&w);
		al[k].push_back({l,w});
		al[l].push_back({k,w});
		ttl+=w;
	}
	dfs(1);
	vtd.reset();
	dfs2(1,0,0);
	for(i=1;i<=n;i++)
	{
		sort(dpl[i].begin(),dpl[i].end(),greater<long long>());
		sm=0;
		sz=dpl[i].size();
		for(j=0;j<min(4ll,sz);j++)
		{
			sm+=dpl[i][j];
		}
		z=max(z,sm);
	}
	printf("%lld\n",ttl*2-z);
}