#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define sz(x) (int) x.size()
#define INF (int) 1e9
#define LINF (ll) 1e18
#define EPS 1e-8
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)

struct item {
	int v;
	ll val;

	item (int v, ll val) : v(v), val(val) {}

	bool operator<(const item &other) const {
		return val > other.val;
	}
};

struct edge {
	int from, to;
	ll w;
	int id;

	edge (int from, int to, ll w, int id) : from(from), to(to), w(w), id(id) {}
};

int n;

vector<ll> dijkstra(int from, vector<vector<edge>> &g) {
	vector<ll> dist(n,  LINF);
	vector<bool> visited(n);
	priority_queue<item> q;
	q.push(item(from, 0));
	dist[from] = 0;

	while (!q.empty()) {
		item best = q.top();
		q.pop();

		while (visited[best.v] && !q.empty()) {
			best = q.top();
			q.pop();
		}

		if (visited[best.v]) {
			break;
		}

		visited[best.v] = true;

		for (edge e : g[best.v]) {
			if (dist[e.to] > dist[best.v] + e.w) {
				dist[e.to] = dist[best.v] + e.w;
				q.push(item(e.to, dist[e.to]));
			}
		}
	}

	return dist;
}

int m, s, t;
vector<vector<edge>> g1;
vector<vector<edge>> g2;
vector<ll> d1;
vector<ll> d2;
vector<vector<edge>> h;
ll ans[100000];

ll func(int u, int v, int w) {
	return d1[u] + w + d2[v];
}

bool visited[100000];
bool is_bridge[100000];
int fup[100000];
int tin[100000];
int dfs_timer;

void dfs(int v, int from) {
	visited[v] = true;
	tin[v] = dfs_timer++;
	fup[v] = tin[v];

	for (edge e : h[v]) {
		if (e.id == from) {
			continue;
		}

		if (visited[e.to]) {
			fup[v] = min(fup[v], tin[e.to]);
		} else {
			dfs(e.to, e.id);

			if (fup[e.to] > tin[v] && e.id != -1) {
				is_bridge[e.id] = true;
			}

			fup[v] = min(fup[v], fup[e.to]);
		}
	}
}

int main() {
	cin >> n >> m >> s >> t;
	g1.resize(n);
	g2.resize(n);
	h.resize(n);
	s--;
	t--;

	for (int i = 0; i < m; i++) {
		int a, b, l;
		cin >> a >> b >> l;
		a--;
		b--;

		g1[a].push_back(edge(a, b, l, i));
		g2[b].push_back(edge(b, a, l, i));
	}

	d1 = dijkstra(s, g1);
	d2 = dijkstra(t, g2);

	for (int i = 0; i < n; i++) {
		for (edge e : g1[i]) {
			if (func(e.from, e.to, e.w) == d1[t]) {
				h[e.from].push_back(e);
				h[e.to].pb(edge(e.to, e.from, e.w, e.id));
			}
		}
	}

	dfs(s, -1);

	for (int i = 0; i < m; i++) {
		if (is_bridge[i]) {
			ans[i] = -1;
		}
	}

	for (int i = 0; i < n; i++) {
		for (edge e : g1[i]) {
			if (ans[e.id] == -1) {
				continue;
			}

			ll cost = func(e.from, e.to, e.w);
			ll delta = cost - d1[t] + 1;

			if (e.w - delta > 0) {
				ans[e.id] = delta;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		if (ans[i] == -1) {
			cout << "YES\n";
		} else if (ans[i] == 0) {
			cout << "NO\n";
		} else {
			cout << "CAN " << ans[i] << "\n";
		}
	}

    return 0;
}