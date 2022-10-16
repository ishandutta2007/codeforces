#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,nn=0,dsu[100069],pr[100069][17],dp[100069][17],bl[100069],dh[100069],cdh=0;
pair<pair<long long,long long>,pair<long long,long long>> a[1000069];
pair<long long,pair<long long,long long>> ed[1000069];
vector<pair<long long,long long>> al[100069];
bitset<100069> vtd;

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
	long long i,j,sz=al[x].size(),l,w;
	
	vtd[x]=1;
	dh[x]=cdh;
	cdh++;
	for(i=0;i<sz;i++)
	{
		l=al[x][i].fr;
		w=al[x][i].sc;
		if(!vtd[l])
		{
			pr[l][0]=x;
			dp[l][0]=w;
			for(j=1;j-1<bl[pr[l][j-1]];j++)
			{
				pr[l][j]=pr[pr[l][j-1]][j-1];
				dp[l][j]=max(dp[l][j-1],dp[pr[l][j-1]][j-1]);
			}
			bl[l]=j;
			dfs(l);
		}
	}
	cdh--;
}

int main()
{
	long long i,j,ii,k,l,w,pz,z,p[2];
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		dsu[i]=i;
	}
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&k,&l,&w);
		a[i]={{w,i},{k,l}};
	}
	sort(a+1,a+m+1);
	for(i=1;i<=m;i++)
	{
		k=a[i].sc.fr;
		l=a[i].sc.sc;
		w=a[i].fr.fr;
		pz=a[i].fr.sc;
		if(fd(k)!=fd(l))
		{
			dsu[fd(l)]=fd(k);
			al[k].push_back({l,w});
			al[l].push_back({k,w});
		}
		else
		{
			nn++;
			ed[nn]={pz,{k,l}};
		}
	}
	dfs(1);
	sort(ed+1,ed+nn+1);
	for(i=1;i<=nn;i++)
	{
		p[0]=ed[i].sc.fr;
		p[1]=ed[i].sc.sc;
		z=-1e18;
		for(ii=0;ii<2;ii++)
		{
			for(j=16;j>=0;j--)
			{
				if(j<bl[p[ii]]&&dh[pr[p[ii]][j]]>=dh[p[!ii]])
				{
					z=max(z,dp[p[ii]][j]);
					p[ii]=pr[p[ii]][j];
				}
			}
		}
		for(j=16;j>=0;j--)
		{
			if(j<bl[p[0]]&&pr[p[0]][j]!=pr[p[1]][j])
			{
				for(ii=0;ii<2;ii++)
				{
					z=max(z,dp[p[ii]][j]);
					p[ii]=pr[p[ii]][j];
				}
			}
		}
		if(p[0]!=p[1])
		{
			z=max(z,max(dp[p[0]][0],dp[p[1]][0]));
		}
		printf("%lld\n",z);
	}
}