#include<cstdio>

int n;

int main()
{
	scanf("%d", &n);
	for (int i = n; i < 2 * n; i++)
		printf("%d ", i);
	return 0;
}