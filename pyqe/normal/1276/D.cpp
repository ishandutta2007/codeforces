#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,dg[200069],od[200069],dp[200069][3],ps[200069],dv=998244353;
vector<pair<long long,long long>> al[200069],cd[200069];
bitset<200069> vtd;

void dfs(long long x)
{
	long long i,sz=al[x].size(),l,w,sm=1,ttl=1,ttl2=1;
	
	vtd[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i].fr;
		w=al[x][i].sc;
		if(!vtd[l])
		{
			od[l]=w;
			cd[x].push_back({w,l});
			dfs(l);
		}
	}
	sort(cd[x].begin(),cd[x].end());
	sz--;
	ps[sz]=1;
	for(i=sz-1;i>=0;i--)
	{
		l=cd[x][i].sc;
		ps[i]=ps[i+1]*dp[l][2]%dv;
	}
	for(i=0;i<sz;i++)
	{
		l=cd[x][i].sc;
		w=cd[x][i].fr;
		if(w<od[x])
		{
			dp[x][0]=(dp[x][0]+sm*dp[l][1]%dv*ps[i+1])%dv;
			ttl=ttl*dp[l][0]%dv;
		}
		else
		{
			dp[x][1]=(dp[x][1]+sm*dp[l][1]%dv*ps[i+1])%dv;
			ttl=ttl*dp[l][2]%dv;
		}
		dp[x][2]=(dp[x][2]+sm*dp[l][1]%dv*ps[i+1])%dv;
		ttl2=ttl2*dp[l][0]%dv;
		sm=sm*dp[l][0]%dv;
	}
	dp[x][0]=(dp[x][0]+ttl)%dv;
	dp[x][1]=(dp[x][1]+ttl2)%dv;
	dp[x][2]=(dp[x][2]+ttl2)%dv;
}

int main()
{
	long long i,k,l,w;
	
	scanf("%lld",&n);
	for(i=1;i<=n-1;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back({l,i});
		al[l].push_back({k,i});
		dg[k]++;
		dg[l]++;
	}
	for(i=1;dg[i]!=1;i++);
	vtd[i]=1;
	k=al[i][0].fr;
	w=al[i][0].sc;
	od[k]=w;
	dfs(k);
	printf("%lld\n",(dp[k][0]+dp[k][1])%dv);
}