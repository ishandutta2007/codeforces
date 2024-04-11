#include <bits/stdc++.h>


using namespace std;


using ll = long long;
mt19937 mt(736);


int up(int n)
{
	int r = 1;

	while (r < n)
		r <<= 1;

	return r;
}


class segtreepii
{
	vector<pair<int, int>> arr;

	[[nodiscard]] pair<int, int> segmin(int l, int r, int cl, int cr, int v) const
	{
		if (r <= cl || cr <= l)
			return {numeric_limits<int>::max(), -1};
		if (l <= cl && cr <= r)
			return arr[v];

		int ct = (cl + cr) / 2;

		return min(segmin(l, r, cl, ct, 2 * v),
		           segmin(l, r, ct, cr, 2 * v + 1));
	}

public:
	segtreepii(const vector<pair<int, int>> &val) : arr(2 * up(val.size()), {numeric_limits<int>::max(), -1})
	{
		copy(val.begin(), val.end(), arr.begin() + arr.size() / 2);

		for (int i = (int) arr.size() / 2 - 1; i > 0; i--)
			arr[i] = min(arr[2 * i], arr[2 * i + 1]);
	}


	[[nodiscard]] pair<int, int> segmin(int l, int r) const
	{
		return segmin(l, r, 0, arr.size() / 2, 1);
	}


	[[nodiscard]] pair<int, int> segmin() const
	{
		return segmin(0, arr.size() / 2, 0, arr.size() / 2, 1);
	}


	void set(int wh, const pair<int, int> &x)
	{
		wh += arr.size() / 2;

		arr[wh] = x;

		while ((wh >>= 1) > 0)
			arr[wh] = min(arr[2 * wh], arr[2 * wh + 1]);
	}
};


class segtreei
{
	vector<int> arr, laz;

	[[nodiscard]] int segmax(int l, int r, int cl, int cr, int v)
	{
		if (r <= cl || cr <= l)
			return 0;
		push(v);
		if (l <= cl && cr <= r)
			return arr[v];

		int ct = (cl + cr) / 2;

		auto ret = max(segmax(l, r, cl, ct, 2 * v),
		               segmax(l, r, ct, cr, 2 * v + 1));

//		upd(v);

		return ret;
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

			arr[v] = max(arr[2 * v], arr[2 * v + 1]);
		}
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

		int ct = (cl + cr) / 2;

		segadd(l, r, cl, ct, 2 * v, x);
		segadd(l, r, ct, cr, 2 * v + 1, x);

		upd(v);
	}

public:
	segtreei(const vector<int> &val) : arr(2 * up(val.size())), laz(2 * up(val.size()))
	{
		copy(val.begin(), val.end(), arr.begin() + arr.size() / 2);

		for (int i = (int) arr.size() / 2 - 1; i > 0; i--)
			arr[i] = max(arr[2 * i], arr[2 * i + 1]);
	}


	[[nodiscard]] int segmax(int l, int r)
	{
		return segmax(l, r, 0, arr.size() / 2, 1);
	}


	void segadd(int l, int r, int x)
	{
		segadd(l, r, 0, arr.size() / 2, 1, x);
	}


	[[nodiscard]] int segmax()
	{
		return segmax(0, arr.size() / 2, 0, arr.size() / 2, 1);
	}


	void set(int wh, const int &x)
	{
		wh += arr.size() / 2;

		arr[wh] = x;

		while ((wh >>= 1) > 0)
			arr[wh] = max(arr[2 * wh], arr[2 * wh + 1]);
	}
};


void build(vector<int> &gr, vector<int> &le, vector<int> &ri, const segtreepii &st, int l, int r, int d = 0)
{
	if (r <= l)
		return;

	auto v = st.segmin(l, r);
	auto t = v.second;

	gr[t] = d;
	le[t] = l - 1;
	ri[t] = r;

	build(gr, le, ri, st, l, t, d + 1);
	build(gr, le, ri, st, t + 1, r, d + 1);
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<pair<int, int>> arr(n);

	int sh = 0;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].first;
		arr[i].first--;
		arr[i].second = i;

		if (arr[i].first == 0)
			sh = i;
	}

	for (auto &it : arr)
	{
		it.second -= sh;

		if (it.second < 0)
			it.second += n;
	}

	rotate(arr.begin(), arr.begin() + sh, arr.end());

	segtreepii st(arr);

	vector<int> tr(n);

	vector<int> le(n, -1), ri(n, -1);

	build(tr, le, ri, st, 0, n);

	segtreei dep(tr);

	pair<int, int> ans = {dep.segmax(), sh};

	for (int p = n - 1; p > 0; p--)
	{
		dep.segadd(le[p] + 1, p, -1);
		dep.segadd(p, p + 1, -dep.segmax(p, p + 1) + dep.segmax(ri[p], ri[p] + 1) + 1);
		if (ri[p] > p)
			dep.segadd(p + 1, ri[p], 1);
		else
		{
			dep.segadd(p + 1, n, 1);
			assert(ri[p] == 0);
		}

		sh--;

		ans = min(ans, {dep.segmax(), sh});
	}

	if (ans.second < 0)
		ans.second += n;

	cout << ans.first + 1 << ' ' << ans.second << endl;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed;

#ifdef LOCAL
	ifstream fin("../input.txt");

	solve(fin);

	cout << setprecision(4);
	cout << "clock: " << clock() / (double) CLOCKS_PER_SEC << endl;
#else
	solve();
#endif

	return 0;
}