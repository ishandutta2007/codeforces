#include <bits/stdc++.h>

typedef long long ll;

ll solve(ll x, ll up, ll cnt)
{
	if (cnt == 3) return 1;
	if (up == 0) return 1;
	ll ans = solve(x, up / 10, cnt), p = 0;
	for (; p < 10; ++p) if (p * up > x) break;
	--p;
	if (p > 0) ans += (p - 1) * solve(x, up / 10, cnt + 1) + solve(x - up * p, up / 10, cnt + 1);
	return ans;
}

inline ll solve(ll x)
{
	return solve(x, 1e18, 0);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		ll L, R;
		scanf("%lld %lld", &L, &R);
		printf("%lld\n", solve(R) - solve(L - 1));
	}
	return 0;
}