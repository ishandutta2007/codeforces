#include <bits/stdc++.h>
using namespace std;

#define SZ(v) ((int)(v).size())
using ll = long long;

ll solve(void);

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int nb_tests;
	cin >> nb_tests;

	for (int i(0); i < nb_tests; ++i)
		cout << solve() << '\n'; 
}

ll solve(void)
{
	int nbCarac;
	cin >> nbCarac;
	string target, start;
	cin >> start >> target;
	vector<array<int, 26> > prefixSumTarget(nbCarac), prefixSumStart(nbCarac);
	for (int i(0); i < nbCarac; ++i)
		for (int j(0); j < 26; ++j)
		{
			prefixSumStart[i][j] = (i ? prefixSumStart[i-1][j] : 0) + (start[i] == 'a'+j);
			prefixSumTarget[i][j] = (i ? prefixSumTarget[i-1][j] : 0) + (target[i] == 'a'+j);
		}

	for (int i(0); i < 26; ++i)
		if (prefixSumTarget[nbCarac-1][i] != prefixSumStart[nbCarac-1][i])
			return -1;
	
	vector<vector<int>> dp(nbCarac + 1, vector<int>(nbCarac + 1));

	for (int i(0); i < nbCarac; ++i)
		dp[0][i] = 0;
	for (int takeStart(1); takeStart <= nbCarac; ++takeStart)
		for (int takeTarget(takeStart); takeTarget <= nbCarac; ++takeTarget)
		{
			int &x = dp[takeStart][takeTarget];
			x = 1e9;
			int targetChar = target[takeTarget-1] - 'a';
			if (target[takeTarget - 1] == start[takeStart - 1])
				x = min(x, dp[takeStart - 1][takeTarget - 1]);
			x = min(x, dp[takeStart-1][takeTarget] + 1);
			if (prefixSumTarget[takeTarget-1][targetChar] > prefixSumStart[takeStart-1][targetChar]
				and takeStart < takeTarget)
				x = min(x, dp[takeStart][takeTarget-1]);
		}
	return dp[nbCarac][nbCarac];
}