#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


vector<int> Eratosthenes(int n)
{
	vector<int> d(n, -1);

	for (int j = 2; j * j < n; j++)
		if (d[j] == -1)
		{
			d[j] = j;

			for (int i = j * j; i < n; i += j)
				if (d[i] == -1)
					d[i] = j;
		}

	for (auto j: ranges::iota_view(2, (int) d.size()))
		if (d[j] == -1)
			d[j] = j;

	return d;
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<int> arr(n);

	for (auto &it: arr)
		cin >> it;

	auto d = Eratosthenes(ranges::max(arr) + 1);

	vector<int> primes;

	for (auto it: ranges::iota_view(2, ssize(d)))
		if (d[it] == it)
			primes.push_back(it);

	vector<int> cnt(d.size());
	vector<ll> dp(cnt.size());

	for (auto it: arr)
		cnt[it]++;

	for (auto it: primes)
		for (auto q = (ssize(cnt) - 1) - (ssize(cnt) - 1) % it; q > 0; q -= it)
			cnt[q / it] += cnt[q];

	for (auto it: ranges::iota_view(1, ssize(cnt)) | views::reverse)
	{
		auto &ans = dp[it];

		ans = cnt[it] * (ll) it;

		for (auto w: primes)
			if (auto q = it * w; q < ssize(dp))
				ans = max(ans, dp[q] + it * ll(cnt[it] - cnt[q]));
			else
				break;
	}

	cout << ranges::max(dp) << endl;
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