#include <bits/stdc++.h>

const int mod = 998244353;
const int N = 2e5 + 50;

inline int inc(int x, int y) { x += y - mod; return x + (x >> 31 & mod); }
inline int dec(int x, int y) { x -= y; return x + (x >> 31 & mod); }
inline int mul(int x, int y) { return 1ll * x * y % mod; }

int n, k;
int a[N], b[N], f[N][2], h[N];

int solve(int *a, int n)
{
	int l = 1, r = n, res = 1, c = 0;
	while (l <= r && a[l] == -1) ++l, ++c;
	while (l <= r && a[r] == -1) --r, ++c;
	res = h[c];
	if (l > r) return mul(h[c - 1], k);
	int last = a[l];
	while (l < r)
	{
		int len = 1;
		while (l <= r && a[l + len] == -1) ++len;
		res = mul(res, f[len - 1][a[l] == a[l + len]]);
		l = l + len;
	}
	return res;
}

int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i) scanf("%d", (i & 1) ? (a + ((i + 1) >> 1)) : (b + (i >> 1)));
	f[0][0] = h[0] = 1, f[0][1] = 0;
	for (int i = 1; i <= n; ++i) 
		f[i][0] = inc(f[i - 1][1], mul(k - 2, f[i - 1][0])),
		f[i][1] = mul(k - 1, f[i - 1][0]),
		h[i] = mul(h[i - 1], k - 1);
	printf("%d", mul(solve(a, (n + 1) >> 1), solve(b, n >> 1)));
	return 0;
}