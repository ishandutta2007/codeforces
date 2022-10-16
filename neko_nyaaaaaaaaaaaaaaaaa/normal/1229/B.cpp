#include <bits/stdc++.h>
using namespace std;

#define int long long
const int M = 1e9+7;

int n, ans;
vector<int> a(100001);
vector<int> adj[100001];

vector<pair<int, int>> values[100001];

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) return a < b;
	return a.second > b.second;
}

void dfs(int now, int prev, int d) {
	vector<pair<int, int>> vl;
	for (auto s: values[prev]) {
		int g, id; tie(g, id) = s;
		vl.emplace_back(__gcd(g, a[now]), id);
	}
	vl.emplace_back(a[now], d);

	sort(vl.begin(), vl.end());
	int prv = -1;
	for (auto s: vl) {
		int g, id; tie(g, id) = s;

		if (prv != g) {
			values[now].emplace_back(g, id);
			prv = g;
		}
	}

	sort(values[now].begin(), values[now].end(), cmp);
	int p = d+1;
	for (auto s: values[now]) {
		int g, id; tie(g, id) = s;

		ans = (ans + g*(p - id)) % M;
		p = id;
	}

	for (int u: adj[now]) {
		if (u != prev) {
			dfs(u, now, d+1);
		}
	}
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i < n; i++) {
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs(1, 0, 0);
	cout << ans;

	return 0;
}