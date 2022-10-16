#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long t,rr,k,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		k=n%7;
		z=n%10+(7-k)%7;
		if(z>9)
		{
			z-=7;
		}
		printf("%lld\n",n/10*10+z);
	}
}