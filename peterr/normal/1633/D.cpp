#include <bits/stdc++.h>
 
using namespace std;

const int INF = 1E9;
const int MAXN = 1E3;
const int MAXK = 1E6;
int b[MAXN];
int c[MAXN];
int dp[MAXN + 1];
int ans[MAXK + 1];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	fill(dp + 1, dp + MAXN + 1, INF);
	dp[1] = 0;
	for (int i = 1; i <= MAXN; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (i + i / j > MAXN)
				continue;
			dp[i + i / j] = min(dp[i + i / j], dp[i] + 1);
		}
	}
	//for (int i = 1; i <= 30; i++)
	//{
		//cout << "dp " << i << " " << dp[i] << endl;
	//}
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		for (int i = 0; i < n; i++)
		{
			cin >> b[i];
		}
		for (int i = 0; i < n; i++)
		{
			cin >> c[i];
		}
		fill(ans, ans + MAXK + 1, 0);
		for (int i = 0; i < n; i++)
		{
			for (int j = k - dp[b[i]]; j >= 0; j--)
			{
				ans[j + dp[b[i]]] = max(ans[j + dp[b[i]]], c[i] + ans[j]);
			}
		}
		int res = 0;
		for (int i = 0; i <= k; i++)
		{
			res = max(res, ans[i]);
		}
		cout << res << "\n";
	}
	return 0;
}