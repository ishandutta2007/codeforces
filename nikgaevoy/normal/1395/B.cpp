#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, m, x, y;

	cin >> n >> m >> x >> y;
	x--;
	y--;

	vector<int> ord(n);

	iota(ord.begin(), ord.end(), 0);
	swap(ord.front(), ord[x]);

	vector<pair<int, int>> ans;
	ans.reserve(n * m);

	auto gen_row = [&y, &ans, &m](int row)
	{
		vector<int> ord(m);
		iota(ord.begin(), ord.end(), 0);
		swap(ord.front(), ord[y]);

		for (auto it : ord)
			ans.emplace_back(row, it);
		y = ord.back();
	};

	for (auto it : ord)
		gen_row(it);

	assert(ans.size() == n * m);

	for (auto it : ans)
		cout << it.first + 1 << ' ' << it.second + 1 << endl;
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