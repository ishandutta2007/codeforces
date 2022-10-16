#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long t,rr,k,l,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&k,&l);
		if(k>l)
		{
			z=k+l;
		}
		else
		{
			z=(l/k*k+l)/2;
		}
		printf("%lld\n",z);
	}
}