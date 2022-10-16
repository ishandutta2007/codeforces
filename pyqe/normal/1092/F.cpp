#include <bits/stdc++.h>

using namespace std;

long long n,a[200069],dh[200069],sbt[200069],z,inf=1e18;
vector<long long> al[200069];
bitset<200069> vtd;

void bd(long long x)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	sbt[x]=a[x];
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			dh[l]=dh[x]+1;
			bd(l);
			sbt[x]+=sbt[l];
		}
	}
}

void trv(long long x,long long w,long long sm)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	z=max(z,sm);
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			trv(l,w+sbt[x]-sbt[l],sm-sbt[l]+w+sbt[x]-sbt[l]);
		}
	}
}

int main()
{
	long long i,k,l,sm=0;
	
	scanf("%lld",&n);
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
	bd(1);
	for(i=1;i<=n;i++)
	{
		sm+=a[i]*dh[i];
	}
	vtd.reset();
	z=-inf;
	trv(1,0,sm);
	printf("%lld\n",z);
}