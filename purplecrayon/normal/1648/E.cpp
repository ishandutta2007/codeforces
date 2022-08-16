#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 1e9+7;

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

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
typedef pair<int, int> pii;
typedef vector<int> vi;

template<class T>
struct RMQ {
	vector<vector<T>> jmp;
	RMQ(const vector<T>& V) : jmp(1, V) {
		for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
			jmp.emplace_back(sz(V) - pw * 2 + 1);
			rep(j,0,sz(jmp[k]))
				jmp[k][j] = max(jmp[k - 1][j], jmp[k - 1][j + pw]);
		}
	}
	T qry(int a, int b) {
		assert(a < b); // or return inf if a == b
		int dep = 31 - __builtin_clz(b - a);
		return max(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};

struct PathMax {
    static constexpr int L = 20;
    vector<vector<ar<int, 2>>> adj;
    vector<vector<int>> anc, sparse;
    vector<int> depth;

    PathMax(int n, const vector<ar<int, 3>>& ed) {
        adj.clear(), adj.resize(n);
        anc.assign(n, vector<int>(L, -1));
        sparse.assign(n, vector<int>(L, -1));
        depth.resize(n);
        for (auto [a, b, w] : ed) {
            adj[a].push_back({b, w});
            adj[b].push_back({a, w});
        }
        dfs_lca(0, -1, 0);
    }
    void dfs_lca(int c, int p, int d) {
        depth[c] = d, anc[c][0] = p;
        for (int i = 1; i < L; i++) {
            anc[c][i] = (anc[c][i-1] == -1 ? -1 : anc[anc[c][i-1]][i-1]);
            sparse[c][i] = sparse[c][i-1];
            if (anc[c][i-1] != -1) sparse[c][i] = max(sparse[c][i], sparse[anc[c][i-1]][i-1]);
        }
        for (auto [nxt, w] : adj[c]) if (nxt != p) {
            sparse[nxt][0] = w;
            dfs_lca(nxt, c, d+1);
        }
    }
    pair<int, int> jump(int a, int h) {
        int ans = -MOD;
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
    int qry(int a, int b) {
        int d = depth[lca(a, b)];
        return max(jump(a, depth[a] - d).second, jump(b, depth[b] - d).second);
    }
};

void solve() {
    int n, m; cin >> n >> m;
    vector<ar<int, 3>> ed(m);
    vector<vector<ar<int, 2>>> adj(n);
    for (auto& [w, a, b] : ed) {
        cin >> a >> b >> w, --a, --b;
        adj[a].push_back({b, w}), adj[b].push_back({a, w});
    }

    auto sed = ed;
    sort(sed.begin(), sed.end());

    vector<ar<int, 3>> mst;
    d.init(n);
    for (auto& [w, a, b] : sed) {
        if (d.union_sets(a, b))
            mst.push_back({a, b, w});
    }

    vector<vector<int>> st(n), weights(n);
    vector<int> par(n);
    for (int i = 0; i < n; i++) {
        par[i] = i;
        st[par[i]].push_back(i);
    }
    for (auto [a, b, w] : mst) {
        a = par[a], b = par[b];
        if (sz(st[a]) < sz(st[b])) swap(a, b);
        weights[a].push_back(w);
        for (auto v : weights[b]) weights[a].push_back(v);
        weights[b].clear();

        for (auto v : st[b]) {
            par[v] = a;
            st[a].push_back(v);
        }
        st[b].clear();
    }
    auto ord = st[par[0]], cost = weights[par[0]];
    assert(sz(ord) == n && sz(cost) == n-1);
    // cerr << "ord: "; for (int c : ord) cerr << c << ' '; cerr << endl;
    // cerr << "cost: "; for (int c : cost) cerr << c << ' '; cerr << endl;

    vector<int> pos(n);
    for (int i = 0; i < n; i++)
        pos[ord[i]] = i;

    RMQ rmq(cost);

    vector<ar<int, 3>> oppMST; 
    d.init(n);
    while (sz(oppMST) < n-1) {
        vector<ar<int, 3>> new_edges;

        set<int> can;
        for (int i = 0; i < n; i++) can.insert(i);
        vector<vector<int>> comps(n);
        for (int i = 0; i < n; i++) comps[d.find_set(i)].push_back(i);
        for (auto& comp : comps) {
            if (sz(comp) == 0) continue;
            for (int x : comp) can.erase(pos[x]);

            ar<int, 3> best{MOD, MOD, MOD};
            for (int x : comp) {
                for (auto [y, _] : adj[x]) if (d.find_set(x) != d.find_set(y)) {
                    can.erase(pos[y]);
                }

                auto nxt = can.upper_bound(pos[x]);
                auto prv = can.lower_bound(pos[x]);
                if (nxt != can.end()) {
                    // cerr << "considering nxt: " << pos[x] << ' ' << *nxt << ' ' << x << ' ' << ord[*nxt] << ' ' << rmq.qry(pos[x], *nxt) << '\n';
                    best = min(best, ar<int, 3>{rmq.qry(pos[x], *nxt), x, ord[*nxt]});
                }
                if (prv != can.begin()) {
                    --prv;
                    // cerr << "considering prv: " << pos[x] << ' ' << *prv<< ' ' << x << ' ' << ord[*prv] << ' ' << rmq.qry(*prv, pos[x]) << '\n';
                    best = min(best, ar<int, 3>{rmq.qry(*prv, pos[x]), x, ord[*prv]});
                }

                for (auto [y, _] : adj[x]) if (d.find_set(x) != d.find_set(y)) {
                    can.insert(pos[y]);
                }
            }
            new_edges.push_back(best);

            for (int x : comp) can.insert(pos[x]);
        }

        for (auto& [w, a, b] : new_edges) {
            if (d.union_sets(a, b)) {
                // cerr << "adding edge: " << a << ' ' << b << ' ' << w << '\n';
                oppMST.push_back({a, b, w});
            }
        }
    }

    PathMax path(n, oppMST);
    for (auto& [w, a, b] : ed) cout << path.qry(a, b) << ' ';
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}