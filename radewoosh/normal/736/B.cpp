#include <bits/stdc++.h>
using namespace std;

long long n;

int ret;

int czek(long long v)
{
	for (int i=2; i*i<=v; i++)
		if (!(v%i))
			return 0;
	return 1;
}

int main()
{
	scanf("%lld", &n);
	if (czek(n))
	{
		printf("1\n");
		return 0;
	}
	if (!(n&1))
	{
		printf("2\n");
		return 0;
	}
	if (czek(n-2))
	{
		printf("2\n");
		return 0;
	}
	printf("3\n");
	return 0;
}