#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
int cnt[MAXN + 1];
int ans;

void addEdge(int u, int v)
{
	if (u > v)
		swap(u, v);
	cnt[u]++;
	if (cnt[u] == 1)
		ans--;
}

void removeEdge(int u, int v)
{
	if (u > v)
		swap(u, v);
	cnt[u]--;
	if (cnt[u] == 0)
		ans++;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	ans = n;
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		addEdge(u, v);
	}
	int q;
	cin >> q;
	while (q--)
	{
		int type;
		cin >> type;
		if (type == 1)
		{
			int u, v;
			cin >> u >> v;
			addEdge(u, v);
		}
		else if (type == 2)
		{
			int u, v;
			cin >> u >> v;
			removeEdge(u, v);
		}
		else
		{
			cout << ans << "\n";
		}
	}
	return 0;
}