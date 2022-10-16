#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const long long inf=1e18;
long long n,m,a[3069],sbt[3069];
vector<long long> al[3069];
bitset<3069> vtd;
pair<long long,long long> dp[3069][3069],tmp[3069];

void dfs(long long x)
{
	long long i,j,r,sz=al[x].size(),l;
	
	vtd[x]=1;
	sbt[x]=0;
	dp[x][0]={0,a[x]};
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			dfs(l);
			for(j=0;j<=sbt[x]+sbt[l];j++)
			{
				tmp[j]={-inf,-inf};
			}
			for(j=0;j<=sbt[x];j++)
			{
				for(r=0;r<=sbt[l];r++)
				{
					tmp[j+r]=max(tmp[j+r],{dp[x][j].fr+dp[l][r].fr,dp[x][j].sc+dp[l][r].sc});
				}
			}
			sbt[x]+=sbt[l];
			for(j=0;j<=sbt[x];j++)
			{
				dp[x][j]=tmp[j];
			}
		}
	}
	sbt[x]++;
	dp[x][sbt[x]]={-inf,-inf};
	for(i=sbt[x];i;i--)
	{
		dp[x][i]=max(dp[x][i],{dp[x][i-1].fr+(dp[x][i-1].sc>0),0});
	}
}

int main()
{
	long long t,rr,i,k,l;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
			al[i].clear();
			vtd[i]=0;
		}
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			a[i]=k-a[i];
		}
		for(i=0;i<n-1;i++)
		{
			scanf("%lld%lld",&k,&l);
			al[k].push_back(l);
			al[l].push_back(k);
		}
		dfs(1);
		printf("%lld\n",dp[1][m-1].fr+(dp[1][m-1].sc>0));
	}
}