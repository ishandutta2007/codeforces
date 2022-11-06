#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
vector<int> adjList[MAXN + 1];
int x[MAXN];
int friends[MAXN + 1];
int cutoffs[MAXN + 1];
vector<int> rec;

void dfs(int v, int p)
{
	rec.push_back(v);
	if (v != 1)
	{
		cutoffs[rec[(int) rec.size() / 2]] += friends[v];
	}
	for (int adj : adjList[v])
	{
		if (adj == p)
			continue;
		dfs(adj, v);
	}
	rec.pop_back();
}

bool canGo(int v, int p)
{
	if (v != 1 && (int) adjList[v].size() == 1)
	{
		return true;
	}
	for (int adj : adjList[v])
	{
		if (adj == p)
			continue;
		if (cutoffs[adj])
			continue;
		if (canGo(adj, v))
			return true;
	}
	return false;
}

int cntRedundant(int v, int p, bool covered)
{
	int ans = 0;
	if (covered)
		ans += cutoffs[v];
	else if (cutoffs[v])
	{
		covered = true;
		ans += cutoffs[v] - 1;
	}
	for (int adj : adjList[v])
	{
		if (adj == p)
			continue;
		ans += cntRedundant(adj, v, covered);
	}
	return ans;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		fill(friends + 1, friends + n + 1, 0);
		fill(cutoffs + 1, cutoffs + n + 1, 0);
		for (int i = 0; i < k; i++)
		{
			cin >> x[i];
			friends[x[i]]++;
		}
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
		dfs(1, 1);
		if (canGo(1, 1))
		{
			cout << "-1\n";
		}
		else
		{
			cout << k - cntRedundant(1, 1, false) << "\n";
		}
	}
	return 0;
}