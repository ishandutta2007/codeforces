#include <bits/stdc++.h>
 
using namespace std;

const int MAXN = 1 << 17;
vector<int> adjList[MAXN + 1];
pair<int, int> edges[MAXN];
int ans1[MAXN + 1];
int ans2[MAXN];
int cnt = 1;

void dfs(int v, int p, int n, bool flip=true)
{
	for (int edgeind : adjList[v])
	{
		int adj = v ^ edges[edgeind].first ^ edges[edgeind].second;
		if (adj == p)
			continue;
		if (flip)
		{
			ans1[adj] = cnt;
			ans2[edgeind] = cnt + n;
		}
		else
		{
			ans1[adj] = cnt + n;
			ans2[edgeind] = cnt;
		}
		cnt++;
		dfs(adj, v, n, !flip);
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
		int p;
		cin >> p;
		int n = 1 << p;
		for (int i = 1; i <= n; i++)
		{
			adjList[i].clear();
		}
		for (int i = 0; i < n - 1; i++)
		{
			int u, v;
			cin >> u >> v;
			edges[i] = {u, v};
			adjList[u].push_back(i);
			adjList[v].push_back(i);
		}
		cnt = 1;
		dfs(1, 1, n);
		ans1[1] = 1 << p;
		cout << "1\n";
		for (int i = 1; i <= n; i++)
		{
			cout << ans1[i] << " \n"[i == n];
		}
		for (int i = 0; i < n - 1; i++)
		{
			cout << ans2[i] << " \n"[i == n - 2];
		}
	}
	return 0;
}