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

	void emplace_back()
	{
		par.push_back(-1);
		siz.push_back(1);
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
	int q;

	cin >> q;

	auto trans = vector<int>((int) 5e5 + 1, -1);
	vector<int> val;

	auto mrg = [&](int a, int b)
	{
		trans[val[b]] = -1;
		trans[val[a]] = a;
		val[b] = val[a];
	};

	dsu slv(0, mrg);

	for (auto query: ranges::iota_view(0, q))
	{
		int type;

		cin >> type;

		if (type == 1)
		{
			int x;

			cin >> x;

			val.push_back(x);
			slv.emplace_back();
			if (trans[x] != -1)
				slv.unite(trans[x], ssize(val) - 1);
			else
				trans[x] = ssize(val) - 1;
		}
		else
		{
			assert(type == 2);

			int x, y;

			cin >> x >> y;

			if (x != y)
			{
				if (trans[x] != -1 && trans[y] != -1)
					slv.unite(trans[x], trans[y]);

				if (trans[x] != -1)
				{
					val[slv.get_class(trans[x])] = y;
					trans[y] = trans[x];
					trans[x] = -1;
				}
			}
		}
	}

	for (auto it: ranges::iota_view(0, ssize(val)))
		cout << val[slv.get_class(it)] << ' ';
	cout << '\n';
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