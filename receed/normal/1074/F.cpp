#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <set>
#include <map>
#include <random>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>

typedef long long ll;
typedef long double ld;
using namespace std;

const int N = 1 << 18, L = 18;
vector<int> g[N];
int tin[N], tout[N], up[L][N], d[N];
pair<int, int> t[N * 2];
set<pair<int, int>> es;
int mod[N * 2];
int ct;

void push(int v) {
	t[v].first += mod[v];
	if (v < N) {
		mod[v * 2] += mod[v];
		mod[v * 2 + 1] += mod[v];
	}
	mod[v] = 0;
}

void relax(int v) {
	if (v >= N)
		return;
	int v1 = v * 2, v2 = v1 + 1;
	t[v] = max(t[v1], t[v2]);
	if (t[v1].first == t[v2].first)
		t[v].second += min(t[v1].second, t[v2].second);
}

void add(int cl, int cr, int x, int v=1, int l=0, int r=N) {
	if (cr <= l || r <= cl) {
		push(v);
		return;
	}
	if (cl <= l && r <= cr) {
		mod[v] += x;
		push(v);
		return;
	}
	push(v);
	add(cl, cr, x, v * 2, l, (l + r) / 2);
	add(cl, cr, x, v * 2 + 1, (l + r) / 2, r);
	relax(v);
}

void dfs(int v, int p) {
	up[0][v] = p;
	d[v] = d[p] + 1;
	tin[v] = ct++;
	for (int u : g[v]) {
		if (u == p)
			continue;
		dfs(u, v);
	}
	tout[v] = ct;
}

int get(int v, int h) {
	for (int i = L - 1; i >= 0; i--)
		if (h >= (1 << i)) {
			v = up[i][v];
			h -= (1 << i);
		}
	return v;
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, q, u, v, sg;
	cin >> n >> q;
	for (int i = 0; i < n - 1; i++) {
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, 1);
	for (int i = 0; i < L - 1; i++)
		for (int j = 1; j <= n; j++)
			up[i + 1][j] = up[i][up[i][j]];
	for (int i = 0; i < n; i++)
		t[N + i].second = 1;
	for (int i = N - 1; i > 0; i--)
		t[i].second = t[i * 2].second + t[i * 2 + 1].second;
	for (int i = 0; i < q; i++) {
		cin >> u >> v;
		if (tin[u] > tin[v])
			swap(u, v);
		if (es.count({u, v})) {
			es.erase({u, v});
			sg = -1;
		}
		else {
			es.insert({u, v});
			sg = 1;
		}
		//cout << tin[u] << ' ' << tout[u] << ' ' << tin[v] << ' ' << tout[v] << '\n';
		if (tout[v] <= tout[u]) {
			int w = get(v, d[v] - d[u] - 1);
			add(tin[1], tout[1], sg);
			add(tin[v], tout[v], sg);
			add(tin[w], tout[w], -sg);
		}
		else {
			add(tin[v], tout[v], sg);
			add(tin[u], tout[u], sg);
		}
		//cout << t[1].first << ' ' << t[1].second << '\n';
		if (t[1].first < es.size())
			cout << 0 << '\n';
		else
			cout << t[1].second << '\n';
	}
}