#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 3e5+10, MOD = 1e9+7;

int cur_node = 0;
int make_node() {
    return cur_node++;
}

int n, a[MAXN], b[MAXN];
bool done[MAXN];

int node_id[4*MAXN], leaf[MAXN], d[5*MAXN], par[5*MAXN];
int rev_leaf[5*MAXN];
vector<pair<int, int>> adj[5*MAXN];
int two[MAXN];

void bld(int v, int tl, int tr) {
    node_id[v] = make_node();
    if (tl == tr) {
        leaf[tl] = node_id[v];
        rev_leaf[leaf[tl]] = tl;
    } else {
        int tm = (tl + tr) / 2;
        bld(2*v, tl, tm), bld(2*v+1, tm+1, tr);

        adj[node_id[2*v]].emplace_back(node_id[v], 0);
        adj[node_id[2*v+1]].emplace_back(node_id[v], 0);
    }
}
void upd(int v, int tl, int tr, int l, int r, int node, int cost) {
    if (tr < l || tl > r) return;
    if (l <= tl && tr <= r) {
        adj[node_id[v]].emplace_back(node, cost);
        return;
    }
    int tm=(tl+tr)/2;
    upd(2*v, tl, tm, l, r, node, cost), upd(2*v+1, tm+1, tr, l, r, node, cost);
}
void add_range(ar<int, 2> range, int node, int cost) {
    upd(1, 0, n-1, range[0], range[1], node, cost);
}
void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) {
        if (a[i] > i) {
            done[i] = 1;
        }
    }
    // add an edge from (c, 1) to (c - a[c] <= x <= c, 0)
    // add an edge from (c, 0) to (c + b[c], 1)
    //
    // (reverse these edges so you can do multisource bfs)

    memset(rev_leaf, -1, sizeof(rev_leaf));
    bld(1, 0, n-1);
    for (int i = 0; i < n; i++) two[i] = make_node();
    for (int i = 0; i < n; i++) {
        add_range(ar<int, 2>{max(0, i - a[i]), i}, two[i], 1);

        adj[two[i+b[i]]].emplace_back(leaf[i], 0);
    }
    fill(d, d+5*n, MOD);
    memset(par, -1, sizeof(par));

    deque<int> q;
    for (int i = 0; i < n; i++) {
        if (done[i]) {
            d[two[i]] = 0;
            q.push_back(two[i]);
        }
    }
    while (sz(q)) {
        int c = q.front(); q.pop_front();
        for (auto [nxt, w] : adj[c]) {
            if (d[c] + w < d[nxt]) {
                d[nxt] = d[c] + w;
                par[nxt] = c;
                if (w == 1) q.push_back(nxt);
                else q.push_front(nxt);
            }
        }
    }
    if (d[two[n-1]] == MOD) {
        cout << -1 << '\n';
        return;
    }
    int c = two[n-1];
    cout << d[c] + 1 << '\n';

    int len = d[c];
    vector<int> ans;
    while (c != -1) {
        if (rev_leaf[c] != -1) {
            ans.push_back(rev_leaf[c]);
        }
        c = par[c];
    }
    ans.push_back(-1);
    for (auto c : ans) cout << c+1 << ' ';
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}