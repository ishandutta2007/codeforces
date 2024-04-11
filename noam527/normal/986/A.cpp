#include <bits/stdc++.h>
#define CHECK cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 998244353, inf = 1e9 + 7;
using namespace std;

void debug(string names) {
	cout << '\n';
}
template<typename A1, typename... A2>
void debug(string names, A1 par, A2... left) {
	int pos = 0;
	for (; pos < names.size() && names[pos] != ' ' && names[pos] != ','; pos++)
		cout << names[pos];
	cout << ": " << par << "  ";
	while (pos < names.size() && (names[pos] == ' ' || names[pos] == ',')) {
		pos++;
	}
	names.erase(names.begin(), names.begin() + pos);
	debug(names, left...);
}

int n, m, k, s;
vector<int> a, dist;
vector<vector<int>> g, d;

void work(int col) {
	for (auto &i : dist) i = -1;
	queue<int> q;
	for (int i = 0; i < n; i++) {
		if (a[i] == col)
			dist[i] = 0, q.push(i);
	}
	while (q.size()) {
		int x = q.front();
		q.pop();
		for (const auto &i : g[x])
			if (dist[i] == -1) {
				dist[i] = 1 + dist[x];
				q.push(i);
			}
	}
	for (int i = 0; i < n; i++) d[i].push_back(dist[i]);
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m >> k >> s;
	a.resize(n);
	g.resize(n);
	d.resize(n);
	dist.resize(n);
	for (auto &i : a) cin >> i;
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v;
		--u, --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (int i = 1; i <= k; i++) work(i);
	ll S;

	for (int i = 0; i < n; i++) {
		sort(d[i].begin(), d[i].end());
		S = 0;
		for (int j = 0; j < s; j++) S += d[i][j];
		cout << S << " ";
	}
}