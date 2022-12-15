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
	string n;
	cin >> n;
	int nb_non_nul(0);
	for (auto c : n)
		nb_non_nul += c != '0';
	cout << nb_non_nul << '\n';
	for (int i(0); i < SZ(n); ++i)
		if (n[SZ(n)-1-i] != '0')
		{
			cout << n[SZ(n)-1-i];
			for (int j(0); j < i; ++j)
				cout << '0';
			cout << ' ';
		}
		cout << '\n';

	return 0;
}