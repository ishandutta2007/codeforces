#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, m;

	cin >> n >> m;

	string str;

	cin >> str;

	assert(str.size() == n * m);

	vector<bool> col(m);
	int col_ans = 0;
	vector<int> row(m, n);

	for (auto i: ranges::iota_view(0, n * m))
	{
		bool ser = str[i] == '1';

		if (ser && !col[i % col.size()])
		{
			col[i % col.size()] = true;
			col_ans++;
		}

		if (ser)
		{
			row[i % row.size()]--;
			for (int j = i - 1; j > i - m && (j < 0 || str[j] != '1'); j--)
				row[(j + m * n) % row.size()]--;
		}

		cout << col_ans + n - row[(i + 1) % row.size()] << ' ';
	}

	cout << '\n';
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int t = 1;

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