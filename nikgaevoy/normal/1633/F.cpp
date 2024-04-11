#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


int dfs(vector<vector<pair<int, int>>> &gr, vector<int> &siz, int v)
{
	siz[v] = 1;

	for (auto[u, w]: gr[v])
	{
		gr[u].erase(ranges::find(gr[u], pair{v, w}));

		siz[v] += dfs(gr, siz, u);
	}

	return siz[v];
}


template<class T>
constexpr T up(const T &x)
{
	T r = 1;

	while (r < x)
		r *= 2;

	return r;
}


class segtree
{
	vector<ll> arr, val;
	vector<bool> laz;


	void push(int v)
	{
		if (!laz[v])
			return;

		if (v < arr.size() / 2)
		{
			laz[2 * v] = !laz[2 * v];
			laz[2 * v + 1] = !laz[2 * v + 1];
		}

		laz[v] = false;
		arr[v] = val[v] - arr[v];
	}


	void upd(int v)
	{
		push(v);

		if (v < arr.size() / 2)
		{
			push(2 * v);
			push(2 * v + 1);

			arr[v] = arr[2 * v] + arr[2 * v + 1];
		}
	}


	ll segsum(int l, int r, int cl, int cr, int v)
	{
		if (r <= cl || cr <= l)
			return 0;

		push(v);

		if (l <= cl && cr <= r)
			return arr[v];

		auto ct = midpoint(cl, cr);

		auto ans = segsum(l, r, cl, ct, 2 * v) + segsum(l, r, ct, cr, 2 * v + 1);

		upd(v);

		return ans;
	}

	void seginv(int l, int r, int cl, int cr, int v)
	{
		if (r <= cl || cr <= l)
			return;

		if (l <= cl && cr <= r)
		{
			laz[v] = !laz[v];

			return;
		}

		push(v);

		auto ct = midpoint(cl, cr);

		seginv(l, r, cl, ct, 2 * v);
		seginv(l, r, ct, cr, 2 * v + 1);

		upd(v);
	}

public:
	explicit segtree(const vector<ll> &q = {}) : arr(2 * up(q.size())), val(2 * up(q.size())), laz(2 * up(q.size()))
	{
		ranges::copy(q, val.begin() + ssize(val) / 2);

		for (auto i: ranges::iota_view(1, ssize(val) / 2) | views::reverse)
			val[i] = val[2 * i] + val[2 * i + 1];
	}

	auto segsum(int l, int r)
	{
		return segsum(l, r, 0, ssize(arr) / 2, 1);
	}

	auto segsum(int l = 0)
	{
		return segsum(l, ssize(arr) / 2);
	}

	auto seginv(int l, int r)
	{
		return seginv(l, r, 0, ssize(arr) / 2, 1);
	}
};


class hld
{
	struct node
	{
		int p = -1, l = 0, sz = 1;
	};

	vector<node> gr;
	vector<int> wh;
	segtree st, odd;
	int cnt;
	vector<ll> val;

	int build(const vector<vector<pair<int, int>>> &tr, int &ind, int v, int p = -1, int l = 0)
	{
		int me = ind;
		ind++;

		wh[v] = me;

		gr[me].p = p;
		gr[me].l = l;

		auto rec = [&](int u, int nl)
		{
			build(tr, ind, u, me, nl);
		};

		if (!tr[v].empty())
		{
			rec(tr[v].front().first, l);

			for (auto it: tr[v] | views::drop(1))
				rec(it.first, ind);
		}

		return me;
	}

	bool check()
	{
		return 2 * odd.segsum() == cnt;
	}

public:
	explicit hld(const vector<vector<pair<int, int>>> &tr = {}) : gr(tr.size()), wh(gr.size(), -1), cnt(0),
	                                                              val(tr.size(), 1)
	{
		int q = 0;

		build(tr, q, 0);

		assert(q == tr.size());
		assert(ranges::count(wh, -1) == 0);

		for (const auto &it: gr | views::drop(1) | views::reverse)
			gr[it.p].sz += it.sz;

		odd = segtree(val);

		for (auto p: ranges::iota_view(0, ssize(tr)))
			for (auto[it, w]: tr[p])
				val[wh[it]] = w;

		st = segtree(val);
	}

	ll activate(int v)
	{
		cnt++;
		v = wh[v];

		while (v >= 0)
		{
			st.seginv(gr[v].l, v + 1);
			odd.seginv(gr[v].l, v + 1);

			v = gr[gr[v].l].p;
		}

		if (check())
			return st.segsum();
		return 0;
	}

	vector<ll> query()
	{
		vector<ll> ans;

		if (check())
			for (auto it: ranges::iota_view(0, ssize(gr)))
				if (odd.segsum(it, it + 1))
					ans.push_back(val[it]);

		return ans;
	}
};


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<vector<pair<int, int>>> gr(n);

	for (auto w: ranges::iota_view(1, n))
	{
		int a, b;

		cin >> a >> b;
		a--;
		b--;

		gr[a].emplace_back(b, w);
		gr[b].emplace_back(a, w);
	}

	vector<int> siz(gr.size());

	dfs(gr, siz, 0);

	for (auto &row: gr)
		if (!row.empty())
			swap(row.front(), *ranges::max_element(row, [&siz](const auto &a, const auto &b)
			{
				return siz[a.first] < siz[b.first];
			}));

	hld slv(gr);
	slv.activate(0);

	int q;

	while (cin >> q)
	{
		if (q == 0 || q == 3)
			return;

		if (q == 1)
		{
			int v;

			cin >> v;
			v--;

			cout << slv.activate(v) << endl;
		}
		else
		{
			assert(q == 2);

			auto ans = slv.query();

			cout << ans.size() << ' ';

			ranges::sort(ans);
			ranges::copy(ans, ostream_iterator<int>(cout, " "));
			cout << endl;
		}
	}
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