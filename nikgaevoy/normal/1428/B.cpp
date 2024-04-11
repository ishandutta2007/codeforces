#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;
	string str;

	cin >> n >> str;

	bool cw = true, ccw = true;

	for (auto it : str)
		if (it == '<')
			cw = false;
		else if (it == '>')
			ccw = false;

	if (cw || ccw)
	{
		cout << n << endl;

		return;
	}

	int ans = 0;

	for (int i = 0; i < str.size(); i++)
		if (str[i] == '-' || str[(i + 1) % str.size()] == '-')
			ans++;

	cout << ans << endl;
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