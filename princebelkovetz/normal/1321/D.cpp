#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;
#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << '\n';
const int N = 5e2 + 2;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout << fixed << setprecision(3);
	int n, m; cin >> n >> m;
	vector <vector <int>> g(n + 1), r(n + 1);
	for (int i = 0, u, v; i < m; ++i) {
		cin >> u >> v;
		g[u].push_back(v);
		r[v].push_back(u);
	}
	int k; cin >> k;
	vector <int> way(k);
	for (auto& x : way) cin >> x;
	vector <int> dist(n + 1, -1);
	dist[way.back()] = 0;
	queue <int> q;
	q.push(way.back());
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (auto u : r[v]) {
			if (dist[u] >= 0) continue;
			dist[u] = dist[v] + 1;
			q.push(u);
		}
	}
	int ans1 = 0, ans2 = 0;
	for (int i = 0; i < way.size() - 1; ++i) {
		int cnt = 0, mn = 1e9 + 7;
		for (auto u : g[way[i]]) {
			if (dist[u] < mn) mn = dist[u], cnt = 1;
			else if (dist[u] == mn) cnt++;
		}
		if (dist[way[i + 1]] != mn)
			ans1++, ans2++;
		else if (dist[way[i + 1]] == mn and cnt == 1)
			ans1 += 0;
		else ans2++;
	}
	cout << ans1 << ' ' << ans2 << '\n';
}