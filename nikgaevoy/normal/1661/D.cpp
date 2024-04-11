#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int k, n;

	cin >> n >> k;

	vector<ll> b(n);

	for (auto &it: b)
		cin >> it;

	ranges::reverse(b);

	ll bal = 0;

	vector<ll> arr(n - k + 1), a(b.size());

	auto gen_val = [&](int pos)
	{
		if (pos > 0)
			a[pos] = a[pos - 1] - bal;
		if (pos >= k)
			bal -= arr[pos - k];
	};

	for (auto j: ranges::iota_view(0, ssize(arr)))
	{
		gen_val(j);

		auto mv = (max(0ll, b[j] - a[j]) + k - 1) / k;

		arr[j] += mv;
		a[j] += k * mv;
		bal += mv;
	}

	ll add = 0;

	for (auto j: ranges::iota_view(ssize(arr), ssize(a)))
	{
		gen_val(j);

		auto mv = (max(0ll, b[j] - a[j]) + (ssize(a) - j - 1)) / (ssize(a) - j);

		add = max(add, mv);
	}

	cerr << add << endl;

	cout << accumulate(arr.begin(), arr.end(), add) << endl;
}


void stress(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, k;

	cin >> n >> k;

	vector<ll> a(n), b(n);

	ll ans = 0;

	auto add = [&](int st)
	{
		ans++;

		for (int i = st; i < st + k; i++)
			a[i] += i - st + 1;
	};

	for (int j = n; j >= k; j--)
		while (b[j - 1] > a[j - 1])
			add(j - k);

	auto check = [&]()
	{
		for (auto i: ranges::iota_view(0, ssize(a)))
			if (b[i] < a[i])
				return false;
		return true;
	};

	while (!check())
		add(0);

	cout << ans << endl;
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int t = 1;

	for (int i = 0; i < t; i++)
		solve_test(cin, cout);
}


void gen(ostream &cout = std::cout)
{}


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