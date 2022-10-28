#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

vector<int> p;
vector<vector<int>> g;

pair<int, int> dfs(int v, int par = -1, int dist = 0) {
	p[v] = par;
	pair<int, int> res = make_pair(dist, v);
	for (auto to : g[v]) {
		if (to == par) continue;
		res = max(res, dfs(to, v, dist + 1));
	}
	return res;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n;
	cin >> n;
	p = vector<int>(n);
	g = vector<vector<int>>(n);
	for (int i = 0; i < n - 1; ++i) {
		int x, y;
		cin >> x >> y;
		--x, --y;
		g[x].push_back(y);
		g[y].push_back(x);	
	}
	
	
	pair<int, int> da = dfs(0);
	pair<int, int> db = dfs(da.y);
	vector<int> diam;
	int v = db.y;
	while (v != da.y) {
		diam.push_back(v);
		v = p[v];
	}
	diam.push_back(da.y);
	
	if (int(diam.size()) == n) {
		cout << n - 1 << " " << endl << diam[0] + 1 << " " << diam[1] + 1 << " " << diam.back() + 1 << endl;
	} else {
		queue<int> q;
		vector<int> d(n, -1);
		for (auto v : diam) {
			d[v] = 0;
			q.push(v);
		}
		while (!q.empty()) {
			int v = q.front();
			q.pop();
			for (auto to : g[v]) {
				if (d[to] == -1) {
					d[to] = d[v] + 1;
					q.push(to);
				}
			}
		}
		pair<int, int> mx = make_pair(d[0], 0);
		for (int v = 1; v < n; ++v) {
			mx = max(mx, make_pair(d[v], v));
		}
		cout << int(diam.size()) - 1 + mx.x << endl << diam[0] + 1 << " " << mx.y + 1 << " " << diam.back() + 1 << endl;
	}
	
	return 0;
}