#include <bits/stdc++.h>
 
using namespace std;

const int MAXN = 2E5;
vector<int> adjList[MAXN + 1];
vector<int> top;
bool visited[MAXN + 1];
int indeg[MAXN + 1];
int outdeg[MAXN + 1];
int dp[MAXN + 1];

void dfs(int v)
{
	visited[v] = true;
	for (int adj : adjList[v])
	{
		if (visited[adj])
			continue;
		dfs(adj);
	}
	top.push_back(v);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		adjList[u].push_back(v);
		indeg[v]++;
		outdeg[u]++;
	}
	for (int i = 1; i <= n; i++)
	{
		if (!visited[i])
			dfs(i);
	}
	int ans = 0;
	for (int v : top)
	{
		dp[v] = 1;
		if (outdeg[v] > 1)
		{
			for (int adj : adjList[v])
			{
				if (indeg[adj] <= 1)
					continue;
				dp[v] = max(dp[v], dp[adj] + 1);
			}
		}
		ans = max(ans, dp[v]);
	}
	cout << ans << "\n";
	return 0;
}