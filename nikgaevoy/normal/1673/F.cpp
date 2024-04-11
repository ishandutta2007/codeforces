#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, k;

	cin >> n >> k;

	vector matr(n, vector<unsigned>(n));

	for (auto y: ranges::iota_view(0, n))
	{
		for (auto x: ranges::iota_view(0, n))
		{
			if (x == 0)
			{
				if (y != 0)
					matr[y][x] = matr[y - 1][x] ^ (1u << (__builtin_ctz(y) * 2 + 1));
			}
			else
				matr[y][x] = matr[y][x - 1] ^ (1u << (__builtin_ctz(x) * 2));
		}
	}

	unsigned sum = 0;

	for (auto y: ranges::iota_view(0, n))
	{
		for (auto x: ranges::iota_view(1, n))
		{
			auto val = matr[y][x] ^ matr[y][x - 1];

			cout << val << ' ';

			sum += val;
		}
		cout << endl;
	}

	for (auto y: ranges::iota_view(1, n))
	{
		for (auto x: ranges::iota_view(0, n))
		{
			auto val = matr[y][x] ^ matr[y - 1][x];

			cout << val << ' ';

			sum += val;
		}
		cout << endl;
	}

	unordered_map<unsigned, pair<int, int>> mp;

	for (auto y: ranges::iota_view(0, n))
		for (auto x: ranges::iota_view(0, n))
		{
			assert(!mp.contains(matr[y][x]));

			mp[matr[y][x]] = {x, y};
		}

	assert(sum <= 48000);

	int pos = 0;

	for (auto q: ranges::iota_view(0, k))
	{
		int t;

		cin >> t;

		pos ^= t;

		auto [x, y] = mp.at(pos);

		cout << y + 1 << ' ' << x + 1 << endl;
	}
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int t = 1;

	for (int i = 0; i < t; i++)
		solve_test(cin, cout);
}


int main()
{
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