#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


bool nxt(vector<int> &arr)
{
	for (int i = 0; i < arr.size(); i++)
		if (arr[i]++ == i)
			arr[i] = 0;
		else
			return true;

	return false;
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, m, k;

	cin >> n >> m >> k;

	vector<vector<pair<int, int>>> gr(n);

	for (int i = 0; i < m; i++)
	{
		int a, b, w;

		cin >> a >> b >> w;
		a--;
		b--;

		gr[a].emplace_back(w, b);
	}

	for (auto &row : gr)
		sort(row.begin(), row.end());

	vector<int> c(k);

	vector<vector<bitset<(int) 2e5 + 1>>> q(k);

	for (int i = 0; i < q.size(); i++)
	{
		q[i].resize(i + 1);

		for (int j = 0; j < q[i].size(); j++)
			for (const auto &vert : gr)
				if (vert.size() - 1 == i)
				{
					if (q[i][j].test(vert[j].second))
						q[i][j].set(q[i][j].size() - 1);
					else
						q[i][j].set(vert[j].second);
				}
	}

	map<tuple<int, int, int, int>, bool> dp;

	auto ask = [&dp, &q](int a, int b, int c, int d)
	{
		if (!dp.count({a, b, c, d}))
			dp[{a, b, c, d}] = (q[a][b] & q[c][d]).none() &&
			                   !q[a][b].test(q[a][b].size() - 1) &&
			                   !q[c][d].test(q[c][d].size() - 1);

		return dp[{a, b, c, d}];
	};

	int ans = 0;

	do
	{
		bool ok = !q[0][0].test(q[0][0].size() - 1);

		for (int i = 0; ok && i < q.size(); i++)
			for (int j = i + 1; ok && j < q.size(); j++)
				ok &= ask(i, c[i], j, c[j]);

		if (ok)
			ans++;
	} while (nxt(c));

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