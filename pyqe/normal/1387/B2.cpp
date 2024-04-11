#include <bits/stdc++.h>

using namespace std;

long long n,ctd,sbt[100069],eu[100069],z=0,sq[100069];
vector<long long> al[100069];
bitset<100069> vtd;

void bd(long long x)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	sbt[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			bd(l);
			sbt[x]+=sbt[l];
		}
	}
}

void fct(long long x)
{
	long long i,sz=al[x].size(),l,mx=n-sbt[x];
	
	vtd[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			fct(l);
			mx=max(mx,sbt[l]);
		}
	}
	if(mx*2<=n)
	{
		ctd=x;
	}
}

void trv(long long x)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	sbt[x]=1;
	n++;
	eu[n]=x;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			trv(l);
			sbt[x]+=sbt[l];
		}
	}
	z+=sbt[x]*2*(x!=ctd);
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
	bd(1);
	vtd.reset();
	fct(1);
	vtd.reset();
	n=0;
	trv(ctd);
	for(i=1;i<=n;i++)
	{
		sq[eu[i]]=eu[(i+n/2-1)%n+1];
	}
	printf("%lld\n",z);
	for(i=1;i<=n;i++)
	{
		printf("%lld%c",sq[i]," \n"[i==n]);
	}
}