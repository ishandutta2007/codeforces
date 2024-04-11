#include <bits/stdc++.h>

using namespace std;

int k;
int ans;

struct edge {
	int from;
	int to;
};

int const N = 1234567;

int q[N], deg[N];
set<int> g[N];
edge edges[N];

int head, tail;

void process() {
	while (head < tail) {
		--ans;
		int v = q[head++];
		for (int to : g[v]) {
			g[to].erase(v);
			--deg[to];
			if (deg[to] + 1 == k) {
				q[tail++] = to;
			}
		}
		g[v].clear();
		deg[v] = 0;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		--x;
		--y;
		deg[x]++;
		deg[y]++;
		edges[i] = {x, y};
		g[x].insert(y);
		g[y].insert(x);
	}
	ans = n;
	head = 0;
	tail = 0;
	for (int i = 0; i < n; i++) if (deg[i] < k) {
		q[tail++] = i;
	}
	process();
	vector<int> ap(m);
	ap[m - 1] = ans;
	for (int i = m - 1; i > 0; i--) {
		int v = edges[i].from;
		int u = edges[i].to;
		if (g[v].find(u) != g[v].end()) {
  		deg[v]--;
  		deg[u]--;
  		g[v].erase(u);
  		g[u].erase(v);
  		if (deg[v] + 1 == k) q[tail++] = v;
  		if (deg[u] + 1 == k) q[tail++] = u;
  		process();
		}
		ap[i - 1] = ans;
	}
	for (int i = 0; i < m; i++) cout << ap[i] << '\n';
}