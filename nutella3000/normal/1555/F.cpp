#include <bits/stdc++.h>
using namespace std;
     
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define size(a) (int) a.size()
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)
#define all(a) begin(a), end(a)
#define mp make_pair
#define pb emplace_back
#define ld long double
mt19937 rnd;

const int inf = 2e9 + 3;
const int max_n = (1 << 19), log_n = 20;

int n;
vector<pii> gr[max_n];
int tin[max_n], tout[max_n], T = 0;
int anc[max_n][log_n], rxor[max_n];

int lazy[2 * max_n];
int par[max_n];

void init_dsu() {
    iota(par, par + max_n, 0);
}

int get(int v) { return par[v] == v ? v : par[v] = get(par[v]); }

void unite(int v1, int v2) { par[get(v1)] = get(v2); }

void segadd(int l, int r) {
    for (l += max_n, r += max_n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) ++lazy[l++];
        if (r & 1) ++lazy[--r];
    }
}

int segget(int id, int v = 1, int tl = 0, int tr = max_n) {
    int res = 0;
    for (id += max_n; id; id >>= 1) res += lazy[id];
    return res;
}

void dfs(int v, int pr = -1) {
    tin[v] = T++;
    for (auto to : gr[v]) {
        if (to.fi == pr) continue;
        rxor[to.fi] = rxor[v] ^ to.se;
        anc[to.fi][0] = v;
        for (int i = 1; i < log_n; ++i)
            anc[to.fi][i] = anc[anc[to.fi][i - 1]][i - 1];
        dfs(to.fi, v);
    }
    tout[v] = T;
}

bool ispar(int v1, int v2) { 
    return tin[v1] <= tin[v2] && tout[v1] >= tout[v2];
}

int lca(int v1, int v2) {
    if (ispar(v1, v2)) return v1;
    for (int k = log_n - 1; k >= 0; --k)
        if (!ispar(anc[v1][k], v2)) v1 = anc[v1][k];
    return anc[v1][0];
}

bool add_edge(int v1, int v2, int w) {
    int l = lca(v1, v2);
    int r1 = segget(tin[v1]) - segget(tin[l]);
    int r2 = segget(tin[v2]) - segget(tin[l]);
    if (r1 || r2 || !(rxor[v1] ^ rxor[v2] ^ w)) return false;
    while (v1 != l) {
        segadd(tin[v1], tout[v1]);
        v1 = anc[v1][0];
    }
    while (v2 != l) {
        segadd(tin[v2], tout[v2]);
        v2 = anc[v2][0];
    }
    return true;
}

void run() {
    init_dsu();
    int q;
    cin >> n >> q;

    vector<pair<pii, int>> req(q);
    vector<bool> tree(q);
    for (int i = 0; i < q; ++i) {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        --v1, --v2;
        req[i] = {{v1, v2}, w};
        if (get(v1) != get(v2)) {
            unite(v1, v2);
            gr[v1].pb(v2, w);
            gr[v2].pb(v1, w);
            tree[i] = true;
        }
    }

    for (int r = 0; r < n; ++r) {
        if (!tin[r]) {
            for (int i = 0; i < log_n; ++i)
                anc[r][i] = r;
            dfs(r);
        }
    }

    for (int i = 0; i < q; ++i) {
        if (tree[i]) { cout << "YES" << '\n'; continue; }
        auto [aboba, w] = req[i];
        auto [v1, v2] = aboba;
        cout << (add_edge(v1, v2, w) ? "YES" : "NO") << '\n';
    }
}


signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(20);

#ifdef ahahaha
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    //cin >> t;
    while (t--) {
        run();
    }
}