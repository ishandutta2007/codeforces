#include <bits/stdc++.h>

int a[10005];

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n, x;
		scanf("%d%d", &n, &x);
		for (int i = 1; i <= n; ++i) scanf("%d", a + i);
		int u = 0;
		for (int i = 1; i <= n; ++i)
		{
			u += a[i];
			if (u == x)
			{
				u -= a[i];
				std::swap(a[i], a[n]);
				u += a[i];
			}
		}
		if (u == x)
		{
			puts("NO");
		}
		else
		{
			puts("YES");
			for (int i = 1; i <= n; ++i) printf("%d ", a[i]);
			putchar('\n');
		}
	}
}