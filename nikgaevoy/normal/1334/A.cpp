#include <bits/stdc++.h>

using namespace std;

using ll = long long;

mt19937 mt(736);


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<pair<int, int>> arr(n);

	for (auto &it : arr)
		cin >> it.first >> it.second;

	pair<int, int> last;

	for (auto it : arr)
	{
		if (it.first < last.first || it.second < last.second || it.first - last.first < it.second - last.second)
		{
			cout << "NO" << endl;

			return;
		}

		last = it;
	}

	cout << "YES" << endl;
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