#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
using namespace std;

int n, q, tme;
vector<int> adj[50001];
int a[50001], par[50001];
int tin[50001], tout[50001], lv[50001], lst[50001], b[50001];

void dfs(int now, int prev) {
	tme++;
	tin[now] = tme;
	lv[tme] = lv[tin[prev]] + 1;
	b[tme] = a[now];

	for (int u: adj[now]) {
		dfs(u, now);
	}

	tout[now] = tme;
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int i = 2; i <= n; i++) {
		cin >> par[i];
		adj[par[i]].push_back(i);
	}
	dfs(1, 0);

	for (int T = 1; T <= q; T++) {
		int u; cin >> u;
		int sum_dist = 0, cnt = 0;
		for (int i = tin[u]; i <= tout[u]; i++) {
			if (lst[i] <= T) {
				sum_dist += lv[i] - lv[tin[u]];
				cnt++;
				lst[i] = T + b[i];
			}
		}
		cout << sum_dist << ' ' << cnt << '\n';
	}

	return 0;
}