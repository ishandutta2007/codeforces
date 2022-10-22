#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, m, k, deg[100000], t[100000];
bool inset[100000], chk[100000], ans[100000];
vector<int> adj[100000];
vector<int> ord;
vector<pair<int, int>> need[100000];

void solve() {
	ord.clear();
	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i) {
		inset[i] = 1;
		ans[i] = 0;
		adj[i].clear();
		//need[i].clear();
	}
	for (int i = 0; i < m; ++i) {
		int a, b; cin >> a >> b, --a, --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	if (k > 450) {cout << "-1\n"; return;}

	set<pair<int, int>> s;
	for (int i = 0; i < n; ++i)
		s.emplace(deg[i] = adj[i].size(), i);
	int timer = 0;
	while(!s.empty()) {
		if (s.begin()->first >= k) {
			cout << "1 " << s.size() << "\n";
			for (auto& x : s) {
				cout << x.second + 1 << " ";
			}
			cout << "\n";
			return;
		}
		int u = s.begin()->second;
		s.erase(s.begin());
		inset[u] = 0;
		t[u] = timer++;
		ord.push_back(u);
		for (int v : adj[u]) {
			if (!inset[v]) continue;
			s.erase({deg[v], v});
			s.emplace(--deg[v], v);
		}
	}
	for (int u : ord) {
		//cout << u << "\n";
		vector<int> nxt;
		for (int v : adj[u]) if (t[u] < t[v]) {
			nxt.push_back(v);
			chk[v] = 1;
		}
		for (pair<int, int> p : need[u]) if (!chk[p.first]) ans[p.second] = 0;
		need[u].clear();
		for (int v : nxt) chk[v] = 0;
		if (nxt.size() != k - 1) continue;
		ans[u] = 1;
		//cout << u << "\n";
		sort(nxt.begin(), nxt.end(), [](int a, int b) {return t[a] < t[b];});
		for (int i = 0; i < nxt.size(); ++i)
			for (int j = i + 1; j < nxt.size(); ++j)
				need[nxt[i]].emplace_back(nxt[j], u);
	}
	for (int u : ord) {
		if (!ans[u]) continue;
		cout << "2\n" << u + 1;
		for (int v : adj[u]) if (t[u] < t[v]) cout << " " << v + 1;
		cout << "\n";
		return;
	}
	cout << "-1\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--) solve();
	return 0;
}