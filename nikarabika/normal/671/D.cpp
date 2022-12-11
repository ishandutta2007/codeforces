#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef long double LD;

#define L first
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define R second
#define smin(x, y) (x) = min((x), (y))
#define PB push_back
#define MP make_pair
#define all(x) (x).begin(),(x).end()

const int maxn = 300 * 1000 + 10;
int h[maxn];
LL lazy[maxn];
map<int, LL> cst[maxn];
vector<int> adj[maxn];
int n, m;
LL ans = 0;

void dfs(int u, int p = -1) {
    for (int v: adj[u])
        if (v != p) {
            h[v] = h[u] + 1;
            dfs(v, u);
        }
}

void insert(int u, int val, int pos) {
    val -= lazy[u];
    auto it = cst[u].upper_bound(pos);
    if (it != cst[u].begin()) {
        auto it2 = it;
        it2--;
        if (it2->R <= val)
            return;
    }
    it = cst[u].lower_bound(pos);
    while (it != cst[u].end() and it->R >= val) {
        cst[u].erase(it);
        it = cst[u].lower_bound(pos);
    }
    cst[u][pos] = val;
}

void solve(int u, int p = -1) {
    if (p != -1)
        adj[u].erase(find(all(adj[u]), p));
    for (int v: adj[u])
        solve(v, u);
    if (u == 0) return;

    sort(all(adj[u]), [](int i, int j) -> bool { return sz(cst[i]) > sz(cst[j]); });
    if (sz(adj[u]) > 0) {
        int v = adj[u][0];
        cst[u].swap(cst[v]);
        swap(lazy[u], lazy[v]);
    }
    for (int v: adj[u]) {
        for (auto pv: cst[v]) {
            int pos = pv.L;
            LL val = pv.R + lazy[v];
            insert(u, val, pos);
        }
    }
    cst[u].erase(h[u]);

    if (sz(cst[u]) == 0) {
        cout << -1 << '\n';
        exit(0);
    }

    LL val = cst[u].rbegin()->R + lazy[u];
    lazy[u] -= val;
    ans += val;
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i < n; i++) {
        int fi, se;
        cin >> fi >> se;
        fi--, se--;
        adj[fi].PB(se);
        adj[se].PB(fi);
    }
    dfs(0);
    for (int i = 0; i < m; i++) {
        int fi, se, th;
        cin >> fi >> se >> th;
        fi--, se--;
        insert(fi, th, h[se]);
    }
    solve(0);
    cout << ans << '\n';
    return 0;
}