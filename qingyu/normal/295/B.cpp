// By Qingyu
#include <bits/stdc++.h>

const int N = 505;

int n, g[N][N], p[N];
long long sum;

inline char nc()
{
	static char buf[1000000], *p1 = buf, *p2 = buf;
	return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++;
}

inline int read()
{
	int res = 0;
	char ch;
	do ch = nc(); while (ch < 48 || ch > 57);
	do res = res * 10 + ch - 48, ch = nc(); while (ch >= 48 && ch <= 57);
	return res;
}

int main()
{
	n = read();
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			g[i][j] = read();
	for (int i = 1; i <= n; ++i) p[i] = read();
	std::vector<long long> vec;
	for (int k = n; k >= 1; --k)
	{
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
			{
				int x = p[i], y = p[j], z = p[k];
				g[x][y] = std::min(g[x][y], g[x][z] + g[z][y]);			
			}
		long long sum = 0;
		for (int i = n; i >= k; --i)
			for (int j = n; j >= k; --j)
				sum += g[p[i]][p[j]];
		vec.emplace_back(sum);
	}
	std::reverse(vec.begin(), vec.end());
	for (auto x : vec) printf("%lld ", x);
	return 0;
}