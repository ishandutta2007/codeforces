#include <bits/stdc++.h>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		long double n, d;
		std::cin >> n >> d;
		long double ans = n + 100000;
		long double sqrtd = sqrtl(d);
		for (int j = std::max(0, (int)sqrtd - 50); j <= sqrtd + 50; ++j)
			ans = std::min(ans, j + std::ceil(d / (j + 1)));
		puts(ans <= n ? "YES" : "NO");
	}
}