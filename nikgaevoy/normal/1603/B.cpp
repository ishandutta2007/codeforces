#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	ll x, y;

	cin >> x >> y;

	ll n;

	if (y < x)
		n = x + y;
	else
		n = y - (y % x / 2);

	assert(n % x == y % n);

	cout << n << endl;
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int t;

	cin >> t;

	for (int i = 0; i < t; i++)
		solve_test(cin, cout);
}


void gen(ostream &cout = std::cout)
{
	cout << 1 << endl;

	uniform_int_distribution<int> uid(1, 10);

	cout << 2 * uid(mt) << ' ' << 2 * uid(mt) << endl;
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

	while (true)
	{
		stringstream ss;

		gen(ss);

		solve(ss);
	}

	cout << setprecision(6) << "clock: " << double(clock() - st) / CLOCKS_PER_SEC << endl;
#else
	solve();
#endif

	return 0;
}