#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

#ifdef LOCAL
mt19937 mt(736);
#else
mt19937 mt(time(nullptr));
#endif


template<class T>
class segtree
{
	vector<T> arr;

	void upd(int v)
	{
		if (v < ssize(arr) / 2)
			arr[v] = arr[2 * v] + arr[2 * v + 1];
	}

public:
	explicit segtree(size_t n = 0) : arr(2 * n)
	{}

	template<class It>
	explicit segtree(It be, It en) : arr(2 * distance(be, en))
	{
		copy(be, en, arr.begin() + ssize(arr) / 2);

		for (int i = ssize(arr) / 2 - 1; i > 0; i--)
			upd(i);
	}

	void set(int wh, const T &x)
	{
		wh += ssize(arr) / 2;

		arr[wh] = x;

		while ((wh /= 2) > 0)
			upd(wh);
	}

	[[nodiscard]] T segsum(int l, int r) const
	{
		l += ssize(arr) / 2;
		r += ssize(arr) / 2;

		T x{0};

		while (l < r)
		{
			if (l & 1u)
				x += arr[l++];
			if (r & 1u)
				x += arr[--r];

			l /= 2;
			r /= 2;
		}

		return x;
	}
};

constexpr int rep = 25;


struct rnd
{
	array<ll, rep> arr;

	rnd()
	{
		uniform_int_distribution<int> uid;

		for (auto &it: arr)
			it = uid(mt);
	}

	rnd(int) : arr{}
	{}

	rnd(const rnd &lhs, const rnd &rhs)
	{
		for (int i = 0; i < rep; i++)
			arr[i] = lhs.arr[i] + rhs.arr[i];
	}

	[[nodiscard]] bool check(int k) const
	{
		for (auto it: arr)
			if (it % k != 0)
				return false;

		return true;
	}

	rnd &operator+=(const rnd &rhs)
	{
		for (int i = 0; i < rep; i++)
			arr[i] += rhs.arr[i];

		return *this;
	}

	rnd operator+(const rnd &rhs) const
	{
		return {*this, rhs};
	}
};


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, q;

	cin >> n >> q;

	unordered_map<int, rnd> mem;
	int x = uniform_int_distribution<int>{}(mt);

	auto get = [&mem, &x](int val) -> const rnd &
	{
		return mem[val ^ x];
	};

	segtree<rnd> st;

	{
		vector<int> arr(n);

		for (auto &it: arr)
			cin >> it;

		vector<rnd> tmp;
		tmp.reserve(arr.size());

		for (auto it: arr)
			tmp.push_back(get(it));

		st = segtree<rnd>(tmp.begin(), tmp.end());
	}

	for (int i = 0; i < q; i++)
	{
		int type;

		cin >> type;

		if (type == 1)
		{
			int ind, val;

			cin >> ind >> val;
			ind--;

			st.set(ind, get(val));
		}
		else
		{
			assert(type == 2);

			int l, r, k;

			cin >> l >> r >> k;
			l--;

			cout << ((r - l) % k == 0 && st.segsum(l, r).check(k) ? "YES\n" : "NO\n");
		}
	}
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

#ifdef STRESS
	for (int cnt = 1;; cnt++)
	{
		stringstream ss, in1, out1, in2, out2;

		gen(ss);

		in1 << ss.str();
		in2 << ss.str();

		solve(in1, out1);
		stress(in2, out2);

		if (out1.str() != out2.str())
		{
			cout << "fail: " << cnt << endl;
			cout << ss.str();
			cout << "solve:" << endl;
			cout << out1.str();
			cout << "stress:" << endl;
			cout << out2.str();

			break;
		}
		else if (cnt % 100 == 0)
			cout << "ok: " << cnt << endl;
	}
#endif

	cout << setprecision((int) floor(log10(chrono::steady_clock::duration::period::den)));
	cout << "clock: " << chrono::duration<double>(chrono::steady_clock::now() - st).count() << endl;
#else
	solve();
#endif

	return 0;
}