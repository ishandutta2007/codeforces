#include<cstdio>

int n, a[200], ans, k;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	if (n == 1 || n % 2 == 0)
	{
		printf("%d\n", -1);
		return 0;
	}
	k = n;
	while (k != 0)
	{
		if (a[k] <= 0)
			k--;
		else
		{
			if (k % 2 == 1)
			{
				a[k - 1] -= a[k];
			}
			ans += a[k];
			a[k / 2] -= a[k];
			k--;
		}
	}
	printf("%d\n", ans);
}