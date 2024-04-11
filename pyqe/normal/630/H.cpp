#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long i,k,w=120,gd,z=1;
	
	scanf("%lld",&n);
	for(i=0;i<5;i++)
	{
		k=(n-i)*(n-i);
		gd=__gcd(k,w);
		k/=gd;
		w/=gd;
		z*=k;
	}
	printf("%lld\n",z);
}