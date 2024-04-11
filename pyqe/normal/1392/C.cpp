#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long t,rr,i,k,l,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		l=0;
		z=0;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&k);
			z+=max(l-k,0ll);
			l=k;
		}
		printf("%lld\n",z);
	}
}