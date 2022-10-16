#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


constexpr int mod = int(1e9) + 7;


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	array<int, 3> b{}, c{};

	for (auto &it: b)
		cin >> it;
	for (auto &it: c)
		cin >> it;

	auto check_inside = [](array<int, 3> a, ll x)
	{
		x -= a[0];

		return !(x < 0 || x % a[1] != 0 || x / a[1] >= a[2]);
	};

	auto get_last = [](array<int, 3> c)
	{
		return c[0] + c[1] * (c[2] - 1ll);
	};

	if (!check_inside(b, c[0]) || !check_inside(b, get_last(c)) || c[1] % b[1] != 0)
	{
		cout << 0 << endl;

		return;
	}

	if (c[0] - c[1] < b[0] || get_last(c) + c[1] > get_last(b))
	{
		cout << -1 << endl;

		return;
	}

	vector<int> cand;

	for (int i = 1; i * i <= c[1]; i++)
		if (c[1] % i == 0)
		{
			cand.push_back(i);
			cand.push_back(c[1] / i);
		}

	ranges::sort(cand);
	cand.resize(cand.size() - ranges::unique(cand).size());

	auto sqr = [](ll x)
	{
		return x * x;
	};

	ll ans = 0;

	for (auto it: cand)
		if (lcm(it, b[1]) == c[1])
		{
			ans += sqr(c[1] / it);
			ans %= mod;
		}

	cout << ans << endl;
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int t = 1;

	cin >> t;

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