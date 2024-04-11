#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, k;

	cin >> n >> k;

	assert(k <= n);

	if (k % 2 == 0 && n % 2 == 1)
	{
		cout << -1 << endl;

		return;
	}

	int val = n;

	while (val <= 500 * k && (val % k != 0 || val / k < ((val - n) + 2 * n - 1) / (2 * n) * 2 + 1))
	{
		do
		{
			val += 2;
		} while (val % k != 0);
	}

	if (val > 500 * k)
	{
		cout << -1 << endl;

		return;
	}

	auto rem = (val - n) % (2 * n) / 2;

	vector<int> cnt(n);

	for (int i = 0; i < n; i++)
	{
		int q = (val - 2 * rem) / n;

		if (i < rem)
			q += 2;

		assert(q % 2 == 1);

		cnt[i] = q;
	}

	vector<int> ord(n);
	iota(ord.begin(), ord.end(), 0);

	vector<vector<int>> quer;

	for (int j = 0; k * j < val; j++)
	{
		sort(ord.begin(), ord.end(), [&](int a, int b)
		{
			return cnt[a] > cnt[b];
		});

		vector<int> q(ord.begin(), ord.begin() + k);

		for (auto it : q)
			cnt[it]--;

		quer.push_back(q);
	}

	assert(count(cnt.begin(), cnt.end(), 0) == cnt.size());

	unsigned x = 0;

	cerr << quer.size() << endl;

	for (const auto &row : quer)
	{
		unsigned t;

		cout << "?";
		for (auto it : row)
			cout << ' ' << it + 1;
		cout << endl;

		cin >> t;

		x ^= t;
	}

	cout << "! " << x << endl;
}


int main()
{
	cout << fixed;

#ifdef LOCAL
	auto st = chrono::steady_clock::now();

	ifstream fin("../input.txt");

	solve();

	cout << setprecision((int) floor(log10(chrono::steady_clock::duration::period::den)));
	cout << "clock: " << chrono::duration<double>(chrono::steady_clock::now() - st).count() << endl;
#else
	solve();
#endif

	return 0;
}