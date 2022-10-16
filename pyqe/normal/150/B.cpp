#include <bits/stdc++.h>

using namespace std;

long long n,m,d,dsu[2069],dv=1e9+7;

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
	long long i,j,z=1;
	
	scanf("%lld%lld%lld",&n,&m,&d);
	for(i=1;i<=n;i++)
	{
		dsu[i]=i;
	}
	for(i=0;i<=n-d;i++)
	{
		for(j=1;j<d+1-j;j++)
		{
			dsu[fd(i+d+1-j)]=fd(i+j);
		}
	}
	for(i=1;i<=n;i++)
	{
		if(fd(i)==i)
		{
			z=z*m%dv;
		}
	}
	printf("%lld\n",z);
}