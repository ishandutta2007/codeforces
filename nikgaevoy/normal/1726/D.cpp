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


void dfs(vector<vector<pair<int, int>>> &gr, vector<int> &par, vector<int> &dep, int v, int d = 0)
{
	dep[v] = d;

	for (auto &[u, i]: gr[v])
	{
		gr[u].erase(find(gr[u].begin(), gr[u].end(), pair{v, i}));
		par[u] = i;
		dfs(gr, par, dep, u, d + 1);
	}
}


void dfs(const vector<vector<int>> &gr, vector<bool> &used, int v)
{
	if (used[v])
		return;
	used[v] = true;

	for (auto it: gr[v])
		dfs(gr, used, it);
}


int get_ans(int n, const vector<pair<int, int>> &edges, const vector<bool> &col)
{
	vector<vector<int>> gr(n);
	vector<bool> used(n);

	for (auto i: ranges::iota_view(0, ssize(edges)))
		if (col[i])
		{
			auto [a, b] = edges[i];

			gr[a].push_back(b);
			gr[b].push_back(a);
		}

	int res = 0;

	for (auto i: ranges::iota_view(0, ssize(gr)))
		if (!used[i])
		{
			res++;

			dfs(gr, used, i);
		}

	gr.assign(gr.size(), {});
	used.assign(used.size(), false);

	for (auto i: ranges::iota_view(0, ssize(edges)))
		if (!col[i])
		{
			auto [a, b] = edges[i];

			gr[a].push_back(b);
			gr[b].push_back(a);
		}

	for (auto i: ranges::iota_view(0, ssize(gr)))
		if (!used[i])
		{
			res++;

			dfs(gr, used, i);
		}

	return res;
}


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, m;

	cin >> n >> m;

	vector<pair<int, int>> edges(m);

	dsu Kr(n);

	vector<bool> col(m);
	vector<int> blue;

	vector<vector<pair<int, int>>> gr(n);

	for (auto i: ranges::iota_view(0, ssize(edges)))
	{
		auto &[a, b] = edges[i];

		cin >> a >> b;
		a--;
		b--;

		col[i] = Kr.unite(a, b);

		if (!col[i])
		{
			blue.push_back(i);
		}
		else
		{
			gr[a].emplace_back(b, i);
			gr[b].emplace_back(a, i);
		}
	}

	vector<int> par(n, -1), dep(n);

	dfs(gr, par, dep, n - 1);

	assert(blue.size() <= 3);

	if (blue.size() == 3)
	{
		set<int> tr;

		for (auto j: blue)
		{
			tr.insert(edges[j].first);
			tr.insert(edges[j].second);
		}

		assert(tr.size() >= 3);

		if (tr.size() == 3)
		{
			auto it = *tr.begin();

			for (auto q: tr)
				if (dep[q] > dep[it])
					it = q;

			assert(par[it] != -1);

			for (auto j: blue)
				if (edges[j].first == it || edges[j].second == it)
				{
					assert(!col[j]);
					col[j] = true;

					break;
				}

			assert(col[par[it]]);
			col[par[it]] = false;
		}
	}

	assert(get_ans(n, edges, col) == 2 * n - m);

	for (auto it: col)
		cout << (it ? '1' : '0');
	cout << '\n';
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int t = 1;

	cin >> t;

	for (int i = 0; i < t; i++)
		solve_test(cin, cout);
}


void gen(ostream &cout = std::cout)
{
	cout << 1 << endl;

	const int n = uniform_int_distribution{2, 20}(mt);
	const int m = uniform_int_distribution{n - 1, min(n + 2, n * (n - 1) / 2)}(mt);

	cout << n << ' ' << m << endl;

	set<pair<int, int>> edges;

	for (int i = 1; i < n; i++)
		edges.emplace(uniform_int_distribution{0, i - 1}(mt), i);

	uniform_int_distribution<int> uid(0, n - 1);

	while (edges.size() < m)
	{
		int a = 0, b = 0;

		while (a == b)
		{
			a = uid(mt);
			b = uid(mt);
		}

		if (b < a)
			swap(a, b);

		edges.emplace(a, b);
	}

	for (auto [a, b]: edges)
		cout << a + 1 << ' ' << b + 1 << endl;
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

#ifdef STRESS
	for (int cnt = 1;; cnt++)
	{
		stringstream ss, in1, out1, in2, out2;

		gen(ss);

		in1 << ss.str();
		in2 << ss.str();

//		cout << ss.str() << endl;

		solve(in1, out1);
//		solve(in2, out2);
//
//		if (out1.str() != out2.str())
//		{
//			cout << "fail: " << cnt << endl;
//			cout << ss.str() << endl;
//			cout << "solve:" << endl;
//			cout << out1.str() << endl;
//			cout << "stress:" << endl;
//			cout << out2.str() << endl;
//
//			break;
//		}
//		else if (cnt % 100 == 0)
		cout << "ok: " << cnt << endl;
	}
#endif

	cout << setprecision((int) floor(log10(chrono::steady_clock::duration::period::den)));
	cout << "clock: " << chrono::duration<double>(chrono::steady_clock::now() - st).count() << endl;
#else
	solve();
#endif

	return 0;
}