#include <bits/stdc++.h>
#define int long long
#define pb emplace_back
#define mp make_pair

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	#ifdef PIYUSH_HOME
		I_O;
	#else
	#define print(...) 0
	#endif
	int n; cin >> n;
	int m; cin >> m;
	std::vector<std::set<std::pair<int, int> > > adj(n);
	std::vector<int> to(n, 0);
	std::map<int, int> ma;
	for (int i = 0; i < m; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c; a--; b--;
		ma[a * 3ll * 100000ll + b] = (i + 1);
		ma[b * 3ll * 100000ll + a] = 0;
		adj[a].insert(mp(b, c));
		adj[b].insert(mp(a, c));
		to[a] += c;
		to[b] += c;
	}
	print(adj, to);
	for (auto p : adj[0])
	{
		int v, w;
		tie(v, w) = p;
		to[v] -= (2ll * w);
		adj[v].erase(mp(0, w));
	}
	to[n - 1] *= 2;
	std::set<std::pair<int, int> > s;
	for (int i = 1; i < n; ++i)
		s.insert(mp(to[i], i));
	while(!s.empty())
	{
		print(adj, s);
		auto p = *(s.begin());
		s.erase(s.begin());
		int u = p.second;
		if(p.first && u != n-1) {
			cout << p.first << " " << u << "\n";
			exit(0);
		}
		for (auto p1 : adj[u])
		{
			int v, w;
			tie(v, w) = p1;
			s.erase(mp(to[v], v));
			to[v] -= (2ll * w);
			s.insert(mp(to[v], v));
			adj[v].erase(mp(u, w));
		}
	}
	std::vector<int> res(m + 1, -1);
	for (int u = 0; u < n; ++u)
	{
		for (auto p : adj[u])
		{
			int v, w;
			tie(v, w) = p;
			if(ma[u * 3ll * 100000ll + v] == 0)
				res[ma[v * 3ll * 100000ll + u]] = 1;
			else
				res[ma[u * 3ll * 100000ll + v]] = 0;
		}
	}
	for (int i = 0; i < m; ++i)
		cout << res[i + 1] << "\n";
}