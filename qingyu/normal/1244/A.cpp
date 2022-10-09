/*
 * sto RainAir orz
 */
#include <bits/stdc++.h>

typedef long long ll;
constexpr ll wyh = 998244353;

inline char nc()
{
	static char buf[1000000], *p1 = buf, *p2 = buf;
	return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++;
}

inline ll read()
{
	ll res = 0;
	char ch;
	do ch = nc(); while (ch < 48 or ch > 57);
	do res = res * 10 + ch - 48, ch = nc(); while (ch >= 48 and ch <= 57);
	return res;
}

int main()
{
	ll t = read();
	while (t--)
	{
		ll a = read(), b = read(), c = read(), d = read(), k = read();
		ll x = std::ceil(1.0 * a / c), y = std::ceil(1.0 * b / d);
		ll tot = std::ceil(1.0 * a / c) + std::ceil(1.0 * b / d);
		if (tot > k) printf("-1\n");
		else printf("%lld %lld\n", x, y);
	}
}