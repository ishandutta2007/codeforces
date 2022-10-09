#include <bits/stdc++.h>

typedef long long ll;

const ll mod = 1e9 + 7;
ll fact[1000000], inv[1000000];

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

int main()
{
	int T;
	fact[0] = 1;
	for (int i = 1; i < 1000000; ++i) fact[i] = i * fact[i - 1] % mod;
	inv[999999] = fastpow(fact[999999], mod - 2);
	for (int i = 999998; i >= 0; --i) inv[i] = (i + 1) * inv[i + 1] % mod;

		long long n, m;
		std::cin >> n >> m;
		std::cout << fact[n + m + m - 1] * inv[n - 1] % mod * inv[m + m] % mod << std::endl;
	
}