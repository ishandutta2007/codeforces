#include <bits/stdc++.h>

using namespace std;

const long long inf=1e18;
long long n,m,dh[200069],dp[200069];
bitset<200069> spc,vtd;
vector<long long> al[200069];

void dfs(long long x)
{
	long long i,sz=al[x].size(),l;
	bool lf=1;
	
	vtd[x]=1;
	dp[x]=0;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			dh[l]=dh[x]+1;
			dfs(l);
			lf=0;
			if(min(dp[x],dp[l])<0)
			{
				dp[x]=min(dp[x],dp[l]);
			}
			else
			{
				dp[x]=min(dp[x]+dp[l],inf);
			}
		}
	}
	if(lf)
	{
		dp[x]=inf;
	}
	dp[x]+=dp[x]<0;
	if(spc[x])
	{
		dp[x]=min(dp[x],-(dh[x]/2));
	}
	dp[x]+=!dp[x];
}

int main()
{
	long long t,rr,i,k,l,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		for(i=1;i<=n;i++)
		{
			spc[i]=0;
			al[i].clear();
			vtd[i]=0;
		}
		for(i=0;i<m;i++)
		{
			scanf("%lld",&k);
			spc[k]=1;
		}
		for(i=0;i<n-1;i++)
		{
			scanf("%lld%lld",&k,&l);
			al[k].push_back(l);
			al[l].push_back(k);
		}
		dfs(1);
		z=dp[1];
		if(z==inf)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}