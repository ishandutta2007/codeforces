#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	array<string, 2> rows;

	for (auto &it: rows)
		cin >> it;

	int prev = -1;
	int ans = 0;

	for (int i = 0; i < n; i++)
	{
		if (rows[0][i] != rows[1][i])
		{
			if (prev == 0)
				ans++;
			ans += 2;
			prev = -1;
		}
		else
		{
			if (prev >= 0)
			{
				if (prev != (rows[0][i] - '0'))
				{
					ans += 2;

					prev = -1;
				}
				else
				{
					if (prev == 0)
						ans++;

					prev = (rows[0][i] - '0');
				}
			}
			else
			{
				prev = (rows[0][i] - '0');
			}
		}
	}

	if (prev == 0)
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