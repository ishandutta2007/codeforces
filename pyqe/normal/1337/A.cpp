#include <bits/stdc++.h>

using namespace std;

long long n,a[4];

int main()
{
	long long t,rr,i;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		for(i=0;i<4;i++)
		{
			scanf("%lld",a+i);
		}
		printf("%lld %lld %lld\n",a[1],a[2],a[2]);
	}
}