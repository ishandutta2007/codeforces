#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long t,rr,i,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		z=0;
		for(;n%6==0;n/=6,z++);
		for(;n%3==0;n/=3,z+=2);
		if(n!=1)
		{
			z=-1;
		}
		printf("%lld\n",z);
	}
}