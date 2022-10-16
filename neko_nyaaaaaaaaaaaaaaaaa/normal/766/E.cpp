#include <bits/stdc++.h>
using namespace std;

int n, a[100005]; 
vector<int> adj[100005];
vector<int> solved(100005);
vector<int> subtr(100005);
long long ans;

void input() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i]; ans += a[i];
	}
	for (int i = 1; i < n; i++) {
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
}

// for finding centroids

int find_subtr_size(int now, int prev) {
	int ans = 1;
	for (int u: adj[now]) {
		if (u != prev && !solved[u]) {
			ans += find_subtr_size(u, now);
		}
	}
	return subtr[now] = ans;
}

int dfsc(int now, int prev, int sz) {
	for (int u: adj[now]) {
		if (u != prev && !solved[u] && subtr[u] > (sz)/2) {
			return dfsc(u, now, sz);
		}
	}
	return now;
}

int find_centroid(int now, int prev) {
	int sz = find_subtr_size(now, prev);
	int centroid = dfsc(now, prev, sz);
	solved[centroid] = 1;
	return centroid;
}

// for solving

void dfsp(int now, int prev, int xr, vector<int> &path) {
	path.push_back(xr);
	for (int u: adj[now]) {
		if (!solved[u] && u != prev) {
			dfsp(u, now, xr ^ a[u], path);
		}
	}
}

void solve_centroid(int centroid) {
	vector<vector<int>> paths;

	for (int u: adj[centroid]) {
		if (!solved[u]) {
			vector<int> path_u;
			dfsp(u, centroid, a[u], path_u);
			paths.push_back(path_u);
		}
	}

	vector<int> o(20), z(20);
	for (auto v: paths) {
		for (int i: v) {
			ans += i^a[centroid];

			for (int b = 0; b < 20; b++) {
				if ((i^a[centroid]) & (1 << b)) {
					ans += z[b] * (1LL << b);
				} else {
					ans += o[b] * (1LL << b);
				}
			}
		}
		for (int i: v) {
			for (int b = 0; b < 20; b++) {
				if (i & (1 << b)) {
					o[b]++;
				} else {
					z[b]++;
				}
			}
		}
	}

	for (int u: adj[centroid]) {
		if (!solved[u]) {
			int ct = find_centroid(u, centroid);
			solve_centroid(ct);
		}
	}
}

void solve() {
	int ct = find_centroid(1, 0);
	solve_centroid(ct);
	cout << ans;
}


signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	input();
	solve();
	
	return 0;
}