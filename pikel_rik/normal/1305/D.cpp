#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;
const int N = 1000 + 5;

int query(int u, int v) {
	cout << "? " << u << ' ' << v << endl;
	int ans;
	cin >> ans;
	return ans;
}

int n, deg[N];
vector<int> g[N];
bool visited[N];

void dfs(int x, int p) {
	visited[x] = true;
	for (int i : g[x]) {
		if (i == p) continue;
		dfs(i, x);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 1, u, v; i < n; i++) {
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
		deg[u]++;
		deg[v]++;
	}

	vector<int> q;

	while (true) {
		for (int i = 1; i <= n; i++) {
			if (!visited[i] && deg[i] <= 1) {
				q.push_back(i);
			}
		}
		if (q.size() == 1) {
			cout << "! " << q.front() << endl;
			return 0;
		}
		for (int i = 1; i < q.size(); i += 2) {
			int lca = query(q[i - 1], q[i]);
			if (lca == q[i - 1]) {
				cout << "! " << q[i - 1] << endl;
				return 0;
			} else if (lca == q[i]) {
				cout << "! " << q[i] << endl;
				return 0;
			}
			visited[q[i - 1]] = visited[q[i]] = true;
			for (int k : g[q[i - 1]]) {
				deg[k]--;
			}
			for (int k : g[q[i]]) {
				deg[k]--;
			}
		}
		q.clear();
	}
	return 0;
}