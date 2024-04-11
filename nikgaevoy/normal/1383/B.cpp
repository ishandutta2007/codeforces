#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<unsigned> arr(n);

	for (auto &it : arr)
		cin >> it;

	unsigned x = 0;

	for (auto &it : arr)
		x ^= it;

	if (x == 0)
	{
		cout << "DRAW" << endl;

		return;
	}

	while ((x & (x - 1)) != 0)
		x &= x - 1;

	int zer = 0, one = 0;

	for (auto it : arr)
		if (it & x)
			one++;
		else
			zer++;

	zer %= 2;

	bool ans;

	if (zer == 0)
		ans = (one + 1) / 2 % 2 != 0;
	else
		ans = true;

	cout << (ans ? "WIN" : "LOSE") << endl;
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