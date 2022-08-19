#include <iostream>
#include <cstdio>
using namespace std;

int n;

long long dziel(long long a, long long b)
{
	long long wyk=n-2;
	while(wyk)
	{
		if (wyk&1)
		{
			a*=b;
			a%=n;
		}
		b*=b;
		b%=n;
		wyk>>=1;
	}
	return a;
}

int main()
{
	scanf("%d", &n);
	if (n==1)
	{
		printf("YES\n1\n");
		return 0;
	}
	if (n==4)
	{
		printf("YES\n1\n3\n2\n4\n");
		return 0;
	}
	for (int i=2; i*i<=n; i++)
	{
		if (!(n%i))
		{
			printf("NO");
			return 0;
		}
	}
	printf("YES\n1\n");
	for (int i=2; i<n; i++)
	{
		printf("%lld\n", dziel(i, i-1));
	}
	printf("%d\n", n);
	return 0;
}