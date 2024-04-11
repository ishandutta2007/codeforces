#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;
const int N = 2e5 + 5;

int n, p[N], d[N];
vector<int> cycle, g[N];

bool cycle_found, visited[N];

void first(int x) {
	visited[x] = true;
	for (int i : g[x]) {
		if (i == p[x]) continue;
		if (!visited[i]) {
			d[i] = 1 + d[x];
			p[i] = x;
			first(i);
		} else if (!cycle_found) {
			for (int ptr = x; ptr != p[i]; ptr = p[ptr]) {
				cycle.push_back(ptr);
			}
			cycle_found = true;
		}
	}
}

int dfs(int x, int p) {
	int sz = 1;
	for (int i : g[x]) {
		if (i == p) continue;
		sz += dfs(i, x);
	}
	return sz;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			g[i].clear();
			visited[i] = false;
		}

		for (int i = 0, u, v; i < n; i++) {
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}

		ll ans = ((ll)n * n - n) / 2;

		p[1] = 0;
		cycle.clear();
		cycle_found = false;
		first(1);

		sort(cycle.begin(), cycle.end());

		ll sum_sq = 0, sum = 0;

		for (int x : cycle) {
			int sz = 1;
			for (int i : g[x]) {
				if (!binary_search(cycle.begin(), cycle.end(), i)) {
					sz += dfs(i, x);
				}
			}
			sum_sq += (ll)sz * sz;
			sum += sz;
		}

		ans += ((ll)sum * sum - sum_sq) / 2;
		cout << ans << '\n';
	}
	return 0;
}