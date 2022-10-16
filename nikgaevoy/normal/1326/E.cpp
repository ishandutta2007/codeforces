#include <bits/stdc++.h>

using namespace std;

using ll = long long;

mt19937 mt(736);


int up(int n)
{
	int r = 1;

	while (r < n)
		r *= 2;

	return r;
}


class segtree
{
	vector<int> arr, laz;


	int segmin(int l, int r, int cl, int cr, int v)
	{
		if (r <= cl || cr <= l)
			return numeric_limits<int>::max();

		push(v);

		if (l <= cl && cr <= r)
			return arr[v];

		auto ct = (cl + cr) / 2;

		auto ret = min(segmin(l, r, cl, ct, 2 * v), segmin(l, r, ct, cr, 2 * v + 1));

		upd(v);

		return ret;
	}

	void segadd(int l, int r, int cl, int cr, int v, int x)
	{
		if (r <= cl || cr <= l)
			return;
		if (l <= cl && cr <= r)
		{
			laz[v] += x;

			return;
		}

		push(v);

		auto ct = (cl + cr) / 2;

		segadd(l, r, cl, ct, 2 * v, x);
		segadd(l, r, ct, cr, 2 * v + 1, x);

		upd(v);
	}


	void push(int v)
	{
		arr[v] += laz[v];

		if (v < arr.size() / 2)
		{
			laz[2 * v] += laz[v];
			laz[2 * v + 1] += laz[v];
		}

		laz[v] = 0;
	}


	void upd(int v)
	{
		push(v);

		if (v < arr.size() / 2)
		{
			push(2 * v);
			push(2 * v + 1);

			arr[v] = min(arr[2 * v], arr[2 * v + 1]);
		}
	}

public:
	segtree(int n) : arr(2 * up(n)), laz(2 * up(n))
	{}

	int segmin(int l, int r)
	{
		return segmin(l, r, 0, (int) arr.size() / 2, 1);
	}

	int segmin(int l = 0)
	{
		return segmin(l, (int) arr.size() / 2, 0, (int) arr.size() / 2, 1);
	}

	void segadd(int x, int l, int r)
	{
		segadd(l, r, 0, (int) arr.size() / 2, 1, x);
	}


	void segadd(int x, int l = 0)
	{
		segadd(l, (int) arr.size() / 2, 0, (int) arr.size() / 2, 1, x);
	}
};


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<int> p(n), q(n);

	for (auto &it : p)
	{
		cin >> it;
		it--;
	}
	for (auto &it : q)
	{
		cin >> it;
		it--;
	}

	vector<int> antip(n);

	for (int i = 0; i < antip.size(); i++)
		antip[p[i]] = i;

	segtree st(n);

	int ans = antip.size() - 1;

	for (int it : q)
	{
		cout << ans + 1 << ' ';

		st.segadd(-1, it);

		while (st.segmin(antip[ans]) - min(0, st.segmin(0, antip[ans])) < 0)
		{
			st.segadd(1, antip[ans]);
			ans--;
		}
	}

	cout << endl;
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

	cout << "clock: " << (clock() - st) / (double) CLOCKS_PER_SEC << endl;
#else
	solve();
#endif

	return 0;
}