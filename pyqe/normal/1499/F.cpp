#include <bits/stdc++.h>

using namespace std;

long long n,d,dp[5069][5069],tmp[5069],dv=998244353;
vector<long long> al[5069];
bitset<5069> vtd;

void dfs(long long x)
{
	long long i,j,ii,sz=al[x].size(),l,sm;
	
	vtd[x]=1;
	dp[x][0]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			dfs(l);
			sm=0;
			for(j=d;j+1;j--)
			{
				sm=(sm+dp[l][j])%dv;
				if(j)
				{
					dp[l][j]=dp[l][j-1];
				}
			}
			dp[l][0]=sm;
			for(j=1;j<=d;j++)
			{
				dp[x][j]=(dp[x][j]+dp[x][j-1])%dv;
				dp[l][j]=(dp[l][j]+dp[l][j-1])%dv;
			}
			for(j=0;j<=d;j++)
			{
				if(d-j<j)
				{
					tmp[j]=0;
					for(ii=0;ii<2;ii++)
					{
						tmp[j]=(tmp[j]+(dp[x][j]+dv-dp[x][j-1])*dp[l][d-j])%dv;
						swap(x,l);
					}
				}
				else
				{
					tmp[j]=dp[x][j]*dp[l][j]%dv;
					if(j)
					{
						tmp[j]=(tmp[j]+dv-dp[x][j-1]*dp[l][j-1]%dv)%dv;
					}
				}
			}
			for(j=0;j<=d;j++)
			{
				dp[x][j]=tmp[j];
			}
		}
	}
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
	for(i=0;i<=d;i++)
	{
		z=(z+dp[1][i])%dv;
	}
	printf("%lld\n",z);
}