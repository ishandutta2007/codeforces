#include <bits/stdc++.h>

using namespace std;

long long n,m,d,dsu[400069];

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
	long long i,k,l,z;
	
	scanf("%lld%lld%lld",&n,&m,&d);
	for(i=1;i<=n+m;i++)
	{
		dsu[i]=i;
	}
	z=n+m-1;
	for(i=0;i<d;i++)
	{
		scanf("%lld%lld",&k,&l);
		z-=fd(k)!=fd(n+l);
		dsu[fd(n+l)]=fd(k);
	}
	printf("%lld\n",z);
}