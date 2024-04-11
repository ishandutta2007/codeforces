#include <bits/stdc++.h>

#include <utility>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


template<int mod>
class modulo
{
	int x;

public:
	explicit modulo(int x = 0) : x(x)
	{}

	auto operator*(const modulo<mod> &oth) const
	{
		return modulo<mod>(x * (ll) oth.x % mod);
	}


	auto &operator+=(const modulo<mod> &oth)
	{
		x += oth.x;

		if (x >= mod)
			x -= mod;

		return *this;
	}


	auto operator+(const modulo<mod> &oth) const
	{
		auto tmp = *this;
		tmp += oth;

		return tmp;
	}


	auto operator==(const modulo<mod> &oth) const
	{
		return x == oth.x;
	}


	auto operator!=(const modulo<mod> &oth) const
	{
		return x != oth.x;
	}


	static modulo Fermat(int pw)
	{
		static vector<modulo> dp = {modulo<mod>(2)};

		while (pw >= dp.size())
			dp.push_back(dp.back() * dp.back());

		return dp[pw];
	}


	explicit operator int() const
	{
		return x;
	}
};


template<int... mods>
class pst
{
	template<size_t ...t>
	static auto merge(int dep, tuple<modulo<mods>...> a, tuple<modulo<mods>...> b, index_sequence<t...>)
	{
		((get<t>(a) += get<t>(b) * tuple_element_t<t, decltype(b)>::Fermat(dep - 1)), ...);

		return a;
	}


	struct node
	{
		using nodeptr = shared_ptr<node>;
		tuple<modulo<mods>...> hashes;

		nodeptr l, r;

		explicit node(int x...) : hashes(modulo<mods>(x)...), l(nullptr), r(nullptr)
		{}

		explicit node(int dep, const nodeptr &l, const nodeptr &r) :
				hashes(merge(dep, get_hashes(l), get_hashes(r), make_index_sequence<sizeof...(mods)>{})), l(l), r(r)
		{}
	};

	using nodeptr = typename node::nodeptr;

	nodeptr root;
	int dep;

	template<int x>
	static auto pst_gen(int dep)
	{
		static vector<nodeptr> dp = {make_shared<node>((mods, x)...)};

		while (dep >= dp.size())
			dp.push_back(make_shared<node>(dp.size(), dp.back(), dp.back()));

		return dp[dep];
	}


	static auto get_hashes(const nodeptr &root)
	{
		if (root == nullptr)
			return decltype(root->hashes){};
		return root->hashes;
	}


	static bool cmp(const nodeptr &a, const nodeptr &b, int dep)
	{
		if (dep == 0)
		{
			assert(a->l == nullptr && b->l == nullptr);
			return int(get<0>(a->hashes)) < int(get<0>(b->hashes));
		}
		assert(a->l != nullptr && b->l != nullptr);
		if (get_hashes(a->r) == get_hashes(b->r))
			return cmp(a->l, b->l, dep - 1);
		return cmp(a->r, b->r, dep - 1);
	}


	static pair<nodeptr, bool> add(const nodeptr &root, size_t wh, int dep)
	{
		if (dep == 0)
		{
			assert(root->l == nullptr);
			if (int(get<0>(root->hashes)) == 0)
				return {pst_gen<1>(0), false};
			return {pst_gen<0>(0), true};
		}

		if (wh == 0 && get_hashes(root) == get_hashes(pst_gen<1>(dep)))
			return {pst_gen<0>(dep), true};

		assert(root->l != nullptr);

		auto lp = root->l;
		size_t tsz = (1u << (dep - 1));

		if (wh < tsz)
		{
			auto[ll, carry] = add(root->l, wh, dep - 1);

			if (!carry)
				return {make_shared<node>(dep, ll, root->r), false};
			wh = tsz;
			lp = ll;
		}

		auto[rr, carry] = add(root->r, wh - tsz, dep - 1);

		return {make_shared<node>(dep, lp, rr), carry};
	}

	pst(int dep, nodeptr root) : dep(dep), root(std::move(root))
	{}


	static void output(ostream &cout, const nodeptr &root, int dep)
	{
		if (dep != 0)
		{
			output(cout, root->l, dep - 1);
			output(cout, root->r, dep - 1);
		}
		else
			cout << int(get<0>(root->hashes));
	}

public:
	explicit pst(int dep = 0) : dep(dep), root(pst_gen<0>(dep))
	{}

	[[nodiscard]] auto get_hashes() const
	{
		return get_hashes(root);
	}

	bool operator==(const pst &other) const
	{
		return get_hashes() == other.get_hashes();
	}

	bool operator!=(const pst &other) const
	{
		return get_hashes() != other.get_hashes();
	}

	bool operator<(const pst &other) const
	{
		if (*this == other)
			return false;
		return cmp(root, other.root, dep);
	}


	pst operator+(size_t wh) const
	{
		auto[nr, carry] = add(root, wh, dep);
		assert(!carry);
		return pst(dep, nr);
	}

	template<int ...pmods>
	friend ostream &operator<<(ostream &cout, const pst<pmods...> &t);
};


template<int ...mods>
ostream &operator<<(ostream &cout, const pst<mods...> &t)
{
	t.output(cout, t.root, t.dep);

	return cout;
}


template<class T>
using minheap = priority_queue<T, vector<T>, greater<T>>;

using weight = pst<
		(int) 1e9 + 7, (int) 1e9 + 9, 998244353, 999999757, 999999761, 999999883, 999999893, 999999929, 999999937>;


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, m;

	cin >> n >> m;

	vector<vector<pair<int, int>>> gr(n);

	for (int i = 0; i < m; i++)
	{
		int a, b, x;

		cin >> a >> b >> x;
		a--;
		b--;

		gr[b].emplace_back(a, x);
		gr[a].emplace_back(b, x);
	}

	int s, t;

	cin >> s >> t;
	s--;
	t--;

	minheap<tuple<weight, int, int>> pq;
	pq.emplace(weight(17), s, s);

	vector<weight> dist(n);
	vector<int> par(n, -1);

	while (!pq.empty())
	{
		auto[d, v, p] = pq.top();
		pq.pop();

		if (par[v] == -1)
		{
			par[v] = p;
			dist[v] = d;

			for (auto[u, w] : gr[v])
				pq.emplace(d + w, u, v);
		}
	}

	if (par[t] == -1)
	{
		cout << -1 << endl;

		return;
	}

	cout << int(get<0>(dist[t].get_hashes())) << endl;

	vector<int> path = {t};

	while (path.back() != s)
		path.push_back(par[path.back()]);
	reverse(path.begin(), path.end());

	cout << path.size() << endl;

	for (auto it : path)
		cout << it + 1 << ' ';
	cout << endl;
}


void gen(ostream &cout = std::cout)
{
	const int n = 1e5, m = 1e5 - 1;

	cout << n << ' ' << m << endl;

	uniform_int_distribution<int> uid(1, n), w(1e5, 1e5);

	for (int i = 0; i < m; i++)
		cout << i + 1 << ' ' << i + 2 << ' ' << w(mt) << endl;

	cout << uid(mt) << ' ' << uid(mt) << endl;
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

	stringstream ss;

	gen(ss);

	solve(ss);

	cout << setprecision((int) floor(log10(chrono::steady_clock::duration::period::den)));
	cout << "clock: " << chrono::duration<double>(chrono::steady_clock::now() - st).count() << endl;
#else
	solve();
#endif

	return 0;
}