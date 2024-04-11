#include <bits/stdc++.h>

const int N = 1e5 + 50;

int a[N];
int main()
{
	int n;
	scanf("%d", &n);
	if (n <= 3) return printf("0"), 0;
	int K = 0, x = 0;
	for (int i = 2; i <= n; ++i)
	{
		int t = n - i - std::ceil(1.0 * n / i) + 1;
		if (x < t)
		{
			x = t;
			K = i;
		}
	}
	for (int i = 0; i < n; ++i) if (i % K == 0) a[i] = -1;
	int y = 0;
	while (y < x)
	{
		printf("%d ", K);
		for (int i = 0, j = 0; i < n && j < K; ++i)
			if (a[i] == 0)
			{
				printf("%d ", i + 1);
				a[i] = 1, ++j, ++y;
			}
		putchar('\n');
		std::fflush(stdout);
		int start_position = 0;
		scanf("%d", &start_position); --start_position;
		for (int i = start_position; i < start_position + K; ++i)
			if (a[i % n] == 1)
				a[i % n] = 0, --y;
	}
	printf("0 ");
	std::fflush(stdout);
}