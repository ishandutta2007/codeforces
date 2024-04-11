#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long t,rr,k,l,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&k,&l);
		if(k%2!=l%2)
		{
			z=-1;
		}
		else if(!k&&!l)
		{
			z=0;
		}
		else if(k==l)
		{
			z=1;
		}
		else
		{
			z=2;
		}
		printf("%lld\n",z);
	}
}