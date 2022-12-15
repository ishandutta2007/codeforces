#include <bits/stdc++.h>
using namespace std;

#define SZ(v) ((int)(v).size())
using ll = long long;

ll solve(void);

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int nb_tests;
	cin >> nb_tests;

	for (int i(0); i < nb_tests; ++i)
		cout << solve() << '\n';
}

pair<int, int> dig(ll n)
{
	ll mn(10), mx(0);
	while (n)
	{
		mn = min(mn, n%10);
		mx = max(mx, n%10);
		n /= 10;
	}
	return make_pair(mn, mx);
}

ll solve(void)
{
	ll n, k;
	cin >> n >> k;
	int cur(1);

	while (cur < k)
	{
		auto [mn, mx] = dig(n);
		if (mn == 0)
			return n;
		n += mn * mx;
		++cur;
	}

	return n;
}