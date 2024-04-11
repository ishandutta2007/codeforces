#include <bits/stdc++.h>

using namespace std;

const long long dv=998244353;
long long n,dsu[100069],cc[100069];

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
	long long i,k,l,w,z=1;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		dsu[i]=i;
		cc[i]=1;
	}
	for(i=1;i<=n-1;i++)
	{
		scanf("%lld%lld",&k,&l);
		z=z*(i*2-1)%dv;
		w=cc[fd(k)]*cc[fd(l)]%dv;
		z=z*w%dv*w%dv;
		cc[fd(k)]+=cc[fd(l)];
		dsu[fd(l)]=fd(k);
	}
	printf("%lld\n",z);
}