#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


constexpr array<int, 4> dy = {1, -1, 0, 0},
		dx = {0, 0, -1, 1};


void dfs(const vector<vector<int>> &gr, vector<bool> &used, int v, vector<int> &ord)
{
	if (used[v])
		return;
	used[v] = true;

	for (auto it : gr[v])
		dfs(gr, used, it, ord);
	ord.push_back(v);
}


void scc(const vector<vector<int>> &gr, vector<int> &col, int v, int c)
{
	if (col[v] != -1)
		return;
	col[v] = c;

	for (auto it : gr[v])
		scc(gr, col, it, c);
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, m;

	cin >> n >> m;

	vector<string> matr(n);

	for (auto &row : matr)
		cin >> row;

	vector<int> arr(m);

	for (auto &it : arr)
		cin >> it;

	vector<int> top(m), bot(m);

	for (int j = 0; j < top.size(); j++)
		while (top[j] < n && matr[top[j]][j] != '#')
			top[j]++;

	bot = top; // f1

	auto conv = [&](int x, int y)
	{
		return y * m + x;
	};
	auto inside = [&](int x, int y)
	{
		return 0 <= y && y < n && 0 <= x && x < m;
	};

	vector<vector<int>> gr(n * m);

	for (int y = 0; y < n; y++)
		for (int x = 0; x < m; x++)
		{
			for (int j = 0; j < (matr[y][x] == '#' ? (int) dx.size() : 1); j++)
			{
				auto nx = x + dx[j];
				auto ny = y + dy[j];

				if (inside(nx, ny))
					gr[conv(x, y)].push_back(conv(nx, ny));
			}
		}

	vector<vector<int>> rg(gr.size());

	for (int i = 0; i < gr.size(); i++)
		for (int j : gr[i])
			rg[j].push_back(i);

	vector<int> ord;
	ord.reserve(gr.size());
	vector<bool> used(gr.size());

	for (int i = 0; i < gr.size(); i++)
		dfs(gr, used, i, ord);

	vector<int> col(gr.size(), -1);

	reverse(ord.begin(), ord.end());

	for (auto it : ord)
		scc(rg, col, it, it);

	vector<pair<int, int>> edges;

	for (int i = 0; i < gr.size(); i++)
		for (auto j : gr[i])
			if (col[i] != col[j])
				edges.emplace_back(col[i], col[j]);

	sort(edges.begin(), edges.end());
	edges.erase(unique(edges.begin(), edges.end()), edges.end());

	vector<vector<int>> sccgr(gr.size());
	vector<int> deg(sccgr.size());

	for (auto[a, b] : edges)
	{
		sccgr[a].push_back(b);
		deg[b]++;
	}

	vector<bool> is_marked(sccgr.size());

	for (int i = 0; i < m; i++)
		if (bot[i] < n)
			is_marked[col[conv(i, bot[i])]] = true;

	vector<int> bad;

	for (int j = 0; j < sccgr.size(); j++)
		if (!is_marked[j] && deg[j] == 0)
			bad.push_back(j);

	while (!bad.empty())
	{
		auto q = bad.back();
		bad.pop_back();

		for (auto it : sccgr[q])
			if (--deg[it] == 0 && !is_marked[it])
				bad.push_back(it);
	}

	int ans = 0;

	for (int i = 0; i < deg.size(); i++)
		if (deg[i] == 0 && is_marked[i])
			ans++;

	cout << ans << endl;
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