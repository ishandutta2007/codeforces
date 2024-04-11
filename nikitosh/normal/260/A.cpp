#include<cstdio>

int n, a, b, boo = 0;

int main()
{
	scanf("%d%d%d", &a, &b, &n);
	for (int i = 0; i < 10; i++)
		if ((10 * a + i) % b == 0)
		{
			a = 10 * a + i;
			boo = 1;
			break;
		}
	if (boo == 0)
	{
		printf("-1");
		return 0;
	}
	printf("%d", a);
	for (int i = 0; i < n - 1; i++)
		printf("0");
	return 0;
}