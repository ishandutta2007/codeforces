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


ll foo(int n, vector<tuple<int, int, int>> edges, int x)
{
	for (auto &[w, a, b]: edges)
		w = abs(w - x);

	ranges::sort(edges);

	ll ans = 0;

	dsu Kr(n);

	for (auto[w, a, b]: edges)
		if (Kr.unite(a, b))
			ans += w;

	return ans;
}


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, m;

	cin >> n >> m;

	vector<tuple<int, int, int>> edges(m);

	for (auto&[w, u, v]: edges)
	{
		cin >> u >> v >> w;
		u--;
		v--;
	}

	ranges::sort(edges);

	int p, k, a, b, c;

	cin >> p >> k >> a >> b >> c;

	vector<int> quer(p);
	quer.reserve(k);

	for (auto &it: quer)
		cin >> it;

	while (ssize(quer) < k)
		quer.push_back((quer.back() * (ll) a + b) % c);

	vector<pair<int, ll>> mem;

	{
		vector<int> to_ask = {0, (int) 1e8};

		for (auto i: ranges::iota_view(0, ssize(edges)))
			for (auto j: ranges::iota_view(i, ssize(edges)))
			{
				to_ask.push_back(midpoint(get<0>(edges[i]), get<0>(edges[j])));
				to_ask.push_back(to_ask.back() + 1);
			}

		ranges::sort(to_ask);
		to_ask.erase(unique(to_ask.begin(), to_ask.end()), to_ask.end());

		mem.reserve(to_ask.size());

		for (auto it: to_ask)
			mem.emplace_back(it, foo(n, edges, it));
	}

	ll x = 0;

	for (auto q: quer)
	{
		auto nxt = lower_bound(mem.begin(), mem.end(), pair{q, 0ll});

		assert(nxt != mem.end());

		ll ans;

		if (nxt->first == q)
		{
			ans = nxt->second;
		}
		else
		{
			assert(nxt != mem.begin());

			auto prv = nxt;
			prv--;

			auto num = prv->second * (nxt->first - q) + nxt->second * (q - prv->first);
			auto den = nxt->first - prv->first;

			assert(num % den == 0);

			ans = num / den;
		}

		x ^= ans;
	}

	cout << x << '\n';
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int t = 1;

	for (weakly_incrementable auto it: ranges::iota_view(0, t))
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