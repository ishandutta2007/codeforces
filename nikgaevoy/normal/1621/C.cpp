#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<pair<int, vector<int>>> cycles;
	int tim = 0;

	auto ask = [&](int v)
	{
		cout << "? " << v + 1 << endl << flush;
		tim++;

		int t;

		cin >> t;

		return t - 1;
	};

	vector<bool> used(n);

	for (int i = 0; i < n; i++)
		if (!used[i])
		{
			cycles.emplace_back();
			cycles.back().first = tim;

			auto &row = cycles.back().second;

			while (row.size() < 2 || row.front() != row.back())
				row.push_back(ask(i));

			row.pop_back();

			for (auto it: row)
				used[it] = true;
		}

	assert(tim <= 2 * n);

	vector<int> ans(n, -1);

	for (auto[rot, cyc]: cycles)
	{
		for (int i = 0; i < cyc.size(); i++)
			ans[cyc[i]] = cyc[(i + 1) % cyc.size()];
	}

	assert(count(ans.begin(), ans.end(), -1) == 0);

	cout << "!";
	for (auto it: ans)
		cout << ' ' << it + 1;
	cout << endl << flush;
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
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);

	cout << fixed;

#ifdef LOCAL
	auto st = chrono::steady_clock::now();

	ifstream fin("../input.txt");

	do
	{
		solve();

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