#include <bits/stdc++.h>

using namespace std;

long long n,dh[200069],dp[200069],z=0;
vector<long long> al[200069];
bitset<200069> vtd;

void dfs(long long x)
{
	long long i,sz=al[x].size(),l;
	bool bad=dh[x]<=2;
	
	vtd[x]=1;
	dp[x]=dh[x];
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			dh[l]=dh[x]+1;
			dfs(l);
			dp[x]=max(dp[x],dp[l]);
			bad|=dp[l]<dh[x];
		}
	}
	dp[x]-=dp[x]==dh[x]&&bad;
	if(dp[x]>dh[x])
	{
		z++;
		dp[x]=dh[x]-2;
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
	dfs(1);
	printf("%lld\n",z);
}