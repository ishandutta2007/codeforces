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
	ll n, k;
	cin >> n >> k;
	ll q = k/(n-1);
	ll r = k - (n-1) * q;
	if (!r)
		cout << q*n-1 << '\n';
	else
		cout << q * n + r << '\n';
	return 0;
}