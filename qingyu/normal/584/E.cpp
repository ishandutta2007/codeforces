// By Qingyu
#include <bits/stdc++.h>

constexpr int N = 2005;

int n, p[N], q[N], r[N], pos[N];

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
	for (int i = 1; i <= n; ++i) p[i] = read();
	for (int i = 1; i <= n; ++i) q[i] = read(), r[q[i]] = i;
	for (int i = 1; i <= n; ++i) p[i] = r[p[i]], pos[p[i]] = i;
	int ans = 0;
	for (int i = 1; i <= n; ++i) ans += abs(i - p[i]);
	ans >>= 1;
	std::vector<std::pair<int, int>> vec;
	for (int i = 1; i <= n; ++i)
	{
		while (pos[i] != i)
		{
			for (int j = pos[i]; ; --j)
				if (p[j] >= pos[i])
				{
					vec.emplace_back(pos[p[j]], pos[i]);
					int z = p[j];
					std::swap(p[j], p[pos[i]]);
					std::swap(pos[z], pos[i]);
					break;
				}
		}
	}
	printf("%d\n", ans);
	printf("%d\n", vec.size());
	for (const auto &p : vec)
	{
		printf("%d %d\n", p.first, p.second);
	}
	return 0;
}