#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct item
{
	int l, r, c, p;

	bool operator < (const item &o) const
	{
		return c < o.c;
	}
};

const ll inf = (ll)1e18;

//struct segtree
//{
//	vector<ll> v;
//
//	segtree (int n, int len)
//	{
//		v.assign(n, len);
//	}
//
//	pair<ll, int> getmin (int l, int r)
//	{
//		ll what = inf + 1;
//		int where = -1;
//		for (int i = l; i < r; i++)
//		{
//			if (v[i] < what)
//			{
//				what = v[i];
//				where = i;
//			}
//		}
//
//		return {what, where};
//	}
//
//	void seg_add (int l, int r, ll x)
//	{
//		for (int i = l; i < r; i++)
//			v[i] += x;
//	}
//};

struct segtree
{
	vector<ll> to_add;
	vector<pair<ll, int>> seg_min;
	int tsz;

	void recalc (int v)
	{
		seg_min[v] = min(seg_min[2 * v], seg_min[2 * v + 1]);
	}

	segtree (int n, ll k)
	{
		tsz = 1;
		while (tsz < n)
			tsz *= 2;

		to_add.assign(2 * tsz, 0);
		seg_min.resize(2 * tsz);

		for (int i = 0; i < tsz; i++)
			seg_min[i + tsz] = pair<ll, int>((i < n ? k : inf), i);
		for (int i = tsz - 1; i >= 1; i--)
			recalc(i);
	}

	void apply (int v, ll what)
	{
		to_add[v] += what;
		seg_min[v].first += what;
	}

	void push (int v)
	{
		for (int son = 2 * v; son <= 2 * v + 1; son++)
			apply(son, to_add[v]);
		to_add[v] = 0;
	}

	void go_add (int v, int L, int R, int l, int r, ll what)
	{
		if (r <= L || R <= l)
			return;

		if (l <= L && R <= r)
		{
			apply(v, what);
			return;
		}

		push(v);
		const int M = (L + R) / 2;
		go_add(2 * v, L, M, l, r, what);
		go_add(2 * v + 1, M, R, l, r, what);
		recalc(v);
	}

	void seg_add (int l, int r, ll what)
	{
		go_add (1, 0, tsz, l, r, what);
	}

	pair<ll, int> go_min (int v, int L, int R, int l, int r)
	{
		if (r <= L || R <= l)
			return {inf, inf};
		if (l <= L && R <= r)
			return seg_min[v];

		push(v);
		const int M = (L + R) / 2;
		return min(go_min(2 * v, L, M, l, r), go_min(2 * v + 1, M, R, l, r));
	}

	pair<ll, int> getmin (int l, int r)
	{
		return go_min(1, 0, tsz, l, r);
	}
};

void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, k, m;

	cin >> n >> k >> m;

	vector<item> v(m);
	for (auto &it : v)
	{
		cin >> it.l >> it.r >> it.p >> it.c;
		--it.l;
	}

	sort(v.begin(), v.end());

	vector<ll> ans(n, -1);
	segtree data(n, k), ans_info(n, 0);

	for (auto it : v)
	{
		const int l = it.l, r = it.r, p = it.p, c = it.c;
		while (true)
		{
			ll what;
			int pos;
			tie(what, pos) = data.getmin(l, r);

			if (what <= p)
			{
				ans[pos] = ans_info.getmin(pos, pos + 1).first + (ll)what * c;
				data.seg_add(pos, pos + 1, inf - what);
			}
			else
			{
				data.seg_add(l, r, -p);
				ans_info.seg_add(l, r, (ll)p * c);
				break;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (ans[i] == -1)
			ans[i] = ans_info.getmin(i, i + 1).first;
	}

//	copy(ans.begin(), ans.end(), ostream_iterator<ll>(cerr, " "));
//	cerr << endl;

	assert(!count(ans.begin(), ans.end(), -1LL));
	ll res = accumulate(ans.begin(), ans.end(), 0LL);
	cout << res << endl;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed;

#ifdef LOCAL
	ifstream fin("../input.txt");

	solve(fin);

	cout << setprecision(4) << "clock: " << clock() / (double) CLOCKS_PER_SEC << endl;
#else
	cout << setprecision(20);

	solve();
#endif

	return 0;
}