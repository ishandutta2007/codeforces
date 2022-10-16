#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

#ifndef LOCAL
mt19937 mt(736);
#else
mt19937 mt(chrono::duration<ull, nano>((chrono::high_resolution_clock::now() + 736h).time_since_epoch()).count());
#endif


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	auto st = chrono::steady_clock::now();

	int n, m, p;

	cin >> n >> m >> p;

	vector<ull> arr(n);

	ull best = 0;

	for (auto &row : arr)
	{
		string ser;

		cin >> ser;

		for (int j = 0; j < ser.size(); j++)
			if (ser[j] == '1')
				row |= (1ull << j);
	}

	uniform_int_distribution<int> num(0, (int) arr.size() - 1);

	do
	{
		auto q = arr[num(mt)];

		vector<int> wh;

		for (int j = 0; j < m; j++)
			if (q & (1ull << j))
				wh.push_back(j);

		vector<int> cnt(1u << wh.size());

		for (auto it : arr)
		{
			unsigned mask = 0;

			for (int j = 0; j < wh.size(); j++)
				if (it & (1ull << wh[j]))
					mask |= 1u << j;

			cnt[mask]++;
		}

		vector<int> ssum(cnt.size());

		for (unsigned mask = 0; mask < cnt.size(); mask++)
			for (auto w = mask; w > 0; w = (w - 1) & mask)
				ssum[w] += cnt[mask];

		unsigned local_best = 0;

		for (unsigned mask = 0; mask < ssum.size(); mask++)
			if (ssum[mask] >= (n + 1) / 2)
				if (__builtin_popcount(mask) > __builtin_popcount(local_best))
					local_best = mask;

		if (__builtin_popcount(local_best) > __builtin_popcount(best))
		{
			best = 0;

			for (int j = 0; j < wh.size(); j++)
				if (local_best & (1u << j))
					best |= 1ull << wh[j];
		}
	} while (chrono::duration<double>(chrono::steady_clock::now() - st).count() < 2.5);

	for (int j = 0; j < m; j++)
		cout << ((best >> j) & 1ull);
	cout << endl;
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