#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long t,rr,k,l,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&k,&l);
		if(!k)
		{
			z=1;
		}
		else
		{
			z=k+l*2+1;
		}
		printf("%lld\n",z);
	}
}