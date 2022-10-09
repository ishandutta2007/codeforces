//sto djq orz
#include <bits/stdc++.h>

int n, m, a[100005];

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
	{
		a[i] = i; m -= (i - 1) / 2;
		if (m <= 0)
		{
			a[i] -= m * 2;
			m = 0;
			int T = std::max(a[i - 1], a[i]);
			a[n + 1] = 1e9;
			for (int j = n; j > i; --j) a[j] = a[j + 1] - T * 2;
			for (int j = 1; j <= n; ++j) printf("%d ", a[j]);
			return 0;
		}
	}
	printf("-1");
	return 0;
}