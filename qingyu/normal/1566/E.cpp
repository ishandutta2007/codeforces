#include <bits/stdc++.h>

const int N = 5e5 + 50;
using namespace std;

int f[N];
bool leaf[N];
vector<int> G[N];

void dfs(int x, int f = 0)
{
	leaf[x] = (G[x].size() == 1);
	for (int y : G[x])
		if (y != f)
		{
			dfs(y, x);
			if (!::f[y]) ++::f[x];
		}
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	int Case;
	cin >> Case;
	while (Case--)
	{
		int n;
		cin >> n;
		for (int i = 1; i <= n; ++i) G[i].clear(), f[i] = 0, leaf[i] = 0;
		for (int i = 1; i < n; ++i)
		{
			int x, y;
			cin >> x >> y;
			G[x].push_back(y);
			G[y].push_back(x);
		}
		dfs(1);
		int ans = 1;
		for (int i = 1; i <= n; ++i)
			if (f[i] > 0)
				ans += f[i] - 1;
		cout << ans << '\n';
	}
	
}