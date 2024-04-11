#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,d,a[200069],dp[200069];
pair<long long,long long> as[200069];
vector<long long> al[200069];
bitset<200069> vtd,vtd2;
bool bad;

void dfs(long long ub,long long x)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	vtd2[x]=1;
	dp[x]=0;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(a[l]<=ub)
		{
			if(!vtd[l])
			{
				dfs(ub,l);
			}
			else if(vtd2[l])
			{
				bad=1;
			}
			dp[x]=max(dp[x],dp[l]+1);
		}
	}
	vtd2[x]=0;
	bad|=dp[x]>=d-1;
}

int main()
{
	long long i,k,l,lh,rh,md,zz;
	
	scanf("%lld%lld%lld",&n,&m,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		as[i]={a[i],i};
	}
	sort(as+1,as+n+1);
	as[n+1].fr=-1;
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back(l);
	}
	for(zz=n+1,lh=1,rh=n;lh<=rh;)
	{
		md=(lh+rh)/2;
		vtd.reset();
		bad=0;
		for(i=1;i<=n;i++)
		{
			if(a[i]<=as[md].fr&&!vtd[i])
			{
				dfs(as[md].fr,i);
			}
		}
		if(bad)
		{
			zz=md;
			rh=md-1;
		}
		else
		{
			lh=md+1;
		}
	}
	printf("%lld\n",as[zz].fr);
}