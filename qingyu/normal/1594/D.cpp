/*
2021.10.09
*/
#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 50;

int n, m;
int good[N], vis[N], c;
bool ban[N];
vector<int> G[N];

void add(int u, int v)
{
	G[u].push_back(v);
	G[v].push_back(u);
}

void dfs(int x)
{
	vis[x] = c;
	if (x <= n) ++good[c];
	for (int y : G[x])
		if (!vis[y])
			dfs(y);
}

inline int solve()
{
	cin >> n >> m;
	c = 0;
	for (int i = 1; i <= m; ++i)
	{
		int u, v; string s;
		cin >> u >> v >> s;
		if (s[0] == 'i')
		{
			add(u, v + n);
			add(v, u + n);
		}
		else
		{
			add(u, v);
			add(u + n, v + n);
		}
	}
	for (int i = 1; i <= n + n; ++i)
	{
		if (!vis[i])
		{
			++c;
			dfs(i);
		}
	}
	for (int i = 1; i <= n; ++i)
		if (vis[i] == vis[i + n])
			return -1;
	int ans = 0;
	for (int i = 1; i <= n; ++i)
		if (!ban[vis[i]])
		{
			ans += max(good[vis[i]], good[vis[i + n]]);
			ban[vis[i]] = ban[vis[i + n]] = 1;
		}
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--)
	{
		cout << solve() << '\n';
	for (int i = 1; i <= 2 * n; ++i) G[i].clear(), good[i] = vis[i] = ban[i] = 0;
	}
}