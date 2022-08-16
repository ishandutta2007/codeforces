#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 3e5+10, MOD = 998244353;

struct DSU {
	vector<int> p, sz;
	void init(int n) { 
        p.resize(n); iota(p.begin(), p.end(), 0);
        sz.assign(n, 1);
    }
	int find_set(int v) { 
        return v == p[v] ? v : p[v] = find_set(p[v]);
    }
	bool union_sets(int a, int b) {
        a = find_set(a), b = find_set(b);
        if (a == b) return false;
		if (sz[a] < sz[b]) swap(a, b);
		p[b] = a, sz[a] += sz[b], sz[b] = 0;
		return true;
	}
} d;


int n, m, mark[N];
bool ans[N];
vector<int> adj[N];


const int L = 20;
int depth[N], anc[N][L];

void init_lca(int c = 0, int p = -1, int d = 0) {
	depth[c] = d, anc[c][0] = p;
	for (int i = 1; i < L; i++) anc[c][i] = (anc[c][i-1] == -1? -1 : anc[anc[c][i-1]][i-1]);
	for (auto nxt : adj[c]) if (nxt != p) init_lca(nxt, c, d+1);
}
int jump(int a, int h) {
	for (int i = 0; i < L; i++) if ((h >> i) & 1) a = anc[a][i];
	return a;
}
int lca(int a, int b) {
	if (depth[a] < depth[b]) swap(a, b);
	a = jump(a, depth[a]-depth[b]);
	if (a == b) return a;
	for (int i = L-1; i >= 0; i--) {
		if (anc[a][i] != anc[b][i]) a = anc[a][i], b = anc[b][i];
	}
	assert(anc[a][0] == anc[b][0]);
	return anc[a][0];
}

void dfs(int c, int p, int delta) {
    delta += mark[c];
    assert(delta >= 0);
    ans[c] = delta == 0;
    for (auto nxt : adj[c]) if (nxt != p)
        dfs(nxt, c, delta);
}
void solve() {
    cin >> n >> m;
    d.init(n);
    vector<ar<int, 2>> bad;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b, --a, --b;
        if (d.union_sets(a, b)) {
            adj[a].push_back(b), adj[b].push_back(a);
        } else {
            bad.push_back({a, b});
        }
    }
    init_lca();
    for (auto [a, b] : bad) {
        if (depth[a] < depth[b]) swap(a, b);
        int l = lca(a, b);
        if (b == l) {
            if (depth[a] - depth[b] > 1) {
                int almost = jump(a, depth[a] - depth[b] - 1);
                mark[almost]++, mark[a]--;
            }
        } else {
            mark[0]++; 
            mark[a]--, mark[b]--;
        }
    }
    dfs(0, -1, 0);
    for (int i = 0; i < n; i++) cout << ans[i];
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}