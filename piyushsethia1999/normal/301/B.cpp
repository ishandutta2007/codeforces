#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define iii pair<int, int>
#define INF 1e8

using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	#ifdef PIYUSH_AASHIRWAAD
		I_O;
	#else
	#define print(...) 0
	#endif
	int n, weight;
	cin >> n >> weight;
	std::vector<int> grid(201*201, 0);
	std::vector<std::vector<int> > adj(201*201);
	for (int i = 0; i < 200; ++i)
		for (int j = 0; j < 201; ++j)
		{
			adj[i*201 + j].pb((i+1)*201 + j);
			adj[j*201 + i].pb(j*201 + (i+1));
			adj[(200 - i)*201 + j].pb((199 - i)*201 + j);
			adj[j*201 + (200 - i)].pb(j*201 + (199 - i));
		}
	std::vector<int> a(n, 0);
	for (int i = 1; i < n-1; ++i)
		cin >> a[i];
	int x, y;
	cin >> x >> y;
	int src = (x+100)*201 + y + 100;
	for(int i = 1; i < n-1; i++)
	{
		cin >> x >> y;
		grid[(x+100)*201 + y + 100] = a[i];
	}
	cin >> x >> y;
	int dest = (x+100)*201 + y + 100;
	print(src, dest);

	priority_queue< iii, vector <iii> , greater<iii> > pq;
	vector<int> maxtime(201*201, INF);
	pq.push(mp(0, src));
	maxtime[src] = 0;
	std::vector<bool> vis(201*201, false);
	while (!pq.empty())
	{
		int u = pq.top().second;
		pq.pop();
		if(!vis[u]) {
	 		vis[u] = true;
			for (int v : adj[u])
				if (!vis[v] && (maxtime[v] > maxtime[u] + weight - grid[u]))
				{
					maxtime[v] = maxtime[u] + weight - grid[u];
					pq.push(mp(maxtime[v], v));
				}
		}
	}
	print(maxtime[src], maxtime[dest], 201*201);
	cout << maxtime[dest];
}