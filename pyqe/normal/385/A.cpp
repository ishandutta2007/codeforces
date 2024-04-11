#include <bits/stdc++.h>

using namespace std;

long long n,d;

int main()
{
	long long i,k,l,z=0;
	
	scanf("%lld%lld",&n,&d);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		if(i)
		{
			z=max(z,l-k-d);
		}
		l=k;
	}
	printf("%lld\n",z);
}