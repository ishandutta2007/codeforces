#include <bits/stdc++.h>

const int mod = 998244353;
const int N = 1e6 + 50;

int fact[N], inv[N];

inline int inc(int x, int y) { x += y - mod; return x + (x >> 31 & mod); }
inline int dec(int x, int y) { x -= y; return x + (x >> 31 & mod); }
inline int mul(int x, int y) { return 1ll * x * y % mod; }

inline void upd(int &x, int y) { x = inc(x, y); }
inline void dpu(int &x, int y) { x = dec(x, y); }
inline void pud(int &x, int y) { x = mul(x, y); }

inline int fastpow(int x, int p)
{
	int r = 1;
	while (p)
	{
		if (p & 1) pud(r, x);
		pud(x, x);
		p >>= 1;
	}
	return r;
}

inline void init(int n)
{
	fact[0] = 1;
	for (int i = 1; i <= n; ++i) fact[i] = mul(i, fact[i - 1]);
	inv[n] = fastpow(fact[n], mod - 2);
	for (int i = n - 1; i >= 0; --i) inv[i] = mul(i + 1, inv[i + 1]);
}

inline int S(int n, int m)
{
	int ans = 0;
	for (int k = 0; k <= m; ++k)
	{
		(k & 1 ? dpu : upd)(ans, mul(mul(inv[k], inv[m - k]), fastpow(m - k, n)));
	}
	return ans;
}

int main()
{
	init(2e5);
	int n; long long _k;
	std::cin >> n >> _k;
	if (_k >= n)
	{
		puts("0");
		return 0;
	}
	int k = _k;
	int ans = mul(S(n, n - k), mul(fact[n], inv[k]));
	if (k != 0) pud(ans, 2);
	std::cout << ans << '\n';
	return 0;
}