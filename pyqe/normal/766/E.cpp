#include <bits/stdc++.h>

using namespace std;

long long n,d=20,a[100069],dp[100069][20][2],z=0;
vector<long long> al[100069];
bitset<100069> vtd;

void dfs(long long x)
{
	long long i,j,ii,sz=al[x].size(),l;
	
	vtd[x]=1;
	z+=a[x];
	for(i=0;i<d;i++)
	{
		dp[x][i][a[x]>>i&1]=1;
	}
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			dfs(l);
			for(j=0;j<d;j++)
			{
				for(ii=0;ii<2;ii++)
				{
					z+=dp[x][j][ii]*dp[l][j][!ii]<<j;
				}
				for(ii=0;ii<2;ii++)
				{
					dp[x][j][ii]+=dp[l][j][ii^(a[x]>>j&1)];
				}
			}
		}
	}
}

int main()
{
	long long i,k,l;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=0;i<n-1;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back(l);
		al[l].push_back(k);
	}
	dfs(1);
	printf("%lld\n",z);
}