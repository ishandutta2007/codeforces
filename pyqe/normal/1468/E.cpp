#include <bits/stdc++.h>

using namespace std;

long long a[4];

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
		sort(a,a+4);
		printf("%lld\n",a[0]*a[2]);
	}
}