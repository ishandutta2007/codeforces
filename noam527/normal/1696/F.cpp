#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = (int)1e9 + 7;
const ll inf = 2e18;
const int OO = 0;
using namespace std;

const int N = 102;

int n;
int a[N][N][N] = {};
vector<vector<int>> L[N];
vector<int> vis;

vector<vector<int>> g;
int dist[N][N];

void getinput() {
	cin >> n;
	for (int i = 1; i <= n - 1; i++) {
		for (int j = 1; j <= n - i; j++) {
			string s;
			cin >> s;
			for (int k = 1; k <= n; k++) {
				if (s[k - 1] == '0') {
					a[i - 1][i - 1 + j][k - 1] = a[i - 1 + j][i - 1][k - 1] = 0;
				}
				else {
					a[i - 1][i - 1 + j][k - 1] = a[i - 1 + j][i - 1][k - 1] = 1;
				}
			}
		}
	}
}

bool getlayers() {
	for (int i = 0; i < n; i++) L[i].clear();

	for (int v = 0; v < n; v++) {
		L[v].push_back(vector<int>(1, v));
		for (int i = 0; i < n; i++) {
			if (i == v) continue;
			bool found = false;
			for (auto &lst : L[v]) {
				if (a[lst[0]][i][v]) {
					lst.push_back(i);
					found = true;
					break;
				}
			}
			if (!found)
				L[v].push_back(vector<int>(1, i));
		}
		if (L[v][0].size() != 1)
			return false;
	}
	return true;
}

// returns neighbors of u given that (u, v) exists
vector<int> calc(int u, int v) {
	vector<int> res;
	for (int i = 0; i < n; i++) {
		if (i == v) continue;
		if (a[i][v][u]) res.push_back(i);
	}
	return res;
}

void dfs(int v) {
	if (vis[v]) return;
	vis[v] = 1;
	for (const auto &i : g[v])
		dfs(i);
}

bool ensure_tree() {
	int s = 0;
	for (int i = 0; i < n; i++)
		s += g[i].size();
	if (s != 2 * n - 2) return false;

	for (auto &i : vis)
		if (i == 0) return false;

	for (auto &i : vis) i = 0;
	dfs(0);
	if (*min_element(vis.begin(), vis.end()) == 0) return false;

	// ensure edge duplicates
	for (int u = 0; u < n; u++) {
		for (const auto &v : g[u]) {
			bool found = false;
			for (const auto &w : g[v]) {
				if (w == u) {
					found = true;
					break;
				}
			}
			if (!found) return false;
		}
	}
	return true;
}

void dfs2(int st, int v, int dep) {
	if (dist[st][v] != -1) return;
	dist[st][v] = dep;
	for (const auto &i : g[v])
		dfs2(st, i, 1 + dep);
}

bool ensure_dist() {
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) dist[i][j] = -1;
	for (int i = 0; i < n; i++)
		dfs2(i, i, 0);
	for (int x = 0; x < n; x++) for (int y = x + 1; y < n; y++) for (int z = 0; z < n; z++) {
		int eq = (dist[x][z] == dist[y][z] ? 1 : 0);
		if (eq != a[x][y][z])
			return false;
	}
	return true;
}

void solve() {
	getinput();
	if (OO) {
		cout << "got input\n";
	}
	if (!getlayers()) {
		cout << "No\n";
		return;
	}
	if (OO) {
		cout << "got layers\n";
	}
	int mn = L[0].size();
	vector<int> at = { 0 };
	for (int i = 1; i < n; i++) {
		if (L[i].size() < mn) {
			mn = L[i].size();
			at = { i };
		}
		else if (L[i].size() == mn)
			at.push_back(i);
	}
	if (OO) {
		cout << "at: ";
		for (const auto &i : at) cout << i << " "; cout << '\n';
	}
	int u = -1, v = -1;
	if (at.size() > 2) {
		cout << "No\n";
		return;
	}
	if (at.size() == 2) {
		u = at[0];
		v = at[1];
	}
	else {
		u = at[0];
		for (int i = 0; i < n; i++) {
			if (L[i].size() == L[u].size() + 1) {
				v = i;
				break;
			}
		}
		if (v == -1) {
			cout << "No\n";
			return;
		}
	}
	if (OO) {
		cout << "u v: " << u << " " << v << '\n';
	}
	vis.clear();
	vis.resize(n, 0);
	queue<pair<int, int>> q;
	q.push({ u, v });
	q.push({ v, u });
	g.clear();
	g.resize(n);
	while (q.size()) {
		auto p = q.front();
		u = p.first, v = p.second;
		q.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		g[u].push_back(v);
		vector<int> neighbors = calc(u, v);
		for (const auto &w : neighbors) {
			g[u].push_back(w);
			q.push({ w, u });
		}
	}
	if (!ensure_tree()) {
		cout << "No\n";
		return;
	}
	if (!ensure_dist()) {
		cout << "No\n";
		return;
	}
	cout << "Yes\n";
	for (int u = 0; u < n; u++) {
		for (const auto &v : g[u]) {
			if (u < v) cout << u + 1 << " " << v + 1 << '\n';
		}
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}