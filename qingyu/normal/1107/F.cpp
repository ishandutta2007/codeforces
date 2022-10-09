//...
#include <bits/stdc++.h>

constexpr int N = 505;
constexpr int Q = 250200;

int n;
long long a[N], b[N], k[N], d[N][N];
int del[N];

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
	for (int i = 1; i <= n; i++)
		a[i] = read(), b[i] = read(), k[i] = read(),del[i] = i;
	std::sort(del + 1, del + n + 1, [](int x, int y) { return b[x] > b[y]; });
	memset(d, 0xcf, sizeof d);
	d[0][0] = 0;
	for (int ii = 1; ii <= n; ii++) 
	{
		int i = del[ii];
		for (int j = n; j >= 0; j--)
			for (int h = n - j; h >= 0; h--) 
			{
				if (j - 1 >= 0)
					d[j][h] = std::max(d[j][h], d[j - 1][h] - std::min((long long)j - 1, k[i]) * b[i] + a[i]);
				if (h - 1 >= 0)
					d[j][h] = std::max(d[j][h], d[j][h - 1] - k[i] * b[i] + a[i]);
			}
	}
	long long res = 0;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			res = std::max(res, d[i][j]);
	printf("%lld", res);
}