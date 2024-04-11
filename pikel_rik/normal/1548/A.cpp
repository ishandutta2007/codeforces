#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<int> lower(n), deg(n);
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v, --u, --v;
		if (u > v) {
			swap(u, v);
		}
		deg[u] += 1;
		deg[v] += 1;
		lower[v] += 1;
	}

	int cur_ans = 0;
	for (int i = 0; i < n; i++) {
		cur_ans += lower[i] == deg[i];
	}

	int q;
	cin >> q;

	while (q--) {
		int t;
		cin >> t;

		if (t <= 2) {
			int u, v;
			cin >> u >> v, --u, --v;

			if (u > v) {
				swap(u, v);
			}

			cur_ans -= lower[u] == deg[u];
			cur_ans -= lower[v] == deg[v];

			if (t == 1) {
				deg[u] += 1;
				deg[v] += 1;
				lower[v] += 1;
			} else {
				deg[u] -= 1;
				deg[v] -= 1;
				lower[v] -= 1;
			}

			cur_ans += lower[u] == deg[u];
			cur_ans += lower[v] == deg[v];
		} else {
			cout << cur_ans << '\n';
		}
	}
	return 0;
}