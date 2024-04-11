#include <bits/stdc++.h>

using namespace std;

const long long dv=1e9+7;
long long n,d;

int main()
{
	long long t,rr,i,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		z=1;
		for(i=0;i<d;i++)
		{
			z=z*n%dv;
		}
		printf("%lld\n",z);
	}
}