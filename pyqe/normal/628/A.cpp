#include <bits/stdc++.h>

using namespace std;

long long n,m,d;

int main()
{
	long long z=0,z2;
	
	scanf("%lld%lld%lld",&n,&m,&d);
	z2=n*d;
	for(;n>1;)
	{
		z+=n/2*(m*2+1);
		n-=n/2;
	}
	printf("%lld %lld\n",z,z2);
}