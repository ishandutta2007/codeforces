#include <bits/stdc++.h>
using namespace std;

struct xor_basis{
	int d, sz;
	vector<int> basis;

	xor_basis(int d) {
		this->d = d; sz = 0;
		basis.resize(d);
	}

	bool add(int x) {
		for (int i = d-1; i >= 0; i--) {
			if (x & (1 << i)) {
				if (!basis[i]) {
					basis[i] = x; sz++;
					return 1;
				}
				x ^= basis[i];
			}
		}
		return 0;
	}
};

vector<pair<int, int>> adj[100001];
vector<int> weight(100001);
bitset<100001> vis;

void dfs(int now, int wcur) {
	weight[now] = wcur;
	vis[now] = 1;

	for (auto [u, w]: adj[now]) {
		if (!vis[u]) dfs(u, wcur ^ w);
	}
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, m; cin >> n >> m;
	vector<tuple<int, int, int>> edges;
	for (int i = 0; i < m; i++) {
		int x, y, w; cin >> x >> y >> w;
		adj[x].emplace_back(y, w);
		adj[y].emplace_back(x, w);
		edges.emplace_back(x, y, w);
	}
	dfs(1, 0);

	xor_basis xrb(30);
	for (auto [x, y, w]: edges) {
		xrb.add(weight[x] ^ weight[y] ^ w);
	}

	int ans = weight[n];
	for (int i = 29; i >= 0; i--) {
		if (ans & (1 << i)) {
			if (xrb.basis[i]) ans ^= xrb.basis[i];
		}
	}
	cout << ans << '\n';

	return 0;
}