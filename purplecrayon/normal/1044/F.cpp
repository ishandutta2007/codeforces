#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

const int MAXL = 18;

struct SEG {
    int n, lzy[4*MAXN];
    pair<int, int> t[4*MAXN];

    pair<int, int> comb(pair<int, int> a, pair<int, int> b) {
        if (a.first != b.first) return min(a, b);
        int x = min(a.first, b.first);
        assert(x == a.first); assert(x == b.first);
        return {x, a.second + b.second};
    }
    void bld(int v, int tl, int tr) {
        if (tl == tr) t[v] = {0, 1};
        else {
            int tm=(tl+tr)/2;
            bld(2*v, tl, tm), bld(2*v+1, tm+1, tr);
            t[v] = comb(t[2*v], t[2*v+1]);
        }
    }
    void init(int N) {
        n = N;
        bld(1, 0, n-1);
    }
    void push(int v, int tl, int tr, int x) {
        t[v].first += x;
        if (tl != tr) {
            lzy[2*v] += x;
            lzy[2*v+1] += x;
        }
    }
    void app(int v, int tl, int tr) {
        push(v, tl, tr, lzy[v]), lzy[v] = 0;
    }
    void upd(int v, int tl, int tr, int l, int r, int x) {
        app(v, tl, tr);
        if (r < tl || l > tr) return;
        if (l <= tl && tr <= r) {
            push(v, tl, tr, x);
            return;
        }
        int tm=(tl+tr)/2;
        upd(2*v, tl, tm, l, r, x), upd(2*v+1, tm+1, tr, l, r, x);
        t[v] = comb(t[2*v], t[2*v+1]);
    }
    void upd(int l, int r, int x) {
        upd(1, 0, n-1, l, r, x);
        // for (int i = l; i <= r; i++) a[i] += x;
    }
    int qry() {
        app(1, 0, n-1);
        assert(t[1].first >= 0);
        if (t[1].first == 0) return t[1].second;
        return 0;
    }
};

int n, q, depth[MAXN], anc[MAXN][MAXL];
int st[MAXN], en[MAXN], tt=0;
vector<int> adj[MAXN];
set<pair<int, int>> ed;
SEG ds;

void init_lca(int c=0, int p=-1, int d=0){
	depth[c]=d, anc[c][0]=p; st[c] = tt++;
	for (int i=1; i < MAXL; i++) anc[c][i] = (anc[c][i-1]==-1?-1:anc[anc[c][i-1]][i-1]);
	for (auto nxt : adj[c]) if (nxt != p) init_lca(nxt, c, d+1);
    en[c] = tt-1;
}
int jmp(int a, int h){
	for (int i = 0; i < MAXL; i++) if ((h>>i)&1) a = anc[a][i];
	return a;
}
int lca(int a, int b){
	if (depth[a] < depth[b]) swap(a, b);
	a = jmp(a, depth[a]-depth[b]);
	if (a==b) return a;
	for (int i = MAXL-1; i >= 0; i--){
		if (anc[a][i] != anc[b][i]) a = anc[a][i], b = anc[b][i];
	}
	assert(anc[a][0]==anc[b][0]);
	return anc[a][0];
}

void dfs(int c, int p) {
    st[c] = tt++;
    for (auto nxt : adj[c]) if (nxt != p) dfs(nxt, c);
    en[c] = tt-1;
}
void solve() {
    cin >> n >> q;
    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b, --a, --b;
        adj[a].push_back(b), adj[b].push_back(a);
    }
    ds.init(n);
    init_lca();
    while (q--) {
        int a, b; cin >> a >> b, --a, --b;
        if (a > b) swap(a, b);

        int me = ed.count({a, b}) ? -1 : 1;
        if (me == 1) ed.insert({a, b});
        else ed.erase({a, b});

        if (depth[a] > depth[b]) swap(a, b);
        int p = lca(a, b);
        if (p == a) {
            int child = jmp(b, depth[b]-depth[a]-1);
            ds.upd(st[child], en[child], me);
            ds.upd(st[b], en[b], -me);
        } else {
            assert(p != a && p != b);
            ds.upd(0, n-1, me);
            ds.upd(st[a], en[a], -me);
            ds.upd(st[b], en[b], -me);
        }
        cout << ds.qry() << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}