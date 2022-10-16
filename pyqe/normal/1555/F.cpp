#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,nn=0,dsu[300069],pst[300069],sbt[300069],xr[300069],pr[300069][19],dh[300069],fw[300069],fi;
pair<pair<long long,long long>,bool> ed[500069];
vector<pair<long long,bool>> al[300069];
bitset<300069> vtd;
bitset<500069> sq;

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
	nn++;
	pst[x]=nn;
	sbt[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i].fr;
		w=al[x][i].sc;
		if(!vtd[l])
		{
			xr[l]=xr[x]^w;
			pr[l][0]=x;
			for(j=1;j<19;j++)
			{
				pr[l][j]=pr[pr[l][j-1]][j-1];
			}
			dh[l]=dh[x]+1;
			dfs(l);
			sbt[x]+=sbt[l];
		}
	}
}

long long lca(long long x,long long y)
{
	long long i,ii;
	
	for(ii=0;ii<2;ii++)
	{
		for(i=18;i+1;i--)
		{
			if(dh[pr[x][i]]>=dh[y])
			{
				x=pr[x][i];
			}
		}
		swap(x,y);
	}
	for(i=18;i+1;i--)
	{
		if(pr[x][i]!=pr[y][i])
		{
			x=pr[x][i];
			y=pr[y][i];
		}
	}
	if(x!=y)
	{
		x=pr[x][0];
	}
	return x;
}

void ud(long long x,long long w)
{
	for(fi=x;fi<=n;fi+=fi&-fi)
	{
		fw[fi]+=w;
	}
}

long long qr(long long x)
{
	long long z=0;
	
	for(fi=x;fi;fi-=fi&-fi)
	{
		z+=fw[fi];
	}
	return z;
}

int main()
{
	long long i,k,l,w,la;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		dsu[i]=i;
	}
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&k,&l,&w);
		ed[i]={{k,l},w};
		if(fd(k)!=fd(l))
		{
			dsu[fd(l)]=fd(k);
			sq[i]=1;
			al[k].push_back({l,w});
			al[l].push_back({k,w});
		}
	}
	dh[0]=-1;
	for(i=1;i<=n;i++)
	{
		if(!vtd[i])
		{
			dfs(i);
		}
	}
	for(i=1;i<=m;i++)
	{
		if(!sq[i])
		{
			k=ed[i].fr.fr;
			l=ed[i].fr.sc;
			w=ed[i].sc;
			la=lca(k,l);
			if((xr[k]^xr[l]^w)&&qr(pst[k])+qr(pst[l])-qr(pst[la])*2==0)
			{
				sq[i]=1;
				for(;1;)
				{
					if(dh[l]>dh[k])
					{
						swap(k,l);
					}
					if(k==la)
					{
						break;
					}
					ud(pst[k],1);
					ud(pst[k]+sbt[k],-1);
					k=pr[k][0];
				}
			}
		}
		if(sq[i])
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}