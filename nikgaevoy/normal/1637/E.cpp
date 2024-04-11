#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, m;

	cin >> n >> m;

	vector<int> arr(n);

	for (auto &it: arr)
		cin >> it;

	ranges::sort(arr);

	vector<pair<int, int>> bad(m);

	for (auto &[x, y]: bad)
		cin >> x >> y;

	ranges::sort(bad);

	vector<vector<int>> cnt(arr.size() + 1);

	for (int l = 0, r; l < ssize(arr); l = r)
	{
		for (r = l; r < ssize(arr) && arr[r] == arr[l]; r++);

		cnt[r - l].push_back(arr[l]);
	}

	vector<int> ind;

	for (auto i: ranges::iota_view(0, ssize(cnt)))
		if (!cnt[i].empty())
			ind.push_back(i);

	auto check_bad = [&bad](int x, int y)
	{
		if (y < x)
			swap(x, y);
		if (x == y)
			return true;
		return ranges::binary_search(bad, pair{x, y});
	};

	for (auto it: ind)
		ranges::reverse(cnt[it]);

	ll ans = 0;

	for (auto cntx: ind)
		for (auto cnty: ind)
			if (cntx <= cnty)
			{
				auto le = cntx + cnty;

				auto val = [&](int ix, int iy)
				{
					return cnt[cntx][ix] + cnt[cnty][iy];
				};

				auto cmp = [&](const pair<int, int> &ia, const pair<int, int> &ib)
				{
					if (auto va = val(ia.first, ia.second), vb = val(ib.first, ib.second); va != vb)
						return va > vb;
					return ia < ib;
				};

				set<pair<int, int>, decltype(cmp)> q(cmp);
				q.emplace(0, 0);

				while (!q.empty())
				{
					auto[ix, iy] = *q.begin();
					q.erase(q.begin());

					if (check_bad(cnt[cntx][ix], cnt[cnty][iy]))
					{
						if (ix + 1 < ssize(cnt[cntx]))
							q.emplace(ix + 1, iy);
						if (iy + 1 < ssize(cnt[cnty]))
							q.emplace(ix, iy + 1);
					}
					else
					{
						ans = max(ans, le * (ll) val(ix, iy));

						break;
					}
				}
			}

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