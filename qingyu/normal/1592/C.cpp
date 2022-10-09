#include <bits/stdc++.h>

using namespace std;

const int N = 255555;
int n, k, sum, a[N], f[N], g[N];
std::vector<int> G[N];
bool ok;

void dfs(int x, int fa = 0)
{
	f[x] = a[x];	
	for (int y : G[x])
		if (y != fa)
		{
			dfs(y, x);
			f[x] ^= f[y];
		}
	if (f[x] == sum) ok = true;
}

void dfs2(int x, int fa = 0)
{
	f[x] = a[x];
	g[x] = 0;
	int xorsum = a[x];
	for (int y : G[x])
	{
		if (y != fa)
		{
			dfs2(y, x);
			f[x] ^= f[y];
			if (g[y] == 0) xorsum ^= f[y];
			else if (g[y] == 1) xorsum ^= f[y] ^ sum;
			else return;
			g[x] += g[y];
		}
		if (ok) return;
	}
	if (xorsum == sum)
	{
		g[x] = min(g[x] + 1, 2);
	}
	if (g[x] >= 2)
	{
		ok = true;
		return;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		sum = 0;
		cin >> n >> k;
		for (int i = 1; i <= n; ++i)
		{
			G[i].clear();
			cin >> a[i];
			sum ^= a[i];
		}
		for (int i = 1; i < n; ++i)
		{
			int u, v;
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		if (k == 2)
		{
			if (sum)
			{
				puts("NO");
				continue;
			}
		}
		else
		{

		}
		if (!sum)
		{
			ok = false;
			dfs(1);
			if (ok)
			{
				puts("YES");
				continue;
			}
		}
		if (k != 2)
		{
			ok = false;
			dfs2(1);
			if (ok)
			{
				puts("YES");
				continue;
			}
		}
		puts("NO");

	}
}