#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<int> perm(2 * n);

	for (auto &it : perm)
	{
		cin >> it;
		it--;
	}

	auto me = perm;

	for (int i = 1; i < me.size(); i++)
		me[i] = max(me[i], me[i - 1]);

	vector<int> blocks;

	for (int l = 0, r; l < me.size(); l = r)
	{
		for (r = l; r < me.size() && me[r] == me[l]; r++);

		blocks.push_back(r - l);
	}

	bitset<2001> bs(1);

	for (auto it : blocks)
		bs |= bs << it;

	cout << (bs.test(n) ? "YES" : "NO") << endl;
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