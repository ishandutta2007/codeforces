#include <bits/stdc++.h>
 
using namespace std;

const int MAXN = 3E5;
int c[MAXN + 1];
vector<int> adjList[MAXN + 1];
bool ans[MAXN + 1];
int sum[MAXN + 1];
int par[MAXN + 1];
int marked_children[MAXN + 1];

void mark(int v, int p)
{
	ans[v] = true;
	for (int adj : adjList[v])
	{
		if (adj == p || ans[adj])
			continue;
		mark(adj, v);
	}
}

void dfs(int v, int p)
{
	par[v] = p;
	sum[v] = c[v];
	for (int adj : adjList[v])
	{
		if (adj == p)
			continue;
		dfs(adj, v);
		sum[v] += sum[adj];
		if (sum[adj])
			marked_children[v]++;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int k = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> c[i];
		k += c[i];
		ans[i] = c[i];
	}
	for (int i = 0; i < n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}
	dfs(1, 1);
	bool all = false;
	for (int i = 1; i <= n; i++)
	{
		if (!c[i])
			continue;
		for (int adj : adjList[i])
		{
			if (c[adj])
				all = true;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (!c[i])
			continue;
		int nonzero = 0;
		int cur_sum = 0;
		for (int adj : adjList[i])
		{
			if (adj == par[i])
				continue;
			if (sum[adj])
				nonzero++;
			cur_sum += sum[adj];
		}
		if (nonzero > 1)
		{
			all = true;
		}
		else if (nonzero == 1)
		{
			if (cur_sum + 1 != k)
				all = true;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (!c[i])
			continue;
		for (int adj : adjList[i])
		{
			if (adj == par[i])
				continue;
			if (marked_children[adj] >= 2)
				all = true;
		}	
		int num = marked_children[par[i]] + (sum[par[i]] != k) - 1;
		if (num >= 2)
			all = true;
	}
	if (all)
	{
		fill(ans + 1, ans + n + 1, true);
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			if (!c[i])
				continue;
			bool found = false;
			for (int adj : adjList[i])
			{
				if (adj == par[i])
					continue;
				if (!sum[adj])
					mark(adj, i);
				else
				{
					found = true;
					for (int adjadj : adjList[adj])
					{
						if (adjadj == i || sum[adjadj])
							continue;
						mark(adjadj, adj);
					}
				}
			}
			if (found && par[i] != i)
				mark(par[i], i);
			if (!found)
			{
				for (int adj : adjList[par[i]])
				{
					if (adj == par[i] || adj == par[par[i]] || sum[adj])
						continue;
					mark(adj, par[i]);
				}
				if (sum[par[i]] == k && par[par[i]] != par[i])
					mark(par[par[i]], par[i]);
			}
		}
	}	
	for (int i = 1; i <= n; i++)
	{
		if (!c[i])
			continue;
		for (int adj : adjList[i])
		{
			ans[adj] = true;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		cout << ans[i] << " \n"[i == n];
	}
	return 0;
}