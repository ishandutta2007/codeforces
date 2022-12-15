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
	int a, b;
	cin >> a >> b;
	int side1 = max(2*a, b);
	int side2 = max(2*b, a);
	cout << min(side1*side1, side2*side2) << '\n';

	return 0;
}