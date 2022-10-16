#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


template<class ... Types>
class dsu
{
	vector<int> par, siz;
	tuple<Types ...> items;

	template<size_t ... t>
	void merge(int a, int b, std::index_sequence<t...>)
	{
		((get<t>(items)(a, b)), ... );
	}

public:
	explicit dsu(size_t n, Types ... args) : par(n, -1), siz(n, 1), items(args...)
	{}

	int get_class(int v)
	{
		return par[v] == -1 ? v : par[v] = get_class(par[v]);
	}

	bool unite(int a, int b)
	{
		a = get_class(a);
		b = get_class(b);

		if (a == b)
			return false;

		if (siz[a] < siz[b])
			swap(a, b);
		siz[a] += siz[b];
		par[b] = a;

		merge(a, b, make_index_sequence<sizeof...(Types)>{});

		return true;
	}
};


template<class T>
auto sqr(const T &x)
{
	return x * x;
}


template<class T>
T &remin(T &x, const T &y)
{
	return x = min(x, y);
}


template<class T>
T &remax(T &x, const T &y)
{
	return x = max(x, y);
}


unsigned solve_small(int m, const vector<vector<pair<int, unsigned>>> &gr)
{
	int all = m * (m - 1) / 2;

	vector<tuple<unsigned, int, int>> edges;

	for (int i = 0; i < gr.size(); i++)
		for (int j = i + 1, wh = 0; j < gr.size(); j++)
		{
			while (wh < gr[i].size() && gr[i][wh].first < j)
				wh++;

			edges.emplace_back((wh < gr[i].size() && gr[i][wh].first == j ? gr[i][wh].second : 0), i, j);
		}

	unsigned x = 0;

	for (auto it : edges)
		x ^= get<0>(it);

	sort(edges.begin(), edges.end());

	dsu Kr(gr.size());

	int rem = all - m;
	ll ans = 0;

	dsu comp(gr.size());

	for (auto[w, a, b] : edges)
		if (Kr.unite(a, b))
		{
			ans += w;

			if (w != 0)
				comp.unite(a, b);
		}
		else if (w == 0)
		{
			x = 0;
		}

	if (x != 0)
	{
		for (auto[w, a, b] : edges)
			if (w != 0 && comp.get_class(a) != comp.get_class(b))
				remin(x, w);
	}

	return ans + x;
}


unsigned solve_large(int m, const vector<vector<pair<int, unsigned>>> &gr)
{
	auto mx = 0;

	while (mx * (gr.size() - mx) <= m)
		mx++;
	mx--;

	vector<int> large, small;

	for (int i = 0; i < gr.size(); i++)
		(gr[i].size() < gr.size() / 2 ? large : small).push_back(i);

	dsu comp(gr.size());

	for (int i = 1; i < large.size(); i++)
		comp.unite(large[i - 1], large[i]);

	for (auto i : small)
		for (int j = 0, wh = 0; j < gr.size(); j++)
		{
			while (wh < gr[i].size() && gr[i][wh].first < j)
				wh++;
			if (wh == gr[i].size() || gr[i][wh].first != j)
				comp.unite(i, j);
		}

	vector<int> classes(gr.size());

	for (int i = 0; i < classes.size(); i++)
		classes[i] = comp.get_class(i);

	sort(classes.begin(), classes.end());
	classes.erase(unique(classes.begin(), classes.end()), classes.end());

	vector<tuple<unsigned, int, int>> edges;

	for (int i = 0; i < gr.size(); i++)
		for (auto[a, w] : gr[i])
			edges.emplace_back(w, comp.get_class(i), comp.get_class(a));

	sort(edges.begin(), edges.end());

	dsu Kr(classes.size());

	ll ans = 0;

	for (auto[w, a, b] : edges)
	{
		a = lower_bound(classes.begin(), classes.end(), a) - classes.begin();
		b = lower_bound(classes.begin(), classes.end(), b) - classes.begin();

		if (Kr.unite(a, b))
			ans += w;
	}

	return ans;
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, m;

	cin >> n >> m;

	vector<vector<pair<int, unsigned>>> gr(n);

	for (int i = 0; i < m; i++)
	{
		int a, b;
		unsigned w;

		cin >> a >> b >> w;
		a--;
		b--;

		gr[a].emplace_back(b, w);
		gr[b].emplace_back(a, w);
	}

	for (auto &row : gr)
		sort(row.begin(), row.end());

	auto ans = (m < sqr(n / 2ll) && m < n * (n - 3ll) / 2 ? solve_large : solve_small)(m, gr);

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