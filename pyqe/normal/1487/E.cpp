#include <bits/stdc++.h>

using namespace std;

long long n[4],a[4][150069],dp[4][150069],inf=1e18;
vector<long long> al[150069];
multiset<long long> ms;

int main()
{
	long long i,j,r,k,l,sz,z=inf;
	
	for(i=0;i<4;i++)
	{
		scanf("%lld",n+i);
	}
	for(i=0;i<4;i++)
	{
		for(j=1;j<=n[i];j++)
		{
			scanf("%lld",&a[i][j]);
			dp[i][j]=a[i][j];
		}
	}
	for(i=1;i<4;i++)
	{
		scanf("%lld",&sz);
		for(j=1;j<=n[i];j++)
		{
			al[j].clear();
		}
		for(j=0;j<sz;j++)
		{
			scanf("%lld%lld",&k,&l);
			al[l].push_back(k);
		}
		ms.clear();
		for(j=1;j<=n[i-1];j++)
		{
			ms.insert(dp[i-1][j]);
		}
		for(j=1;j<=n[i];j++)
		{
			sz=al[j].size();
			for(r=0;r<sz;r++)
			{
				l=al[j][r];
				ms.erase(ms.find(dp[i-1][l]));
			}
			if(!ms.empty())
			{
				dp[i][j]=*ms.begin()+a[i][j];
			}
			else
			{
				dp[i][j]=inf;
			}
			for(r=0;r<sz;r++)
			{
				l=al[j][r];
				ms.insert(dp[i-1][l]);
			}
		}
	}
	for(i=1;i<=n[3];i++)
	{
		z=min(z,dp[3][i]);
	}
	if(z>=inf)
	{
		z=-1;
	}
	printf("%lld\n",z);
}