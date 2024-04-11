#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, m;

	cin >> n >> m;

	array<vector<string>, 2> good{};

	for (int i = 0; i < 2; i++)
		good[i] = vector<string>(n, string(m, 'R'));

	for (int y = 0; y < n; y++)
		for (int x = 0; x < m; x++)
			good[(y + x) % 2][y][x] = 'W';

	vector<string> arr(n);

	for (auto &row : arr)
		cin >> row;

	for (auto &cand : good)
	{
		bool ok = true;

		for (int y = 0; y < n; y++)
			for (int x = 0; x < m; x++)
				if (arr[y][x] != '.' && arr[y][x] != cand[y][x])
					ok = false;

		if (ok)
		{
			cout << "YES" << endl;

			for (auto &row : cand)
				cout << row << endl;

			return;
		}
	}

	cout << "NO" << endl;
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
	auto st = chrono::steady_clock::now();

	ifstream fin("../input.txt");

	do
	{
		solve(fin);

		cout << "===" << endl;

		string str;
		while (getline(fin, str) && str != string(max(1, (int) str.size()), '='));
	} while (fin);

	cout << setprecision((int) floor(log10(chrono::steady_clock::duration::period::den)));
	cout << "clock: " << chrono::duration<double>(chrono::steady_clock::now() - st).count() << endl;
#else
	solve();
#endif

	return 0;
}