#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 4e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

int n, m, k;
vector<int> a;
vector<vector<int>> g;

vector<int> bfs(int s) {
	vector<int> dist(n, -1);
	dist[s] = 0;
	queue<int> q;
	q.push(s);
	while (q.size()) {
		int x = q.front();
		q.pop();
		for (const auto &i : g[x])
			if (dist[i] == -1) {
				dist[i] = 1 + dist[x];
				q.push(i);
			}
	}
	return dist;
}

int lower(const vector<vector<int>> &p1, int diff) {
	int lo = 0, hi = (int)p1.size() - 1, mid;
	while (lo < hi) {
		mid = (lo + hi) / 2;
		if (p1[mid][0] - p1[mid][1] < diff) lo = mid + 1;
		else hi = mid;
	}
	return lo;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m >> k;
	a.resize(k);
	for (auto &i : a) cin >> i, --i;
	g.resize(n);
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v;
		--u, --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<int> C = bfs(0), D = bfs(n - 1);
	int M = C[n - 1];
	vector<vector<int>> p1, tmp;
	for (const auto &i : a)
		p1.push_back({ C[i], D[i], i });
	sort(p1.begin(), p1.end());
	for (const auto &i : p1) {
		while (tmp.size() && tmp.back()[1] <= i[1]) tmp.pop_back();
		tmp.push_back(i);
	}
	p1 = tmp;
	int ans = 0;
	for (const auto &v : a) {
		int d1 = D[v], d2 = C[v];
		int ind = lower(p1, d2 - d1);
		for (int i = max(0, ind - 2); i < min((int)p1.size(), ind + 3); i++) {
			if (p1[i][2] != v) {
				int res = 1 + min(d1 + p1[i][0], d2 + p1[i][1]);
				ans = max(ans, res);
			}
		}
	}
	cout << min(ans, M) << '\n';
}