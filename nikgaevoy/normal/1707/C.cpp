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
	explicit dsu(int n, Types ... args) : par(n, -1), siz(n, 1), items(args...)
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

struct sblifts
{
private:
	vector<int> par;
	vector<int> dep;
	vector<int> jump;
	vector<pair<int, int>> tim;
	vector<int> bal;

	void build(const vector<vector<int>> &gr, int &t, int v = 0, int p = 0, int d = 0)
	{
		tim[v].first = t++;
		dep[v] = d;
		par[v] = p;

		auto pj = jump[p];
		auto pjj = jump[pj];

		jump[v] = dep[p] + dep[pjj] == 2 * dep[pj] ? pjj : p;

		for (auto it: gr[v])
			if (it != p)
				build(gr, t, it, v, d + 1);

		tim[v].second = t;
	}


	void dfs(const vector<vector<int>> &gr, string &ans, int v = 0, int p = 0, int ps = 0)
	{
		ps += bal[v];

		if (ps > 0)
			ans[v] = '0';

		for (auto it: gr[v])
			if (it != p)
				dfs(gr, ans, it, v, ps);
	}

public:
	sblifts() = default;

	explicit sblifts(const vector<vector<int>> &gr) : par(gr.size()), dep(gr.size()), jump(gr.size()), tim(gr.size()),
	                                                  bal(gr.size())
	{
		int t = 0;

		build(gr, t);

		assert(t == gr.size());
	}

	[[nodiscard]] bool is_ancestor(int a, int b) const
	{
		return tim[a].first <= tim[b].first && tim[b].second <= tim[a].second;
	}

	template<class F>
	int lower_bound(int v, F &&fn) const
	{
		while (true)
		{
			if (fn(jump[v]))
				v = jump[v];
			else if (fn(par[v]))
				v = par[v];
			else
				break;
		}

		return v;
	}


	[[nodiscard]] int lca(int a, int b) const
	{
		a = almost_lca(a, b);

		if (!is_ancestor(a, b))
			a = par[a];

		return a;
	}


	[[nodiscard]] int almost_lca(int a, int b) const
	{
		a = lower_bound(a, [&](int v)
		{
			return !is_ancestor(v, b);
		});

		return a;
	}


	void mark_bad(int a, int b)
	{
		auto l = lca(a, b);

		if (l != a && l != b)
		{
			bal[0]++;
			bal[a]--;
			bal[b]--;
		}
		else
		{
			auto la = almost_lca(a, b);
			auto lb = almost_lca(b, a);

			bal[la]++;
			bal[a]--;
			bal[lb]++;
			bal[b]--;
		}
	}

	string get_bad(const vector<vector<int>> &tr)
	{
		string ans(tr.size(), '1');

		dfs(tr, ans);

		return ans;
	}
};


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, m;

	cin >> n >> m;

	vector<pair<int, int>> edges(m);

	dsu Kr(n);

	vector<vector<int>> tr(n);
	vector<pair<int, int>> bad;

	for (auto &[a, b]: edges)
	{
		cin >> a >> b;
		a--;
		b--;

		if (Kr.unite(a, b))
		{
			tr[a].push_back(b);
			tr[b].push_back(a);
		}
		else
			bad.emplace_back(a, b);
	}

	sblifts sbl(tr);

	for (auto [a, b]: bad)
		sbl.mark_bad(a, b);

	cout << sbl.get_bad(tr) << endl;
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int t = 1;

	for (int i = 0; i < t; i++)
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