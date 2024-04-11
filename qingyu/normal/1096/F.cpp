#include <bits/stdc++.h>

constexpr int N = 2e5 + 50;
constexpr int mod = 998244353;
constexpr int inc(int x, int y) { x += y - mod; return x + (x >> 31 & mod); } 
constexpr int dec(int x, int y) { x -= y; return x + (x >> 31 & mod); }
constexpr int mul(int x, int y) { return 1ll * x * y % mod; } 
constexpr void upd(int &x, int y) { x = inc(x, y); }
constexpr int lowbit(int x) { return x & -x; }

int n, ans, tot, a[N], t[N], inv[N], cnt[N], pre[N], suf[N];

inline void add(int p, int x)
{
	for (int i = p; i <= n; i += lowbit(i)) t[i] += x;
}

inline int qry(int p)
{
	int v = 0;
	for (int i = p; i; i -= lowbit(i)) v += t[i];
	return v;
}

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

int main()
{
	n = read();
	inv[1] = 1;
	for (int i = 2; i <= n; ++i) inv[i] = mul((mod - mod / i), inv[mod % i]);
	for (int i = 1; i <= n; ++i)
	{
		++cnt[i];
		a[i] = read();
		if (a[i] != -1)
		{
			upd(ans, tot++ - qry(a[i]));
			add(a[i], 1);
			--cnt[a[i]];
		}
		else
		{
			++pre[i];
			++suf[i];
		}
	}
	for (int i = 1; i <= n; ++i) pre[i] += pre[i - 1];
	for (int i = 1; i <= n; ++i) cnt[i] += cnt[i - 1];
	for (int i = n; i >= 1; --i) suf[i] += suf[i + 1];
	assert(tot + cnt[n] == n);
	int negs = n - tot;
	for (int i = 1; i <= n; ++i)
		if (a[i] != -1)
		{
			upd(ans, mul(pre[i], mul(cnt[n] - cnt[a[i]], inv[negs])));
			upd(ans, mul(suf[i], mul(cnt[a[i]], inv[negs])));
		}
	upd(ans, 1ll * negs * (negs - 1) / 2 % mod * inv[2] % mod);
	printf("%d", ans);
	return 0;
}