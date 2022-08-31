#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 3e3+10, MOD = 1e9+7;

int n, sub[MAXN][MAXN];
vector<int> adj[MAXN];
vector<ar<int, 2>> path[MAXN];
ll dp[MAXN][MAXN];

int dfs(int c, int p, int root) {
    sub[root][c] = 1;
    for (auto nxt : adj[c]) if (nxt != p)
        sub[root][c] += dfs(nxt, c, root);
    return sub[root][c];
}
int get_sub(int c, int root) {
    return sub[root][c];
}
void dfs_path(int c, int p, int d, int root) {
    path[d].push_back({c, root});
    for (auto nxt : adj[c]) if (nxt != p)
        dfs_path(nxt, c, d+1, root);
}
void solve(){
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b, --a, --b;
        adj[a].push_back(b), adj[b].push_back(a);
    }
    for (int i = 0; i < n; i++) {
        dfs(i, -1, i);
        dfs_path(i, -1, 0, i);
    }
    for (int i = 0; i < n; i++) {
        for (auto [a, b] : path[i]) {
            for (int rep = 0; rep < 2; rep++) {
                for (int nxt : adj[a]) if (get_sub(nxt, b) < get_sub(a, b)) { // not on the (a, b) path
                    dp[nxt][b] = max(dp[nxt][b], get_sub(nxt, b) * get_sub(b, nxt) + dp[a][b]);
                    dp[b][nxt] = max(dp[b][nxt], get_sub(nxt, b) * get_sub(b, nxt) + dp[a][b]);
                }
                swap(a, b);
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            ans = max(ans, dp[i][j]);
        }

    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}