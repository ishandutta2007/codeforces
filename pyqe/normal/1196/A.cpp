#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long z,k,i,rr,t;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		z=0;
		for(i=0;i<3;i++)
		{
			scanf("%lld",&k);
			z+=k;
		}
		printf("%lld\n",z/2);
	}
}