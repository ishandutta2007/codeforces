#include <bits/stdc++.h>


using namespace std;


using ll = long long;


mt19937 mt(736);


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<vector<int>> arr(n);
	vector<int> l, r;
	int cnt = 0, good = 0;

	for (auto &row : arr)
	{
		int k;

		cin >> k;

		row.resize(k);

		for (auto &it : row)
			cin >> it;

		bool bad = is_sorted(row.rbegin(), row.rend());

		if (bad && !row.empty())
		{
			l.push_back(row.back());
			r.push_back(row.front());
		}

		if (row.empty())
			cnt++;

		if (!bad)
			good++;
	}

	sort(r.begin(), r.end());

	ll ans = (n - cnt) * ll(good) + 2ll * good * cnt;

	for (auto it : l)
	{
		ans += good;
		ans += r.end() - upper_bound(r.begin(), r.end(), it);
	}

	cout << ans << endl;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed;

#ifdef LOCAL
	auto st = clock();

	ifstream fin("../input.txt");

	solve(fin);

	cout << "clock: " << setprecision(4) << (clock() - st) / (double) CLOCKS_PER_SEC << endl;
#else
	solve();
#endif

	return 0;
}