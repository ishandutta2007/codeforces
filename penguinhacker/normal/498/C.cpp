#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

struct Dinic {
	struct Edge {
		int to, rev;
		ll c, oc;
		ll flow() { return max(oc - c, 0LL); } // if you need flows
	};
	vector<int> lvl, ptr, q;
	vector<vector<Edge>> adj;
	Dinic(int n) : lvl(n), ptr(n), q(n), adj(n) {}
	void add(int a, int b, ll c, ll rcap = 0) {
		adj[a].push_back({b, (int)adj[b].size(), c, c});
		adj[b].push_back({a, (int)adj[a].size() - 1, rcap, rcap});
	}
	ll dfs(int v, int t, ll f) {
		if (v == t || !f) return f;
		for (int& i = ptr[v]; i < adj[v].size(); i++) {
			Edge& e = adj[v][i];
			if (lvl[e.to] == lvl[v] + 1)
				if (ll p = dfs(e.to, t, min(f, e.c))) {
					e.c -= p, adj[e.to][e.rev].c += p;
					return p;
				}
		}
		return 0;
	}
	ll calc(int s, int t) {
		ll flow = 0; q[0] = s;
		for (int L=0; L<31; ++L) do { // 'int L=30' maybe faster for random data
			lvl = ptr = vector<int>(q.size());
			int qi = 0, qe = lvl[s] = 1;
			while (qi < qe && !lvl[t]) {
				int v = q[qi++];
				for (Edge e : adj[v])
					if (!lvl[e.to] && e.c >> (30 - L))
						q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
			}
			while (ll p = dfs(s, t, LLONG_MAX)) flow += p;
		} while (lvl[t]);
		return flow;
	}
	bool leftOfMinCut(int a) { return lvl[a] != 0; }
};

int n, m, ans, a[100], c[100];
ar<int, 2> e[100];
map<int, map<int, int>> mp;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i=0; i<n; ++i) {
		cin >> a[i];
		for (int j=2; j*j<=a[i]; ++j) {
			if (a[i]%j)
				continue;
			while(a[i]%j==0)
				a[i]/=j, ++mp[j][i];
		}
		if (a[i]>1)
			++mp[a[i]][i];
	}
	for (int i=0; i<m; ++i) {
		cin >> e[i][0] >> e[i][1], --e[i][0], --e[i][1];
		if (e[i][0]%2)
			swap(e[i][0], e[i][1]);
	}
	for (auto& x : mp) {
		map<int, int> mp2=x.second;
		if (mp2.size()<2)
			continue;
		vector<int> c(n);
		for (auto& y : mp2)
			c[y.first]=y.second;
		Dinic g(n+2);
		for (int i=0; i<n; ++i) {
			if (i%2==0)
				g.add(0, i+1, c[i]);
			else
				g.add(i+1, n+1, c[i]);
		}
		for (int i=0; i<m; ++i)
			g.add(e[i][0]+1, e[i][1]+1, 6969);
		ans+=g.calc(0, n+1);
	}
	cout << ans;
	return 0;
}