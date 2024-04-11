#include <bits/stdc++.h>


using namespace std;


using ll = long long;


mt19937 mt(736);


class dsu
{
	vector<int> siz, par;

public:
	dsu(int n) : siz(n, 1), par(n, -1)
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

		if (siz[a] < siz[b])
			swap(a, b);

		par[b] = a;
		siz[a] += siz[b];

		return true;
	}
};


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, m, a, b;

	cin >> n >> m >> a >> b;
	a--;
	b--;

	vector<pair<int, int>> edges(m);

	for (auto &it : edges)
	{
		cin >> it.first >> it.second;
		it.first--;
		it.second--;
	}

	dsu comp(n);

	for (auto it : edges)
		if (it.first != a && it.second != a && it.first != b && it.second != b)
			comp.unite(it.first, it.second);

	vector<bool> ca(n), cb(n), used;

	for (auto it : edges)
		if (it.first == a || it.second == a)
			ca[comp.get_par(it.first)] = ca[comp.get_par(it.second)] = true;
	for (auto it : edges)
		if (it.first == b || it.second == b)
			cb[comp.get_par(it.first)] = cb[comp.get_par(it.second)] = true;

	int ap = 0, bp = 0;

	for (int i = 0; i < n; i++)
	{
		int c = comp.get_par(i);

		assert(ca[c] || cb[c]);

		if (c != a && c != b)
		{
			if (!cb[c])
				ap++;
			if (!ca[c])
				bp++;
		}
	}

	cout << ap * (ll) bp << '\n';
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int t;

	cin >> t;

	for (int i = 0; i < t; i++)
		solve_test(cin, cout);
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed;

#ifdef LOCAL
	auto st = clock();

	ifstream fin("../input.txt");

	solve(fin);

	cout << "clock: " << setprecision(4) << (clock() - st) / (double) CLOCKS_PER_SEC << endl;
#else
	solve();
#endif

	return 0;
}