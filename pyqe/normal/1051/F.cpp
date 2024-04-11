#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,nn=0,nm=0,dsu[100069],ex[69],od[100069],am[69][69],dh[100069],nr[100069],pst[100069],lg2[200069],inf=1e18;
vector<pair<long long,long long>> al[100069];
bitset<100069> vtd;
pair<long long,long long> sp[18][200069];

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
	long long i,sz=al[x].size(),l,w;
	
	vtd[x]=1;
	nn++;
	sp[0][nn]={dh[x],x};
	pst[x]=nn;
	for(i=0;i<sz;i++)
	{
		l=al[x][i].fr;
		w=al[x][i].sc;
		if(!vtd[l])
		{
			dh[l]=dh[x]+1;
			nr[l]=nr[x]+w;
			dfs(l);
			nn++;
			sp[0][nn]={dh[x],x};
		}
	}
}

void spbd()
{
	long long i,j,k;
	
	for(i=1;1ll<<i<=nn;i++)
	{
		for(j=1;j<=nn-(1ll<<i)+1;j++)
		{
			sp[i][j]=min(sp[i-1][j],sp[i-1][j+(1ll<<i-1)]);
		}
	}
	for(i=1;i<=nn;i++)
	{
		for(k=i;k>1;k/=2,lg2[i]++);
	}
}

long long qr(long long lh,long long rh)
{
	long long e=lg2[rh-lh+1];
	
	return min(sp[e][lh],sp[e][rh-(1ll<<e)+1]).sc;
}

long long lca(long long x,long long y)
{
	if(pst[x]>pst[y])
	{
		swap(x,y);
	}
	return qr(pst[x],pst[y]);
}

long long ds(long long x,long long y)
{
	return nr[x]+nr[y]-nr[lca(x,y)]*2;
}

int main()
{
	long long t,rr,i,j,r,ii,k,l,w,z;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		dsu[i]=i;
	}
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld%lld",&k,&l,&w);
		if(fd(k)!=fd(l))
		{
			al[k].push_back({l,w});
			al[l].push_back({k,w});
			dsu[fd(l)]=fd(k);
		}
		else
		{
			for(ii=0;ii<2;ii++)
			{
				if(!od[k])
				{
					nm++;
					ex[nm]=k;
					od[k]=nm;
					for(j=1;j<nm;j++)
					{
						am[j][nm]=inf;
						am[nm][j]=inf;
					}
				}
				swap(k,l);
			}
			am[od[k]][od[l]]=min(am[od[k]][od[l]],w);
			am[od[l]][od[k]]=min(am[od[l]][od[k]],w);
		}
	}
	dfs(1);
	spbd();
	for(i=1;i<=nm;i++)
	{
		for(j=1;j<=nm;j++)
		{
			am[i][j]=min(am[i][j],ds(ex[i],ex[j]));
		}
	}
	for(i=1;i<=nm;i++)
	{
		for(j=1;j<=nm;j++)
		{
			for(r=1;r<=nm;r++)
			{
				am[j][r]=min(am[j][r],am[j][i]+am[i][r]);
			}
		}
	}
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&k,&l);
		z=ds(k,l);
		for(i=1;i<=nm;i++)
		{
			for(j=1;j<=nm;j++)
			{
				z=min(z,ds(k,ex[i])+am[i][j]+ds(ex[j],l));
			}
		}
		printf("%lld\n",z);
	}
}