#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

int n, m, big_top[MAXN], col[MAXN];
vector<ar<int, 2>> adj[MAXN];

map<int, int> loc;
vector<int> val;
vector<int> g[MAXN];

bool dfs(int c, int b) {
    col[c] = b;
    loc[c] = sz(val);
    val.push_back(c);
    for (auto [nxt, t] : adj[c]) {
        int need = b ^ 1;
        if (col[nxt] == -1) {
            if (!dfs(nxt, need)) return 0;
        } else if (col[nxt] != need) {
            return 0;
        }
        if ((t == 1 && b == 0) || (t == 2 && b == 1)) 
            g[loc[c]].push_back(loc[nxt]);
    }
    return 1;
}
void clear(int c) {
    g[loc[c]].clear();
    col[c] = -1;
    for (auto [nxt, _] : adj[c]) if (col[nxt] != -1)
        clear(nxt);
}
bool can_top(int base) {
    for (int x : val) big_top[x] = -1;
    int N = sz(val);
    vector<int> deg(N);
    for (int i = 0; i < N; i++) {
        for (int j : g[i]) {
            deg[j]++;
        }
    }
    vector<int> q; q.reserve(N);
    for (int i = 0; i < N; i++) if (deg[i] == 0) q.push_back(i);
    for (int rep = 0; rep < sz(q); rep++) {
        int c = q[rep];
        big_top[val[c]] = base++;
        for (int nxt : g[c]) {
            --deg[nxt];
            if (deg[nxt] == 0)
                q.push_back(nxt);
        }
    }
    return sz(q) == N;
}
void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int t, a, b; cin >> t >> a >> b, --a, --b;
        adj[a].push_back({b, t}), adj[b].push_back({a, t});
    }
    memset(col, -1, sizeof(col));
    int base = 0;
    for (int i = 0; i < n; i++) if (col[i] == -1) {
        if (dfs(i, 0)) {
            if (can_top(base)) {
                base += sz(val);

                for (int i = 0; i < sz(val); i++) g[i].clear();
                loc.clear(), val.clear();
                continue;
            }
        }
        if (dfs(i, 1)) {
            if (can_top(base)) {
                base += sz(val);

                for (int i = 0; i < sz(val); i++) g[i].clear();
                loc.clear(), val.clear();
                continue;
            }
        }
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        cout << (col[i] ? 'R' : 'L') << ' ' << big_top[i] << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}