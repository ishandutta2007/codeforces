#include <bits/stdc++.h>

using namespace std;

const int N = 500010;

int n, m, q;

struct Edge {
	int u, v, w; 
	Edge(int u = 0, int v = 0, int w = 0) {
		this->u = u;
		this->v = v;
		this->w = w;
	}
} a[N];

bool cmp(int u, int v) {
	return a[u].w < a[v].w;
}

int id[N], res[N];
vector<int> b[N], has[N];
int cur[N];

struct DSU {
	int root[N], sz[N];
	vector<Edge> a;
	DSU() {
		for (int i = 1; i <= n; i++) {
			root[i] = i;
			sz[i] = 1;
		}
	}

	int getRoot(int u) {
		return root[u] == u ? u : getRoot(root[u]);
	}

	void join(int u, int v, int roll) {
		if (u == v) {
			return;
		}
		if (sz[u] > sz[v]) {
			swap(u, v);
		}
		if (roll) {
			a.emplace_back(u, v, sz[u]);
		}
		root[u] = v;
		sz[v] += sz[u];
	}

	void rollBack() {
		while (!a.empty()) {
			Edge u = a.back();
			a.pop_back();
			sz[u.v] -= u.w;
			root[u.u] = u.u;
		}
	}
};

int main() {
	scanf("%d %d", &n, &m);
	DSU d;
	for (int i = 1; i <= m; i++) {
		scanf("%d %d %d", &a[i].u, &a[i].v, &a[i].w);
		id[i] = i;
	}
	sort(id + 1, id + m + 1, cmp);
	scanf("%d", &q);
	for (int i = 1; i <= q; i++) {
		int k;
		scanf("%d", &k);
		for (int j = 0; j < k; j++) {
			int u;
			scanf("%d", &u);
			b[i].push_back(u);
		}
		sort(b[i].begin(), b[i].end(), cmp);
		int last = -1;
		for (int u : b[i]) {
			if (a[u].w != last) {
				has[a[u].w].push_back(i);
			}
			last = a[u].w;
		}
	}
	for (int s = 1; s <= m;) {
		int val = a[id[s]].w;
		for (int id : has[val]) {
			int &now = cur[id];
			while (now < b[id].size() && a[b[id][now]].w == val) {
				int u = a[b[id][now]].u;
				int v = a[b[id][now]].v;
				int uu = d.getRoot(u);
				int vv = d.getRoot(v);
				if (uu == vv) {
					res[id] = 1;
				} else {
					d.join(uu, vv, 1);
				}
				now++;
			}
			d.rollBack();
		}

		int &cur = s;
		while (cur <= m && a[id[cur]].w == val) {
			int u = a[id[cur]].u;
			int v = a[id[cur]].v;
			int uu = d.getRoot(u);
			int vv = d.getRoot(v);
			d.join(uu, vv, 0);
			cur++;
		}
	}
	for (int i = 1; i <= q; i++) {
		puts(res[i] ? "NO" : "YES");
	}
	return 0;
}