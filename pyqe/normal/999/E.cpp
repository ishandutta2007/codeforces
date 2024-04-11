#include <bits/stdc++.h>

using namespace std;

long long n,m,d,dh[100069],dsu[100069],dg[100069];
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
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			dh[l]=dh[x]+1;
			scc(l);
		}
		if(vtd2[fd(l)]&&dh[fd(l)]<=dh[fd(x)])
		{
			dsu[fd(x)]=fd(l);
		}
	}
	vtd2[x]=0;
}

int main()
{
	long long i,j,k,l,sz,z=0;
	
	scanf("%lld%lld%lld",&n,&m,&d);
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back(l);
	}
	for(i=1;i<=n;i++)
	{
		dsu[i]=i;
	}
	for(i=1;i<=n;i++)
	{
		if(!vtd[i])
		{
			scc(i);
		}
	}
	for(i=1;i<=n;i++)
	{
		sz=al[i].size();
		for(j=0;j<sz;j++)
		{
			l=al[i][j];
			dg[fd(l)]+=fd(l)!=fd(i);
		}
	}
	for(i=1;i<=n;i++)
	{
		z+=fd(i)==i&&!dg[i]&&i!=fd(d);
	}
	printf("%lld\n",z);
}