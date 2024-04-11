#include <bits/stdc++.h>

using namespace std;

long long n,m,nn=0,dsu[500069],sq[500069],zs=0,dv=1e9+7;

long long fd(long long x)
{
	if(dsu[x]!=x)
	{
		dsu[x]=fd(dsu[x]);
	}
	return dsu[x];
}

int main()
{
	long long i,ky,k,l,z=1;
	
	scanf("%lld%lld",&n,&m);
	for(i=0;i<=m;i++)
	{
		dsu[i]=i;
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",&ky,&k);
		if(ky==1)
		{
			l=0;
		}
		else
		{
			scanf("%lld",&l);
		}
		if(fd(k)!=fd(l))
		{
			z=z*2%dv;
			zs++;
			sq[zs]=i;
			dsu[fd(l)]=fd(k);
		}
	}
	printf("%lld %lld\n",z,zs);
	for(i=1;i<=zs;i++)
	{
		printf("%lld%c",sq[i]," \n"[i==zs]);
	}
}