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
		if(n>=1900)
		{
			z=1;
		}
		else if(n>=1600)
		{
			z=2;
		}
		else if(n>=1400)
		{
			z=3;
		}
		else
		{
			z=4;
		}
		printf("Division %lld\n",z);
	}
}