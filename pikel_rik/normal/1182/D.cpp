#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;
const int N = 1e5 + 5;

int n, d[N];
vector<int> g[N];

void dfs(int x, int p) {
	for (int i : g[x]) {
		if (i == p) continue;
		d[i] = 1 + d[x];
		dfs(i, x);
	}
}

int cur[N];
bool check(int x) {
	d[x] = 0;
	dfs(x, 0);

	memset(cur, -1, sizeof(cur));
	for (int i = 1; i <= n; i++) {
		if (cur[d[i]] == -1) {
			cur[d[i]] = g[i].size();
		} else if (cur[d[i]] != g[i].size()) {
			return false;
		}
	}
	return true;
}

int lvl[N];
bool visited[N];

int bfs(int s) {
	fill(visited, visited + n + 1, false);
	queue<int> q;
	q.push(s);
	visited[s] = true;
	lvl[s] = 0;

	int furthest = s;
	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i : g[x]) {
			if (!visited[i]) {
				q.push(i);
				visited[i] = true;
				lvl[i] = 1 + lvl[x];
				if (lvl[i] > lvl[furthest]) {
					furthest = i;
				}
			}
		}
	}
	return furthest;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 1, u, v; i < n; i++) {
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	int f1 = bfs(1);
	int f2 = bfs(f1);

	if (check(f1)) {
		cout << f1 << '\n';
		return 0;
	} else if (check(f2)) {
		cout << f2 << '\n';
		return 0;
	}

	if (lvl[f2] % 2 != 0) {
		cout << "-1\n";
		return 0;
	}

	int dia = lvl[f2];
	vector<int> path = {f2};
	int x = f2;
	while (true) {
		for (int i : g[x]) {
			if (lvl[i] == lvl[x] - 1) {
				x = i;
				break;
			}
		}
		path.push_back(x);
		if (x == f1) {
			break;
		}
	}

	if (check(path[dia / 2])) {
		cout << path[dia / 2];
		return 0;
	}

	bfs(path[dia / 2]);

	int leaf = f1;
	for (int i = 1; i <= n; i++) {
		if (g[i].size() == 1 && lvl[i] <= lvl[leaf]) {
			leaf = i;
		}
	}

	if (check(leaf)) {
		cout << leaf << '\n';
	} else {
		cout << "-1\n";
	}
	return 0;
}