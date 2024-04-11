#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long t,rr,k,l,w,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",&k,&l,&w);
		if(w<k)
		{
			z=w;
		}
		else
		{
			z=(l/w+1)*w;
		}
		printf("%lld\n",z);
	}
}