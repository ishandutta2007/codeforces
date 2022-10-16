#include <bits/stdc++.h>


using namespace std;


using ll = long long;


mt19937 mt(736);


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		ll x;

		cin >> x;

		bool ans;

		auto cnt = x / 14;

		cnt = max(0ll, cnt - 10);
		x -= cnt * 14;

		while (x > 7 * 3 - 1)
			x -= 14;

		ans = 7 * 3 - 6 <= x && x <= 7 * 3 - 1;

		cout << (ans ? "YES" : "NO") << endl;
	}
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

	cout << "clock: " << setprecision(4) << (clock() - st) / (double) CLOCKS_PER_SEC << endl;
#else
	solve();
#endif

	return 0;
}