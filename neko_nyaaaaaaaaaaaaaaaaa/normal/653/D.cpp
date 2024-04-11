#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Edge {
	int u, v;
	double capacity;
	double flow;
};

struct Flow {
	int n;
	int source, sink;

	vector<vector<int>> a;
	vector<Edge> E;

	vector<int> cur;
	vector<double> dist;

	Flow();
	Flow(int n, int s, int t) {
		this->n = n;
		source = s; sink = t;
		a.resize(n+1);
		cur.resize(n+1);
		dist.resize(n+1);
	}

	void add_edge(int u, int v, double c) {
		a[u].push_back(E.size());	E.push_back({u, v, c, 0});
		a[v].push_back(E.size());	E.push_back({v, u, 0, 0});
	}

	int bfs() {
		fill(dist.begin(), dist.end(), -1);

		queue<int> Q;
		Q.push(source); dist[source] = 0;

		while (!Q.empty()) {
			int u = Q.front(); Q.pop();

			for (int i = 0; i < a[u].size(); i++) {
				int id = a[u][i];
				int v = E[id].v;

				if (dist[v] < 0 && E[id].flow < E[id].capacity) {
					dist[v] = dist[u] + 1;
					Q.push(v);
				}
			}
		}

		return dist[sink] >= 0;
	}

	double dfs(int now, double flow) {
		if (flow == 0) return 0;
		if (now == sink) return flow;

		for (; cur[now] < a[now].size(); cur[now]++) {
			int id = a[now][cur[now]];
			int v = E[id].v;

			if (dist[v] == dist[now] + 1) {
				double delta = dfs(v, min(flow, E[id].capacity - E[id].flow));
				if (delta) {
					E[id].flow += delta;
					E[id^1].flow -= delta;

					return delta;
				}
			}
		}

		return 0;
	}

	double maxflow() {
		double ans = 0;
		while (bfs()) {
			fill(cur.begin(), cur.end(), 0);
			while (1) {
				int delta = dfs(source, 1e9);
				if (!delta) break;

				ans += delta;
			}
		}
		return ans;
	}
};
signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

      int n, m, x;
      cin >> n >> m >> x;
      vector<int> a(m), b(m);
      vector<double> c(m);
      for (int i = 0; i < m; i++) {
            cin >> a[i] >> b[i] >> c[i];
      }

      double lo = 1e-12, hi = 1e12;
      for (int ite = 1; ite <= 300; ite++) {
            double mid = (lo + hi)/2;
            Flow F(n, 1, n);

            for (int i = 0; i < m; i++) {
                  ll w = min((ll)x, ll(c[i]/mid));
                  F.add_edge(a[i], b[i], w);
            }

            if (F.maxflow() >= x) lo = mid;
            else hi = mid;
      }
      cout << fixed << setprecision(12) << lo*x;

	return 0;
}