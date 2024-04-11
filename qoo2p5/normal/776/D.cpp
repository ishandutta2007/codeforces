#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = (int) 1e9 + 123;
const ll LINF = (ll) 1e18 + 123;
const ld EPS = 1e-8;
const int MOD = (int) 1e9 + 7;

#define sz(x) (int) x.size()

const int N = (int) 2e5 + 123;

int n, m;
bool r[N];
vector<pair<int, int>> g[N];
vector<int> a[N];

int color[N];

void dfs(int v) {
	for (auto &e : g[v]) {
		int to = color[v] ^ e.second;
		if (color[e.first] == -1) {
			color[e.first] = to;
			dfs(e.first);
		} else {
			if (color[e.first] != to) {
				cout << "NO\n";
				exit(0);
			}
		}
	}
}

void run() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> r[i];
	}
	for (int i = 0; i < m; i++) {
		int cnt = 0;
		cin >> cnt;
		for (int j = 0; j < cnt; j++) {
			int id;
			cin >> id;
			id--;
			a[id].push_back(i);
		}
	}
	for (int i = 0; i < n; i++) {
		int x = a[i][0];
		int y = a[i][1];
		g[x].push_back({y, !r[i]});
		g[y].push_back({x, !r[i]});
	}
	
	fill(color, color + m, -1);
	
	for (int i = 0; i < m; i++) {
		if (color[i] == -1) {
			color[i] = 0;
			dfs(i);
		}
	}
	
	cout << "YES\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	run();
	return 0;
}