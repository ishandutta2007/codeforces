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


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<tuple<int, int, int>> arr(n * n);

	for (int y = 0; y < n; y++)
		for (int x = 0; x < n; x++)
		{
			int t;

			cin >> t;

			arr[y * n + x] = {t, x, y};
		}

	sort(arr.begin(), arr.end());

	vector<int> par(n, -1), val(n), top(n);

	iota(top.begin(), top.end(), 0);

	for (auto it : arr)
	{
		int v, a, b;

		tie(v, a, b) = it;

		if (a == b)
			val[a] = v;
	}

	int cur = 0;

	auto q = [&](int a, int b)
	{
		par[top[a]] = par.size();
		par[top[b]] = par.size();
		top[a] = par.size();
		par.push_back(-1);
		val.emplace_back(get<0>(arr[cur]));
	};

	dsu<decltype(q)> slv(n, q);

	while (cur < arr.size())
	{
		slv.unite(get<1>(arr[cur]), get<2>(arr[cur]));

		cur++;
	}

	for (int i = 0; i < par.size(); i++)
		if (par[i] != -1)
			assert(val[par[i]] >= val[i]);

	vector<bool> alive(par.size(), true);

	for (int i = (int) par.size() - 1; i >= 0; i--)
		if (par[i] != -1 && val[par[i]] == val[i])
			alive[i] = false;

	function<int(int)> get_par = [&](int v)
	{
		if (alive[v])
			return v;
		return par[v] = get_par(par[v]);
	};

	vector<int> ord;

	for (int i = 0; i < par.size(); i++)
		if (alive[i])
			ord.push_back(i);

	cout << ord.size() << endl;

	for (auto it : ord)
		cout << val[it] << ' ';
	cout << endl;

	for (auto it : ord)
		if (par[it] != -1)
			assert(val[it] < val[get_par(par[it])]);

	cout << lower_bound(ord.begin(), ord.end(), find(par.begin(), par.end(), -1) - par.begin()) - ord.begin() + 1
	     << endl;

	for (int i = 0; i < ord.size(); i++)
		if (par[ord[i]] != -1)
			cout << i + 1 << ' ' << lower_bound(ord.begin(), ord.end(), get_par(par[ord[i]])) - ord.begin() + 1 << endl;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed;

#ifdef LOCAL
	auto st = clock();

	ifstream fin("../input.txt");

	do
	{
		solve(fin);

		cout << "===" << endl;

		string str;
		while (getline(fin, str) && str != string(max(1, (int) str.size()), '='));
	} while (fin);

	cout << setprecision(6) << "clock: " << double(clock() - st) / CLOCKS_PER_SEC << endl;
#else
	solve();
#endif

	return 0;
}