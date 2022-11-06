#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int n; cin >> n;
	int m; cin >> m;
	vector<vector<int> > adj(n); for (int o = 0; o < m; o++) { int x, y; cin >> x >> y; x--; y--; adj[x].pb(y); adj[y].pb(x); }
	std::vector<int> vis(n, 0);
	std::vector<int> vv;
	priority_queue<int> pq;
	pq.push(0);
	while(!pq.empty()) {
		int t = -pq.top();
		pq.pop();
		if (!vis[t])
		{
			vis[t] = 1;
			vv.pb(t);
			for (int v : adj[t])
			{
				if(!vis[v])
				{
					pq.push(-v);
				}
			}
		}
	}
	for (int i = 0; i < n; ++i)
	{
		cout << vv[i] + 1 << " ";
	}
}