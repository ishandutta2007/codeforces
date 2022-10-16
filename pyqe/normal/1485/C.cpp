#include <bits/stdc++.h>

using namespace std;

long long n,m;

int main()
{
	long long t,rr,i,k,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		z=0;
		for(i=1;1;i++)
		{
			k=min(n/i-1,m);
			z+=max(k-i,0ll);
			if(k<=i)
			{
				break;
			}
		}
		printf("%lld\n",z);
	}
}