#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
vector<int> adjList[MAXN + 1];
int ans[MAXN + 1];
vector<int> gathered;
bool used[MAXN + 1];

int dfs(int v, int p, bool yes=true)
{
	int cnt = yes;
	for (int adj : adjList[v])
	{
		if (adj == p)
			continue;
		cnt += dfs(adj, v, !yes);
	}
	return cnt;
}

void gather(int v, int p, bool yes=true)
{
	if (yes)
		gathered.push_back(v);
	for (int adj : adjList[v])
	{
		if (adj == p)
			continue;
		gather(adj, v, !yes);
	}
}

bool solve(int root, int n)
{
	//cout << "solve " << root << endl;
	if (dfs(root, root) * 2 > n)
		return false;
	int cnt = dfs(root, root);
	gathered.clear();
	gather(root, root);
	fill(used + 1, used + n + 1, false);
	fill(ans + 1, ans + n + 1, -1);
	for (int i = 0; i < 30; i++)
	{
		if (cnt & (1 << i))
		{
			int amt = 1 << i;
			for (int j = 0; j < amt; j++)
			{
				ans[gathered.back()] = amt + j;
				gathered.pop_back();
				used[amt + j] = true;
			}
		}
	}
	int ptr = 1;
	for (int j = 1; j <= n; j++)
	{
		if (ans[j] == -1)
		{
			while (used[ptr])
				ptr++;
			ans[j] = ptr;
			used[ptr] = true;
		}
	}
	//cout << "solved " << endl;
	return true;
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
		if (n == 1)
		{
			cout << "1\n";
		}
		else
		{
			if (!solve(1, n))
			{
				solve(adjList[1].back(), n);
			}
			for (int i = 1; i <= n; i++)
			{
				cout << ans[i] << " \n"[i == n];
			}
		}
	}
	return 0;
}