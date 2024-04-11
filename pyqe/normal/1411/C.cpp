#include <bits/stdc++.h>

using namespace std;

long long n,m,dsu[100069];

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
	long long t,rr,i,k,l,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		for(i=1;i<=n;i++)
		{
			dsu[i]=i;
		}
		z=0;
		for(i=0;i<m;i++)
		{
			scanf("%lld%lld",&k,&l);
			z+=(k!=l)+(k!=l&&fd(k)==fd(l));
			dsu[fd(l)]=fd(k);
		}
		printf("%lld\n",z);
	}
}