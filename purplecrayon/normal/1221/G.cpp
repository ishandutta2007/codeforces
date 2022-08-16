#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 4e1+1, MOD = 1e9+7;

ll po(ll b, ll p) {
    ll ans = 1;
    for (; p; b *= b, p /= 2) if (p & 1)
        ans *= b;
    return ans;
}

int n, m;
vector<int> adj[N];

int col[N];
bool dfs(int c, int b) {
    col[c] = b;
    for (auto nxt : adj[c]) {
        if (col[nxt] == -1) {
            if (dfs(nxt, b ^ 1)) return 1;
        } else {
            if (col[nxt] == b) return 1;
        }
    }
    return 0;
}
ll count_bip() {
    memset(col, -1, sizeof(col));
    ll ans = 1;
    for (int i = 0; i < n; i++) if (col[i] == -1) {
        if (dfs(i, 0)) {
            return 0;
        }
        ans *= 2;
    }
    return ans;
}
void dfs_vis(int c) {
    col[c] = 1;
    for (auto nxt : adj[c]) if (col[nxt] == -1)
        dfs_vis(nxt);
}
int count_cc() {
    memset(col, -1, sizeof(col));
    int ans = 0;
    for (int i = 0; i < n; i++) if (col[i] == -1) {
        ans++;
        dfs_vis(i);
    }
    return ans;
}
ll count_independent() {
    if (n <= 3) {
        ll ans = 0;
        for (int i = 0; i < (1 << n); i++) {
            bool bad = 0;
            for (int a = 0; a < n && !bad; a++) if ((i >> a) & 1) {
                for (int b : adj[a]) if ((i >> b) & 1)
                    bad = 1;
            }
            ans += !bad;
        }
        return ans;
    }
    vector<ll> masks(n);
    for (int i = 0; i < n; i++) {
        for (int b : adj[i])
            masks[i] |= 1LL << b;
    }
    int l = n / 2, r = (n + 1) / 2;
    vector<int> cnt_sub(1 << r);
    for (int i = 0; i < (1 << r); i++) {
        bool bad = 0;
        for (int j = 0; j < r; j++) if ((i >> j) & 1) {
            int use_r = masks[j + l] >> l;
            if (use_r & i) {
                bad = 1;
                break;
            }
        }
        if (!bad) {
            cnt_sub[i]++;
        } 
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < (1 << r); j++) if ((j >> i) & 1)
            cnt_sub[j] += cnt_sub[j ^ (1 << i)];
    }
    ll ans = 0;
    for (int i = 0; i < (1 << l); i++) {
        bool bad = 0;
        int can = (1 << r) - 1;
        for (int j = 0; j < l; j++) if ((i >> j) & 1) {
            int use_l = masks[j] & ((1 << l) - 1);
            if (use_l & i) {
                bad = 1;
                break;
            }
            int use_r = masks[j] >> l;
            can &= ~use_r;
        }
        if (bad) continue;
        ans += cnt_sub[can];
    }
    return ans;
}
int count_deg_z() {
    int ans = 0;
    for (int i = 0; i < n; i++) ans += sz(adj[i]) == 0;
    return ans;
}
void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b, --a, --b;
        adj[a].push_back(b), adj[b].push_back(a);
    }
    
    // {0} -> everything is a 0, except for nodes with deg == 0
    // {1} -> everything is 1 - 0, just the number of bipartite colorings of the graph
    // {2} -> everything is a 1 (same as 0)
    // {0, 1} -> no having 1 1's, number of independent sets
    // {0, 2} -> no having 1 0, just 2^cc
    // {1, 2} -> no having 0 0, number of independent sets
    // {0, 1, 2} -> 2^n 

    ll ans = 0;
    ans += po(2, n);
    ans -= count_independent();
    ans -= po(2, count_cc());
    ans -= count_independent();
    ans += po(2, count_deg_z());
    ans += count_bip();
    ans += po(2, count_deg_z());
    if (m == 0) ans -= po(2, n);
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}