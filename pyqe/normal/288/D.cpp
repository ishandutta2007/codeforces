#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,sbt[80069],a[80069],ps[80069],pss[2][80069];
vector<pair<long long,long long>> al[80069];
bitset<80069> vtd;

void bd(long long x)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	sbt[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i].fr;
		if(!vtd[l])
		{
			bd(l);
			sbt[x]+=sbt[l];
		}
	}
}

void dfs(long long x,long long w)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i].fr;
		if(!vtd[l])
		{
			dfs(l,w+sbt[x]-sbt[l]);
			al[x][i].sc=sbt[l];
		}
		else
		{
			al[x][i].sc=w;
		}
	}
}

int main()
{
	long long i,j,ii,u,k,l,sz,sm,z=0;
	
	scanf("%lld",&n);
	for(i=0;i<n-1;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back({l,0});
		al[l].push_back({k,0});
	}
	bd(1);
	vtd.reset();
	dfs(1,0);
	for(i=1;i<=n;i++)
	{
		sz=al[i].size();
		for(j=1;j<=sz;j++)
		{
			a[j]=al[i][j-1].sc;
			ps[j]=ps[j-1]+a[j];
		}
		for(ii=0;ii<2;ii++)
		{
			u=!ii*2-1;
			sm=0;
			pss[ii][(sz+1)*ii]=0;
			for(j=1+(sz-1)*ii;j&&j<=sz;j+=u)
			{
				pss[ii][j]=pss[ii][j-u]+a[j]*sm;
				sm+=a[j];
			}
		}
		for(j=1;j<=sz;j++)
		{
			z+=a[j]*(a[j]-1)/2*(ps[sz]-a[j]+ps[j-1]*(ps[sz]-ps[j])+pss[0][j-1]+pss[1][j+1]);
		}
	}
	printf("%lld\n",z);
}