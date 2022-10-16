#include <bits/stdc++.h>

using namespace std;

using ll = long long;


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int test;
	cin >> test;

	const int let = 26;

	int n, m, k;
	for (int it = 0; it < test; it++)
	{
		cin >> n >> m >> k;

		vector<int> cnt(let);
		string s;
		cin >> s;
		for (char ch : s)
			cnt[ch - 'A']++;

		ll ans = (ll)n * m;
		for (int i = 0; i < let; i++)
		{
			vector<char> can(n + 1, 0);
			can[0] = 1;

			for (int j = 0; j < let; j++)
			{
				if (j == i)
					continue;

				for (int sum = n; sum >= cnt[j]; sum--)
					can[sum] |= can[sum - cnt[j]];
			}

			for (int sum = n; sum >= max(0, n - cnt[i]); sum--)
			{
				if (!can[sum])
				    continue;

				int x = n - sum;
				assert(0 <= x && x <= cnt[i]);
				int y = max(0, m - (k - sum - cnt[i]));
				ans = min(ans, (ll)x * y);
			}
		}

		cout << ans << "\n";
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed;

#ifdef LOCAL
	ifstream fin("../input.txt");

	solve(fin);

	cout << setprecision(4) << "clock: " << clock() / (double) CLOCKS_PER_SEC << endl;
#else
	cout << setprecision(20);

	solve();
#endif

	return 0;
}