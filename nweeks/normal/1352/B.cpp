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
	int n, k;
	cin >> n >> k;
	if (n%2==1)
	{
		if (k%2==0 or k > n)
		{
			cout << "NO" << '\n';
			return 0;
		}
		cout << "YES" << '\n';
		for (int i(0); i < k-1; ++i)
			cout << 1 << ' ';
		cout << n - (k-1) << '\n';
		return 0;
	}
	if (k%2==1)
	{
		if (2*k > n)
		{
			cout << "NO\n";
			return 0;
		}
		cout << "YES" << '\n';
		for (int i(0); i < k-1; ++i)
			cout << 2 << ' ';
		cout << n - 2*(k-1) << '\n';
		return 0;
	}
	if (k > n)
	{
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	for (int i(0); i < k-1; ++i)
		cout << 1 << ' ';
	cout << n-k+1 << '\n';
	return 0;
}