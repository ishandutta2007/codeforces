#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);

constexpr int inf = numeric_limits<int>::max() / 2;


int dfs(vector<vector<int>> &gr, const vector<bool> &bad, vector<int> &dist, int v)
{
	if (bad[v])
		dist[v] = 0;
	else
		dist[v] = inf;

	for (auto &it : gr[v])
	{
		gr[it].erase(ranges::find(gr[it], v));

		dist[v] = min(dist[v], dfs(gr, bad, dist, it) + 1);
	}

	return dist[v];
}


int foo(const vector<vector<int>> &gr, const vector<int> &dist, int v, int d = 0)
{
	if (dist[v] <= d)
		return 1;
	if (gr[v].empty())
		return inf;

	int ans = 0;

	for (auto it : gr[v])
		ans = min(ans + foo(gr, dist, it, d + 1), inf);

	return ans;
}


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, k;

	cin >> n >> k;

	vector<bool> bad(n);

	for (auto it : ranges::iota_view(0, k))
	{
		int t;

		cin >> t;
		t--;

		bad[t] = true;
	}

	vector<vector<int>> gr(n);

	for (auto it : ranges::iota_view(1, n))
	{
		int a, b;

		cin >> a >> b;
		a--;
		b--;

		gr[a].push_back(b);
		gr[b].push_back(a);
	}

	vector<int> dist(n, -1);

	dfs(gr, bad, dist, 0);

	auto ans = foo(gr, dist, 0);

	cout << (ans == inf ? -1 : ans) << endl;
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int t;

	cin >> t;

	for (auto it : ranges::iota_view(0, t))
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

	cout << setprecision((int)floor(log10(chrono::steady_clock::duration::period::den)));
	cout << "clock: " << chrono::duration<double>(chrono::steady_clock::now() - st).count() << endl;
#else
	solve();
#endif

	return 0;
}