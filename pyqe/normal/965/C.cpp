#include <bits/stdc++.h>

using namespace std;

long long n,m,d,dd,inf=1e18;

int main()
{
	long long i,k,z=-inf;
	
	scanf("%lld%lld%lld%lld",&n,&m,&d,&dd);
	for(i=1;i<=dd&&m*(i-1)+1<=n;i++)
	{
		k=n/(m*(i-1)+1);
		if(k<=d)
		{
			z=max(z,k*i);
		}
	}
	z=max(z,d*((n/d+m-1)/m));
	printf("%lld\n",z);
}