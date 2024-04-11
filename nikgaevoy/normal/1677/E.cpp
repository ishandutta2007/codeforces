#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


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


constexpr auto up(auto n)
{
	decltype(n) r = 1;

	while (r < n)
		r *= 2;

	return r;
}


template<class T, T one>
class segtree
{
	vector<pair<T, T>> arr;

	void push(size_t v)
	{
		auto &[val, laz] = arr[v];

		val *= laz;

		if (v < arr.size() / 2)
		{
			arr[2 * v].second *= laz;
			arr[2 * v + 1].second *= laz;
		}

		laz = one;
	}

	void upd(size_t v)
	{
		push(v);

		if (v < arr.size() / 2)
		{
			push(2 * v);
			push(2 * v + 1);

			arr[v].first = arr[2 * v].first + arr[2 * v + 1].first;
		}
	}

	void segmul(size_t l, size_t r, size_t cl, size_t cr, size_t v, const T &val)
	{
		if (r <= cl || cr <= l)
			return;
		if (l <= cl && cr <= r)
		{
			arr[v].second *= val;

			return;
		}

		push(v);

		auto ct = midpoint(cl, cr);

		segmul(l, r, cl, ct, 2 * v, val);
		segmul(l, r, ct, cr, 2 * v + 1, val);

		upd(v);
	}

	T segsum(size_t l, size_t r, size_t cl, size_t cr, size_t v)
	{
		if (r <= cl || cr <= l)
			return T{};

		push(v);

		if (l <= cl && cr <= r)
			return arr[v].first;

		auto ct = midpoint(cl, cr);

		return segsum(l, r, cl, ct, 2 * v) +
		       segsum(l, r, ct, cr, 2 * v + 1);
	}

public:
	explicit segtree(size_t n = 0) : arr(2 * up(n), pair{T{}, one})
	{
		for (auto i: ranges::iota_view(1, ssize(arr)) | views::reverse)
			upd(i);
	}

	void segmul(const T &val, size_t l, size_t r)
	{
		segmul(l, r, 0, arr.size() / 2, 1, val);
	}

	void segmul(const T &val, size_t l = 0)
	{
		segmul(val, l, arr.size() / 2);
	}

	[[nodiscard]] T segsum(size_t l, size_t r)
	{
		return segsum(l, r, 0, arr.size() / 2, 1);
	}

	[[nodiscard]] T segsum(size_t l = 0)
	{
		return segsum(l, arr.size() / 2);
	}
};


struct shit
{
	size_t sz = 1;
	ll st = 0, a = 0, b = 0;

	shit &operator*=(const shit &rhs)
	{
		assert(rhs.sz == 0);

		if (rhs.st == -1)
			return *this;
		if (st == -1)
			return *this = rhs;

		assert(st <= rhs.st);

		auto diff = rhs.st - st;
		ll mlt = sz == 0 ? 1 : ll(sz);

		b += a * diff;
		a = rhs.a * mlt;
		b -= a * diff;
		b += rhs.b * mlt;

		return *this;
	}

	[[nodiscard]] shit operator+(const shit &rhs) const
	{
		assert(st == 0 && rhs.st == 0);

		return shit{sz + rhs.sz, 0, a + rhs.a, b + rhs.b};
	}

	[[nodiscard]] ll eval(ll x) const
	{
		assert(st == 0);

		return a * x + b;
	}
};


class segtree_beats
{
	segtree<shit, shit{0, -1, 0, 0}> st;
	ll tim = 0;

public:
	explicit segtree_beats(size_t n = 0) : st(n)
	{}


	void add()
	{
		tim++;
	}


	void set(size_t l, size_t r, ll val)
	{
		st.segmul(shit{0, tim, val, 0}, l, r);
//		flush();
	}


	[[nodiscard]] ll sum(size_t l, size_t r)
	{
		return st.segsum(l, r).eval(tim);
	}
};


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, q;

	cin >> n >> q;

	vector<int> arr(n), wh(n + 1, -1);

	for (auto &it: arr)
		cin >> it;

	for (auto i: ranges::iota_view(0, ssize(arr)))
		wh[arr[i]] = i;

	vector<pair<int, int>> quer(q);

	for (auto &[l, r]: quer)
	{
		cin >> l >> r;
		l--;
	}

	vector<vector<int>> ask(n + 1);

	for (auto i: ranges::iota_view(0, q))
		ask[quer[i].second].push_back(i);

	vector<ll> ans(quer.size(), -1);

	vector<vector<int>> divs(n + 1, {1});

	for (int i = 2; i < ssize(divs); i++)
		for (auto j = i * (ll) i; j < ssize(divs); j += i)
			divs[j].push_back(i);

	vector<int> mpos(divs.size(), -1);
	vector<pair<int, int>> pms;

	segtree_beats st(n + 1);

	for (auto i: ranges::iota_view(0, ssize(arr)))
	{
		auto it = arr[i];

		while (!pms.empty() && pms.back().first < it)
		{
			mpos[pms.back().first] = -1;
			pms.pop_back();
		}

		const auto rb = pms.empty() ? 0 : pms.back().second + 1;

		st.set(rb, i + 1, 0);

		mpos[it] = ssize(pms);
		pms.emplace_back(it, i);

		int ss = 0;

		for (auto a: divs[it])
			if (int pa = wh[a]; it != a * (ll) a && rb <= pa && pa <= i)
			{
				auto b = it / a;
				auto pb = wh[b];

				if (rb <= pb && pb <= i)
					remax(ss, min(pa, pb) + 1);
			}

		st.set(rb, ss, 1);

		for (int mul = 2 * it; mul < ssize(divs); mul += it)
			if (auto mm = mpos[mul]; mm != -1 && mul != it * (ll) it)
			{
				auto lb = mm == 0 ? 0 : pms[mm - 1].second + 1;
				auto b = mul / it;
				auto pb = wh[b];

				if (pb < i)
					st.set(lb, min(pb, pms[mm].second) + 1, 1);
			}

		st.add();

		for (auto ind: ask[i + 1])
		{
			auto [l, r] = quer[ind];

			ans[ind] = st.sum(l, i + 1); // query l
		}
	}

	for (auto it: ans)
		cout << it << '\n';
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int t = 1;

	for (int i = 0; i < t; i++)
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