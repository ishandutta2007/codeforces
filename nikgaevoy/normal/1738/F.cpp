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

	int get_size(int v)
	{
		return siz[get_class(v)];
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

void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<int> deg(n);

	for (auto &it: deg)
		cin >> it;

	vector<int> ord(n);

	iota(ord.begin(), ord.end(), 0);
	ranges::sort(ord.begin(), ord.end(), [&deg](int a, int b)
	{
		return deg[a] > deg[b];
	});

	vector<int> root(ord.size());

	for (int i = 0; i < ssize(ord); i++)
		root[ord[i]] = i;

	auto mrg = [&](int a, int b)
	{
		root[a] = min(root[a], root[b]);
	};

	dsu cc(n, mrg);

	int rem = n;

	auto ask = [&](int v)
	{
		assert(rem-- > 0);

		cout << "? " << v + 1 << endl;

		int t;

		cin >> t;

		return t - 1;
	};

	for (auto it: ord)
		for (int i = 0; ord[root[cc.get_class(it)]] == it && i < deg[it]; i++)
		{
			auto v = ask(it);

			cc.unite(it, v);
		}

	cout << '!';
	for (int i = 0; i < n; i++)
		cout << ' ' << root[cc.get_class(i)] + 1;
	cout << endl;
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int t = 1;

	cin >> t;

	for (int i = 0; i < t; i++)
		solve_test(cin, cout);
}


int main()
{
	cout << fixed;

#ifdef LOCAL
	auto st = chrono::steady_clock::now();

	ifstream fin("../input.txt");

	solve();

#ifdef STRESS
	for (int cnt = 1;; cnt++)
	{
		stringstream ss, in1, out1, in2, out2;

		gen(ss);

		in1 << ss.str();
		in2 << ss.str();

		solve(in1, out1);
		stress(in2, out2);

		if (out1.str() != out2.str())
		{
			cout << "fail: " << cnt << endl;
			cout << ss.str();
			cout << "solve:" << endl;
			cout << out1.str();
			cout << "stress:" << endl;
			cout << out2.str();

			break;
		}
		else if (cnt % 100 == 0)
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