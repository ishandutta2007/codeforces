#include <bits/stdc++.h>
 
using namespace std;

const int MAXN = 500;
const int INF = 1E9 + 5;
int dp[MAXN][MAXN + 1];
int d[MAXN];
int a[MAXN];

int main()
{
	int n, l, k;
	cin >> n >> l >> k;
	for (int i = 0; i < n; i++)
		cin >> d[i];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	fill(dp[0] + 1, dp[0] + k + 1, INF);
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j <= k; j++)
		{
			dp[i][j] = INF;
			for (int z = 0; z < i; z++)
			{
				if (i - z - 1 > j)
					continue;
				dp[i][j] = min(dp[i][j], dp[z][j - (i - z - 1)] + a[z] * (d[i] - d[z]));
			}
		}
	}
	int ans = INF;
	for (int i = 0; i < n; i++)
	{
		if (n - i - 1 > k)
			continue;
		for (int j = 0; j <= k - (n - i - 1); j++)
			ans = min(ans, dp[i][j] + a[i] * (l - d[i]));
	}
	cout << ans << "\n";
	return 0;
}