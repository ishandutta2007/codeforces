#include <bits/stdc++.h>

using namespace std;

long long n,d,dg[1000069],dp[1000069],z=0,inf=1e18;
vector<long long> al[1000069];
bitset<1000069> vtd;

void dfs(long long x)
{
	long long i,sz=al[x].size(),k,l;
	
	vtd[x]=1;
	dp[x]=-inf*(dg[x]>1);
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			dfs(l);
			k=dp[l]+1;
			if(dp[x]<k)
			{
				swap(dp[x],k);
			}
			if(dp[x]+k>d)
			{
				z++;
				swap(dp[x],k);
			}
		}
	}
}

int main()
{
	long long i,ii,k,l;
	
	scanf("%lld%lld",&n,&d);
	for(i=0;i<n-1;i++)
	{
		scanf("%lld%lld",&k,&l);
		for(ii=0;ii<2;ii++)
		{
			al[k].push_back(l);
			dg[k]++;
			swap(k,l);
		}
	}
	for(i=1;i<=n;i++)
	{
		if(dg[i]>1)
		{
			dfs(i);
			z+=dp[i]>=0;
			break;
		}
	}
	printf("%lld\n",z);
}