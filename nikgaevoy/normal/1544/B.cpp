#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int h, w;

	cin >> h >> w;

	vector<string> field(h, string(w, '0'));

	for (int i = 0; i < w; i += 2)
		field[0][i] = '1';
	for (int i = 0; i < h; i += 2)
		field[i][0] = '1';
	for (int i = w - 1; i >= 0; i -= 2)
		field.back()[i] = '1';
	for (int i = h - 1; i >= 0; i -= 2)
		field[i].back() = '1';

	field[0][w - 2] = '0';
	field[1].back() = '0';
	field[0].back() = '1';

	field[h - 2][0] = '0';
	field.back()[1] = '0';
	field.back()[0] = '1';

	for (auto row : field)
		cout << row << endl;
	cout << endl;
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