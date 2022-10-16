#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	array arr{vector<int>(n), vector<int>(n)};

	for (auto &row: arr)
		for (auto &it: row)
			cin >> it;

	vector<vector<int>> gr(n);

	vector<int> ord(n);
	iota(ord.begin(), ord.end(), 0);

	for (const auto &row: arr)
	{
		ranges::sort(ord, [&](int a, int b)
		{
			return row[a] > row[b];
		});

		for (auto it: ranges::iota_view(1, ssize(ord)))
			gr[ord[it]].push_back(ord[it - 1]);
	}

	queue<int> q;
	vector<bool> used(gr.size());

	for (auto it: ranges::iota_view(0, ssize(ord)))
		if (gr[it].size() < 2)
			q.push(it);

	while (!q.empty())
	{
		auto v = q.front();
		q.pop();

		if (used[v])
			continue;
		used[v] = true;

		for (auto u : gr[v])
			q.push(u);
	}

	for (auto it : ranges::iota_view(0, n))
		cout << used[it];
	cout << endl;
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