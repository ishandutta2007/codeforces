#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<int> arr(n);

	for (auto &it: arr)
		cin >> it;

	ll best = numeric_limits<ll>::max() - 100;

	for (auto target: ranges::iota_view(ranges::max(arr)))
	{
		ll sum = 0, ones = 0;

		for (auto it: arr)
		{
			sum += target - it;
			ones += (target - it) % 2;
		}

		if (2 * sum / 3 > best + 10)
			break;

		ll days = max(0ll, max(ones * 2 - 1, 2 * sum / 3 - 10));

		auto ok = [&]()
		{
			auto tot = (days / 2) * 2 + (days + 1) / 2;

			if (ones % 2 != (days + 1) / 2 % 2)
				tot--;
			if (tot < sum)
				return false;

			return true;
		};

		while (!ok())
			days++;

		best = min(best, days);
	}

	cout << best << endl;
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