#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 500, inf = 1e9;
int n, l[maxn + 10], r[maxn + 10], c[maxn + 10], f[maxn + 10], lim[maxn + 10], w[maxn + 10];
int m;
ll ans;

namespace flow {
	typedef long long FlowType, CostType;
	const int maxn = 1e5, maxm = 2e5;
	const FlowType inff = 1e18;
	const CostType infc = 1e18;

	int n, m, s, t;
	vector<int> g[maxn];

	struct Edge {
		int v;
		FlowType cap, flow;
		CostType cost;
	} edge[maxm << 1];

	CostType dist[maxn], h[maxn];

	void Init(int _n, int _s, int _t) {
		n = _n; s = _s; t = _t; m = 0;
		for (int i = 0; i <= n; ++i) g[i].clear();
	}

	void AddEdge(int u, int v, FlowType cap, CostType cost) {
		g[u].push_back(m);
		edge[m++] = (Edge){v, cap, 0, cost};
		g[v].push_back(m);
		edge[m++] = (Edge){u, 0, 0, -cost};
	}

	struct Node {
		int u;
		CostType d;
		bool operator < (const Node &rhs) const {
			return d > rhs.d;
		}
	};

	bool Dijkstra(void) {
		priority_queue<Node> q;
		q.push((Node){s, 0});
		fill(dist, dist + n, infc);
		dist[s] = 0;
		while (!q.empty()) {
			int u = q.top().u;
			CostType d = q.top().d;
			q.pop();
			if (d != dist[u]) continue;
			for (int i = 0; i < g[u].size(); ++i) {
				Edge &e = edge[g[u][i]];
				if (e.flow < e.cap) {
					CostType t = dist[u] + h[u] - h[e.v] + e.cost;
					if (dist[e.v] > t) {
						dist[e.v] = t;
						q.push((Node){e.v, t});
					}
				}
			}
		}
		for (int i = 0; i < n; ++i) {
			h[i] = min(h[i] + dist[i], infc);
		}
		return h[t] != infc;
	}

	bool ins[maxn];
	int cur[maxn];

	FlowType Dfs(int u, FlowType f) {
		if (u == t) return f;
		ins[u] = true;
		FlowType sum = 0;
		for (int &i = cur[u]; i < g[u].size(); ++i) {
			Edge &e = edge[g[u][i]], &r = edge[g[u][i] ^ 1];
			if (e.flow < e.cap && e.cost + h[u] - h[e.v] == 0 && !ins[e.v]) {
				FlowType t = Dfs(e.v, min(f - sum, e.cap - e.flow));
				e.flow += t;
				r.flow -= t;
				sum += t;
				if (sum == f) break;
			}
		}
		ins[u] = false;
		return sum;
	}

	pair<FlowType, CostType> Solve(void) {
		pair<FlowType, CostType> ans(0, 0);
		fill(h, h + n, 0);
		fill(ins, ins + n, false);
		while (Dijkstra()) {
			fill(cur, cur + n, 0);
			FlowType f = Dfs(s, inff);
			ans.first += f;
			ans.second += f * h[t];
		}
		return ans;
	}
}

int main() {
	scanf("%d%d", &n, &m);
	flow::Init(n + 3, 1, 2);
	for (int i = 1; i <= m; ++i) {
		scanf("%d%d%d%d", &l[i], &r[i], &c[i], &f[i]);
		lim[i] = f[i];
		if (f[i] > c[i]) {
			ans += f[i] - c[i];
			f[i] = c[i];
		}
		w[l[i]] -= f[i]; w[r[i]] += f[i];
	}
	for (int i = 1; i <= n; ++i)
		if (w[i] < 0)
			flow::AddEdge(i + 2, 2, -w[i], 0);
		else if (w[i] > 0)
			flow::AddEdge(1, i + 2, w[i], 0);
	for (int i = 1; i <= m; ++i) {
		flow::AddEdge(l[i] + 2, r[i] + 2, lim[i] - f[i], 0);
		flow::AddEdge(l[i] + 2, r[i] + 2, c[i] - lim[i], 1);
		flow::AddEdge(l[i] + 2, r[i] + 2, inf, 2);
		flow::AddEdge(r[i] + 2, l[i] + 2, f[i], 1);
	}
	flow::AddEdge(n + 2, 3, inf, 0);
	printf("%lld", ans + flow::Solve().second);
}