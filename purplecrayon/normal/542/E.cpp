#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e3+10, MOD = 1e9+7;


int n, m, col[MAXN], d[MAXN], far[MAXN];
vector<int> adj[MAXN];

bool bip(int c, bool b) {
    col[c] = b;
    for (auto nxt : adj[c]) {
        if (col[nxt] == -1) {
            if (!bip(nxt, b^1)) return 0;
        } else {
            if (col[nxt] == col[c]) {
                return 0;
            }
        }
    }
    return 1;
}

bool vis[MAXN];

int dfs(int c) {
    int ans = far[c];
    vis[c] = 1;
    for (auto nxt : adj[c]) if (!vis[nxt]) {
        ans = max(ans, dfs(nxt));
    }
    return ans;
}
void solve(){
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b, --a, --b;
        adj[a].push_back(b), adj[b].push_back(a);
    }
    memset(col, -1, sizeof(col));
    for (int i = 0; i < n; i++) if (col[i] == -1) {
        if (!bip(i, 0)) {
            cout << -1 << '\n';
            return;
        }
    }
    for (int i = 0; i < n; i++) {
        fill(d, d+n, MOD);

        vector<int> q; q.reserve(n);
        q.push_back(i), d[i] = 0;

        far[i] = 0;
        for (int rep = 0; rep < sz(q); rep++) {
            int c = q[rep];
            for (auto nxt : adj[c]) if (d[nxt] > d[c]+1) {
                d[nxt] = d[c]+1;
                q.push_back(nxt);
            }
            far[i] = max(far[i], d[c]);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) if (!vis[i]) {
        ans += dfs(i);
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}