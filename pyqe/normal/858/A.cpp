#include <bits/stdc++.h>

using namespace std;

long long n,d;

int main()
{
	long long i,w=1;
	
	scanf("%lld%lld",&n,&d);
	for(i=0;i<d;i++)
	{
		w*=10;
	}
	printf("%lld\n",n/__gcd(n,w)*w);
}