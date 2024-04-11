#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,nn=0,a[100069],dh[100069],pst[100069],sbt[100069],lg2[200069],fw[200069],fi;
vector<long long> al[100069];
bitset<100069> vtd;
pair<long long,long long> sp[18][200069];

void dfs(long long x)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	nn++;
	pst[x]=nn;
	sbt[x]=1;
	sp[0][nn]={dh[x],x};
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			dh[l]=dh[x]+1;
			dfs(l);
			sbt[x]+=sbt[l];
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

long long spqr(long long lh,long long rh)
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
	return spqr(pst[x],pst[y]);
}

void ud(long long x,long long w)
{
	for(fi=x;fi<=nn;fi+=fi&-fi)
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
	long long t,rr,i,ky,k,l,la;
	
	scanf("%lld%lld",&n,&t);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=0;i<n-1;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back(l);
		al[l].push_back(k);
	}
	dfs(1);
	spbd();
	for(i=1;i<=n;i++)
	{
		ud(pst[i],abs(a[i]));
		ud(pst[i]+sbt[i]*2-1,-abs(a[i]));
	}
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",&ky,&k,&l);
		if(ky==1)
		{
			ud(pst[k],abs(l)-abs(a[k]));
			ud(pst[k]+sbt[k]*2-1,abs(a[k])-abs(l));
			a[k]=l;
		}
		else
		{
			la=lca(k,l);
			printf("%lld\n",(qr(pst[k])+qr(pst[l])-qr(pst[la])*2+abs(a[la]))*2-abs(a[k])-abs(a[l]));
		}
	}
}