// By Qingyu
#include <bits/stdc++.h>

const int N = 2e5 + 50;

int n, v[31], a[N];
long long ans = 0;

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
	for (int i = 1; i <= n; ++i) a[i] = read();
	for (int i = 0; i <= 20; ++i)
	{
		int p = 0;
		for (int j = 1; j <= n; ++j)
			if ((a[j] >> i) & 1)
			{
				int x = a[j], y = a[++p];
				a[p] = x | y, a[j] = x & y;
			}
	}
	for (int i = 1; i <= n; ++i) ans += 1ll * a[i] * a[i];
	printf("%lld", ans);
	return 0;
}