#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 1e5+10, MOD = 998244353;
const ll INF = 1e18+10;

template<class T> using min_pq = priority_queue<T, vector<T>, greater<T>>;

struct DSU {
	vector<int> p, sz;
	void init(int n){ p.resize(n); sz.assign(n, 1); iota(p.begin(), p.end(), 0); }
	int find_set(int v){ return v==p[v]?v:p[v]=find_set(p[v]); }
	bool union_sets(int a, int b){
		if ((a=find_set(a))==(b=find_set(b))) return false;
		if (sz[a] < sz[b]) swap(a, b);
		p[b]=a, sz[a]+=sz[b], sz[b]=0;
		return true;
	}
} d;

// an edge can be used iff dist[a] + w + dist[b] <= C
// find MST of dist[a] + w + dist[b], find max edge

const int L = 20;

int n, m, k, q;
ll dist[N];
vector<pair<int, ll>> adj[N];

int depth[N], anc[N][L];
ll sparse[N][L];

void dfs(int c, int p, int d) {
	depth[c] = d, anc[c][0] = p;
	for (int i = 1; i < L; i++) {
        anc[c][i] = (anc[c][i-1] == -1 ? -1 : anc[anc[c][i-1]][i-1]);
        sparse[c][i] = max(sparse[c][i-1], (anc[c][i-1] == -1 ? -1LL : sparse[anc[c][i-1]][i-1])); 
    }
	for (auto [nxt, w] : adj[c]) if (nxt != p) {
        sparse[nxt][0] = w;
        dfs(nxt, c, d+1);
    }
}
pair<int, ll> jump(int a, int h) {
    ll ans = -1;
	for (int i = 0; i < L; i++) if ((h >> i) & 1) {
        ans = max(ans, sparse[a][i]);
        a = anc[a][i];
    }
	return {a, ans};
}
int lca(int a, int b) {
	if (depth[a] < depth[b]) swap(a, b);
	a = jump(a, depth[a]-depth[b]).first;
	if (a == b) return a;
	for (int i = L-1; i >= 0; i--) {
		if (anc[a][i] != anc[b][i]) a = anc[a][i], b = anc[b][i];
	}
	assert(anc[a][0] == anc[b][0]);
	return anc[a][0];
}
ll qry(int a, int b) {
    int l = lca(a, b);
    auto [lx, x] = jump(a, depth[a] - depth[l]);
    auto [ly, y] = jump(b, depth[b] - depth[l]);
    return max(x, y);
}

void solve() {
    cin >> n >> m >> k >> q;
    for (int i = 0; i < m; i++) {
        int a, b, w; cin >> a >> b >> w, --a, --b;
        adj[a].push_back({b, w}), adj[b].push_back({a, w});
    }
    std::fill(dist, dist + n, INF);
    min_pq<pair<ll, int>> pq;
    for (int i = 0; i < k; i++) {
        dist[i] = 0, pq.push({0, i});
    }
    while (sz(pq)) {
        auto [d_c, c] = pq.top(); pq.pop();
        if (d_c != dist[c]) continue;
        for (auto [nxt, w] : adj[c]) {
            if (dist[c] + w < dist[nxt]) {
                dist[nxt] = dist[c] + w;
                pq.push({dist[nxt], nxt});
            }
        }
    }
    vector<ar<ll, 3>> ed; ed.reserve(m);
    for (int a = 0; a < n; a++) {
        for (auto& [b, w] : adj[a]) {
            ed.push_back({w + dist[a] + dist[b], a, b});
        }
    }
    for (int i = 0; i < n; i++) adj[i].clear();

    sort(ed.begin(), ed.end());
    d.init(n);
    for (auto [w, x, y] : ed) {
        if (d.union_sets(x, y)) {
            adj[x].push_back({y, w});
            adj[y].push_back({x, w});
        }
    }

    dfs(0, -1, 0);

    while (q--) {
        int a, b; cin >> a >> b, --a, --b;
        cout << qry(a, b) << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}