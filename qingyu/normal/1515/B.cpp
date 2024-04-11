#include <bits/stdc++.h>

int a[10005];

int main()
{
	auto ip = [](int x)
	{
		int t = sqrt(x);
		for (int i = t - 10; i <= t + 10; ++i)
			if (i * i == x)
				return true;
		return false;
	};
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		if (n % 2)
		{
			puts("NO");
		}
		else
		{
			while (n % 2 == 0) n /= 2;
			puts(ip(n) ? "YES" : "NO");
		}
	}
}