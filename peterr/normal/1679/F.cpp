#include <bits/stdc++.h>

using namespace std;

const int MAXN = 50000;
const int MOD = 998244353;
bool adj[10][10];
int dp[MAXN + 1][1 << 10];
int tab[1 << 10][10];

void add(int &x, int y)
{
	x += y;
	if (x >= MOD)
		x -= MOD;
}

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u][v] = adj[v][u] = true;
	}
	for (int mask = 0; mask < (1 << 10); mask++)
	{
		for (int i = 0; i < 10; i++)
		{
			tab[mask][i] = 1 << i;
			bool good = true;
			for (int j = 0; j < 10; j++)
			{
				if (!(mask & (1 << j)))
					continue;
				if (adj[i][j] && j < i)
					good = false;
				if (adj[i][j])
					tab[mask][i] = tab[mask][i] | (1 << j);
			}
			if (!good)
				tab[mask][i] = -1;
		}
	}
	dp[0][0] = 1;
	for (int i = 0; i < n; i++)
	{
		for (int mask = 0; mask < (1 << 10); mask++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (tab[mask][j] == -1)
					continue;
				add(dp[i + 1][tab[mask][j]], dp[i][mask]);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < (1 << 10); i++)
	{
		add(ans, dp[n][i]);
	}
	cout << ans << "\n";
	return 0;
}