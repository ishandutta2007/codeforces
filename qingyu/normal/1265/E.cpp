#include <bits/stdc++.h>

const int N = 2e5 + 50;
const int M = 105;
const int mod = 998244353;
int inv[N], p[N];

inline int inc(int x, int y) { x += y - mod; return x + (x >> 31 & mod); }
inline int dec(int x, int y) { x -= y; return x + (x >> 31 & mod); }
inline int mul(int x, int y) { return 1ll * x * y % mod; }

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
	inv[1] = 1;
	for (int i = 2; i <= M; ++i) inv[i] = mul((mod - mod / i), inv[mod % i]);
	int n = read(), cur = 0;
	for (int i = 0; i < n; ++i)
	{
		int p = mul(100, inv[read()]);
		cur = mul(cur + 1, p);
	}
	printf("%d", cur);
	return 0;
}