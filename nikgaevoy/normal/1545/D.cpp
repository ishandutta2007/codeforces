#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int m, k;

	cin >> m >> k;

	vector<vector<int>> table(k, vector<int>(m));

	for (auto &row : table)
		for (auto &it : row)
			cin >> it;

	vector<ll> sum(k), sq_sum(k);

	for (int j = 0; j < table.size(); j++)
	{
		sum[j] = accumulate(table[j].begin(), table[j].end(), 0ll);

		for (auto it : table[j])
			sq_sum[j] += it * (ll) it;
	}

	auto bad = (ssize_t) size(sum) - 3;

	while (2 * sum[bad + 1] == sum[bad] + sum[bad + 2])
		bad--;

	bad -= 2;

	if (2 * sum[bad + 1] != sum[bad] + sum[bad + 2])
		bad += 2;
	else
		bad += 3;

	cout << bad << ' ' << flush;

	auto diff = (sum[bad - 1] + sum[bad + 1] - 2 * sum[bad]) / 2;

	int mid = bad - 2;

	while (mid < 1 || mid - 1 <= bad && bad <= mid + 1)
		mid++;

	auto c = sq_sum.at(mid);
	auto c2 = 2 * c;
	auto a2 = sq_sum.at(mid - 1) + sq_sum.at(mid + 1) - c2;
	auto b2 = 2 * sq_sum[mid + 1] - c2 - a2;

	auto sq_val = 2 * a2 + c + (bad < mid ? -b2 : b2);

	cerr << diff << endl;

	for (auto it : table[bad])
		if (sq_sum[bad] - it * (ll) it + (it + diff) * ll(it + diff) == sq_val)
		{
			cout << it + diff << endl;

			return;
		}

	assert(false);
}


pair<int, int> gen(ostream &cout = std::cout)
{
	const int m = 5, k = 7;

	cout << m << ' ' << k << endl;

	uniform_int_distribution<int> uid(0, 10);

	vector<int> val(m), diff(m);

	for (auto &it : val)
		it = uid(mt);
	for (auto &it : diff)
		it = uid(mt);

	vector<vector<int>> table(k);

	for (auto &row : table)
	{
		row = val;

		for (int j = 0; j < val.size(); j++)
			val[j] += diff[j];
	}

	int y = uniform_int_distribution{1, (int) table.size() - 2}(mt);
	int x = uniform_int_distribution{0, (int) table[y].size() - 1}(mt);

	auto ans = table[y][x];

	while (table[y][x] == ans)
		table[y][x] = uid(mt);

	for (auto &row : table)
	{
		for (auto it : row)
			cout << it << ' ';
		cout << endl;
	}

	return {y, ans};
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
		solve(fin);

		cout << "===" << endl;

		string str;
		while (getline(fin, str) && str != string(max(1, (int) str.size()), '='));
	} while (fin);

	while (true)
	{
		stringstream ss;

		auto ans = gen(ss);

		cout << ans.first << ' ' << ans.second << endl;

		cout << ss.str();

		solve(ss);
	}

	cout << setprecision((int) floor(log10(chrono::steady_clock::duration::period::den)));
	cout << "clock: " << chrono::duration<double>(chrono::steady_clock::now() - st).count() << endl;
#else
	solve();
#endif

	return 0;
}