#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long t,rr,k,l,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&k,&l);
		if(k==l)
		{
			z=0;
		}
		else
		{
			z=max(((l-1)/2*2+1)%max((l-1)/2+1,k),l%k);
		}
		printf("%lld\n",z);
	}
}