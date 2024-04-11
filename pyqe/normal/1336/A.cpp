#include <bits/stdc++.h>

using namespace std;

long long n,d,sbt[200069],dh[200069],cdh=0,dp[200069];
vector<long long> al[200069];
bitset<200069> vtd;

void dfs(long long x)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	sbt[x]=1;
	dh[x]=cdh;
	cdh++;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			dfs(l);
			sbt[x]+=sbt[l];
		}
	}
	cdh--;
}

int main()
{
	long long i,k,l,z=0;
	
	scanf("%lld%lld",&n,&d);
	for(i=0;i<n-1;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back(l);
		al[l].push_back(k);
	}
	dfs(1);
	for(i=1;i<=n;i++)
	{
		dp[i]=sbt[i]-1-dh[i];
	}
	sort(dp+1,dp+n+1,greater<long long>());
	for(i=1;i<=n-d;i++)
	{
		z+=dp[i];
	}
	printf("%lld\n",z);
}