#include <bits/stdc++.h>

using namespace std;

using ll = long long;

mt19937 mt(736);


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<vector<bool>> gr(n, vector<bool>(n));

	for (auto &row : gr)
	{
		string str;

		cin >> str;

		for (int i = 0; i < str.size(); i++)
			row[i] = str[i] == '1';
	}

	vector<vector<vector<ll>>> dp(gr.size(), vector<vector<ll>>(1u << gr.size()));

	for (auto &row : dp)
		for (unsigned mask = 1; mask < row.size(); mask++)
			row[mask].resize(1u << (unsigned) (__builtin_popcount(mask) - 1));

	for (unsigned i = 0; i < gr.size(); i++)
		dp[i][1u << i][0] = 1;

	for (unsigned mask = 0; mask < dp.front().size(); mask++)
		for (int last = 0; last < n; last++)
			for (unsigned type = 0; type < dp[last][mask].size(); type++)
				for (size_t i = 0; i < gr.size(); i++)
					if (((1u << i) & mask) == 0)
						dp[i][mask | (1u << i)][(type << 1u) | (gr[last][i] ? 1u : 0u)] += dp[last][mask][type];

	for (unsigned i = 0; i < (1u << (gr.size() - 1)); i++)
	{
		ll cnt = 0;

		for (int j = 0; j < gr.size(); j++)
			cnt += dp[j].back()[i];

		cout << cnt << ' ';
	}

	cout << endl;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed;

#ifdef LOCAL
	auto st = clock();

	ifstream fin("../input.txt");

	solve(fin);

	cout << "clock: " << (clock() - st) / (double) CLOCKS_PER_SEC << endl;
#else
	solve();
#endif

	return 0;
}