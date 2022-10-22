#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN = 1e6;
int n;
pair<int, int> ans[mxN]; //index, count
vector<int> adj[mxN];
vector<int> d[mxN];

void dfs(int u = 0, int p = -1) {
	int big = -1;
	for (int v : adj[u]) {
		if (v != p) {
			dfs(v, u);
			if (big == -1 || d[v].size() > d[big].size()) {
				big = v;
			}
		}
	}
	if (big == -1) {
		d[u] = {1};
		ans[u] = {0, 1};
	}
	else {
		auto upd = [&](int a, int b) {
			if (b > ans[u].second || (b == ans[u].second && a < ans[u].first)) {
				ans[u] = {a, b};
			}
		};
		swap(d[u], d[big]);
		d[u].push_back(1);
		ans[u] = {ans[big].first + 1, ans[big].second};
		upd(0, 1);
		for (int v : adj[u]) {
			if (v != p && v != big) {
				for (int i = d[v].size() - 1; i >= 0; --i) {
					int ind = d[v].size() - i;
					d[u][d[u].size() - ind - 1] += d[v][i];
					upd(ind, d[u][d[u].size() - ind - 1]);
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i < n; ++i) {
		int a, b;
		cin >> a >> b, --a, --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs();
	for (int i = 0; i < n; ++i) {
		cout << ans[i].first << "\n";
	}
	return 0;
}