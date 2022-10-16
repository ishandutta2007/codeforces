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
	vector<ll> arr;

	void push(int v)
	{
		if (v == 0)
			return;

		push(v / 2);

		arr[2 * v] += arr[v];
		arr[2 * v + 1] += arr[v];
		arr[v] = 0;
	}


	void segadd(int l, int r, int cl, int cr, int v, ll x)
	{
		if (r <= cl || cr <= l)
			return;
		if (l <= cl && cr <= r)
		{
			arr[v] += x;
			return;
		}

		int ct = (cl + cr) / 2;

		segadd(l, r, cl, ct, 2 * v, x);
		segadd(l, r, ct, cr, 2 * v + 1, x);
	}

public:
	segtree(int n) : arr(2 * up(n))
	{}


	ll &operator[](int wh)
	{
		wh += (int) arr.size() / 2;

		push(wh / 2);

		return arr[wh];
	}

	void segadd(int l, int r, ll x)
	{
		segadd(l, r, 0, (int) arr.size() / 2, 1, x);
	}
};

template<class T>
T &remin(T &x, const T &y)
{
	return x = min(x, y);
}


template<class T>
T &remax(T &x, const T &y)
{
	return x = max(x, y);
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<int> arr(n), p(n);

	for (auto &it : arr)
		cin >> it;
	for (auto &it : p)
		cin >> it;

	int m;

	cin >> m;

	vector<int> brr(m);

	for (auto &it : brr)
		cin >> it;
	brr.insert(brr.begin(), 0);

	const ll inf = numeric_limits<ll>::max() / 2;

	segtree st(n + 1);
	st.segadd(0, n + 1, inf);
	st[brr.front()] = 0;

	for (int i = 0; i < arr.size(); i++)
	{
		auto wh = lower_bound(brr.begin(), brr.end(), arr[i]) - brr.begin();

		if (p[i] < 0)
			st.segadd(arr[i], n + 1, p[i]);

		if (wh < brr.size() && brr[wh] == arr[i])
		{
			assert(wh > 0);
			remin(st[arr[i]], st[brr[wh - 1]]);
		}

		st.segadd(0, arr[i], p[i]);
	}

	auto ans = st[brr.back()];

	if (ans < inf / 2)
	{
		cout << "YES" << endl;
		cout << ans << endl;
	}
	else
		cout << "NO" << endl;
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