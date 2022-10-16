#include <bits/stdc++.h>

using namespace std;

long long n,d,inf=1e18;

int main()
{
	long long i,k,l,z=-inf;
	
	scanf("%lld%lld",&n,&d);
	for(i=0;i<n;i++)
	{
		scanf("%lld%lld",&k,&l);
		z=max(z,k-max(l-d,0ll));
	}
	printf("%lld\n",z);
}