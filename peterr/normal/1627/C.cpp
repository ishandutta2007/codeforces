#include <bits/stdc++.h>
 
using namespace std;

const int MAXN = 1E5;
vector<pair<int, int>> adjList[MAXN + 1];
int ans[MAXN];

void dfs(int v, int p, int d)
{
	for (pair<int, int> edge : adjList[v])
	{
		if (edge.first == p)
			continue;
		if (d & 1)
			ans[edge.second] = 2;
		else
			ans[edge.second] = 3;
		dfs(edge.first, v, d + 1);
	}
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
			adjList[i].clear();
		bool ok = true;
		for (int i = 0; i < n - 1; i++)
		{
			int u, v;
			cin >> u >> v;
			adjList[u].push_back({v, i});
			adjList[v].push_back({u, i});
			if (adjList[u].size() > 2 || adjList[v].size() > 2)
				ok = false;
		}
		if (ok)
		{
			int v = 1;
			while (adjList[v].size() == 2)
				v++;
			dfs(v, v, 0);
			for (int i = 0; i < n - 1; i++)
				cout << ans[i] << " \n"[i == n - 2];
			}
		else
			cout << "-1\n";
	}
	return 0;
}