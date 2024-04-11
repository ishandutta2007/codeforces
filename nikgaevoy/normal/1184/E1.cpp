#include <bits/stdc++.h>


using namespace std;


using ll = long long;
mt19937 mt(736);


template<class T>
T &remin(T &x, T y)
{
	return x = min(x, y);
}


template<class T>
T &remax(T &x, T y)
{
	return x = max(x, y);
}


class dsu
{
	vector<int> par, siz;

public:
	dsu(int n) : par(n, -1), siz(n, 1)
	{}


	int get_par(int v)
	{
		return par[v] == -1 ? v : par[v] = get_par(par[v]);
	}


	bool unite(int a, int b)
	{
		a = get_par(a);
		b = get_par(b);

		if (a == b)
			return false;

		uniform_int_distribution<int> uid(0, siz[a] + siz[b] - 1);

		if (uid(mt) < siz[a])
		{
			par[b] = a;
			siz[a] += siz[b];
		}
		else
		{
			par[a] = b;
			siz[b] += siz[a];
		}

		return true;
	}
};


void dfs(vector<vector<pair<int, int>>> &gr, int v = 0)
{
	for (auto it : gr[v])
	{
		gr[it.first].erase(find(gr[it.first].begin(), gr[it.first].end(), pair<int, int>{v, it.second}));

		dfs(gr, it.first);
	}
}


void build(const vector<vector<pair<int, int>>> &gr, vector<vector<pair<int, int>>> &bup,
           vector<vector<pair<int, int>>> &bupw, vector<int> &dep, int v = 0)
{
	if (!bup[v].empty())
	{
		while (bup[bup[v].back().first].size() >= bup[v].size())
		{
			auto &add = bup[bup[v].back().first][bup[v].size() - 1];
			bupw[v].emplace_back(add.first, numeric_limits<int>::max());
			bup[v].emplace_back(add.first, max(bup[v].back().second, add.second));
		}
	}

	for (auto it : gr[v])
	{
		dep[it.first] = dep[v] + 1;
		bup[it.first].emplace_back(v, it.second);
		bupw[it.first].emplace_back(v, numeric_limits<int>::max());

		build(gr, bup, bupw, dep, it.first);
	}
}


int lca(const vector<vector<pair<int, int>>> &bup, const vector<int> &dep, int a, int b)
{
	if (dep[a] < dep[b])
		swap(a, b);

	int pos = numeric_limits<int>::max();
	int ans = 0;

	while (dep[a] != dep[b])
	{
		pos = min(pos, (int) bup[a].size() - 1);

		if (dep[bup[a][pos].first] < dep[b])
			pos--;
		else
		{
			ans = max(ans, bup[a][pos].second);
			a = bup[a][pos].first;
		}
	}

	pos = numeric_limits<int>::max();

	while (a != b)
	{
		pos = min(pos, (int) bup[a].size() - 1);

		if (pos != 0 && bup[a][pos].first == bup[b][pos].first)
			pos--;
		else
		{
			ans = max(ans, bup[a][pos].second);
			a = bup[a][pos].first;
			ans = max(ans, bup[b][pos].second);
			b = bup[b][pos].first;
		}
	}

	return ans;
}


void lcaw(vector<vector<pair<int, int>>> &bup, const vector<int> &dep, int a, int b, int val)
{
	if (dep[a] < dep[b])
		swap(a, b);

	int pos = numeric_limits<int>::max();

	while (dep[a] != dep[b])
	{
		pos = min(pos, (int) bup[a].size() - 1);

		if (dep[bup[a][pos].first] < dep[b])
			pos--;
		else
		{
			bup[a][pos].second = min(bup[a][pos].second, val);
			a = bup[a][pos].first;
		}
	}

	pos = numeric_limits<int>::max();

	while (a != b)
	{
		pos = min(pos, (int) bup[a].size() - 1);

		if (pos != 0 && bup[a][pos].first == bup[b][pos].first)
			pos--;
		else
		{
			bup[a][pos].second = min(bup[a][pos].second, val);
			a = bup[a][pos].first;
			bup[b][pos].second = min(bup[b][pos].second, val);
			b = bup[b][pos].first;
		}
	}
}


void relax(const vector<vector<pair<int, int>>> &tr, vector<vector<pair<int, int>>> &bup, int v = 0)
{
	for (auto it : tr[v])
		relax(tr, bup, it.first);

	while (bup[v].size() > 1)
	{
		int q = bup[v].back().second;

		bup[v].pop_back();
		remin(bup[v].back().second, q);
		remin(bup[bup[v].back().first][bup[v].size() - 1].second, q);
	}
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, m;

	cin >> n >> m;

	vector<tuple<int, int, int, int>> edges(m);

	for (int i = 0; i < m; i++)
	{
		auto &it = edges[i];

		int a, b, w;

		cin >> a >> b >> w;

		a--;
		b--;

		it = {w, a, b, i};
	}

	auto edges_s = edges;
	sort(edges_s.begin(), edges_s.end());

	set<int> mst;

	dsu Kr(n);

	for (auto it : edges_s)
		if (Kr.unite(get<1>(it), get<2>(it)))
			mst.insert(get<3>(it));

	vector<vector<pair<int, int>>> tr(n);

	for (auto it : mst)
	{
		tr[get<1>(edges[it])].emplace_back(get<2>(edges[it]), get<0>(edges[it]));
		tr[get<2>(edges[it])].emplace_back(get<1>(edges[it]), get<0>(edges[it]));
	}

	dfs(tr);

	vector<vector<pair<int, int>>> bup(n), bupw(n);
	vector<int> dep(n);

	build(tr, bup, bupw, dep);

	vector<int> ans(m);

	for (auto it : edges)
		if (!mst.count(get<3>(it)))
		{
			ans[get<3>(it)] = lca(bup, dep, get<1>(it), get<2>(it));
			lcaw(bupw, dep, get<1>(it), get<2>(it), get<0>(it));
		}

	relax(tr, bupw);

	for (auto it : mst)
	{
		int a = get<1>(edges[it]);
		int b = get<2>(edges[it]);

		if (dep[a] < dep[b])
			swap(a, b);

		ans[it] = bupw[a].front().second;
	}

	ans.resize(1);

	for (auto it : ans)
		cout << min(it, (int) 1e9) << '\n';
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