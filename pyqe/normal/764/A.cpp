#include <bits/stdc++.h>

using namespace std;

long long n,m,d;

int main()
{
	scanf("%lld%lld%lld",&n,&m,&d);
	printf("%lld\n",d/(n/__gcd(n,m)*m));
}