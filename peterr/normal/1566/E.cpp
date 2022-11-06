#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
vector<int> adjList[MAXN + 1];
bool bud[MAXN + 1];
int leaves[MAXN + 1];

void dfs(int v, int p)
{
	for (int adj : adjList[v])
	{
		if (adj == p)
			continue;
		dfs(adj, v);
		if (!bud[adj])
		{
			bud[v] = true;
			leaves[v]++;
		}
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
		fill(bud + 1, bud + n + 1, false);
		fill(leaves + 1, leaves + n + 1, 0);
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
		int ans = 0;
		int numBuds = 0;
		for (int i = 1; i <= n; i++)
		{
			//cout << "is bud " << i << " " << bud[i] << endl;
			numBuds += bud[i] && i > 1;
			ans += leaves[i];
		}
		//cout << "leaves " << ans << endl;
		if (leaves[1])
		{
			//cout << "Here\n";
			ans -= numBuds;
		}
		else
		{
			ans -= max(0, numBuds - 1);
		}
		cout << ans << "\n";
	}
	return 0;
}