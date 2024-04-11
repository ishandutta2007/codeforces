#include <bits/stdc++.h>

using namespace std;

long long n,d;

int main()
{
	long long t,rr,i,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		if(d>n)
		{
			z=d-n;
		}
		else
		{
			z=(n-d)%2;
		}
		printf("%lld\n",z);
	}
}