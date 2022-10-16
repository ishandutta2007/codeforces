#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<int> perm(n);

	for (auto &it: perm)
	{
		cin >> it;
		it--;
	}

	auto get_pref = [](auto be, int n)
	{
		vector<vector<int>> pref(n + 1, vector<int>(n + 1));

		for (auto i: ranges::iota_view(1, ssize(pref)))
		{
			pref[i] = pref[i - 1];

			for (auto j: ranges::iota_view(*(be + i - 1) + 1, ssize(pref[i])))
				pref[i][j]++;
		}

		return pref;
	};

	auto pref = get_pref(perm.begin(), n);
	auto suff = get_pref(perm.rbegin(), n);
	ranges::reverse(suff);

	ll ans = 0;

	for (auto b: ranges::iota_view(0, ssize(perm)))
		for (auto c: ranges::iota_view(b + 1, ssize(perm)))
			ans += pref[b][perm[c]] * suff[c + 1][perm[b]];

	cout << ans << '\n';
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