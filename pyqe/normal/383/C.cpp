#include <bits/stdc++.h>

using namespace std;

long long n,m,nn=0,a[200069],pst[200069],sbt[200069],dh[200069],fw[200069],fi;
vector<long long> al[200069];
bitset<200069> vtd;

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

void dfs(long long x)
{
	long long i,u=dh[x]%2*2-1,sz=al[x].size(),l;
	
	vtd[x]=1;
	nn++;
	pst[x]=nn;
	sbt[x]=1;
	ud(nn,a[x]*u);
	ud(nn+1,-a[x]*u);
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			dh[l]=dh[x]+1;
			dfs(l);
			sbt[x]+=sbt[l];
		}
	}
}

int main()
{
	long long t,rr,i,u,ky,k,l;
	
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
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&ky,&k);
		u=dh[k]%2*2-1;
		if(ky==1)
		{
			scanf("%lld",&l);
			ud(pst[k],l*u);
			ud(pst[k]+sbt[k],-l*u);
		}
		else
		{
			printf("%lld\n",qr(pst[k])*u);
		}
	}
}