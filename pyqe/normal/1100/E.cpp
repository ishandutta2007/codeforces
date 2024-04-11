#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,md,zz,a[100069],zs=0;
vector<pair<long long,long long>> al[100069];
pair<pair<long long,long long>,pair<long long,long long>> ed[100069];
bitset<100069> vtd,vtd2;
bool r0;
pair<long long,long long> dp[100069];
vector<long long> sq;

void cyc(long long x)
{
	long long i,sz=al[x].size(),l,w;
	
	vtd[x]=1;
	vtd2[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i].sc;
		w=al[x][i].fr;
		if(w<md)
		{
			if(vtd2[l])
			{
				r0=1;
				return;
			}
			if(!vtd[l])
			{
				cyc(l);
				if(r0)
				{
					return;
				}
			}
		}
	}
	vtd2[x]=0;
}

void tps(long long x)
{
	long long i,sz=al[x].size(),l,w;
	
	vtd[x]=1;
	dp[x].fr=0;
	for(i=0;i<sz;i++)
	{
		l=al[x][i].sc;
		w=al[x][i].fr;
		if(w<zz)
		{
			if(!vtd[l])
			{
				tps(l);
			}
			dp[x].fr=max(dp[x].fr,dp[l].fr+1);
		}
	}
}

int main()
{
	long long i,k,l,w,lh,rh,pz;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&k,&l,&w);
		ed[i]={{w,i},{k,l}};
	}
	sort(ed+1,ed+m+1,greater<pair<pair<long long,long long>,pair<long long,long long>>>());
	for(i=1;i<=m;i++)
	{
		k=ed[i].sc.fr;
		l=ed[i].sc.sc;
		al[k].push_back({i,l});
	}
	for(lh=1,rh=m+1;lh<=rh;)
	{
		md=(lh+rh)/2;
		r0=0;
		vtd.reset();
		vtd2.reset();
		for(i=1;!r0&&i<=n;i++)
		{
			if(!vtd[i])
			{
				cyc(i);
			}
		}
		if(!r0)
		{
			zz=md;
			lh=md+1;
		}
		else
		{
			rh=md-1;
		}
	}
	vtd.reset();
	for(i=1;i<=n;i++)
	{
		dp[i].sc=i;
		if(!vtd[i])
		{
			tps(i);
		}
	}
	sort(dp+1,dp+n+1);
	for(i=1;i<=n;i++)
	{
		a[dp[i].sc]=i;
	}
	for(i=1;i<=m;i++)
	{
		k=ed[i].sc.fr;
		l=ed[i].sc.sc;
		pz=ed[i].fr.sc;
		if(a[k]<a[l])
		{
			sq.push_back(pz);
			zs++;
		}
	}
	printf("%lld %lld\n",ed[zz].fr.fr,zs);
	for(i=0;i<zs;i++)
	{
		printf("%lld%c",sq[i]," \n"[i==zs-1]);
	}
}