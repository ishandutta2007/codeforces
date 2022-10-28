#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e5+10, MOD = 1e9+7;

namespace kactl {

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
typedef pair<int, int> pii;
typedef vector<int> vi;

template<class T>
struct RMQ {
	vector<vector<T>> jmp;
    RMQ(){}
	RMQ(const vector<T>& V) : jmp(1, V) {
		for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
			jmp.emplace_back(sz(V) - pw * 2 + 1);
			rep(j,0,sz(jmp[k]))
				jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
		}
	}
	T query(int a, int b) {
		assert(a < b); // or return inf if a == b
		int dep = 31 - __builtin_clz(b - a);
		return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};
struct LCA {
	int T = 0;
	vi time, path, ret;
	RMQ<int> rmq;

	LCA(vector<vi>& C) : time(sz(C)), rmq((dfs(C,0,-1), ret)) {}
    LCA(){}
	void dfs(vector<vi>& C, int v, int par) {
		time[v] = T++;
		for (int y : C[v]) if (y != par) {
			path.push_back(v), ret.push_back(time[v]);
			dfs(C, y, v);
		}
	}

	int lca(int a, int b) {
		if (a == b) return a;
		tie(a, b) = minmax(time[a], time[b]);
		return path[rmq.query(a, b)];
	}
} lca;

#undef rep
#undef all

};
using kactl::LCA;
using kactl::lca;


const int MAXS = 43;

int n, m;
vector<ar<int, 2>> adj[MAXN];
vector<ar<int, 2>> tree[MAXN];
vector<ar<int, 3>> spec;
int id_spec[MAXN], rev_id[MAXS];

ll root[MAXN], dist[MAXS][MAXS];
ll one[MAXN], two[MAXN];

void root_dist(int c, int p) {
    for (auto [nxt, w] : tree[c]) if (nxt != p) {
        root[nxt] = root[c]+w;
        root_dist(nxt, c);
    }
}
ll dist_tree(int a, int b) {
    return root[a]+root[b]-2*root[lca.lca(a, b)];
}

bool vis[MAXN];
void dfs_tree(int c, int p) {
    vis[c] = 1;
    for (auto [nxt, w] : adj[c]) if (nxt != p) {
        if (vis[nxt]) {
            if (c > nxt) spec.push_back({c, nxt, w});
        } else {
            dfs_tree(nxt, c);
            tree[c].push_back({nxt, w});
            tree[nxt].push_back({c, w});
        }
    }
}
void init_lca() {
    vector<vector<int>> G(n);
    for (int a = 0; a < n; a++) for (auto [b, w] : tree[a]) 
        G[a].push_back(b);
    lca = LCA(G);
}
void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, w; cin >> a >> b >> w, --a, --b;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }
    dfs_tree(0, -1);
    root_dist(0, -1);

    memset(id_spec, -1, sizeof(id_spec));
    int s = 0;
    for (auto [a, b, w] : spec) {

        auto add = [&](int x) {
            if (id_spec[x] == -1) {
                id_spec[x] = s++;
                rev_id[id_spec[x]] = x;
            }
        };

        add(a), add(b);
    }
    assert(s < MAXS);

    init_lca();
    for (int i = 0; i < s; i++) {
        for (int j = 0; j < s; j++) {
            dist[i][j] = dist_tree(rev_id[i], rev_id[j]);
        }
    }
    for (auto [a, b, w] : spec) {
        a = id_spec[a], b = id_spec[b];
        dist[a][b] = min(dist[a][b], (long long) w);
        dist[b][a] = min(dist[b][a], (long long) w);
    }
    for (int k = 0; k < s; k++) {
        for (int i = 0; i < s; i++) {
            for (int j = 0; j < s; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }
    int q; cin >> q;
    while (q--) {
        int a, b; cin >> a >> b, --a, --b;
        for (int i = 0; i < s; i++) one[i] = dist_tree(a, rev_id[i]);
        for (int i = 0; i < s; i++) two[i] = dist_tree(b, rev_id[i]);
        ll ans = dist_tree(a, b);
        for (int i = 0; i < s; i++) for (int j = 0; j < s; j++)
            ans = min(ans, one[i]+dist[i][j]+two[j]);
        cout << ans << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}