#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,dp[200069],z;
vector<long long> al[200069];
pair<long long,long long> rg[200069];

void dfs(long long x)
{
	long long i,sz=al[x].size(),l;
	
	dp[x]=0;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		dfs(l);
		dp[x]+=dp[l];
	}
	if(dp[x]<rg[x].fr)
	{
		z++;
		dp[x]=rg[x].sc;
	}
	dp[x]=min(dp[x],rg[x].sc);
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
		}
		for(i=2;i<=n;i++)
		{
			scanf("%lld",&k);
			al[k].push_back(i);
		}
		for(i=1;i<=n;i++)
		{
			scanf("%lld%lld",&k,&l);
			rg[i]={k,l};
		}
		z=0;
		dfs(1);
		printf("%lld\n",z);
	}
}