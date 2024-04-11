#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


class segtree
{
	vector<bool> arr;

public:
	explicit segtree(size_t n = 0) : arr(2 * n)
	{}

	void inv(size_t wh)
	{
		for (wh += arr.size() / 2; wh > 0; wh /= 2)
			arr[wh] = !arr[wh];
	}

	bool operator()(size_t l = 0) const
	{
		return (*this)(l, arr.size() / 2);
	}

	bool operator()(size_t l, size_t r) const
	{
		l += arr.size() / 2;
		r += arr.size() / 2;

		bool ans = false;

		while (l < r)
		{
			if (l % 2 != 0)
				ans ^= arr[l++];
			if (r % 2 != 0)
				ans ^= arr[--r];

			l /= 2;
			r /= 2;
		}

		return ans;
	}
};


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<int> arr(n);

	for (auto &it: arr)
	{
		cin >> it;
		it--;
	}

	segtree st(ranges::max(arr) + 1);

	bool ans = false;

	for (auto it: arr)
	{
		if (st(it, it + 1))
		{
			cout << "yes\n";

			return;
		}

		ans ^= st(it);
		st.inv(it);
	}

	cout << (!ans ? "yes\n" : "no\n");
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int t;

	cin >> t;

	for (auto it: ranges::iota_view(0, t))
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