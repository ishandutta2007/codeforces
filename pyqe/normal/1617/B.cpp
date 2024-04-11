#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long t,rr,z,z2;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		if(n%2==0)
		{
			z=n/2-1;
			z2=n/2;
		}
		else if(n/2%2==0)
		{
			z=n/2-1;
			z2=n/2+1;
		}
		else
		{
			z=n/2-2;
			z2=n/2+2;
		}
		printf("%lld %lld %lld\n",z,z2,__gcd(z,z2));
	}
}