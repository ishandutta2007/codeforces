#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	array<int, 4> arr{};

	for (auto &it : arr)
		cin >> it;

	for (unsigned mask = 0; mask < (1u << 4u); mask++)
	{
		bool good = true;

		for (unsigned i = 0; i < 4 && good; i++)
		{
			int add = 0;

			add += (mask >> i) & 1u;
			add += (mask >> ((i + 1) % 4)) & 1u;

			good &= add <= arr[i] && arr[i] <= n - 2 + add;
		}

		if (good)
		{
			cout << "yes" << endl;

			return;
		}
	}

	cout << "no" << endl;
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
		while (getline(fin, str) && str != string(max(1, (int)str.size()), '='));
	} while (fin);

	cout << setprecision(6) << "clock: " << double(clock() - st) / CLOCKS_PER_SEC << endl;
#else
	solve();
#endif

	return 0;
}