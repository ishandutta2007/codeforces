#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);

constexpr int mod = 998244353;


int prod(int a, int b)
{
	return a * (ll) b % mod;
}


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	ssize_t n, s;

	cin >> n >> s;

	vector<int> arr(n), brr(n);

	for (auto &it: arr)
	{
		cin >> it;
		it--;
	}
	for (auto &it: brr)
	{
		cin >> it;
		if (it != -1)
			it--;
	}

	vector<int> reord(arr.size());
	for (auto i: ranges::iota_view(0, ssize(arr)))
		reord[arr[i]] = brr[i];

	vector<bool> used(brr.size());

	for (auto it: brr)
		if (it != -1)
			used[it] = true;

	int ans = 1, var = count(used.rbegin(), used.rbegin() + min(s, ssize(used)), false);

	for (auto i: ranges::iota_view(0, ssize(reord)) | views::reverse)
	{
		if (i - s >= 0)
			var += !used[i - s];

		if (reord[i] != -1 && reord[i] < i - s)
		{
			cout << 0 << '\n';

			return;
		}

		if (reord[i] == -1)
			ans = prod(ans, var--);
	}

	assert(var == 0);

	cout << ans << '\n';
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int t;

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