#include<cstdio>

int n;

int main()
{
	scanf("%d", &n);
	if (n % 2 == 1)
	{
		for (int i = 0; i < n; i++)
			printf("%d ", i);
		printf("\n");
		for (int i = 0; i < n; i++)
			printf("%d ", i);
		printf("\n");
		for (int i = 0; i < n; i++)
			printf("%d ", (2 * i) % n);
		printf("\n");
	}
	else
	{
		printf("-1\n");
	}
	return 0;
}