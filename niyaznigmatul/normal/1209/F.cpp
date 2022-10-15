/**
 * Niyaz Nigmatullin
 */

#include <bits/stdc++.h>

using namespace std;

struct edge {
	int from, to, d;
};

vector<vector<edge>> edges;

void addPath(int v, int u, vector<int> const &d, int &fr) {
	int last = v;
	for (int j = 0; j + 1 < (int) d.size(); j++) {
		edges.emplace_back();
		int nlast = fr++;
		edges[last].push_back({last, nlast, d[j]});
		last = nlast;
	}
	edges[last].push_back({last, u, d.back()});
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int n, m;
	cin >> n >> m;
	int fr = n;
	edges.resize(n);
	for (int i = 1; i <= m; i++) {
		vector<int> d;
		d.reserve(10);
		int x = i;
		while (x > 0) {
			d.push_back(x % 10);
			x /= 10;
		}
		reverse(d.begin(), d.end());
		int v, u;
		cin >> v >> u;
		--v;
		--u;
		addPath(v, u, d, fr);
		addPath(u, v, d, fr);
	}
	int const INF = 1 << 30;
	vector<int> d(fr, INF);
	vector<int> q1;
	q1.push_back(0);
	d[0] = 0;
	vector<int> color(fr, INF);
	vector<pair<int, int>> ps(fr, {INF, INF});
	vector<int> from(fr);
	vector<int> ans(fr);
	int const MOD = 1000000007;
	while (true) {
		vector<int> q2;
		for (auto v : q1) {
			for (edge &e : edges[v]) {
				if (d[e.to] == INF) {
					d[e.to] = d[v] + 1;
					q2.push_back(e.to);
					color[e.to] = INF;
				}
				if (d[e.to] == d[v] + 1) {
					if (ps[e.to].first == INF || ps[e.to].first == color[v]) {
						ps[e.to].first = color[v];
						if (e.d < ps[e.to].second) {
							ps[e.to].second = e.d;
							ans[e.to] = (int) (((long long) ans[v] * 10 + e.d) % MOD);
						}
					}
				}
			}
		}
		if (q2.empty()) break;
		sort(q2.begin(), q2.end(), [&](int v, int u) {
			return ps[v] < ps[u];
		});
		color[q2[0]] = 0;
		int cur = 1;
		for (int i = 1; i < (int) q2.size(); i++) {
			if (ps[q2[i]] != ps[q2[i - 1]]) {
				cur++;
			}
			color[q2[i]] = cur - 1;
		}
		q2.swap(q1);
	}
	for (int i = 1; i < n; i++) {
		cout << ans[i] << '\n';
	}
}