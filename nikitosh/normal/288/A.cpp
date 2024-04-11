#include<cstdio>

int n, k, l;

int main()
{
	scanf("%d%d", &n, &k);
	if (k == 1 && n == 1)
	{
		printf("a");
		return 0;
	}
	if (k == 1)
	{
		printf("-1\n");
		return 0;
	}
	if (n < k)
	{
		printf("-1\n");
		return 0;
	}
	if ((n - k) % 2 == 0)
	{
		for (int i = 0; i < (n - k + 2) / 2; i++)
			printf("ab");
		for (int i = 0; i < k - 2; i++)
			printf("%c", i + 'a' + 2);
	}
	else
	{
		printf("a");
		n--;
		for (int i = 0; i < (n - k + 2) / 2; i++)
			printf("ba");
		for (int i = 0; i < k - 2; i++)
			printf("%c", i + 'a' + 2);
	}                
	return 0;
}