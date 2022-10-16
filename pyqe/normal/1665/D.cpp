#include <bits/stdc++.h>

using namespace std;

const long long d=30;

int main()
{
	long long t,rr,i,k,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		z=0;
		for(i=0;i<d;i++)
		{
			printf("? %lld %lld\n",(1ll<<i)-z,(3ll<<i)-z);
			fflush(stdout);
			scanf("%lld",&k);
			z|=(long long)(k==1ll<<i+1)<<i;
		}
		printf("! %lld\n",z);
		fflush(stdout);
	}
}