#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


template<class T>
auto up(T n)
{
	T r = 1;

	while (r < n)
		r *= 2;

	return r;
}


class segtree
{
	vector<int> arr;

	[[nodiscard]] size_t find(size_t l, size_t r, size_t cl, size_t cr, size_t v, int y) const
	{
		if (r <= cl || cr <= l)
			return cr;
		if (l <= cl && cr <= r)
		{
			if (arr[v] < y)
				return cr;
			if (cl + 1 == cr)
				return cl;
		}

		auto ct = (cl + cr) / 2;

		auto ll = find(l, r, cl, ct, 2 * v, y);

		if (ll != ct)
			return ll;

		return find(l, r, ct, cr, 2 * v + 1, y);
	}

public:
	explicit segtree(size_t n = 0) : arr(2 * up(n))
	{}

	void set(size_t wh, int x)
	{
		wh += arr.size() / 2;

		arr[wh] = x;

		while ((wh /= 2) > 0)
			arr[wh] = max(arr[2 * wh], arr[2 * wh + 1]);
	}

	[[nodiscard]] auto find(size_t x, int y) const
	{
		return find(x, arr.size() / 2, 0, arr.size() / 2, 1, y);
	}
};


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<tuple<string, size_t, int>> quer(n);
	vector<size_t> xs;
	xs.reserve(n);

	for (auto &[t, x, y] : quer)
	{
		cin >> t >> x >> y;

		xs.push_back(x);
	}

	sort(xs.begin(), xs.end());
	xs.erase(unique(xs.begin(), xs.end()), xs.end());

	for (auto &[t, x, y] : quer)
		x = lower_bound(xs.begin(), xs.end(), x) - xs.begin();

	segtree st(xs.size());
	vector<set<int>> cols(xs.size());

	for (auto &[t, x, y] : quer)
	{
		if (t == "add")
		{
			cols[x].insert(y);
			st.set(x, *cols[x].rbegin());
		}
		else if (t == "remove")
		{
			cols[x].erase(y);
			st.set(x, cols[x].empty() ? 0 : *cols[x].rbegin());
		}
		else
		{
			assert(t == "find");
			auto tx = st.find(x + 1, y + 1);

			if (tx < xs.size())
				cout << xs[tx] << ' ' << *cols[tx].lower_bound(y + 1) << endl;
			else
				cout << -1 << endl;
		}
	}
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