#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ar array
 
struct Point {
	int x, y, id;
	void read(int index) {cin >> x >> y; id = index;}
};
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<Point> points(m + 1);
	points[0].read(0);
	int fx, fy;
	cin >> fx >> fy;
	for (int i = 1; i <= m; ++i) {
		points[i].read(i);
	}
	vector<vector<pair<int, int>>> adj(m + 1);
	auto add = [&](const Point& a, const Point& b) {
		adj[a.id].emplace_back(b.id, min(abs(a.x - b.x), abs(a.y - b.y)));
	};
	sort(points.begin(), points.end(), [&](const Point& a, const Point& b) {return a.x < b.x;});
	for (int i = 0; i < m; ++i) {
		Point& a = points[i];
		Point& b = points[i + 1];
		add(a, b);
		add(b, a);
	}
	sort(points.begin(), points.end(), [&](const Point& a, const Point& b) {return a.y < b.y;});
	for (int i = 0; i < m; ++i) {
		Point& a = points[i];
		Point& b = points[i + 1];
		add(a, b);
		add(b, a);
	}
	vector<int> d(m + 1, (int)2e9 + 1);
	vector<bool> vis(m + 1, 0);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.emplace(d[0] = 0, 0);
	while(!pq.empty()) {
		int u = pq.top().second; pq.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for (pair<int, int>& p : adj[u]) {
			int v = p.first, w = p.second;
			if (!vis[v] && (ll)d[u] + w < d[v]) {
				pq.emplace(d[v] = d[u] + w, v);
			}
		}
	}
	int ans = INT_MAX;
	for (Point& p : points) {
		ans = min(ans, d[p.id] + abs(p.x - fx) + abs(p.y - fy));
	}
	cout << ans << "\n";
	return 0;
}