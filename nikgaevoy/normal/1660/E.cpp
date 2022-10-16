#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<string> matr(n);

	for (auto &row: matr)
		cin >> row;

	int zeros = 0, ones = 0;

	vector<int> q(n);

	for (auto y: ranges::iota_view(0, n))
	{
		zeros += ranges::count(matr[y], '0');
		ones += ranges::count(matr[y], '1');

		for (auto x: ranges::iota_view(0, n))
		{
			auto pos = y - x;

			if (pos < 0)
				pos += n;

			q[pos] += matr[y][x] - '0';
		}
	}

	assert(zeros + ones == n * n);

	auto ans = ones + n - 2 * ranges::max(q);

	cout << ans << '\n';
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int t = 1;

	cin >> t;

	for (weakly_incrementable auto it: ranges::iota_view(0, t))
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