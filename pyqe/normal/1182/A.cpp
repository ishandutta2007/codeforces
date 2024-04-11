#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	scanf("%lld",&n);
	printf("%lld\n",(n+1)%2<<n/2);
}