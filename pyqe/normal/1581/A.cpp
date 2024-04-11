#include <bits/stdc++.h>

using namespace std;

const long long dv=1e9+7;
long long n;

int main()
{
	long long t,rr,i,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		z=1;
		for(i=3;i<=n*2;i++)
		{
			z=z*i%dv;
		}
		printf("%lld\n",z);
	}
}