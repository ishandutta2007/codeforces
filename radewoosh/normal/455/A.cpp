#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int a;
long long kub[100007];
long long wyn[100007];

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		scanf("%d", &a);
		kub[a]++;
	}
	wyn[1]=kub[1];
	for (int i=2; i<=100000; i++)
	{
		wyn[i]=max(wyn[i-1], wyn[i-2]+i*kub[i]);
	}
	printf("%lld", wyn[100000]);
	return 0;
}