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
	int n;
	cin >> n;
	if (n==1)
	{
		cout << 1 << endl;
		return 0;
	}
	if (n <= 3)
	{
		cout << -1 << endl;
		return 0;
	}
	if (n%2==0)
	{
		for (int i(2); i <= n; i += 2)
			cout << i << ' ';
		cout << n-3 << ' ';
		cout << n-1 << ' ';
		for (int i(n-5); i >= 1; i -= 2)
			cout << i << ' ';
		cout << '\n';
		return 0;
	}
	if (n%2==1)
	{
		for (int i(1); i <= n; i += 2)
			cout << i << ' ';
		cout << n-3 << ' ';
		cout << n-1 << ' ';
		for (int i(n-5); i >= 1; i -= 2)
			cout << i << ' ';
		cout << '\n';
	}

	return 0;
}