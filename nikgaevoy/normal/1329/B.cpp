#include <bits/stdc++.h>

using namespace std;

using ll = long long;

mt19937 mt(736);


int foo(vector<int> &dp, int val, int d, int m)
{
	if (val >= d)
		return 0;

	auto ctz = __builtin_ctz(val);

	if (val > 0 && dp[ctz] != -1)
		return dp[ctz];

	ll ans = 1;

	for (ll q = max(1ll, 2ll * val); q < d; q *= 2)
		ans += (min((ll) d, 2 * q) - q) * foo(dp, q, d, m) % m;

	if (val > 0 && dp[ctz] == -1)
		dp[ctz] = ans % m;

	return ans % m;
}


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int d, m;

	cin >> d >> m;

	vector<int> dp(30, -1);

	cout << (foo(dp, 0, d + 1, m) + m - 1) % m << endl;
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int t;

	cin >> t;

	for (int i = 0; i < t; i++)
		solve_test(cin, cout);
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed;

#ifdef LOCAL
	auto st = clock();

	ifstream fin("../input.txt");

	solve(fin);

	cout << "clock: " << (clock() - st) / (double) CLOCKS_PER_SEC << endl;
#else
	solve();
#endif

	return 0;
}