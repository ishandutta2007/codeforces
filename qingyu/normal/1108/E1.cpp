#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <vector>

int n, m, a[300005], b[300005], c[300005], ans[300005], l[300005], r[300005], cnt = 0, wyhakioi = 0;

inline char nc()
{
	static char buf[1000000], *p1 = buf, *p2 = buf;
	return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++;
}

inline int read()
{
	int res = 0, neg = 1;
	char ch;
	do
	{
		ch = nc();
		if (ch == '-') neg = -1;
	} while (ch < 48 || ch > 57);
	do res = res * 10 + ch - 48, ch = nc(); while (ch >= 48 && ch <= 57);
	return res * neg;
}

int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }
int lcm(int x, int y) { return x / gcd(x, y) * y; }

int main()
{
	n = read(), m = read();;
	for (int i = 1; i <= n; ++i)
	{
		a[i] = read();
	}
	for (int i = 1; i <= m; ++i)
	{
		l[i] = read(); r[i] = read();
	}
	int t = -1;
	for (int i = 1; i <= n; ++i)
	{
		cnt = 0;
		memcpy(b, a, sizeof a);
		for (int j = 1; j <= m; ++j)
		{
			if (l[j] > i || r[j] < i)
			{
				for (int k = l[j]; k <= r[j]; ++k)
				{
					--b[k];
				}
				c[++cnt] = j;
			}
		}
		int max = 0xcfcfcfcf, min = 0x3f3f3f3f;
		for (int j = 1; j <= n; ++j)
		{
			max = std::max(max, b[j]);
			min = std::min(min, b[j]);
		}
		if (max - min > t)
		{
			memcpy(ans, c, sizeof c);
			wyhakioi = cnt;
			t = max - min;
		}
	}
	printf("%d\n%d\n", t, wyhakioi);
	for (int i = 1; i <= wyhakioi; ++i)
	{
		printf("%d ", ans[i]);
	}
	return 0;
}