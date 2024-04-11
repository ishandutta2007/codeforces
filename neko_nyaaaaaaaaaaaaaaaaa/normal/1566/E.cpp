#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 200001;

int n, h[MAXN], par[MAXN], eras[MAXN];
vector<int> adj[MAXN];
set<pair<int, int>> st;

void dfs(int now, int prv, int he) {
	st.insert({he, now});
	par[now] = prv;
	h[now] = he;
	for (int u: adj[now]) {
		if (u != prv) {
			dfs(u, now, he+1);
		}
	}
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		adj[i].clear(); h[i] = par[i] = eras[i] = 0;
	}
	st.clear();

	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, 0, 0);

	int lf = 0, brnch = 0;
	while (st.size()) {
		auto [hei, u] = *st.rbegin();
		if (u == 1) {
			brnch++; lf++;
			break;
		} else {
			brnch++;

			int pr = par[u];
			//cout << "Bud: " << pr << endl;
			for (int v: adj[pr]) {
				if (v == par[pr]) continue;
				if (eras[v]) continue;

				lf++; st.erase(st.find({h[v], v}));
				eras[v] = 1;
				//cout << v << ' ';
			}
			//cout << endl;
			st.erase(st.find({h[pr], pr}));
			eras[pr] = 1;
		}
	}

	cout << lf-brnch+1 << '\n';
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}