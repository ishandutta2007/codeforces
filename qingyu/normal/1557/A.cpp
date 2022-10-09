#include <bits/stdc++.h>

const int N = 1e6 + 50;
int a[N], b[N], c[N];

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) scanf("%d", a + i);
		std::sort(a + 1, a + n + 1);
		double sum = 0;
		for (int i = 1; i < n; ++i) sum += a[i];
		double ans = a[n] + sum / (n - 1);
		printf("%.12f\n", ans);
	}
	return 0;
}