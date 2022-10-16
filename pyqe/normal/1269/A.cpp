#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long k;
	
	scanf("%lld",&n);
	k=4+n%2*5;
	printf("%lld %lld\n",k+n,k);
}