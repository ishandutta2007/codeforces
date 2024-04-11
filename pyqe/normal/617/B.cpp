#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long i,k,l,z=1;
	
	scanf("%lld",&n);
	l=n+1;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		if(k)
		{
			z*=max(i-l,1ll);
			l=i;
		}
	}
	printf("%lld\n",z*(l<=n));
}