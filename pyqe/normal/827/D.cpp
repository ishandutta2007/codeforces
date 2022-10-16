#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const long long d=18,inf=1e18;
long long n,m,wg[200069],as[200069],dsu[200069],pr[200069][d],mxa[200069][d],dh[200069],pe[200069],sq[200069];
pair<long long,long long> ed[200069];
vector<pair<long long,long long>> al[200069];
bitset<200069> spc,vtd;

bool cwg(long long x,long long y)
{
	return wg[x]<wg[y];
}

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
	long long i,sz=al[x].size(),l,p;
	
	vtd[x]=1;
	for(i=1;i<d;i++)
	{
		pr[x][i]=pr[pr[x][i-1]][i-1];
		mxa[x][i]=max(mxa[x][i-1],mxa[pr[x][i-1]][i-1]);
	}
	for(i=0;i<sz;i++)
	{
		l=al[x][i].fr;
		p=al[x][i].sc;
		if(!vtd[l])
		{
			pr[l][0]=x;
			mxa[l][0]=wg[p];
			dh[l]=dh[x]+1;
			pe[l]=p;
			dfs(l);
		}
	}
}

inline long long pth(long long x,long long y)
{
	long long i,ii,z=-inf;
	
	for(ii=0;ii<2;ii++)
	{
		for(i=d-1;i>=0;i--)
		{
			if(dh[pr[x][i]]>=dh[y])
			{
				z=max(z,mxa[x][i]);
				x=pr[x][i];
			}
		}
		swap(x,y);
	}
	for(i=d-1;i>=0;i--)
	{
		if(pr[x][i]!=pr[y][i])
		{
			z=max(z,max(mxa[x][i],mxa[y][i]));
			x=pr[x][i];
			y=pr[y][i];
		}
	}
	if(x!=y)
	{
		z=max(z,max(mxa[x][0],mxa[y][0]));
	}
	return z;
}

int main()
{
	long long i,k,l,p;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&k,&l,wg+i);
		ed[i]={k,l};
		as[i]=i;
		sq[i]=-1;
	}
	sort(as+1,as+m+1,cwg);
	for(i=1;i<=n;i++)
	{
		dsu[i]=i;
	}
	for(i=1;i<=m;i++)
	{
		p=as[i];
		k=ed[p].fr;
		l=ed[p].sc;
		if(fd(k)!=fd(l))
		{
			dsu[fd(l)]=fd(k);
			al[k].push_back({l,p});
			al[l].push_back({k,p});
		}
		else
		{
			spc[i]=1;
		}
	}
	dh[0]=-1;
	dfs(1);
	for(i=1;i<=n;i++)
	{
		dsu[i]=i;
	}
	for(i=1;i<=m;i++)
	{
		if(spc[i])
		{
			p=as[i];
			k=ed[p].fr;
			l=ed[p].sc;
			sq[p]=pth(k,l)-1;
			for(k=fd(k),l=fd(l);k!=l;k=fd(k))
			{
				if(dh[l]>dh[k])
				{
					swap(k,l);
				}
				sq[pe[k]]=wg[p]-1;
				dsu[k]=pr[k][0];
			}
		}
	}
	for(i=1;i<=m;i++)
	{
		printf("%lld%c",sq[i]," \n"[i==m]);
	}
}