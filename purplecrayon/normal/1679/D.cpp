#include <bits/stdc++.h>
using namespace std;

#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 1e9+7;

int n, m;
ll k;
int a[N];
vector<int> adj[N];

int vis[N], dp[N];
bool dfs(int c, int x) {
    vis[c] = 1;
    for (auto nxt : adj[c]) if (a[nxt] <= x) {
        if (vis[nxt] == 1) return true;
        else if (vis[nxt] == -1) {
            if (dfs(nxt, x)) return true;
        }
    }
    vis[c] = 2;
    return false;
}
int rec(int c, int x) {
    if (dp[c] != -1) return dp[c];
    int ans = 1;
    for (auto nxt : adj[c]) if (a[nxt] <= x)
        ans = max(ans, 1 + rec(nxt, x));
    return dp[c] = ans;
}
bool v(int x) {
    memset(vis, -1, sizeof(vis));
    for (int i = 0; i < n; i++) if (a[i] <= x && vis[i] == -1) {
        if (dfs(i, x)) return true;
    }
    memset(dp, -1, sizeof(dp));
    int ans = -1;
    for (int i = 0; i < n; i++) if (a[i] <= x) ans = max(ans, rec(i, x));
    return ans >= k;
}
void solve() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b, --a, --b;
        adj[a].push_back(b);
    }

    int lo = 0, hi = MOD, mid = (lo + hi) / 2;
    while (lo < mid && mid < hi) {
        if (v(mid)) hi = mid;
        else lo = mid;
        mid = (lo + hi) / 2;
    }
    cout << (hi == MOD ? -1 : hi) << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}