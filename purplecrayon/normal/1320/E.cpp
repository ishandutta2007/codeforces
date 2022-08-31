#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 1e9+7;

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
	vi time, path, ret, depth;
	RMQ<int> rmq;

	LCA(vector<vi>& C) : time(sz(C)), depth(sz(C)), rmq((dfs(C,0,-1), ret)) {}
	void dfs(vector<vi>& C, int v, int par) {
		time[v] = T++;
        if (par != -1) depth[v] = depth[par] + 1;
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
    int dist(int a, int b) {
        return depth[a] + depth[b] - 2 * depth[lca(a, b)];
    }
};

typedef vector<pair<int, int>> vpi;
vpi compressTree(LCA& lca, const vi& subset) {
	static vi rev; rev.resize(sz(lca.time));
	vi li = subset, &T = lca.time;
	auto cmp = [&](int a, int b) { return T[a] < T[b]; };
	sort(all(li), cmp);
	int m = sz(li)-1;
	rep(i,0,m) {
		int a = li[i], b = li[i+1];
		li.push_back(lca.lca(a, b));
	}
	sort(all(li), cmp);
	li.erase(unique(all(li)), li.end());
	rep(i,0,sz(li)) rev[li[i]] = i;
	vpi ret = {pii(0, li[0])};
	rep(i,0,sz(li)-1) {
		int a = li[i], b = li[i+1];
		ret.emplace_back(rev[lca.lca(a, b)], b);
	}
	return ret;
}

template<class T> using min_pq = priority_queue<T, vector<T>, greater<T>>;

void solve() {
    int n; cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b, --a, --b;
        adj[a].push_back(b), adj[b].push_back(a);
    }
    int q; cin >> q;
    LCA lca(adj);
    while (q--) {
        int k, m; cin >> k >> m;
        vector<ar<int, 2>> a(k);
        vector<int> use;
        for (auto& [c, s] : a) {
            cin >> c >> s, --c;
            use.push_back(c);
        }
        vector<int> ans(m);
        for (int i = 0; i < m; i++) {
            int c; cin >> c, --c;
            ans[i] = c;
            use.push_back(c);
        }

        sort(use.begin(), use.end());
        use.resize(unique(use.begin(), use.end()) - use.begin());
        auto comp_par = compressTree(lca, use);

        int M = sz(comp_par);
        vector<vector<pair<int, int>>> nadj(M);
        map<int, int> me;
        for (int i = 0; i < M; i++) {
            me[comp_par[i].second] = i;
            if (i > 0) {
                int p = comp_par[i].first, d = lca.dist(comp_par[i].second, comp_par[p].second);
                nadj[i].emplace_back(p, d), nadj[p].emplace_back(i, d);
            }
        }


        vector<bool> vis(M);
        vector<ar<int, 3>> dist(M, {MOD, MOD, MOD}); // {turn, virus, time since turn started}
        for (int i = 0; i < k; i++) {
            auto [c, s] = a[i];
            // cerr << "virus: " << c << ' ' << s << ' ' << me[c] << endl;
            dist[me[c]] = {0, i, 0};
        }

        min_pq<pair<ar<int, 3>, int>> pq;
        for (int i = 0; i < M; i++) if (dist[i][0] != MOD) {
            // cerr << "> " << i << ' ' << comp_par[i].second << endl;
            vis[i] = 1;
            pq.push({dist[i], i});
        }

        while (sz(pq)) {
            auto [d, c] = pq.top(); pq.pop();
            if (dist[c] != d) continue;
            // cerr << "AT: " << comp_par[c].second << ' ' << d[0] << ' ' << d[1] << ' ' << d[2] << endl;
            for (auto [nxt, w] : nadj[c]) {
                // cerr << comp_par[nxt].second << ' ' << w << endl;
                if (!vis[nxt]) {
                    int s = a[d[1]][1];
                    int cnt_rounds = (d[2] + w - 1) / s;
                    ar<int, 3> his{d[0] + cnt_rounds, d[1], d[2] + w - s * cnt_rounds};

                    // cerr << comp_par[c].second << ' ' << comp_par[nxt].second << ' ' << w << ' ' << d[0] << ' ' << d[1] << ' ' << d[2] << ' ' << his[0] << ' ' << his[1] << ' ' << his[2] << '\n';
                    if (dist[nxt] > his) {
                        dist[nxt] = his;
                        pq.push({dist[nxt], nxt});
                    }
                }
            }
        }

        for (auto& c : ans) {
            cout << dist[me[c]][1]+1 << ' ';
        }
        cout << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}