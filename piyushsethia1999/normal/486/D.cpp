#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;

int d;
ll mod = 1000000007;

ll dfs(std::vector<std::vector<int> >& adj, std::vector<int>& a, int u, int p, int root)
{
	ll res = 1;
	for (int v : adj[u])
		if (v != p && ((a[v] <= (a[root]+d) && a[v] > a[root]) || (a[v] == a[root] && v <= root)))
			res = (res*(dfs(adj, a, v, u, root)+1))%mod;
	return res;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	#ifdef PIYUSH_AASHIRWAAD
		I_O;
	#else
	#define print(...) 0
	#endif
	int n;
	cin >> d >> n;
	std::vector<int> a(n);
	std::vector<std::vector<int> > adj(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	int u, v;
	for (int i = 0; i < n-1; ++i)
	{
		cin >> u >> v; u--; v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	ll res = 0;
	for (int i = 0; i < n; ++i)
		res += dfs(adj, a, i, -1, i);
	cout << res%mod;
}