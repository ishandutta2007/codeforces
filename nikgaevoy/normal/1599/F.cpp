#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

using ld = long double;

const int mod = int(1e9) + 7;

int mult (const int a, const int b)
{
	return ll(a) * b % mod;
}
int mult (const int a, const int b, const int c)
{
	return mult(mult(a, b), c);
}
int mult (const int a, const int b, const int c, const int d)
{
	return mult(mult(a, b), mult(c, d));
}
void add (int &a, const int b)
{
	a += b;
	if (a >= mod)
		a -= mod;
}
void sub (int &a, const int b)
{
	a -= b;
	if (a < 0)
		a += mod;
}
int sum (int a, const int b)
{
	add(a, b);
	return a;
}
int powmod (int a, int pw)
{
	int res = 1;
	while (pw)
	{
		if (pw & 1)
			res = mult(res, a);
		a = mult(a, a);
		pw >>= 1;
	}
	return res;
}
int inv (const int a)
{
	assert(0 < a && a < mod);
	const int res = powmod(a, mod - 2);
	assert(mult(a, res) == 1);
	return res;
}

struct info
{
	int cnt;
	int sum_one;
	int sum_sq;
	int prod;

	info() : cnt(0), sum_one(0), sum_sq(0), prod(1) {}

	info (const int a) : cnt(1), sum_one(a), sum_sq(mult(a, a)), prod(a) {}

	friend info operator * (const info &l, const info &r)
	{
		info ans;
		ans.cnt = l.cnt + r.cnt;
		ans.sum_one = sum(l.sum_one, r.sum_one);
		ans.sum_sq = sum(l.sum_sq, r.sum_sq);
		ans.prod = mult(l.prod, r.prod);
		return ans;
	}
};

struct query
{
	int l, r, d, id;

	bool operator < (const query &o) const
	{
		return l < o.l;
	}
};

struct segtree
{
	vector<info> vals;
	int n;

	void recalc (const int v)
	{
		vals[v] = vals[2 * v] * vals[2 * v + 1];
	}

	segtree(const int n_)
	{
		n = n_;
		vals.resize(2 * n, info());
	}

	void put (int pos, const info &what)
	{
		vals[pos += n] = what;
		for (pos >>= 1; pos > 0; pos >>= 1)
			recalc(pos);
	}

	info get (int l, int r)
	{
		info ans;
		for (l += n, r += n; l < r; l >>= 1, r >>= 1)
		{
			if (l & 1)
				ans = ans * vals[l++];
			if (r & 1)
				ans = ans * vals[--r];
		}
		return ans;
	}
};

struct thing
{
	int l, r, prod, id;

	bool operator < (const thing &o) const
	{
		return l < o.l;
	}
};

void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, q;
	cin >> n >> q;

	vector<int> a(n);
	for (auto &it : a)
		cin >> it;

	mt19937 rng(450);
	const int shift = rng() % mod;
	for (auto &it : a)
		add(it, shift);

	vector<query> qs(q);
	for (int i = 0; i < q; i++)
	{
		auto &it = qs[i];
		it.id = i;
		cin >> it.l >> it.r >> it.d;
		--it.l;
	}
	sort(qs.begin(), qs.end());


	map<int, int> last;
	vector<int> next(n, n);
	segtree tree(n);

	for (int i = n - 1; i >= 0; i--)
	{
		if (last.count(a[i]))
			next[i] = last.at(a[i]);
		last[a[i]] = i;
	}
	
	for (auto pr : last)
		tree.put(pr.second, info(a[pr.second]));

	int last_l = 0;
	vector<thing> to_check;
	vector<bool> ans(q);
	for (const auto &it : qs)
	{
		for (int i = last_l; i < it.l; i++)
			if (next[i] < n)
				tree.put(next[i], info(a[next[i]]));
		last_l = it.l;

		const info res = tree.get(it.l, it.r);
		if (it.d == 0)
		{
			ans[it.id] = (res.cnt == 1);
			continue;
		}

		int start = res.sum_one;
		assert(res.cnt >= 1);
		sub(start, mult(inv(2), res.cnt, res.cnt - 1, it.d));
		start = mult(start, inv(res.cnt));

		int sum_sq = mult(res.cnt, start, start);
		add(sum_sq, mult(start, res.cnt, res.cnt - 1, it.d));
		add(sum_sq, mult(it.d, it.d, mult(res.cnt - 1, res.cnt, 2 * res.cnt - 1, inv(6))));

		if (res.sum_sq != sum_sq)
			continue;

		const int id = inv(it.d);
		const int shift_start = mult(start, id);

		if (shift_start + res.cnt > mod)
			ans[it.id] = (res.prod == 0);
		else
			to_check.push_back(thing{shift_start, shift_start + res.cnt, mult(res.prod, powmod(id, res.cnt)), it.id});
	}

	sort(to_check.begin(), to_check.end());

	for (int i = 0, j = 0; i < int(to_check.size()); i = j)
	{
		int max_r = to_check[i].r;
		for (j = i; j < int(to_check.size()) && to_check[j].l <= max_r; j++)
			max_r = max(max_r, to_check[j].r);

		const int left = to_check[i].l;
		segtree cur(max_r - left + 1);
		for (int k = left; k <= max_r; k++)
			cur.put(k - left, info(k));

		for (int k = i; k < j; k++)
			if (cur.get(to_check[k].l - left, to_check[k].r - left).prod == to_check[k].prod)
				ans[to_check[k].id] = true;
	}

	for (int i = 0; i < q; i++)
		cout << (ans[i] ? "Yes\n" : "No\n");
	cout.flush();
}

void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
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