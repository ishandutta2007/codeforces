#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 3e5+10, MOD = 1e9+7;
const int Q = 5e5+10;

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

template<class T>
struct FT {
    vector<T> bit;
    FT(int n) : bit(n) {}
    FT(){}
    void upd(int i, T x) {
        for (; i < sz(bit); i |= i+1) bit[i] += x;
    }
    T qry(int r) {
        T ans = T();
        for (++r; r > 0; r &= r-1) ans += bit[r-1];
        return ans;
    }
    T qry(int l, int r) {
        return qry(r)-qry(l-1);
    }
};

int n, q, up[N];
ar<int, 3> qs[Q];
bool tree[Q];
vector<ar<int, 2>> adj[N];

const int L = 19;
int depth[N], anc[N][L], st[N], en[N], tt = 0;

void dfs(int c, int p, int d) {
	depth[c] = d, anc[c][0] = p; st[c] = tt++;
	for (int i = 1; i < L; i++) anc[c][i] = (anc[c][i-1] == -1 ? -1 : anc[anc[c][i-1]][i-1]);
	for (auto [nxt, w] : adj[c]) if (nxt != p) {
        up[nxt] = up[c] ^ w;
        dfs(nxt, c, d+1);
    }
    en[c] = tt-1;
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
void solve() {
    cin >> n >> q;
    d.init(n);
    for (int i = 0; i < q; i++) {
        int a, b, x; cin >> a >> b >> x, --a, --b;
        qs[i] = {a, b, x};
        if (d.union_sets(a, b)) {
            adj[a].push_back({b, x}), adj[b].push_back({a, x});
            tree[i] = 1;
        }
    }

    memset(anc, -1, sizeof(anc));
    for (int i = 0; i < n; i++) if (anc[i][0] == -1) {
        dfs(i, -1, 0);
    }

    FT<int> bit(n);
    auto qry = [&](int a, int b) {
        return bit.qry(st[a]) + bit.qry(st[b]) - 2 * bit.qry(st[lca(a, b)]);
    };
    auto upd = [&](int c) {
        bit.upd(st[c], +1);
        bit.upd(en[c] + 1, -1);
    };

    for (int i = 0; i < q; i++) {
        if (tree[i]) {
            cout << "YES\n";
            continue;
        }
        auto [a, b, x] = qs[i];
        if ((up[a] ^ up[b] ^ x) == 0) {
            cout << "NO\n";
            continue;
        }
        if (qry(a, b)) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        int top = lca(a, b);
        while (a != top) upd(a), a = anc[a][0];
        while (b != top) upd(b), b = anc[b][0];
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}