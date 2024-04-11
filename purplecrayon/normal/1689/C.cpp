#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 3e5+10, MOD = 1e9+7;

int n, dp[N], sub[N];
vector<int> adj[N];

int dfs(int c, int p) {
    if (p != -1) {
        adj[c].erase(find(adj[c].begin(), adj[c].end(), p));
    }
    sub[c] = 1;
    for (auto nxt : adj[c]) if (nxt != p)
        sub[c] += dfs(nxt, c);

    if (sz(adj[c]) == 0) {
        dp[c] = 0;
    } else if (sz(adj[c]) == 1) {
        dp[c] = sub[c] - 2;
    } else {
        int a = adj[c][0], b = adj[c][1];
        dp[c] = max(dp[a] + sub[b] - 1, dp[b] + sub[a] - 1);
    }

    return sub[c];
}
void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) adj[i].clear();
    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b, --a, --b;
        adj[a].push_back(b), adj[b].push_back(a);
    }
    dfs(0, -1);
    cout << dp[0] << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}