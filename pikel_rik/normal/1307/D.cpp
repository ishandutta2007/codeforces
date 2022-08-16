#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;
const int N = 2e5 + 5;

int n, m, k, a[N];
vector<int> g[N];

bool visited[N], special[N];
int lvl1[N], lvln[N];

void bfs(int s, int lvl[N]) {
	memset(visited, false, sizeof(visited));

	queue<int> q;
	q.push(s);
	visited[s] = true;
	lvl[s] = 0;

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i : g[x]) {
			if (!visited[i]) {
				q.push(i);
				visited[i] = true;
				lvl[i] = 1 + lvl[x];
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		cin >> a[i];
		special[a[i]] = true;
	}

	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	bfs(1, lvl1);
	bfs(n, lvln);

	int ans = 0;

	for (int x = 1; x <= n; x++) {
		if (!special[x]) continue;
		for (int i : g[x]) {
			if (special[i]) {
				cout << lvl1[n] << '\n';
				return 0;
			}
		}
	}

	sort(a, a + k, [&] (int x, int y) {
		return lvln[x] < lvln[y];
	});

	for (int i = 1; i < k; i++) {
		int temp = min(lvl1[a[i - 1]] + 1 + lvln[a[i]], lvl1[a[i]] + 1 + lvln[a[i - 1]]);
		ans = max(ans, min(lvl1[n], temp));
	}

	sort(a, a + k, [&] (int x, int y) {
		return lvl1[x] < lvl1[y];
	});

	for (int i = 1; i < k; i++) {
		int temp = min(lvl1[a[i - 1]] + 1 + lvln[a[i]], lvl1[a[i]] + 1 + lvln[a[i - 1]]);
		ans = max(ans, min(lvl1[n], temp));
	}

	cout << ans << '\n';
	return 0;
}