#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 1e9+7;

int n;
vector<int> adj[N];
ar<int, 2> a[N];

ar<int, 2> dfs(int c) {
    int ans = 0;
    ll free = 0;
    for (auto nxt : adj[c]) {
        auto dp = dfs(nxt);
        ans += dp[0];
        free += dp[1];
    }
    if (free < a[c][0]) {
        ans++;
        free = a[c][1];
    }
    free = min(free, (long long) a[c][1]);
    return {ans, int(free)};
}


void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) adj[i].clear();
    for (int i = 1; i < n; i++) {
        int p; cin >> p, --p;
        adj[p].push_back(i);
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1];
    }
    cout << dfs(0)[0] << '\n';
    // min number of ops, max value of the sum of the min values of the array starting at this node
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}