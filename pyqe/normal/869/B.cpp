#include <bits/stdc++.h>

using namespace std;

long long lb,rb;

int main()
{
	long long i,z=1;
	
	scanf("%lld%lld",&lb,&rb);
	if(rb/2*2>lb&&rb/5*5>lb)
	{
		z=0;
	}
	else
	{
		for(i=lb+1;i<=rb;i++)
		{
			z=z*(i%10)%10;
		}
	}
	printf("%lld\n",z);
}