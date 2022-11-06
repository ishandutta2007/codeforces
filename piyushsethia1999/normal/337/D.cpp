#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;

void butr(std::vector<std::vector<int> >& adj, int n) { int x, y; for (int i = 0; i < n - 1 ; ++i) { cin >> x >> y; x--; y--; adj[x].pb(y); adj[y].pb(x); } }

int inf = 1e7;

void dfsin(std::vector<std::vector<int> >& adj, int u, int p, std::vector<int>& maxin, std::vector<int>& maxin2)
{
	for(int v : adj[u])
		if(v != p) {
			dfsin(adj, v, u, maxin, maxin2);
			if(maxin[v] + 1> maxin[u])
			{
				maxin2[u] = maxin[u];
				maxin[u] = maxin[v] + 1;
			}
			else if(maxin[v] + 1 > maxin2[u])
			{
				maxin2[u] = maxin[v] + 1;
			}
		}
}

void dfsout(std::vector<std::vector<int> >& adj, int u, int p, std::vector<int>& maxout, std::vector<int>& maxin, std::vector<int>& maxin2)
{
	if(p != -1) {
		maxout[u] = max(maxout[u], maxout[p] + 1);
		if(maxin[u] + 1 == maxin[p])
			maxout[u] = max(maxout[u], maxin2[p] + 1);
		else
			maxout[u] = max(maxout[u], maxin[p] + 1);
	}
	for(int v : adj[u])
		if(v != p)
			dfsout(adj, v, u, maxout, maxin, maxin2);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	#ifdef PIYUSH_AASHIRWAAD
		I_O;
	#else
	#define print(...) 0
	#endif
	int n, m, d;
	cin >> n >> m >> d;
	std::vector<std::vector<int> > adj(n);
	std::vector<int> maxin(n, -inf);
	std::vector<int> maxin2(n, -inf);
	std::vector<int> maxout(n, -inf);
	int x;
	for (int i = 0; i < m; ++i)
	{
		cin >> x;
		maxin[x-1] = 0;
		maxout[x-1] = 0;
	}
	butr(adj, n);
	dfsin(adj, 0, -1, maxin, maxin2);
	dfsout(adj, 0, -1, maxout, maxin, maxin2);
	int cnt = 0;
	for (int i = 0; i < n; ++i)
		if(max(maxin[i], maxout[i]) <= d)
			cnt++;
	cout << cnt;
}