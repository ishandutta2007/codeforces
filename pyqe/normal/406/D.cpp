#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,nn=0,vx[100069],vy[100069],sk[100069],dh[100069],pst[100069],lg2[200069];
vector<long long> al[100069];
pair<long long,long long> sp[18][200069];

bool cmp(long long x,long long y,long long x2,long long y2)
{
	return x*y2>x2*y;
}

bool chk(long long x,long long y,long long y2)
{
	return cmp(vy[y2]-vy[x],vx[y2]-vx[x],vy[y]-vy[x],vx[y]-vx[x]);
}

void dfs(long long x)
{
	long long i,sz=al[x].size(),l;
	
	nn++;
	pst[x]=nn;
	sp[0][nn]={dh[x],x};
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		dh[l]=dh[x]+1;
		dfs(l);
		nn++;
		sp[0][nn]={dh[x],x};
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

int main()
{
	long long t,rr,i,k,l;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",vx+i,vy+i);
	}
	for(i=n;i;i--)
	{
		for(;nn>=2&&chk(i,sk[nn],sk[nn-1]);nn--);
		if(i<n)
		{
			al[sk[nn]].push_back(i);
		}
		nn++;
		sk[nn]=i;
	}
	nn=0;
	dfs(n);
	spbd();
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&k,&l);
		printf("%lld%c",lca(k,l)," \n"[rr==t-1]);
	}
}