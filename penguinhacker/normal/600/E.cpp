#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, c[100000];
ll ans[100000];
vector<int> adj[100000];
map<int, int> cnt[100000];
map<int, ll> sum[100000];

void merge(int a, int b) {
	for (auto& x : cnt[b]) {
		sum[a][cnt[a][x.first]] -= x.first;
		if (sum[a][cnt[a][x.first]] == 0) sum[a].erase(cnt[a][x.first]);
		cnt[a][x.first] += x.second;
		sum[a][cnt[a][x.first]] += x.first;
	}
}

void dfs(int u = 0, int p = -1) {
	cnt[u][c[u]] = 1;
	sum[u][1] += (c[u]);
	for (int v : adj[u]) if (v != p) {
		dfs(v, u);
		if (cnt[u].size() < cnt[v].size()) {
			swap(cnt[u], cnt[v]);
			swap(sum[u], sum[v]);
		}
		merge(u, v);
	}
	ans[u] = sum[u].rbegin()->second;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> c[i];
	for (int i = 1; i < n; ++i) {
		int a, b; cin >> a >> b, --a, --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs();
	for (int i = 0; i < n; ++i) cout << ans[i] << " ";
	return 0;
}