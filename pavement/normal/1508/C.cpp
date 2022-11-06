#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#ifdef _WIN32
#define getchar_unlocked _getchar_nolock
#endif
#define int long long
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define ppb pop_back
#define eb emplace_back
#define g0(a) get<0>(a)
#define g1(a) get<1>(a)
#define g2(a) get<2>(a)
#define g3(a) get<3>(a)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef double db;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef tuple<int, int, int, int> iiii;
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int N, M, cst, xo, use, link[200005], sz[200005];
vector<int> vec[200005];
vector<ii> aft, adj[200005];
iii ED[200005];
set<ii> segs;

int find(int x) {
	if (x == link[x]) return x;
	return link[x] = find(link[x]);
}

void unite(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	if (sz[b] > sz[a]) swap(a, b);
	sz[a] += sz[b];
	for (int i : vec[b]) vec[a].pb(i);
	link[b] = a;
}

void wrk(int a, int l, int r) {
	segs.emplace(l, r);
	aft.eb(a, l);
}

int anc[200005][25], nz[200005], mw[200005][25], dep[200005]; // memset(anc, -1, sizeof anc);
vector<ii> adj2[200005];
void dfs(int n, int e = -1, int ed = -1) {
    anc[n][0] = e;
    mw[n][0] = ed; // ed is the weight of the edge connecting n and n's parent
    for (int i = 1; i <= 20; i++)
        if (anc[n][i - 1] != -1) {
            anc[n][i] = anc[anc[n][i - 1]][i - 1];
            mw[n][i] = max(mw[n][i - 1], mw[anc[n][i - 1]][i - 1]);
        }    
    for (auto u : adj2[n])
        if (u.first != e) {
			nz[u.first] = nz[n];
			if (u.second == 0) nz[u.first]++;
            dep[u.first] = dep[n] + 1;
            dfs(u.first, n, u.second);
        }
}
int mlca(int u, int v) { // maximum edge weight on path u -> v
    int m = 0;
    if (dep[u] < dep[v]) swap(u, v);
    for (int i = 20; i >= 0; i--)
        if (dep[u] - (1 << i) >= dep[v]) m = max(m, mw[u][i]), u = anc[u][i];
    if (u == v) return m;
    for (int i = 20; i >= 0; i--)
        if (anc[u][i] != anc[v][i]) {
            m = max(m, mw[u][i]);
            m = max(m, mw[v][i]);
            u = anc[u][i];
            v = anc[v][i];
        }
    return max({m, mw[u][0], mw[v][0]});
}
int lca(int u, int v) {
	if (dep[u] < dep[v]) swap(u, v);
	for (int i = 20; i >= 0; i--)
		if (dep[u] - (1 << i) >= dep[v]) u = anc[u][i];
	if (u == v) return u;
	for (int i = 20; i >= 0; i--)
		if (anc[u][i] != anc[v][i]) {
			u = anc[u][i];
			v = anc[v][i];
		}
	return anc[u][0];
}

main() {
	memset(anc, -1, sizeof anc);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) link[i] = i, sz[i] = 1, vec[i].pb(i);
	for (int i = 1, u, v, w; i <= M; i++) {
		cin >> u >> v >> w;
		xo ^= w;
		adj[u].eb(v, w);
		adj[v].eb(u, w);
		ED[i] = mt(w, u, v);
	}
	sort(ED + 1, ED + 1 + M);
	for (int i = 1; i <= N; i++) {
		sort(adj[i].begin(), adj[i].end());
		if (!adj[i].empty() && adj[i][0].first != 1) wrk(i, 1, adj[i][0].first - 1);
		if (!adj[i].empty() && adj[i].back().first != N) wrk(i, adj[i].back().first + 1, N);
		for (int j = 0; j < (int)adj[i].size() - 1; j++)
			if (adj[i][j].first != adj[i][j + 1].first - 1) wrk(i, adj[i][j].first + 1, adj[i][j + 1].first - 1);
		if (adj[i].empty()) wrk(i, 1, N);
	}
	int rb = -1, st = -1;
	for (auto i : segs) {
		if (i.first <= rb) {
			rb = max(rb, i.second);
		} else {
			for (int j = st; j < rb; j++) unite(j, j + 1);
			st = i.first;
			rb = i.second;
		}
	}
	for (int j = st; j < segs.rbegin()->second; j++) unite(j, j + 1);
	for (auto i : aft) unite(i.first, i.second);
	for (int i = 1; i <= N; i++) {
		if (i != find(i)) continue;
		for (int j = 0; j < (int)vec[i].size() - 1; j++) {
			adj2[vec[i][j]].eb(vec[i][j + 1], 0);
			adj2[vec[i][j + 1]].eb(vec[i][j], 0);
		}
	}
	for (int i = 1, u, v, w; i <= M; i++) {
		tie(w, u, v) = ED[i];
		if (find(u) != find(v)) {
			cst += w;
			use++;
			adj2[u].eb(v, w);
			adj2[v].eb(u, w);
			unite(u, v);
		}
	}
	if (N - 1 - use != (N * (N - 1) / 2) - M) cout << cst << '\n';
	else {
		dfs(1);
		int out = cst + xo;
		for (int i = 1, u, v, w; i <= M; i++) {
			tie(w, u, v) = ED[i];
			if (nz[u] + nz[v] - 2 * nz[lca(u, v)] > 0) out = min(out, cst + w);
		}
		cout << out << '\n';
	}
}