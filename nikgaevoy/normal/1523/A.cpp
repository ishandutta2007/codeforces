#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, m;

	cin >> n >> m;

	string str;

	cin >> str;

	string ans;
	ans.reserve(str.size());

	for (int l = 0, r; l < str.size(); l = r)
	{
		for (r = l; r < str.size() && str[l] == str[r]; r++);

		if (str[l] == '1')
			ans += string(r - l, '1');
		if (str[l] == '0')
		{
			if (l > 0)
			{
				if (r < str.size())
				{
					int sz = min(m, (r - l) / 2);

					ans += string(sz, '1');
					ans += string(r - l - 2 * sz, '0');
					ans += string(sz, '1');
				}
				else
				{
					int sz = min(m, r - l);

					ans += string(sz, '1');
					ans += string(r - l - sz, '0');
				}
			}
			else
			{
				if (r < str.size())
				{
					int sz = min(m, r - l);

					ans += string(r - l - sz, '0');
					ans += string(sz, '1');
				}
				else
					ans = str;
			}
		}
	}

	assert(ans.size() == str.size());

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