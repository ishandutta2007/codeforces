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
		z=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			if(i-1)
			{
				z=max(z,k*l);
			}
			l=k;
		}
		printf("%lld\n",z);
	}
}