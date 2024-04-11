#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000;
int dp[MAXN];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	dp[0] = 0;
	for (int i = 1; i < MAXN; i++)
	{
		dp[i] = dp[i - 1] + 15;
		dp[i] = min(dp[i], 15 + (i - 6 >= 0 ? dp[i - 6] : 0));
		dp[i] = min(dp[i], 20 + (i - 8 >= 0 ? dp[i - 8] : 0));
		dp[i] = min(dp[i], 25 + (i - 10 >= 0 ? dp[i - 10] : 0));
	}
	while (t--)
	{
		long long x;
		cin >> x;
		if (x >= MAXN)
		{
			if (x & 1)
				x++;
			cout << (x / 2) * 5 << "\n";
		}
		else
		{
			cout << dp[x] << "\n";
		}
	}
	return 0; 
}