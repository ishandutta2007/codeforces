#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int inf = 1e9 + 7;


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, q;

	cin >> n >> q;

	string str;

	cin >> str;

	vector<vector<int>> nxt(str.size() + 1, vector<int>(26, inf));

	vector<int> pos(26, inf);

	for (int i = str.size(); i >= 0; i--)
	{
		nxt[i] = pos;

		if (i > 0)
			pos[str[i - 1] - 'a'] = i - 1;
	}

	vector<string> relic(3);

	vector<vector<vector<int>>> dp(251);

	for (auto &row : dp)
	{
		row.resize(251);

		for (auto &it : row)
			it.assign(251, inf);
	}

	dp[0][0][0] = 0;

	for (int quer = 0; quer < q; quer++)
	{
		char t;
		int r;

		cin >> t >> r;
		r--;

		if (t == '+')
		{
			char c;

			cin >> c;

			relic[r] += c;

			for (int i = (r == 0 ? relic[0].size() : 0); i <= (int) relic[0].size(); i++)
				for (int j = (r == 1 ? relic[1].size() : 0); j <= (int) relic[1].size(); j++)
					for (int k = (r == 2 ? relic[2].size() : 0); k <= (int) relic[2].size(); k++)
					{
						if (i > 0 && dp[i - 1][j][k] != inf)
							dp[i][j][k] = min(dp[i][j][k], nxt[dp[i - 1][j][k]][relic[0][i - 1] - 'a'] + 1);
						if (j > 0 && dp[i][j - 1][k] != inf)
							dp[i][j][k] = min(dp[i][j][k], nxt[dp[i][j - 1][k]][relic[1][j - 1] - 'a'] + 1);
						if (k > 0 && dp[i][j][k - 1] != inf)
							dp[i][j][k] = min(dp[i][j][k], nxt[dp[i][j][k - 1]][relic[2][k - 1] - 'a'] + 1);
					}
		}
		else
		{
			assert(t == '-');

			for (int i = (r == 0 ? relic[0].size() : 0); i <= (int) relic[0].size(); i++)
				for (int j = (r == 1 ? relic[1].size() : 0); j <= (int) relic[1].size(); j++)
					for (int k = (r == 2 ? relic[2].size() : 0); k <= (int) relic[2].size(); k++)
						dp[i][j][k] = inf;

			relic[r].pop_back();
		}

		cout << (dp[relic[0].size()][relic[1].size()][relic[2].size()] != inf ? "yes" : "no") << endl;
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