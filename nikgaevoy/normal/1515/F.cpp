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


void dfs(const vector<vector<pair<int, int>>> &gr, vector<pair<int, int>> &par, vector<bool> &used,
         vector<int> &dep, int v, int p = -1, int ind = -1, int d = 0)
{
	if (used[v])
		return;
	used[v] = true;

	dep[v] = d;
	par[v] = {p, ind};

	for (auto[it, ind] : gr[v])
		dfs(gr, par, used, dep, it, v, ind, d + 1);
}


template<class T>
void updown(const vector<vector<pair<int, int>>> &gr, T &cc, vector<bool> &used,
            const vector<pair<int, int>> &par, vector<int> &ans, int v)
{
	if (used[v])
		return;
	used[v] = true;

	if (par[v].first != -1 && cc.get_class(par[v].first) != cc.get_class(v))
	{
		ans.push_back(par[v].second);
		cc.unite(v, par[v].first);
	}

	for (auto[it, ind] : gr[v])
		updown(gr, cc, used, par, ans, it);
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, m, x;

	cin >> n >> m >> x;

	vector<ll> asp(n);

	for (auto &it : asp)
		cin >> it;

	if (accumulate(asp.begin(), asp.end(), 0ll) < x * (n - 1ll))
	{
		cout << "NO" << endl;

		return;
	}

	cout << "YES" << endl;

	vector<vector<pair<int, int>>> gr(n);
	vector<pair<int, int>> edges(m);

	for (int i = 0; i < edges.size(); i++)
	{
		auto &it = edges[i];

		cin >> it.first >> it.second;
		it.first--;
		it.second--;

		gr[it.first].emplace_back(it.second, i);
		gr[it.second].emplace_back(it.first, i);
	}

	auto merge_asphalt = [&asp, x](int a, int b)
	{
		assert(asp[a] + asp[b] >= x);

		asp[a] += asp[b] - x;
		asp[b] = 0;
	};

	vector<pair<int, int>> par(n);
	vector<bool> used(n);
	vector<int> dep(n), root(n);

	dfs(gr, par, used, dep, 0);
	iota(root.begin(), root.end(), 0);

	auto merge_root = [&dep, &root](int a, int b)
	{
		if (dep[b] < dep[a])
		{
			dep[a] = dep[b];
			root[a] = root[b];
		}
	};

	dsu cc(n, merge_asphalt, merge_root);

	vector<int> ans;
	ans.reserve(n - 1);

	vector<bool> conn(n);
	conn[0] = true;

	for (int i = 0; i < n; i++)
	{
		int v = i;

		while (!conn[v] && asp[cc.get_class(par[v].first)] + asp[cc.get_class(v)] >= x)
		{
			ans.push_back(par[v].second);
			cc.unite(v, par[v].first);
			conn[v] = true;

			v = root[cc.get_class(v)];
		}
	}

	fill(used.begin(), used.end(), false);

	updown(gr, cc, used, par, ans, 0);

	assert(ans.size() == n - 1);

	for (auto it : ans)
		cout << it + 1 << '\n';
}


void gen(ostream &cout = std::cout)
{
	const int n = 5;
	const int m = n - 1;
	const int x = 2;

	cout << n << ' ' << m << ' ' << x << endl;

	vector<int> q = {0, x * (n - 1ll)};

	uniform_int_distribution<int> col(q[0], q[1]);

	for (int i = 0; i < n - 1; i++)
		q.push_back(col(mt));

	sort(q.begin(), q.end());

	assert(q.size() == n + 1);

	for (int i = 1; i < q.size(); i++)
		cout << q[i] - q[i - 1] << ' ';
	cout << endl;

	for (int i = 1; i < n; i++)
		cout << uniform_int_distribution{1, i}(mt) << ' ' << i + 1 << endl;
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