#include <bits/stdc++.h>

using namespace std;

long long n,d;

int main()
{
	long long i,k,z;
	
	scanf("%lld%lld",&n,&d);
	z=d;
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		if(d%k==0)
		{
			z=min(z,d/k);
		}
	}
	printf("%lld\n",z);
}