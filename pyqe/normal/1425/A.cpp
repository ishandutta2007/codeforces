#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long t,rr,k,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		z=0;
		for(k=n/2*2;k>4;)
		{
			if(k%4==0)
			{
				z++;
				k-=2;
			}
			z+=k/2;
			k=k/2-1;
		}
		z+=max(k-1,0ll);
		if(n%2)
		{
			z=n-z;
		}
		printf("%lld\n",z);
	}
}