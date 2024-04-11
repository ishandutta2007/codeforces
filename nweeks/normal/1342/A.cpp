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
		solve();
}

ll solve(void)
{
	ll x,y;
	ll a, b;
	cin >> x >> y >> a >> b;
	ll sol = a * abs(x-y) + min(2 * a * min(x, y), b * min(x,y));
	cout << sol << '\n';

	return 0;
}