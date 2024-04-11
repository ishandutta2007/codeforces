#include <bits/stdc++.h>

typedef long long ll;
constexpr ll mod = 1e9 + 7;

ll x, y;

std::unordered_map<ll, ll> f;

inline ll fastpow(ll x, ll p)
{
	ll res = 1;
	while (p)
	{
		if (p & 1) res = res * x % mod;
		x = x * x % mod;
		p >>= 1;
	}
	return res;
}

inline ll dowork(ll x)
{
	if (x == 1) return 1;
	if (f.count(x)) return f[x];
	ll ans = fastpow(2, x - 1) - 1;
	for (ll i = 2; i * i <= x; ++i)
	{
		if (x % i == 0)
		{
			ans -= dowork(i);
			if (i != x / i) ans -= dowork(x / i);
		}
	}
	return f[x] = (ans % mod + mod) % mod;
}

int main()
{
	scanf("%lld %lld", &x, &y);
	if (y % x) printf("0");
	else printf("%lld", dowork(y / x));
	return 0;
}