#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,nn,sbt[500069],dp[500069],cx[500069],z,inf=1e18;
vector<long long> al[500069],cd[500069];
bitset<500069> vtd;
pair<long long,long long> a[500069];

long long tri(long long x)
{
	return x*(x-1)/2;
}

bool cmp(long long x,long long y,long long x2,long long y2)
{
	if(x/y==x2/y2)
	{
		return x%y<=x2%y2;
	}
	else
	{
		return x/y<=x2/y2;
	}
}

void bd(long long x)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	sbt[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			cd[x].push_back(l);
			bd(l);
			sbt[x]+=sbt[l];
		}
	}
}

void dfs(long long x)
{
	long long i,sz=cd[x].size(),k,l,lh,rh,md,zz;
	
	dp[x]=inf*!!sz;
	for(i=0;i<sz;i++)
	{
		l=cd[x][i];
		dfs(l);
		dp[x]=min(dp[x],tri(sbt[x]-sbt[l])+dp[l]);
		z=min(z,tri(n-sbt[l])+dp[l]);
	}
	for(i=0;i<sz;i++)
	{
		l=cd[x][i];
		a[i]={dp[l]-sbt[l]*(n*2-sbt[l]-1)/2,sbt[l]};
	}
	sort(a,a+sz);
	nn=0;
	for(i=0;i<sz;i++)
	{
		k=a[i].fr;
		l=a[i].sc;
		if(nn)
		{
			zz=1;
			for(lh=2,rh=nn;lh<=rh;)
			{
				md=(lh+rh)/2;
				if(a[cx[md]].fr+a[cx[md]].sc*l<=a[cx[md-1]].fr+a[cx[md-1]].sc*l)
				{
					zz=md;
					lh=md+1;
				}
				else
				{
					rh=md-1;
				}
			}
			z=min(z,a[cx[zz]].fr+a[cx[zz]].sc*l+k+n*(n-1)/2);
		}
		if(!i||l<a[i-1].sc)
		{
			for(;nn>=2&&cmp(a[i].fr-a[cx[nn-1]].fr,a[cx[nn-1]].sc-a[i].sc,a[i].fr-a[cx[nn]].fr,a[cx[nn]].sc-a[i].sc);nn--);
			nn++;
			cx[nn]=i;
		}
	}
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
	z=inf;
	bd(1);
	dfs(1);
	printf("%lld\n",tri(n)*2-z);
}