#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


class segtree
{
	vector<int> arr;

public:
	explicit segtree(size_t n = 0) : arr(2 * n)
	{}

	void add(size_t wh, int x = 1)
	{
		wh += arr.size() / 2;

		while (wh > 0)
		{
			arr[wh] += x;

			wh /= 2;
		}
	}

	int sum(size_t l = 0) const
	{
		return sum(l, arr.size() / 2);
	}


	int sum(size_t l, size_t r) const
	{
		l += arr.size() / 2;
		r += arr.size() / 2;

		int ans = 0;

		while (l < r)
		{
			if (l & 1u)
				ans += arr[l++];
			if (r & 1u)
				ans += arr[--r];

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

	string str;

	cin >> str;

	vector<int> ps(str.size() + 1);

	for (int i = 1; i < ssize(ps); i++)
		ps[i] = ps[i - 1] + (str[i - 1] == '+' ? 1 : -1);

	auto sh = -ranges::min(ps);

	vector<segtree> sts(3, segtree(ranges::max(ps) + sh + 1));

	ll ans = 0;

	for (auto it: ps)
	{
		it += sh;
		ans += sts[it % 3].sum(it);

		sts[it % 3].add(it);
	}

	cout << ans << '\n';
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int t = 1;

	cin >> t;

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