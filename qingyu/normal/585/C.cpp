// By Qingyu
#include <bits/stdc++.h>

typedef long long ll;

void solve(ll x, ll y, bool ok)
{
	if (y)
	{
		ll t = (y == 1) ? (x / y - 1) : (x / y);
		printf("%lld%c", t, ok ? 'A' : 'B');
		solve(y, x % y, !ok);
	}
}

int main()
{
	ll x, y;
	std::cin >> x >> y;
	if (std::gcd(x, y) == 1) 
	{
		if (x > y) solve(x, y, true);
		else solve(y, x, false);
	}
	else puts("Impossible");
	return 0;
}