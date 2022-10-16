#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<pair<int, int>> arr(n);

	for (auto &[m, k]: arr)
		cin >> m >> k;

	vector<int> best;
	double e = 0;

	for (size_t cnt = 1; cnt <= arr.size() && clock() < 2 * CLOCKS_PER_SEC; cnt++)
	{
		unordered_map<int, int> mem;

		for (auto[m, k]: arr)
			mem[m] += min(k, (int)cnt);

		if (mem.size() < cnt)
			break;

		vector<pair<int, int>> val;

		for (auto &[ind, num]: mem)
			val.emplace_back(num, ind);

		ranges::sort(val, greater());
		val.resize(min(val.size(), cnt));

		double q = 0;
		vector<int> cur;

		cur.reserve(val.size());

		for (auto[num, ind]: val)
		{
			q += num;
			cur.push_back(ind);
		}

		q /= cnt;

		if (q > e)
		{
			e = q;
			best = cur;
		}
	}

	cerr << e << endl;

	cout << best.size() << endl;

	ranges::copy(best, ostream_iterator<int>(cout, " "));
	cout << endl;
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