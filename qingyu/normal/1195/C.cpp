#include <bits/stdc++.h>

typedef long long ll;
constexpr ll N = 3e5 + 50;

ll n, h[N][3], f[N][3];

inline int read()
{
	int x; scanf("%d", &x); return x;
}

int main()
{
	n = read();
	for (int i = 1; i <= 2; ++i)
		for (int j = 1; j <= n; ++j)
			h[j][i] = read();
	for (int i = 1; i <= n; ++i)
	{
		// f[i][0]: none
		// f[i][1]: select upside
		// f[i][2]: select downside
		f[i][0] = std::max(f[i - 1][0], std::max(f[i - 1][1], f[i - 1][2]));
		f[i][1] = std::max(f[i - 1][0], f[i - 1][2]) + h[i][1];
		f[i][2] = std::max(f[i - 1][0], f[i - 1][1]) + h[i][2];
	}
	printf("%lld\n", std::max(std::max(f[n][0], f[n][1]), f[n][2]));
	return 0;
}