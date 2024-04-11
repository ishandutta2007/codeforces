#include <bits/stdc++.h>

using namespace std;

using ll = long long;

mt19937 mt(736);


int build(vector<vector<int>> &gr, vector<int> &siz, int v)
{
	siz[v] = 1;

	for (auto &it : gr[v])
	{
		gr[it].erase(find(gr[it].begin(), gr[it].end(), v));

		siz[v] += build(gr, siz, it);
	}

	return siz[v];
}


ll foo(const vector<vector<int>> &gr, const vector<int> &siz, int a, int b)
{
	static vector<vector<ll>> dp(gr.size(), vector<ll>(gr.size(), -1));

	if (a < b)
		swap(a, b);

	if (dp[a][b] == -1)
	{
		ll ans = 0;

		for (auto it : gr[a])
		{
			ll val = siz[it] * (ll) siz[b];

			ans = max(ans, val + foo(gr, siz, it, b));
		}

		for (auto it : gr[b])
		{
			ll val = siz[it] * (ll) siz[a];

			ans = max(ans, val + foo(gr, siz, a, it));
		}

		dp[a][b] = ans;
	}

	return dp[a][b];
}


ll dfs(vector<vector<int>> &gr, vector<int> &siz, int v, int par = -1)
{
	ll best = 0;

	for (int i = 0; i < gr[v].size(); i++)
		if (gr[v][i] != par)
		{
			auto tmp = gr[v][i];

			swap(gr[v].back(), gr[v][i]);
			gr[v].pop_back();
			siz[v] -= siz[tmp];

			best = max(best, siz[v] * (ll) siz[tmp] + foo(gr, siz, v, tmp));

			siz[tmp] += siz[v];
			gr[tmp].push_back(v);
			best = max(best, dfs(gr, siz, tmp, v));
			gr[tmp].pop_back();
			siz[tmp] -= siz[v];

			gr[v].push_back(tmp);
			swap(gr[v].back(), gr[v][i]);
			siz[v] += siz[tmp];
		}

	return best;
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<vector<int>> gr(n);

	for (int i = 1; i < n; i++)
	{
		int a, b;

		cin >> a >> b;
		a--;
		b--;

		gr[a].push_back(b);
		gr[b].push_back(a);
	}

	vector<int> siz(n);

	build(gr, siz, 0);

	cout << dfs(gr, siz, 0) << endl;
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

	cout << "clock: " << (clock() - st) / (double) CLOCKS_PER_SEC << endl;
#else
	solve();
#endif

	return 0;
}