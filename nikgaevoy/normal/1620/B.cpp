#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int w, h;

	cin >> w >> h;

	array<vector<int>, 4> arr{};

	for (auto &row: arr)
	{
		int k;

		cin >> k;

		row.resize(k);

		for (auto &it: row)
			cin >> it;
	}

	ll ans = 0;

	for (auto i: ranges::iota_view(0, ssize(arr)))
		ans = max(ans, (arr[i].back() - arr[i].front()) * ll(i < 2 ? h : w));

	cout << ans << endl;
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int t;

	cin >> t;

	for (auto it: ranges::iota_view(0, t))
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

	do
	{
		solve(fin);

		cout << "===" << endl;

		string str;
		while (getline(fin, str) && str != string(max(1, (int) str.size()), '='));
	} while (fin);

	cout << setprecision(6) << "clock: " << double(clock() - st) / CLOCKS_PER_SEC << endl;
#else
	solve();
#endif

	return 0;
}