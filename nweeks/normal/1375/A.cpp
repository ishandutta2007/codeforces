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
	int nbEntiers;
	cin >> nbEntiers;
	for (int i(0); i < nbEntiers; ++i)
	{
		int val;
		cin >> val;
		val = abs(val);
		if (i%2) val = -val;
		cout << val << ' ';
	}
	cout << '\n';
	return 0;
}