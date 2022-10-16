#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,a[300069],dp[300069],inf=1e18,z=-inf;
vector<pair<long long,long long>> al[300069];
bitset<300069> vtd;

void dfs(long long x)
{
	long long i,j,ii,sz=al[x].size(),l,w,mx[2]={0,0};
	
	vtd[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i].fr;
		w=al[x][i].sc;
		if(!vtd[l])
		{
			dfs(l);
			for(ii=0;ii<2;ii++)
			{
				if(dp[l]-w>=mx[ii])
				{
					for(j=1;j>ii;j--)
					{
						mx[j]=mx[j-1];
					}
					mx[ii]=dp[l]-w;
					break;
				}
			}
		}
	}
	dp[x]=mx[0]+a[x];
	z=max(z,mx[0]+mx[1]+a[x]);
}

int main()
{
	long long i,k,l,w;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=0;i<n-1;i++)
	{
		scanf("%lld%lld%lld",&k,&l,&w);
		al[k].push_back({l,w});
		al[l].push_back({k,w});
	}
	dfs(1);
	printf("%lld\n",z);
}