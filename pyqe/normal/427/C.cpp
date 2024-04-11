#include <bits/stdc++.h>

using namespace std;

long long n,m,a[100069],dsu[100069],dis[100069],cdis=0,mn[100069],fq[100069],dv=1e9+7;
vector<long long> al[100069];
bitset<100069> vtd,vtd2;

long long fd(long long x)
{
	if(dsu[x]!=x)
	{
		dsu[x]=fd(dsu[x]);
	}
	return dsu[x];
}

void scc(long long x)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	vtd2[x]=1;
	dis[x]=cdis;
	cdis++;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			scc(l);
		}
		if(vtd2[fd(l)]&&dis[fd(l)]<dis[fd(x)])
		{
			dsu[fd(x)]=fd(l);
		}
	}
	cdis--;
	vtd2[x]=0;
}

int main()
{
	long long i,k,l,sm=0,z=1;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		dsu[i]=i;
	}
	scanf("%lld",&m);
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back(l);
	}
	for(i=1;i<=n;i++)
	{
		if(!vtd[i])
		{
			scc(i);
		}
		mn[i]=1e18;
	}
	for(i=1;i<=n;i++)
	{
		if(a[i]<mn[fd(i)])
		{
			mn[fd(i)]=a[i];
			fq[fd(i)]=0;
		}
		if(a[i]==mn[fd(i)])
		{
			fq[fd(i)]++;
		}
	}
	for(i=1;i<=n;i++)
	{
		if(fd(i)==i)
		{
			sm+=mn[i];
			z=z*fq[i]%dv;
		}
	}
	printf("%lld %lld\n",sm,z);
}