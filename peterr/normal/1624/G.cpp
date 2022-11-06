#include <bits/stdc++.h>
 
using namespace std;

const int MAXN = 2E5;
int par[MAXN + 1];
int sz[MAXN + 1];
vector<tuple<int, int, int>> edges;

int getRoot(int x)
{
	if (par[x] != x)
		par[x] = getRoot(par[x]);
	return par[x];
}

bool mge(int x, int y)
{
	x = getRoot(x);
	y = getRoot(y);
	if (x == y)
		return false;
	if (sz[x] > sz[y])
		swap(x, y);
	par[x] = y;
	sz[y] += sz[x];
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
		int n, m;
		cin >> n >> m;
		edges = vector<tuple<int, int, int>>(m);
		for (int i = 0; i < m; i++)
		{
			int u, v, w;
			cin >> u >> v >> w;
			edges[i] = {w, u, v};
		}
		int ans = 0;
		int pos = 30;
		while (pos)
		{
			//cout << "pos " << pos << endl;
			for (int i = 0; i <= pos; i++)
			{
				//cout << "iter " << i << endl;
				fill(sz + 1, sz + n + 1, 1);
				for (int j = 1; j <= n; j++)
				{
					par[j] = j;
				}
				int cnt = 0;
				for (tuple<int, int, int> edge : edges)
				{
					if (get<0>(edge) >= (1 << i))
						continue;
					//cout << "edge " << endl;
					if (mge(get<1>(edge), get<2>(edge)))
						cnt++;
				}
				if (cnt == n - 1)
				{
					pos = i;
					//cout << "stop " << pos << endl;
					break;
				}
			}
			if (pos)
				ans = ans | (1 << (pos - 1));
			for (int i = (int) edges.size() - 1; i >= 0; i--)
			{
				if (get<0>(edges[i]) >= (1 << pos))
				{
					swap(edges[i], edges.back());
					edges.pop_back();
				}
				else if (pos && (get<0>(edges[i]) & (1 << (pos - 1))))
				{
					get<0>(edges[i]) = get<0>(edges[i]) ^ (1 << (pos - 1));
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}