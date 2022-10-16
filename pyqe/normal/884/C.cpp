#include <bits/stdc++.h>

using namespace std;

long long n,nn=0,pr[100069],as[100069];
bitset<100069> vtd;

inline long long sqr(long long x)
{
	return x*x;
}

int main()
{
	long long i,p,c,z;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",pr+i);
	}
	for(i=1;i<=n;i++)
	{
		if(!vtd[i])
		{
			c=0;
			for(p=i;!vtd[p];p=pr[p])
			{
				vtd[p]=1;
				c++;
			}
			nn++;
			as[nn]=c;
		}
	}
	sort(as+1,as+nn+1,greater<long long>());
	z=sqr(as[1]+as[2]);
	for(i=3;i<=nn;i++)
	{
		z+=sqr(as[i]);
	}
	printf("%lld\n",z);
}