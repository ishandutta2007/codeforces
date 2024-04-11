#include <bits/stdc++.h>
using namespace std;

int n, n1, n2, m, k;
vector<int> w, to, sz;
vector<vector<int>> g, ans;
int s, t;

vector<int> vis, pre;
queue<int> q;

bool bfs() {
	while (!q.empty()) q.pop();
	for (int i = 0; i < n; i++) vis[i] = 0;
	vis[t] = 0;
	vis[s] = 1;
	q.push(s);
	int x;
	while (!q.empty()) {
		x = q.front(), q.pop();
		for (const auto &i : g[x]) {
			if (!vis[to[i]] && w[i]) {
				vis[to[i]] = 1;
				pre[to[i]] = i;
				q.push(to[i]);
				if (to[i] == t) return true;
			}
		}
	}
	return false;
}

void update() {
	for (const auto &i : g[s])
		w[i]++;
	for (const auto &i : g[t])
		w[i ^ 1]++;
}

void augment() {
	static int at;
	at = t;
	while (at != s) {
		w[pre[at]]--;
		w[pre[at] ^ 1]++;
		at = to[pre[at] ^ 1];
	}
}

void work() {
	while (bfs()) augment();
	ans.push_back(vector<int>());
	for (int i = 0; i < 2 * m; i += 2)
		if (w[i]) ans.back().push_back(1 + i / 2);
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	cin >> n1 >> n2 >> m;
	n = n1 + n2;
	s = n;
	t = n + 1;
	g.resize(n + 2);
	sz.resize(n);
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v;
		--u, --v;
		v += n1;

		g[u].push_back(w.size());
		w.push_back(1);
		to.push_back(v);
		g[v].push_back(w.size());
		w.push_back(0);
		to.push_back(u);
	}
	for (int i = 0; i < n; i++) sz[i] = g[i].size();
	k = *min_element(sz.begin(), sz.end());
	for (int i = 0; i < n1; i++) {
		g[s].push_back(w.size());
		w.push_back(sz[i] - k);
		to.push_back(i);
		g[i].push_back(w.size());
		w.push_back(0);
		to.push_back(s);
	}
	for (int i = n1; i < n; i++) {
		g[i].push_back(w.size());
		w.push_back(sz[i] - k);
		to.push_back(t);
		g[t].push_back(w.size());
		w.push_back(0);
		to.push_back(i);
	}

	vis.resize(n + 2);
	pre.resize(n + 2);

	for (; k >= 0; k--) work(), update();
	for (int i = ans.size() - 1; i >= 0; i--) {
		cout << ans[i].size() << " ";
		for (const auto &j : ans[i]) cout << j << " "; cout << '\n';
	}
}