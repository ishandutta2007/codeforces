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
	ll d(0);
	while ((1LL<<(d+1)) <= n)
		++d;
	cout << d << endl;
	for (int i(0); i < d-2; ++i)
		cout << (1LL<<i) << ' ';
	if (n >= (1LL<<d) + (1LL<<(d-1)) - 1)
	{
		if (d-2 >= 0)
			cout << (1LL<<(d-2)) << ' ';
		cout << n - (1LL<<(d-1)) - ((1LL<<d) - 1) << ' ';
	}
	else
	{
		int k(min((1LL<<(d-2)), (n-(1LL<<d) + 1)/2));
		cout << k << ' ';
		cout << (n - (1LL<<d) + 1-2*k) << ' ';
	}
	cout << '\n';
	return 0;
}