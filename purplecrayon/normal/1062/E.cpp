#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e5+10, MOD = 1e9+7;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
typedef pair<int, int> pii;
typedef vector<int> vi;

template<class T>
struct RMQ_MIN {
	vector<vector<T>> jmp;
    RMQ_MIN(){}
	RMQ_MIN(const vector<T>& V) : jmp(1, V) {
		for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
			jmp.emplace_back(sz(V) - pw * 2 + 1);
			rep(j,0,sz(jmp[k]))
				jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
		}
	}
	T _query(int a, int b) {
		assert(a < b); // or return inf if a == b
		int dep = 31 - __builtin_clz(b - a);
		return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
    T query(int a, int b) {
        return _query(a, b+1);
    }
};
struct LCA {
	int T = 0;
	vi time, path, ret;
	RMQ_MIN<int> rmq;

    LCA(){}
	LCA(vector<vi>& C) : time(sz(C)), rmq((dfs(C,0,-1), ret)) {}
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
		return path[rmq._query(a, b)];
	}
} lca;

template<class T>
struct RMQ_LCA {
	vector<vector<T>> jmp;
    RMQ_LCA(){}
	RMQ_LCA(const vector<T>& V) : jmp(1, V) {
		for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
			jmp.emplace_back(sz(V) - pw * 2 + 1);
			rep(j,0,sz(jmp[k]))
				jmp[k][j] = lca.lca(jmp[k - 1][j], jmp[k - 1][j + pw]);
		}
	}
	T query(int a, int b) {
        b++;
		assert(a < b); // or return inf if a == b
		int dep = 31 - __builtin_clz(b - a);
		return lca.lca(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};

RMQ_LCA<int> range_lca;

int n, q, depth[MAXN], st[MAXN], en[MAXN], tt=0;
vector<vector<int>> adj;

int get(int x, int l, int r) {
    if (x == l) return depth[range_lca.query(l+1, r)];
    if (x == r) return depth[range_lca.query(l, r-1)];
    int a = range_lca.query(l, x-1), b = range_lca.query(x+1, r), c = lca.lca(a, b);
    return depth[c];
}
void dfs(int c = 0) {
    st[c] = tt++;
    for (auto nxt : adj[c]) {
        depth[nxt] = depth[c]+1;
        dfs(nxt);
    }
    en[c] = tt-1;
}
void solve() {
    cin >> n >> q;
    adj.resize(n);
    for (int i = 1; i < n; i++) {
        int p; cin >> p, --p;
        adj[p].push_back(i);
    }
    dfs();
    lca = LCA(adj);

    vector<int> nodes(n); iota(nodes.begin(), nodes.end(), 0);
    range_lca = RMQ_LCA(nodes);

    vector<pair<int, int>> min_ord(n), max_ord(n);
    for (int i = 0; i < n; i++) min_ord[i] = {st[i], i}, max_ord[i] = {-st[i], i};
    RMQ_MIN<pair<int, int>> st_min(min_ord), st_max(max_ord);

    while (q--) {
        int l, r; cin >> l >> r, --l, --r;

        vector<int> cand{st_min.query(l, r).second, st_max.query(l, r).second};

        ar<int, 2> ans{-1, -1};
        for (int i : cand) {
            ans = max(ans, {get(i, l, r), i});
        }
        cout << ans[1]+1 << ' ' << ans[0] << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}