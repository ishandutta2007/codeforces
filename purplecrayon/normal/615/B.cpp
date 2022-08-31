#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

int n, m;
vector<int> adj[MAXN];
ll dp[MAXN];

void solve(){
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b, --a, --b;
        adj[a].push_back(b), adj[b].push_back(a);
    }
    fill(dp, dp+n, 1);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (auto nxt : adj[i]) if (i < nxt) dp[nxt] = max(dp[nxt], dp[i]+1);
        ans = max(ans, dp[i]*sz(adj[i]));
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}