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
	int n;
	cin >> n;
	vector<int> e(n);
	for (auto &v : e)
		cin >> v;
	sort(e.begin(), e.end());
	vector<int> dp(n);

	for (int i(0); i < n; ++i)
	{
		if (i+1 >= e[i])
			dp[i] = 1 + (i-e[i] >= 0 ? dp[i-e[i]] : 0);
		if (i) dp[i] = max(dp[i], dp[i-1]);
	}

	return dp[n-1];
}