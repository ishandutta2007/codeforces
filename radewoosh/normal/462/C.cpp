#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n;
long long licz[1000007];
long long wyn;

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	scanf("%lld", &licz[i]);
	sort(licz+1, licz+1+n);
	for (int i=1; i<=n; i++)
	{
		wyn+=min(i+1, n)*licz[i];
	}
	printf("%lld", wyn);
	return 0;
}