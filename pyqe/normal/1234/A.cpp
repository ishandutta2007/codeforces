#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long t,rr,i,k,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		z=0;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&k);
			z+=k;
		}
		printf("%lld\n",(z-1)/n+1);
	}
}