#include <bits/stdc++.h>

typedef long long ll;
const int N = 1e6 + 50;
const int mod = 1e9 + 7;

ll n, K;
ll pri[N], isnt_pri[N], tot, v[N];
ll fact[N], inv[N];

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

inline void init()
{
	isnt_pri[1] = true; v[1] = fact[0] = 1;
	for (int i = 1; i < N; ++i)
	{
		fact[i] = fact[i - 1] * i % mod;
		if (isnt_pri[i] == false)
		{
			pri[++tot] = i;
			v[i] = fastpow(i, K);
		}
		for (int j = 1; j <= tot && i * pri[j] < N; ++j)
		{
			isnt_pri[i * pri[j]] = true;
			v[i * pri[j]] = v[i] * v[pri[j]] % mod;
			if (i % pri[j] == 0)
			{
				break;
			}
		}
	}
	inv[N - 1] = fastpow(fact[N - 1], mod - 2);
	for (int i = N - 2; i >= 0; --i) inv[i] = (i + 1) * inv[i + 1] % mod;
}

int main()
{
	scanf("%d%d", &n, &K);
	init();
	if (n < N) 
	{
		ll ans = 0;
		for(int i = 1; i <= n; ++i) ans = (ans + v[i]) % mod;
		printf("%lld", ans);
	}
	else
	{
		ll factor = 1, ans = 0;
		for (int i = 1; i <= K + 2; ++i) factor = factor * (n - i) % mod;
		for (int i = 1; i <= K + 2; ++i)
		{
			v[i] += v[i - 1]; v[i] %= mod;
			ll cur = v[i] * factor % mod * fastpow(n - i, mod - 2) % mod * inv[i - 1] % mod * inv[K + 2 - i] % mod;
			if ((K - i) % 2 == 0) ans += cur;
			else ans -= cur;
		}
		ans %= mod; ans += mod;
		printf("%lld", ans % mod);
	}
	return 0;
}