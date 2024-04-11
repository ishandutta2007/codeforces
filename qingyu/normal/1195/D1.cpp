#include <bits/stdc++.h>

typedef long long ll;
constexpr ll N = 5e5 + 50;
constexpr ll mod = 998244353;

ll n, a[N], len, p0[N], p1[N], p10[N];

inline ll get_length(int n) { return log10(n + 1) + 1; }
inline ll idx(ll n, ll i) { 
	return 1ll * n / p10[i - 1] % 10; 
}

int main()
{
	scanf("%lld", &n);
	p10[0] = 1;
	for (int i = 1; i <= 18; ++i) p10[i] = 10 * p10[i - 1];
	for (int i = 19; i <= 20; ++i) p10[i] = (p10[i - 1] % mod) * 10 % mod;
	for (int i = 1; i <= n; ++i) scanf("%d", a + i);
	len = get_length(a[1]);
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= len; ++j) p0[i] += idx(a[i], j) * p10[2 * j - 2] % mod;
		for (int j = 1; j <= len; ++j) p1[i] += idx(a[i], j) * p10[2 * j - 1] % mod;
	}
	ll S = 0, ans = 0;
	for (int i = 1; i <= n; ++i) (S += p0[i]) %= mod;
	for (int i = 1; i <= n; ++i) (ans += p1[i]) %= mod;
	ans = (n * ans + n * S % mod) % mod;
	printf("%lld", ans);
	return 0;
}