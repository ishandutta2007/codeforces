#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,nr[100069],inf=1e18;
pair<long long,long long> ed[100069],dp[100069];
bitset<100069> wg,vtd,spc;
vector<pair<long long,bool>> al[100069],cd[100069];
queue<long long> q;

void dfs(long long x)
{
	long long i,sz=cd[x].size(),l,w;
	
	vtd[x]=1;
	dp[x]={inf*(x!=1),-1};
	for(i=0;i<sz;i++)
	{
		l=cd[x][i].fr;
		w=cd[x][i].sc;
		if(!vtd[l])
		{
			dfs(l);
		}
		dp[x]=min(dp[x],{dp[l].fr+!w*2-1,l});
	}
}

int main()
{
	long long i,k,l,w,sz,c=0,p;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&k,&l,&w);
		ed[i]={k,l};
		wg[i]=w;
		al[k].push_back({l,w});
		al[l].push_back({k,w});
		c+=w;
	}
	for(i=1;i<=n;i++)
	{
		nr[i]=inf;
	}
	q.push(1);
	nr[1]=0;
	for(;!q.empty();)
	{
		k=q.front();
		q.pop();
		sz=al[k].size();
		for(i=0;i<sz;i++)
		{
			l=al[k][i].fr;
			w=al[k][i].sc;
			if(nr[k]+1<nr[l])
			{
				q.push(l);
				nr[l]=nr[k]+1;
			}
			if(nr[k]+1==nr[l])
			{
				cd[l].push_back({k,w});
			}
		}
	}
	dfs(n);
	for(p=n;p+1;p=dp[p].sc)
	{
		spc[p]=1;
	}
	printf("%lld\n",c+dp[n].fr);
	for(i=1;i<=m;i++)
	{
		k=ed[i].fr;
		l=ed[i].sc;
		if((spc[k]&&spc[l])^wg[i])
		{
			printf("%lld %lld %lld\n",k,l,(long long)!wg[i]);
		}
	}
}