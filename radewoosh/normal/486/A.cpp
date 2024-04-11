#include <iostream>
#include <cstdio>
using namespace std;

long long n;

int main()
{
	scanf("%lld", &n);
	if (!(n%2))
	{
		printf("%lld", n/2);
	}
	else
	{
		printf("%lld", n/2-n);
	}
	return 0;
}