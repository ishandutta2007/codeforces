#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int k;
	ll x;

	cin >> k >> x;

	auto cnt = [&k](int t)
	{
		if (t >= k)
		{
			auto ans = k * (k + 1ll) / 2 + k * (k - 1ll) / 2;
			auto mx = 2 * k - 1;

			assert(t <= mx);

			ans -= (mx - t) * (mx - t + 1ll) / 2;

			return ans;
		}
		else
			return t * (t + 1ll) / 2;
	};

	int l = 0, r = 2 * k;

	while (l + 1 < r)
	{
		auto t = midpoint(l, r);

		if (cnt(t) >= x)
			r = t;
		else
			l = t;
	}

	cout << min(2 * k - 1, r) << endl;
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