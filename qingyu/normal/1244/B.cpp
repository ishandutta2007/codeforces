/*
 * sto RainAir orz
 */
#include <bits/stdc++.h>

typedef long long ll;
constexpr ll N = 5e5 + 50;
ll a[N];

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

inline ll read_bit()
{
	ll res = 0;
	char ch;
	do ch = nc(); while (ch < 48 or ch > 57);
	return ch - 48;
}

int main()
{
	ll t = read();
	while (t--)
	{
		ll n = read();
		ll _le = -1, _re = -1;
		for (int i = 1; i <= n; ++i) 
		{
			a[i] = read_bit();
			if (a[i])
			{
				if (_le == -1) _le = i;
				_re = i;
			}
		}
		if (_le == -1) printf("%lld\n", n);
		else
		{
			ll ans = n;
			ans = std::max(ans, _le * 2);
			ans = std::max(ans, _re * 2);
			ans = std::max(ans, (n - _re + 1) * 2);
			ans = std::max(ans, (n - _le + 1) * 2);
			printf("%lld\n", ans);
		}
	}
}