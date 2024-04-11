#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

long long n, a, b;
long long wyna, wynb;
bool czy;

int main()
{
	scanf("%lld%lld%lld", &n, &a, &b);
	if (a*b>=6*n)
	{
		printf("%lld\n%lld %lld", a*b, a, b);
		return 0;
	}
	if (a<b)
	{
		czy=true;
		a+=b;
		b=a-b;
		a-=b;
	}
	wyna=max(n, a);
	wynb=6;
	wynb=max(wynb, b);
	for (long long i=1; i*i<=n*6; i++)
	{
		if (max(b, i)*max(a, (n*6+i-1)/i)<=wyna*wynb)
		{
			wynb=max(b, i);
			wyna=max(a, (n*6+i-1)/i);
		}
	}
	if (!czy)
	{
		printf("%lld\n%lld %lld", wyna*wynb, wyna, wynb);
	}
	else
	{
		printf("%lld\n%lld %lld", wyna*wynb, wynb, wyna);
	}
	return 0;
}