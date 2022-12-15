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
	ll n;
	cin >> n;
	ll a(0), b(0);
	for (int i(1); i <= n/2-1; ++i)
		a += (1<<i);
	a += (1LL<<n);
	for (int i(n/2); i < n; ++i)
		b += (1LL<<i);
	cout << abs(a-b) << '\n';

	return 0;
}