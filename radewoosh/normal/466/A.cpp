#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

long long n, m, a, b;

int main()
{
	scanf("%lld%lld%lld%lld", &n, &m, &a, &b);
	printf("%lld", min((n/m)*b+min((n%m)*a, b), n*a));
	return 0;
}