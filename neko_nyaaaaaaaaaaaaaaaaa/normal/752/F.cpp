#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> adj[200005];
vector<int> subtr(200005);
vector<int> team(200005);

void input() {
	cin >> n >> k;
	for (int i = 1; i < n; i++) {
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for (int i = 1; i <= 2*k; i++) {
		int x; cin >> x;
		subtr[x]++;
		team[x] = 1;
	}
}

int find_subtr_size(int now, int prev) {
	int ans = subtr[now];
	for (int u: adj[now]) {
		if (u != prev) {
			ans += find_subtr_size(u, now);
		}
	}
	return subtr[now] = ans;
}	

int dfsc(int now, int prev, int sz) {
	for (int u: adj[now]) {
		if (u != prev && subtr[u] > (sz)/2) {
			return dfsc(u, now, sz);
		}
	}
	return now;
}

int find_centroid() {
	return dfsc(1, 0, 2*k);
}

void dfs(int now, int prev, vector<int> &ans) {
	for (int u: adj[now]) {
		if (u != prev) dfs(u, now, ans);
	}
	if (team[now]) ans.push_back(now);
}

void solve() {
	cout << "1\n";

	find_subtr_size(1, 0);
	int centroid = find_centroid();
	cout << centroid << '\n';

	vector<int> ans;
	dfs(centroid, 0, ans);

	for (int i = 0; i < k; i++) {
		cout << ans[i] << ' ' << ans[i+k] << ' ' << centroid << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	input();
	solve();

	return 0;
}