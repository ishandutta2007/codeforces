#include <bits/stdc++.h>

using namespace std;

long long a[3];

int main()
{
	long long t,rr,i,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		z=0;
		for(i=0;i<3;i++)
		{
			scanf("%lld",a+i);
			z+=a[i]*(i+1);
		}
		printf("%lld\n",z%2);
	}
}