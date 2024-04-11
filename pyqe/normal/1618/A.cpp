#include <bits/stdc++.h>

using namespace std;

long long a[8];

int main()
{
	long long t,rr,i;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		for(i=0;i<7;i++)
		{
			scanf("%lld",a+i);
		}
		printf("%lld %lld %lld\n",a[0],a[1],a[2+(a[2]==a[0]+a[1])]);
	}
}