#include<cstdio>

long long n, x, k, b, min1 = 1e18, a[200000];

int main()
{
	scanf("%I64d%I64d", &n, &x);
	x--;
	for (int i = 0; i < n; i++)
	{
		scanf("%I64d", &a[i]);
		a[n + i] = a[i];
	}
	for (int i = x + 1; i <= x + n; i++)
	{
		if (a[i] <= min1)
		{
			min1 = a[i];
			k = i;
		}
	}
	if (k >= n)
		k -= n;
 	b = a[k];
	if (x > k)
	{
		for (int i = 0; i < k; i++)
			printf("%I64d ", a[i] - a[k]);
		printf("%I64d ", b * n + x - k);
		for (int i = k + 1; i <= x; i++)
			printf("%I64d ", a[i] - a[k] - 1);
		for (int i = x + 1; i < n; i++)
			printf("%I64d ", a[i] - a[k]);
	}
	if (x < k)
	{                                     
		for (int i = 0; i <= x; i++)
			printf("%I64d ", a[i] - a[k] - 1);
		for (int i = x + 1; i < k; i++)
			printf("%I64d ", a[i] - a[k]);
		printf("%I64d ", b * n + x + n - k);
		for (int i = k + 1; i < n; i++)
			printf("%I64d ", a[i] - a[k] - 1);
	}
	if (x == k)
	{
		for (int i = 0; i < k; i++)
			printf("%I64d ", a[i] - b);
			printf("%I64d ", b * n);
		for (int i = k + 1; i < n; i++)
			printf("%I64d ", a[i] - b);	
	}
	return 0;
}