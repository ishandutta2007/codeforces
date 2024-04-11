#include <bits/stdc++.h>


using namespace std;


using ll = long long;


mt19937 mt(736);


int best = numeric_limits<int>::max();


void dfs(const vector<vector<int>> &gr, vector<bool> &used, vector<int> &dep, int d, int v, int par = -1)
{
	if (dep[v] != -1)
	{
		best = min(best, d - dep[v]);

		return;
	}

	dep[v] = d;
	used[v] = true;

	for (auto it : gr[v])
		if (it != par)
			dfs(gr, used, dep, d + 1, it, v);

	dep[v] = -1;
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<ll> masks(n);

	for (auto &it : masks)
		cin >> it;

	vector<vector<int>> edges(60);

	vector<pair<int, int>> edg;

	for (int sh = 0; sh < edges.size(); sh++)
		for (int i = 0; i < masks.size(); i++)
			if (masks[i] & (1ll << sh))
				edges[sh].push_back(i);

	for (auto &row : edges)
		if (row.size() > 2)
		{
			cout << 3 << endl;

			return;
		}
		else if (row.size() == 2)
			edg.emplace_back(row[0], row[1]);

	vector<vector<int>> gr(n);

	for (auto it : edg)
	{
		gr[it.first].push_back(it.second);
		gr[it.second].push_back(it.first);
	}

	vector<bool> used(n);
	vector<int> dep(n, -1);

	for (int i = 0; i < gr.size(); i++)
		if (!used[i] && gr[i].size() > 1)
			dfs(gr, used, dep, 0, i);

	cout << (best == numeric_limits<int>::max() ? -1 : best) << endl;
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