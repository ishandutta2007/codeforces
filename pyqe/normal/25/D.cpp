#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,dsu[100069],zs=0;
pair<long long,long long> sq[100069];

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
	long long i,k,l;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		dsu[i]=i;
	}
	for(i=0;i<n-1;i++)
	{
		scanf("%lld%lld",&k,&l);
		if(fd(k)!=fd(l))
		{
			dsu[fd(l)]=fd(k);
		}
		else
		{
			zs++;
			sq[zs]={k,l};
		}
	}
	printf("%lld\n",zs);
	zs=0;
	l=0;
	for(i=1;i<=n;i++)
	{
		if(fd(i)==i)
		{
			if(l)
			{
				zs++;
				printf("%lld %lld %lld %lld\n",sq[zs].fr,sq[zs].sc,i,l);
			}
			l=i;
		}
	}
}