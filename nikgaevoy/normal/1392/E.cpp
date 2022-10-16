#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<vector<ull>> ans(n, vector<ull>(n));

	for (int sum = 0; sum <= 2 * (n - 1); sum++)
		for (int i = 0; i <= sum; i++)
			if (i < n && sum - i < n && i % 2 == 0)
				ans[i][sum - i] = 1ull << (unsigned) sum;

	for (auto &row : ans)
	{
		for (auto it : row)
			cout << it << ' ';
		cout << endl;
	}

	cout << flush;

	int q;

	cin >> q;

	for (int i = 0; i < q; i++)
	{
		ull val;

		cin >> val;

		vector<pair<int, int>> pos;
		pos.emplace_back();

		while (pos.size() < 2 * n - 1)
		{
			if (pos.back().first == n - 1)
				pos.emplace_back(pos.back().first, pos.back().second + 1);
			else if (pos.back().second == n - 1)
				pos.emplace_back(pos.back().first + 1, pos.back().second);
			else
			{
				if (ans[pos.back().second][pos.back().first + 1] != 0)
				{
					if (ans[pos.back().second][pos.back().first + 1] & val)
						pos.emplace_back(pos.back().first + 1, pos.back().second);
					else
						pos.emplace_back(pos.back().first, pos.back().second + 1);
				}
				else if (ans[pos.back().second + 1][pos.back().first] != 0)
				{
					if (ans[pos.back().second + 1][pos.back().first] & val)
						pos.emplace_back(pos.back().first, pos.back().second + 1);
					else
						pos.emplace_back(pos.back().first + 1, pos.back().second);
				}
				else
					assert(false);
			}
		}

		assert(pos.back() == pair(n - 1, n - 1));

		for (auto it : pos)
			cout << it.second + 1 << ' ' << it.first + 1 << endl;
	}
}


int main()
{
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);

	cout << fixed;

#ifdef LOCAL
	auto st = clock();

	ifstream fin("../input.txt");

	solve();

	cout << setprecision(6) << "clock: " << double(clock() - st) / CLOCKS_PER_SEC << endl;
#else
	solve();
#endif

	return 0;
}