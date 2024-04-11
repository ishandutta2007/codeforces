#include <bits/stdc++.h>
using namespace std;

int QUES = 12;

int ask(vector<int> x) {
	assert(QUES > 0);
	QUES--;

	cout << "? " << x.size();
	for (int i: x) cout << ' ' << i;
		cout << endl;

	int y; cin >> y;
	return y;
}

void answer(int a, int b) {
	cout << "! " << a << ' ' << b << endl;
	exit(0);
}

int n, sz;
vector<int> adj[1001], vis(1001);

signed main() {
	//ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int mx = 0;
	{
		vector<int> a;
		for (int i = 1; i <= n; i++) {
			a.push_back(i);
		}
		mx = ask(a);
	}
	
	vector<pair<int, int>> edges;

	queue<int> q;
	q.push(1); vis[1] = 1;
	while (q.size()) {
		int u = q.front(); q.pop();
		for (auto v: adj[u]) {
			if (!vis[v]) {
				vis[v] = 1;
				q.push(v);
				edges.emplace_back(u, v);
			}
		}
	}

	while (edges.size() > 1) {
		int sz = edges.size();
		vector<pair<int, int>> l, r;
		for (int i = 0; i < sz/2; i++) {
			l.push_back(edges[i]);
		}
		for (int i = sz/2; i < sz; i++) {
			r.push_back(edges[i]);
		}

		set<int> st;
		for (auto [u, v]: l) {
			st.insert(u); st.insert(v);
		}

		vector<int> q(st.begin(), st.end());
		if (ask(q) == mx) {
			edges = l;
		} else {
			edges = r;
		}
	}

	auto [a, b] = edges[0];
	answer(a, b);
	return 0;
}