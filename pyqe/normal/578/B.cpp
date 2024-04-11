#include <bits/stdc++.h>

using namespace std;

long long n,m,d,dd=1,a[200069],fq[63];

int main()
{
	long long i,j,sm,z=-1e18;
	
	scanf("%lld%lld%lld",&n,&m,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		for(j=0;j<63;j++)
		{
			fq[j]+=a[i]>>j&1;
		}
	}
	for(i=0;i<m;i++)
	{
		dd*=d;
	}
	for(i=1;i<=n;i++)
	{
		sm=0;
		for(j=0;j<63;j++)
		{
			sm+=(long long)!!(fq[j]-(a[i]>>j&1)+(a[i]*dd>>j&1))<<j;
		}
		z=max(z,sm);
	}
	printf("%lld\n",z);
}