#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5E5;
const int MOD = 998244353;
int a[MAXN];
int dp1[MAXN + 5];
int dp2[MAXN + 5];

void add(int &x, int y)
{
	x += y;
	if (x >= MOD)
		x -= MOD;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			if (x)
			{
				add(dp2[x - 1], dp2[x - 1]);
				add(dp2[x - 1], dp1[x - 1]);
			}
			add(dp1[x + 1], dp1[x + 1]);
			add(dp2[x + 1], dp2[x + 1]);
			add(dp1[x + 1], dp1[x]);
			if (x == 0)
				add(dp1[1], 1);
			if (x == 1)
				add(dp2[0], 1);
			//cout << "dp ";
			//for (int j = 0; j <= n + 1; j++)
				//cout << dp[j] << " ";
			//cout << "\n";
		}
		int ans = 0;
		for (int i = 0; i <= n + 3; i++)
		{
			add(ans, dp1[i]);
			add(ans, dp2[i]);
		}
		cout << ans << "\n";
		fill(dp1, dp1 + n + 3, 0);
		fill(dp2, dp2 + n + 3, 0);
	}
	return 0;
}