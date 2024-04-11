#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long t,rr,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		z=0;
		for(;n>=10;)
		{
			z+=n-n%10;
			n=n/10+n%10;
		}
		z+=n;
		printf("%lld\n",z);
	}
}