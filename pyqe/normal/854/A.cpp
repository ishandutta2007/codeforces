#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long i;
	
	scanf("%lld",&n);
	for(i=(n-1)/2;__gcd(i,n-i)>1;i--);
	printf("%lld %lld\n",i,n-i);
}