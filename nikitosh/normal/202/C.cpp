#include<cstdio>

int k, x, i;

int main()
{
	scanf("%d", &x);
	if (x == 0)
	{
		printf("%d", 1);
		return 0;
	}
	if (x == 1)
	{
		printf("%d", 1);
		return 0;
	}
	if (x == 2)
	{
		printf("%d", 3);
		return 0;
	}
	if (x == 3)
	{
		printf("%d", 5);
		return 0;
	}

	k = 2 * x - 1;
	for (i = 1; i < 50; i++)
	{
		if (i * i >= k && i % 2 == 1)
		{
			printf("%d", i);
			return 0;
		}
 	}
	return 0;
}