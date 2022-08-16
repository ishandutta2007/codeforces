#include <bits/stdc++.h>
using namespace std;

#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 1e6+10, MOD = 1e9+7;

struct DSU {
    int n, cnt_bad;
    vector<ar<int, 2>> p;
    vector<bool> bip;
    vector<int> siz;
 
    int cur_op;
    vector<pair<int, int>> change_cnt;
    vector<pair<int, pair<int, ar<int, 2>>>> change_p;
    vector<pair<int, pair<int, int>>> change_bip, change_sz;
 
    DSU() {}
    DSU(int _n): n(_n), p(_n), bip(_n, 1), cnt_bad(), cur_op(), siz(n, 1) {
        for (int i = 0; i < n; i++) {
            p[i] = {i, 0};
        }
    }
    bool is_bip() {
        return cnt_bad == 0;
    }
    ar<int, 2> find_set(int v) {
        if (v == p[v][0]) return p[v];
        ar<int, 2> ans = find_set(p[v][0]);
        return {ans[0], ans[1] ^ p[v][1]};
    }
    void union_sets(int u, int v) {
        int me_op = cur_op++;
        auto [a, x] = find_set(u);
        auto [b, y] = find_set(v);
        if (siz[a] < siz[b]) swap(a, b);
        if (a == b) {
            if (x == y) {
                if (bip[a]) {
                    change_cnt.emplace_back(me_op, cnt_bad);
                    cnt_bad++;
                }
                change_bip.emplace_back(me_op, make_pair(a, bip[a]));
                bip[a] = 0;
            }
            return;
        }
 
        change_p.emplace_back(me_op, make_pair(b, p[b]));
        p[b] = {a, x ^ y ^ 1};
 
        change_bip.emplace_back(me_op, make_pair(a, bip[a]));
        bip[a] = bip[a] && bip[b];
 
        change_sz.emplace_back(me_op, make_pair(a, siz[a]));
        siz[a] += siz[b];
    }
    void undo() {
        cur_op--;
        while (sz(change_cnt) && change_cnt.back().first == cur_op) {
            cnt_bad = change_cnt.back().second;
            change_cnt.pop_back();
        }
        while (sz(change_p) && change_p.back().first == cur_op) {
            auto [i, x] = change_p.back().second;
            p[i] = x;
 
            change_p.pop_back();
        }
        while (sz(change_bip) && change_bip.back().first == cur_op) {
            auto [i, x] = change_bip.back().second;
            bip[i] = x;
 
            change_bip.pop_back();
        }
        while (sz(change_sz) && change_sz.back().first == cur_op) {
            auto [i, x] = change_sz.back().second;
            siz[i] = x;
 
            change_sz.pop_back();
        }
    }
} d;

int n, m, ans[N];
ar<int, 2> e[N];
vector<int> adj[N];

int rec(int l, int r) {
    if (l > r) return -1;
    if (l == r) {
        if (d.is_bip()) {
            return l;
        } else {
            return -1;
        }
    }
    int m = (l + r) / 2;
    for (int i = l; i <= m; i++) {
        d.union_sets(e[i][0], e[i][1]);
    }
    int r_ans = rec(m+1, r);
    if (r_ans != -1) return r_ans;
    for (int i = l; i <= m; i++) {
        d.undo();
    }

    for (int i = m+1; i <= r; i++) {
        d.union_sets(e[i][0], e[i][1]);
    }
    int l_ans = rec(l, m);
    if (l_ans != -1) return l_ans;
    for (int i = m+1; i <= r; i++) {
        d.undo();
    }

    return -1;
}
void dfs(int c, int b) {
    ans[c] = b;
    for (auto nxt : adj[c]) if (ans[nxt] == -1)
        dfs(nxt, b ^ 1);
}
void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b, --a, --b;
        e[i] = {a, b};
    }
    d = DSU(n);
    int er = rec(0, m-1);
    if (er == -1) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";

    for (int i = 0; i < n; i++) adj[i].clear(), ans[i] = -1;
    for (int i = 0; i < m; i++) if (er != i) {
        auto [a, b] = e[i];
        adj[a].push_back(b), adj[b].push_back(a);
    }
    int root = e[er][0];
    dfs(root, 1);
    for (int i = 0; i < n; i++) if (ans[i] == -1)
        dfs(i, 1);
    for (int i = 0; i < n; i++) cout << ans[i];
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}