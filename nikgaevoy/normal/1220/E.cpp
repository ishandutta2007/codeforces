#include <bits/stdc++.h>


using namespace std;


using ll = long long;
mt19937 mt(736);


void fun(vector<set<int>> &gr, int v, int s)
{
	if (gr[v].size() == 1 && v != s)
	{
		auto tmp = gr[*gr[v].begin()].find(v);

		if (tmp != gr[*gr[v].begin()].end())
		{
			gr[*gr[v].begin()].erase(tmp);

			fun(gr, *gr[v].begin(), s);
		}
	}
}


void dfs(const vector<set<int>> &gr, vector<bool> &used, int v)
{
	if (used[v])
		return;
	used[v] = true;

	for (auto it : gr[v])
		dfs(gr, used, it);
}


ll foo(const vector<set<int>> &gr, const vector<int> &w, const vector<bool> &used, int v)
{
	static vector<ll> dp(gr.size(), -1);

	if (dp[v] == -1)
		dp[v] = used[v] ? 0 : w[v] + foo(gr, w, used, *gr[v].begin());

	return dp[v];
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, m;

	cin >> n >> m;

	vector<int> w(n);

	for (auto &it : w)
		cin >> it;

	vector<set<int>> gr(n);

	for (int i = 0; i < m; i++)
	{
		int a, b;

		cin >> a >> b;
		a--;
		b--;

		gr[a].insert(b);
		gr[b].insert(a);
	}

	int s;

	cin >> s;
	s--;

	vector<bool> cc(n);

	dfs(gr, cc, s);

	for (int i = 0; i < n; i++)
		fun(gr, i, s);

	vector<bool> used(n);

	dfs(gr, used, s);

	ll ans = 0;

	for (int i = 0; i < n; i++)
		if (used[i])
			ans += w[i];

	ll add = 0;

	for (int i = 0; i < n; i++)
		if (cc[*gr[i].begin()])
			add = max(add, foo(gr, w, used, i));

	cout << ans + add << endl;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed;

#ifdef LOCAL
	ifstream fin("../input.txt");

	solve(fin);

	cout << setprecision(4);
	cout << "clock: " << clock() / (double) CLOCKS_PER_SEC << endl;
#else
	solve();
#endif

	return 0;
}