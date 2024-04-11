#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

const int MAXL = 18;

int n, N, depth[MAXN], anc[MAXN][MAXL];
vector<int> adj[MAXN];

void init_lca(int c=0, int p=-1, int d=0){
	depth[c]=d, anc[c][0]=p;
	for (int i=1; i < MAXL; i++) anc[c][i] = (anc[c][i-1]==-1?-1:anc[anc[c][i-1]][i-1]);
	for (auto nxt : adj[c]) if (nxt != p) init_lca(nxt, c, d+1);
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
int dist(int a, int b){ return depth[a]+depth[b]-2*depth[lca(a, b)]; }
int kth_on_path(int a, int b, int k) { //kth on the path from a to b
    int l = lca(a, b);
    if (depth[a] - depth[l] >= k) return jmp(a, k);
    k -= depth[a]-depth[l];
    //kth down from l
    int up_path = depth[b]-depth[l];
    return jmp(b, up_path-k);
}

ll sm[MAXN], sm_ch[MAXN];
int cnt[MAXN], cnt_ch[MAXN];

struct CENT_DECOMP {
    bool blocked[MAXN];
    int par[MAXN], sub[MAXN];
    vector<int> dist[MAXN];
    void dfs_dist(int u, int p, int d){
        dist[u].push_back(d);
        for (auto v : adj[u]) if (!blocked[v] && v != p) dfs_dist(v, u, d+1);
    }
    int dfs_sub(int u, int p){
        sub[u] = 1;
        for (auto v : adj[u]) if (v != p && !blocked[v]) sub[u] += dfs_sub(v,u);
        return sub[u];
    }
    int dfs_centroid(int u, int p, int sz){
        for (auto v : adj[u])  if (v != p && !blocked[v] && sub[v] > sz/2) return dfs_centroid(v,  u, sz);
        return u;
    }
    void bld(int u=0, int p=-1){
        int sz = dfs_sub(u, p);
        int cent = dfs_centroid(u, p, sz);
        par[cent] = p; blocked[cent] = 1;
        for (auto nxt : adj[cent]) if (!blocked[nxt]) {
            dfs_dist(nxt, cent, 1);
        }
        for (auto nxt : adj[cent]) if (!blocked[nxt]) bld(nxt, cent);
        dist[cent].push_back(0);
        reverse(dist[cent].begin(), dist[cent].end());
    }
    int operator[](int i){ return par[i]; }
} cd;


void upd(int v, int mul) {
    int c = v, p = -1, c_anc = 0;
    while (c != -1) {
        cnt[c] += mul;
        sm[c] += cd.dist[v][c_anc]*mul;

        if (p != -1) {
            cnt_ch[p] += mul;
            sm_ch[p] += cd.dist[v][c_anc]*mul;
        }

        p = c, c = cd[c], c_anc++;
    }
}
void add(int v){ upd(v, 1); }
void er(int v){ upd(v, -1); }
ll sm_dist(int v) {
    ll ans = 0;
    int c = v, p = -1, c_anc = 0;
    while (c != -1) {
        ll c_cnt = cnt[c], c_dist = sm[c];
        if (p != -1) {
            c_cnt -= cnt_ch[p];
            c_dist -= sm_ch[p];
        }
        ans += c_cnt*cd.dist[v][c_anc]+c_dist;

        p = c, c = cd[c], c_anc++;
    }
    return ans;
}

struct C { //circles
    int v, r;
    int diam(){ return 2*r; }
};
bool contains(C a, C b) { //does a contain b
    return dist(a.v, b.v) <= a.r-b.r;
}
C merge(C a, C b) { //merge two covers
    if (contains(a, b)) return a;
    if (contains(b, a)) return b;
    int r = (a.r+b.r+dist(a.v, b.v))/2;
    int v_a = kth_on_path(a.v, b.v, (r-a.r));
    //int v_b = kth_on_path(b.v, a.v, (r-b.r));
    //assert(v_a == v_b);
    return C{v_a, r};
}
ll ans = 0;
void rec(int l, int r) {
    if (l >= r) return;
    int m = (l+r)/2;

    vector<C> a, b;
    a.reserve(m-l+1), b.reserve(r-m);
    for (int i = m; i >= l; i--) {
        if (sz(a)) a.push_back(merge(a.back(), C{i, 0}));
        else a.push_back(C{i, 0});
    }
    for (int i = m+1; i <= r; i++) {
        if (sz(b)) b.push_back(merge(b.back(), C{i, 0}));
        else b.push_back(C{i, 0});
    }
    vector<ll> ps(r-m);
    for (int i = 0; i < r-m; i++) {
        ps[i] = b[i].r;
        if (i) ps[i] += ps[i-1];
    }
    auto qry = [&](int l, int r) {
        return ps[r]-(l?ps[l-1]:0);
    };

    int nsub = 0; //first to not be a subset
    int super = 0; //first to be a superset
    for (auto ca : a) {
        while (super < sz(b) && !contains(b[super], ca)) {
           super++;
           add(b[super-1].v);
        }
        while (nsub < super && contains(ca, b[nsub])) {
            nsub++;
            er(b[nsub-1].v);
        }

        //0..nsub-1 -> subsets of ca
        //nsub..super-1 -> ca and cb coexist
        //super..sz(b)-1 -> subsets of cb
        
        if (0 <= nsub-1) {
            ans += ll(ca.diam())*((nsub-1)-0+1);
        }
        if (nsub <= super-1) {
            //diam = a.r + b.r + dist(a.v, b.v)
            ans += ll(ca.r)*((super-1)-nsub+1);
            ans += qry(nsub, super-1);
            ans += sm_dist(ca.v);
        }
        if (super <= sz(b)-1) {
            ans += qry(super, sz(b)-1)*2ll;
        }
    }
    for (int i = nsub; i <= super-1; i++) er(b[i].v);

    rec(l, m), rec(m+1, r);
}
void solve(){
    cin >> n, N = n;
    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b, --a, --b;
        int red_node = N++;
        adj[a].push_back(red_node), adj[red_node].push_back(a);
        adj[b].push_back(red_node), adj[red_node].push_back(b);
    }
    init_lca(); cd.bld();

    rec(0, n-1);
    cout << ans/2 << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}