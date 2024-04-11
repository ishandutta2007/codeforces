#include <iostream>
#include <cstdio>
using namespace std;

int n, m;
int k;
int a, b;

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	if (!(n&1))
	{
		printf("Marsel");
		return 0;
	}
	for (int i=2; i*i<=m && m/i>=k; i++)
	{
		if (!(m%i))
		{
			printf("Timur");
			return 0;
		}
	}
	if (k==1 && m!=1)
	{
		printf("Timur");
		return 0;
	}
	printf("Marsel");
	return 0;
}