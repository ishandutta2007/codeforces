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
		cout << solve() << '\n';;
}

ll solve(void)
{
	ll n, m;
	cin >> n >> m;
	if (n == 1)
		return 0;
	if (n == 2)
		return m;
	return 2 * m;
}