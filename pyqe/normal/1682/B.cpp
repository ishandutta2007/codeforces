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
		z=(1ll<<30)-1;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&k);
			if(k!=i)
			{
				z&=k;
			}
		}
		printf("%lld\n",z);
	}
}