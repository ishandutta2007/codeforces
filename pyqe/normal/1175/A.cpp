#include <bits/stdc++.h>

using namespace std;

long long n,d;

int main()
{
	long long t,rr,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		for(z=0;1;)
		{
			z+=n%d;
			n-=n%d;
			if(!n)
			{
				break;
			}
			z++;
			n/=d;
		}
		printf("%lld\n",z);
	}
}