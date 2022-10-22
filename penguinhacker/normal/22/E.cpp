#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, p[100000];
bool vis1[100000], vis2[100000];
vector<int> adj[100000], cyc, cur;
vector<ar<int, 2>> ans;
vector<vector<int>> cmp;

void dfs1(int u) {
	if (vis1[u]) {
		cyc.push_back(u);
		return;
	}
	vis1[u] = 1;
	dfs1(p[u]);
	if (p[u] == cyc.back() && cyc[0] != u)
		cyc.push_back(u);
}

void dfs2(int u) {
	vis2[u] = 1;
	if (adj[u].empty()) {
		cur.push_back(u);
		return;
	}
	for (int v : adj[u])
		if (!vis2[v])
			dfs2(v);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> p[i], --p[i];
		adj[p[i]].push_back(i);
	}
	for (int i = 0; i < n; ++i) {
		if (vis2[i])
			continue;
		dfs1(i);
		cur = {cyc[0]};
		dfs2(cyc[0]);
		cmp.push_back(cur);
		cyc.clear();
		cur.clear();
	}
	if (cmp.size() == 1 && cmp[0].size() == 1) {
		cout << 0;
		return 0;
	}
	for (int i = 0; i < cmp.size(); ++i) {
		int r = cmp[i][0];
		vector<int> nxt = cmp[(i + 1) % cmp.size()];
		if (nxt.size() == 1)
			ans.push_back({r, nxt[0]});
		else
			for (int j = 1; j < nxt.size(); ++j)
				ans.push_back({r, nxt[j]});
	}
	cout << ans.size() << "\n";
	for (ar<int, 2> e : ans)
		cout << e[0] + 1 << " " << e[1] + 1 << "\n";
	return 0;
}