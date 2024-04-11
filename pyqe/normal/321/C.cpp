#include <bits/stdc++.h>

using namespace std;

long long n,rr=0,ctd,vi[100069],sbt[100069],dhh[100069],inf=1e18;
vector<long long> al[100069];

void bd(long long x)
{
	long long i,sz=al[x].size(),l;
	
	vi[x]=rr;
	sbt[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(vi[l]<rr)
		{
			bd(l);
			sbt[x]+=sbt[l];
		}
	}
}

void bd2(long long x,long long w)
{
	long long i,sz=al[x].size(),l,mx=w-sbt[x];
	
	vi[x]=rr;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(vi[l]<rr)
		{
			bd2(l,w);
			mx=max(mx,sbt[l]);
		}
	}
	if(mx*2<=w)
	{
		ctd=x;
	}
}

void cdc(long long x,long long w)
{
	long long i,k,l,sz;
	
	rr++;
	bd(x);
	rr++;
	bd2(x,sbt[x]);
	k=ctd;
	dhh[k]=w;
	vi[k]=inf;
	sz=al[k].size();
	for(i=0;i<sz;i++)
	{
		l=al[k][i];
		if(vi[l]!=inf)
		{
			cdc(l,w+1);
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
	cdc(1,0);
	for(i=1;i<=n;i++)
	{
		printf("%c%c",(char)dhh[i]+'A'," \n"[i==n]);
	}
}