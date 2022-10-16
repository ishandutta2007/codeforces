#include <bits/stdc++.h>

using namespace std;

long long n,m,cr,dp[200069];
vector<long long> al[2][200069];
bitset<200069> vtd,vtd2,spc[2];

void dfs(long long x)
{
	long long i,sz=al[cr][x].size(),l;
	
	vtd[x]=1;
	dp[x]=x;
	vtd2[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[cr][x][i];
		if(!vtd[l])
		{
			dfs(l);
		}
		else if(vtd2[l])
		{
			printf("-1\n");
			exit(0);
		}
		dp[x]=min(dp[x],dp[l]);
	}
	vtd2[x]=0;
	spc[cr][x]=dp[x]==x;
}

int main()
{
	long long i,ii,k,l,z=0;
	
	scanf("%lld%lld",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&k,&l);
		for(ii=0;ii<2;ii++)
		{
			al[ii][k].push_back(l);
			swap(k,l);
		}
	}
	for(cr=0;cr<2;cr++)
	{
		vtd.reset();
		for(i=1;i<=n;i++)
		{
			if(!vtd[i])
			{
				dfs(i);
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		z+=spc[0][i]&&spc[1][i];
	}
	printf("%lld\n",z);
	for(i=1;i<=n;i++)
	{
		printf("%c","EA"[spc[0][i]&&spc[1][i]]);
	}
}