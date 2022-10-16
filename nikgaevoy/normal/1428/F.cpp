#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;
	string str;

	cin >> n >> str;

	vector<pair<int, int>> dp;
	ll ans = 0, sum = 0;

	for (int l = 0, r; l < str.size(); l = r)
	{
		for (r = l; r < str.size() && str[r] == '1'; r++);

		if (l == r)
		{
			ans += sum;
			if (!dp.empty() && dp.back().first == 0)
				dp.back().second++;
			else
				dp.emplace_back(0, 1);
			r++;
		}
		else
		{
			for (int i = 1; i <= r - l; i++)
			{
				if (!dp.empty() && dp.back().first < i)
				{
					int q = dp.back().second;
					sum += q;
					dp.pop_back();
					if (!dp.empty() && dp.back().first == i)
						dp.back().second += q;
					else
						dp.emplace_back(i, q);
				}

				ans += sum + i * (i + 1ll) / 2;
			}

			for (int i = r - l; i > 0; i--)
			{
				if (!dp.empty() && dp.back().first == i)
					dp.back().second++;
				else
					dp.emplace_back(i, 1);
				sum += i;
			}
		}
	}

	cout << ans << endl;
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