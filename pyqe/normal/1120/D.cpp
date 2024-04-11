#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,a[200069],dp[200069],bg[200069],bs[200069],dsu[200069],sq[200069],zs=0;
vector<long long> al[200069];
bitset<200069> vtd,spc;

long long fd(long long x)
{
	if(dsu[x]!=x)
	{
		dsu[x]=fd(dsu[x]);
	}
	return dsu[x];
}

void dfs(long long x)
{
	long long i,j,ii,sz=al[x].size(),k,l,mx=-1e18,e=-1;
	pair<long long,long long> tmp;
	
	vtd[x]=1;
	dp[x]=a[x];
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			dfs(l);
			dp[x]+=dp[l];
			if(bg[l]>mx)
			{
				mx=bg[l];
				e=bs[l];
			}
			else if(bg[l]==mx)
			{
				e=0;
			}
		}
	}
	if(e==-1)
	{
		bg[x]=a[x];
		bs[x]=x;
	}
	else
	{
		k=x;
		if(mx==a[x])
		{
			if(e)
			{
				dsu[e]=x;
			}
			e=n+1;
		}
		tmp=max(mp(mx,e),{a[x],k});
		dp[x]-=tmp.fr;
		spc[tmp.sc]=1;
		tmp=min(mp(mx,e),{a[x],k});
		bg[x]=tmp.fr;
		bs[x]=tmp.sc;
	}
}

int main()
{
	long long i,k,l,w;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		dsu[i]=i;
	}
	for(i=0;i<n-1;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back(l);
		al[l].push_back(k);
	}
	dfs(1);
	for(i=1;i<=n;i++)
	{
		if(!spc[fd(i)])
		{
			zs++;
			sq[zs]=i;
		}
	}
	printf("%lld %lld\n",dp[1],zs);
	for(i=1;i<=zs;i++)
	{
		printf("%lld%c",sq[i]," \n"[i==zs]);
	}
}