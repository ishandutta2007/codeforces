#include <bits/stdc++.h>
using namespace std;

#define int long long
int n, m;
vector<int> indeg(100001);
vector<int> outdeg(100001);
vector<int> adj[100001];

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	while (m--) {
		int x, y; cin >> x >> y;
		if (x > y) swap(x, y);
		adj[x].push_back(y);

		indeg[max(x, y)]++;
		outdeg[min(x, y)]++;
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += indeg[i] * outdeg[i];
	}
	cout << ans << '\n';

	int q; cin >> q;
	for (int i = 1; i <= q; i++) {
		int x; cin >> x;

		ans -= indeg[x] * outdeg[x];
		indeg[x] += outdeg[x]; outdeg[x] = 0;

		for (int u: adj[x]) {
			adj[u].push_back(x);

			ans -= indeg[u] * outdeg[u];
			indeg[u]--; outdeg[u]++;
			ans += indeg[u] * outdeg[u];
		}
		adj[x].clear();

		cout << ans << '\n';
	}

	return 0;
}