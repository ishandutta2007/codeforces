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
	int a1, b1, a2, b2;
	cin >> a1 >> b1 >> a2 >> b2;
	if ((a1 == a2 and b1 + b2 == a1) or (a1==b2 and b1+a2 == a1) or (b1 == a2 and a1+b2==b1) or (b1==b2 and a1+a2==b1))
		cout << "Yes" << '\n';
	else
		cout << "No\n";

	return 0;
}