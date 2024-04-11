#include <bits/stdc++.h>

typedef long long ll;

inline bool is_p(ll x)
{
	if (x == 1) return false;
	if (x == 2) return true;
	if ((~x) & 1) return false;
	for (ll i = 3; i * i <= x; i += 2)
		if (x % i == 0)
			return false;
	return true;
}

inline ll fastpow(ll x, ll p, ll mod)
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
	ll n;
	scanf("%lld", &n);
	if (n == 1)
	{
		printf("YES\n1");
		return 0;
	}
	if (n == 4)
	{
		printf("YES\n1\n3\n2\n4\n");
		return 0;
	}
	if (is_p(n) == false)
	{
		printf("NO");
		return 0;
	}
	printf("YES\n1\n");
	ll x = 1;
	for (int i = 2; i < n; ++i)
	{
		x = i * fastpow(i - 1, n - 2, n) % n;
		printf("%lld\n", x);
	}
	printf("%lld", n);
	return 0;
}