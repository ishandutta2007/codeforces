#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	scanf("%lld",&n);
	printf("%lld\n",(n+1)/(n%2+1)*!!n);
}