#include <bits/stdc++.h>

using namespace std;
const int N = 250;
const int M = 1e5 + 50;
const long long inf = 1e18;

int n, m, s, t, cur[N], d[N], a[N], b[N], ans[N][N];
int head[N], nxt[M], ver[M], edge[M], tot = 1;

inline void add(int u, int v, int w) {
	nxt[++tot] = head[u], ver[tot] = v, edge[tot] = w, head[u] = tot;
	nxt[++tot] = head[v], ver[tot] = u, edge[tot] = 0, head[v] = tot;
}

bool bfs() {
	queue<int> que;
	memcpy(cur, head, sizeof head);
	memset(d, 0x3f, sizeof d);
	d[s] = 0;
	que.emplace(s);
	while (!que.empty()) {
		int x = que.front(); que.pop();
		for (int i = head[x]; i; i = nxt[i]) {
			int y = ver[i], w = edge[i];
			if (w && d[y] > d[x] + 1) {
				d[y] = d[x] + 1;
				if (y == t) return true;
				que.emplace(y);
			}
		}
	}
	return false;
}

long long dinic(int x, long long flow) {
	if (x == t) return flow;
	long long rest = flow;
	for (int &i = cur[x]; i; i = nxt[i]) {
		int y = ver[i], w = edge[i];
		if (w && d[y] == d[x] + 1) {
			long long k = dinic(y, min((long long)w, rest));
			if (!k) d[y] = 0;
			edge[i] -= k;
			rest -= k;
			edge[i ^ 1] += k;
			if (!rest) break;
		}
	}
	return flow - rest;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;
	s = 2 * n + 1; t = s + 1;
	int suma = 0, sumb = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		add(s, i, a[i]);
		suma += a[i];
	}	
	for (int i = 1; i <= n; ++i) {
		cin >> b[i];
		add(i + n, t, b[i]);
		sumb += b[i];
	}
	if (suma != sumb) {
		puts("NO");
		return 0;
	}
	for (int i = 1; i <= n; ++i) {
		add(i, i + n, 0x3f3f3f3f);
	}
	for (int i = 1; i <= m; ++i) {
		int p, q;
		cin >> p >> q;
		add(p, q + n, 0x3f3f3f3f);
		add(q, p + n, 0x3f3f3f3f);
	}
	long long maxflow = 0, flow;
	while (bfs())
		while (flow = dinic(s, inf))
			maxflow += flow;
	if (maxflow != suma) {
		puts("NO");
		return 0;
	}
	cout << "YES\n";
	for (int i = 1; i <= n; ++i) {
		for (int j = head[i + n]; j; j = nxt[j]) {
			int y = ver[j];
			if (1 <= y && y <= n) {
				ans[y][i] += edge[j];				
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cout << ans[i][j] << " \n"[j == n];
		}
	}
	return 0;
}