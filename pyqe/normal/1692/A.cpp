#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long t,rr,i,k,z=0;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		z=0;
		for(i=0;i<3;i++)
		{
			scanf("%lld",&k);
			z+=k>n;
		}
		printf("%lld\n",z);
	}
}