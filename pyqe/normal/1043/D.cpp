#include <bits/stdc++.h>

using namespace std;

long long n,m,dp[100069],z=0;
map<long long,map<long long,long long>> fq;
vector<long long> al[100069];
bitset<100069> vtd;

void dfs(long long x)
{
	long long i,sz=al[x].size(),l;
	
	dp[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			dfs(l);
		}
		dp[x]=max(dp[x],dp[l]+1);
	}
	z+=dp[x];
	vtd[x]=1;
}

int main()
{
	long long i,j,k,l;
	
	scanf("%lld%lld",&n,&m);
	for(i=0;i<m;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%lld",&k);
			if(j-1)
			{
				fq[l][k]++;
				if(fq[l][k]==m)
				{
					al[l].push_back(k);
				}
			}
			l=k;
		}
	}
	for(i=1;i<=n;i++)
	{
		if(!vtd[i])
		{
			dfs(i);
		}
	}
	printf("%lld\n",z);
}