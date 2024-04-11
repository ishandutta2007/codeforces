#include <bits/stdc++.h>

using namespace std;

long long n,dp[100069][2],z,inf=1e18;
vector<long long> al[100069];
bitset<100069> vtd;

void dfs(long long x)
{
	long long i,j,r,ii,iii,sz=al[x].size(),k,l,mx[2][2];
	
	vtd[x]=1;
	for(ii=0;ii<2;ii++)
	{
		for(iii=0;iii<2;iii++)
		{
			mx[ii][iii]=!ii;
		}
	}
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			dfs(l);
			for(ii=0;ii<2;ii++)
			{
				for(j=0;j<2;j++)
				{
					k=max(dp[l][0],dp[l][!ii]);
					if(k>=mx[ii][j])
					{
						for(r=1;r>j;r--)
						{
							mx[ii][r]=mx[ii][r-1];
						}
						mx[ii][j]=k;
						break;
					}
				}
			}
		}
	}
	dp[x][0]=mx[0][0]+sz-1-!!(x-1);
	dp[x][1]=mx[1][0]+1;
	z=max(z,max(mx[0][0]+mx[0][1]+sz-2,mx[1][0]+mx[1][1]+1));
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
	z=-inf;
	dfs(1);
	printf("%lld\n",z);
}