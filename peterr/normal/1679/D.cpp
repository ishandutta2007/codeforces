#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
int a[MAXN + 1];
int path[MAXN + 1];
vector<int> adjList[MAXN + 1];
bool visited[MAXN + 1];
bool rec[MAXN + 1];
long long threshold = 0;

bool hasCycle(int v)
{
	bool ans = false;
	rec[v] = visited[v] = true;
	for (int adj : adjList[v])
	{
		if (a[adj] > threshold)
			continue;
		if (rec[adj])
			ans = true;
		else if (visited[adj])
			continue;
		else if (hasCycle(adj))
			ans = true;
	}
	rec[v] = false;
	return ans;
}

void dfs(int v)
{
	visited[v] = true;
	path[v] = 1;
	for (int adj : adjList[v])
	{
		if (a[adj] > threshold)
			continue;
		if (!visited[adj])
			dfs(adj);
		path[v] = max(path[v], 1 + path[adj]);
	}
}

bool check(int n, long long k)
{
	//cout << "check " << threshold << endl;
	fill(visited + 1, visited + MAXN + 1, false);
	fill(rec + 1, rec + MAXN + 1, false);
	for (int i = 1; i <= n; i++)
	{
		if (visited[i] || a[i] > threshold)
			continue;
		if (hasCycle(i))
			return true;
	}
	//cout << "true" << endl;
	fill(visited + 1, visited + MAXN + 1, false);
	fill(path + 1, path + MAXN + 1, 0);
	for (int i = 1; i <= n; i++)
	{
		if (a[i] > threshold)
			continue;
		if (!visited[i])
		{
			dfs(i);
		}
		if (path[i] >= k)
			return true;
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	long long k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		adjList[u].push_back(v);
	}
	threshold = 1E9;
	if (!check(n, k))
	{
		cout << "-1\n";
		return 0;
	}
	int ans = 0;
	for (int jump = 1E9; jump; jump >>= 1)
	{
		while (ans + jump <= 1E9)
		{
			threshold = ans + jump;
			if (check(n, k))
				break;
			ans += jump;
		}
	}
	cout << ans + 1 << "\n";
	return 0;
}