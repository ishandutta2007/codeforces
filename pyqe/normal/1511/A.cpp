#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long t,rr,i,k,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		z=0;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&k);
			z+=k!=2;
		}
		printf("%lld\n",z);
	}
}