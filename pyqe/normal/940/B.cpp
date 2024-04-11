#include <bits/stdc++.h>

using namespace std;

long long n,d,z1,z2,z=0;

int main()
{
	long long i;
	
	scanf("%lld%lld%lld%lld",&n,&d,&z1,&z2);
	while(d>1&&n>=d)
	{
		z+=n%d*z1;
		n-=n%d;
		if(z2<=(n-n/d)*z1)
		{
			z+=z2;
		}
		else
		{
			z+=(n-n/d)*z1;
		}
		n/=d;
	}
	z+=(n-1)*z1;
	printf("%lld\n",z);
}