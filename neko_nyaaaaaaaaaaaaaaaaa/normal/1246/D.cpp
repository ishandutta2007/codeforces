#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> p(100001);
vector<int> pp(100001);
vector<int> sub(100001);
vector<int> adj[100001];
vector<int> first_branch;
vector<int> bamboo;
vector<int> ans;

void dfs(int now) {
	if (now != 0) {
		pp[now] = bamboo.back();
		while (pp[now] != p[now]) {
			ans.push_back(now);
			pp[now] = pp[pp[now]];
		}
	}
	bamboo.push_back(now);
	for (int u: adj[now]) {
		dfs(u);
	}
}

bool cmp(int a, int b) {
	return sub[a] < sub[b];
}

void init(int now, int d) {
	sub[now] = d;
	for (int u: adj[now]) {
		init(u, d+1);
		sub[now] = max(sub[u], sub[now]);
	}
	sort(adj[now].begin(), adj[now].end(), cmp);
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> p[i];
		adj[p[i]].push_back(i);
	}
	init(0, 1);
	dfs(0);
	for (int i: bamboo) cout << i << ' ';
		cout << '\n';
	cout << ans.size() << '\n';
	for (int i: ans) cout << i << ' ';

	return 0;
}