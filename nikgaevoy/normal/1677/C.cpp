#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<int> ca(n), cb(n);

	for (auto &it: ca)
	{
		cin >> it;
		it--;
	}
	for (auto &it: cb)
	{
		cin >> it;
		it--;
	}

	vector<pair<int, int>> edges(n);

	for (auto i: ranges::iota_view(0, n))
	{
		edges[ca[i]].first = cb[i];
		edges[cb[i]].second = ca[i];
	}

	vector<vector<int>> cyc;
	vector<bool> used(n);

	auto dfs = [&](int v)
	{
		if (used[v])
			return;
		cyc.emplace_back();

		while (!used[v])
		{
			used[v] = true;

			cyc.back().push_back(v);
			v = edges[v].first;
		}
	};

	for (auto i: ranges::iota_view(0, n))
		dfs(i);

	ranges::sort(cyc, [](const auto &a, const auto &b)
	{
		if (a.size() % 2 != b.size() % 2)
			return a.size() % 2 < b.size() % 2;
		else
			return a.size() > b.size();
	});

	int l = 0, r = n;

	vector<int> val(n, -1);

	for (auto &row: cyc)
	{
		bool sm = true;

		for (auto it: row | views::drop(row.size() % 2))
		{
			if (sm)
				val[it] = l++;
			else
				val[it] = --r;

			sm = !sm;
		}
	}

	for (auto &it: val)
		if (it == -1)
			it = l++;

	assert(l == r);
	assert(ranges::count(val, -1) == 0);

	ll ans = 0;

	for (auto i: ranges::iota_view(0, n))
		ans += abs(val[ca[i]] - val[cb[i]]);

	cout << ans << '\n';
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