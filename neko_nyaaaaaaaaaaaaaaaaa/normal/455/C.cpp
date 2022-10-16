#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct DSU {
	vector<int> P, S, D;
	DSU(int n) {
		P.resize(n+1);
		S.resize(n+1, 1);
		D.resize(n+1);
		for (int i = 1; i <= n; i++) P[i] = i;
	}
	
	int find(int x) {
		while (x != P[x]) x = P[x];
		return x;
	}
	
	void merge(int a, int b) {
		a = find(a); b = find(b);
		if (S[a] < S[b]) swap(a, b);
		
		S[a] += S[b];
		D[a] = max(max(D[a], D[b]), (D[a]+1)/2 + (D[b]+1)/2 + 1);
		P[b] = a;
	}
	
	int same(int a, int b) {
		return find(a) == find(b);
	}
	
	void setD(int a, int d) {
		D[find(a)] = d;
	}
	
	int getD(int a) {
		return D[find(a)];
	}
};

int n, m, q, maxnode, maxdist;
vector<vector<int>> adj(300005);
vector<int> dist(300005);
DSU d(300005);

void dfs(int now, int prev, int ds) {
	dist[now] = ds;
	if (dist[now] > dist[maxnode]) maxnode = now;
	maxdist = max(maxdist, ds);
	for (auto u: adj[now]) {
		if (u != prev) dfs(u, now, ds+1);
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m >> q;
	while (m--) {
		int x, y;
		cin >> x >> y;
		d.merge(x, y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	
	for (int i = 1; i <= n; i++) {
		if (dist[i] == 0) {
			maxnode = 0;
			dfs(i, 0, 1);
			maxdist = 0;
			dfs(maxnode, 0, 0);
			
			d.setD(i, maxdist);
		}
	}
	
	while (q--) {
		int c; cin >> c;
		if (c == 2) {
			int x, y;
			cin >> x >> y;
			if (!d.same(x, y)) {d.merge(x, y);}
		} else {
			int x; cin >> x;
			cout << d.getD(x) << '\n';
		}
	}
	
	return 0;
}