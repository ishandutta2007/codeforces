#include <bits/stdc++.h>

using namespace std;

const long long ma=100;
long long n,d,d2;

int main()
{
	scanf("%lld%lld%lld",&n,&d,&d2);
	printf("%lld\n",(d+d2+n*ma-1)%n+1);
}