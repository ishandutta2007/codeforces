#include <bits/stdc++.h>

using namespace std;

long long n,dsu[150069],mn[150069],mx[150069],pr[150069];

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
	long long i,k,l,p;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		dsu[i]=i;
		mn[i]=i;
		mx[i]=i;
	}
	for(i=0;i<n-1;i++)
	{
		scanf("%lld%lld",&k,&l);
		pr[mx[fd(k)]]=mn[fd(l)];
		mx[fd(k)]=mx[fd(l)];
		dsu[fd(l)]=fd(k);
	}
	for(i=1,p=mn[fd(1)];i<=n;p=pr[p],i++)
	{
		printf("%lld%c",p," \n"[i==n]);
	}
}