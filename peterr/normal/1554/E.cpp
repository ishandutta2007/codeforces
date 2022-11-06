#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
const int MOD = 998244353;
vector<int> adjList[MAXN + 1];
int cnt[MAXN + 1];
int ways[MAXN + 1];
int ans[MAXN + 1];

bool dfs(int v, int p, int g)
{
	//cout << "dfs " << v << " " << g << endl;
	for (int adj : adjList[v])
	{
		if (adj == p)
			continue;
		if (!dfs(adj, v, g))
			return false;
	}
	if (v != p)
	{
		if (cnt[v] % g == 0)
			cnt[p]++;
		else
			cnt[v]++;
	}
	return cnt[v] % g == 0;
}

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
		for (int i = 1; i <= n; i++)
		{
			adjList[i].clear();
		}
		for (int i = 0; i < n - 1; i++)
		{
			int u, v;
			cin >> u >> v;
			adjList[u].push_back(v);
			adjList[v].push_back(u);
		}
		ways[1] = 1;
		for (int i = 0; i < n - 1; i++)
			ways[1] = (int) ((long long) ways[1] * 2 % MOD);
		for (int i = 2; i <= n; i++)
		{
			if ((n - 1) % i != 0)
				ways[i] = 0;
			else
			{
				fill(cnt + 1, cnt + n + 1, 0);
				ways[i] = dfs(1, 1, i);
			}
		}
		//for (int i = 1; i <= n; i++)
		//{
			//cout << "ways " << i << " = " << ways[i] << endl;
		//}
		for (int i = n; i >= 1; i--)
		{
			ans[i] = ways[i];
			for (int j = 2 * i; j <= n; j += i)
			{
				add(ans[i], MOD - ans[j]);
			}
		}
		for (int i = 1; i <= n; i++)
		{
			cout << ans[i] << " \n"[i == n];
		}
	}
	return 0;
}