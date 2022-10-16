#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,sbt[3069],pr[3069],ds[3069][3069],d[3069][3069],an[3069][3069][2],dp[3069][3069],cdh=0,rt,bs,dd;
vector<pair<long long,long long>> al[3069];
bitset<3069> vtd;

void cnt(long long x)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	sbt[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i].fr;
		if(!vtd[l])
		{
			cnt(l);
			sbt[x]+=sbt[l];
		}
	}
}

void cnt2(long long x,long long w)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i].fr;
		if(!vtd[l])
		{
			cnt2(l,w+sbt[x]-sbt[l]);
			al[x][i].sc=w+sbt[x]-sbt[l];
		}
		else
		{
			al[x][i].sc=sbt[x];
		}
	}
}

void dfs(long long x)
{
	long long i,sz=al[x].size(),l,w,ww;
	
	vtd[x]=1;
	cdh++;
	for(i=0;i<sz;i++)
	{
		l=al[x][i].fr;
		w=al[x][i].sc;
		if(cdh==1)
		{
			bs=l;
			dd=w;
		}
		if(!vtd[l])
		{
			pr[l]=x;
			dfs(l);
		}
		else
		{
			ww=w;
		}
	}
	cdh--;
	if(cdh)
	{
		ds[rt][x]=cdh;
		d[rt][x]=dd*ww;
		an[rt][x][0]=bs;
		an[rt][x][1]=pr[x];
	}
}

long long bf(long long x,long long y)
{
	if(dp[x][y]==-1)
	{
		dp[x][y]=d[x][y];
		if(ds[x][y]>1)
		{
			dp[x][y]+=max(bf(an[x][y][0],y),bf(x,an[x][y][1]));
		}
	}
	return dp[x][y];
}

int main()
{
	long long i,j,k,l,mx=-1e18;
	
	scanf("%lld",&n);
	for(i=0;i<n-1;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back({l,0});
		al[l].push_back({k,0});
	}
	cnt(1);
	vtd.reset();
	cnt2(1,0);
	for(i=1;i<=n;i++)
	{
		vtd.reset();
		rt=i;
		dfs(i);
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			dp[i][j]=-1;
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(i!=j)
			{
				bf(i,j);
				mx=max(mx,dp[i][j]);
				
			}
		}
	}
	printf("%lld\n",mx);
}