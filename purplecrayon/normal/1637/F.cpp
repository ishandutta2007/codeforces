#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 1e9+7;
const ll INF = 1e18+10;

int n, a[N];
vector<int> adj[N];
int max_sub[N];
ll dp[N];

void rec(int c, int p) {
    max_sub[c] = 0;
    for (auto nxt : adj[c]) if (nxt != p) {
        rec(nxt, c);
        max_sub[c] = max(max_sub[c], max_sub[nxt]);
        dp[c] += dp[nxt];
    }
    dp[c] += max(max_sub[c], a[c]) - max_sub[c];
    max_sub[c] = max(max_sub[c], a[c]);
}
ll best_path(int c, int p, ll sum) {
    if (p != -1 && sz(adj[c]) == 1) {
        return sum;
    }
    for (auto nxt : adj[c]) if (nxt != p) sum += dp[nxt];
    ll ans = INF;
    for (auto nxt : adj[c]) if (nxt != p) {
        ans = min(ans, best_path(nxt, c, sum - dp[nxt]));
    }
    return ans;
}
void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b, --a, --b;
        adj[a].push_back(b), adj[b].push_back(a);
    }
    int root = max_element(a, a + n) - a;
    rec(root, -1);

    vector<ll> path_costs{0}; 
    ll base = 0;
    for (int nxt : adj[root]) {
        base += dp[nxt];
        path_costs.push_back(best_path(nxt, root, 0) - dp[nxt]);
    }
    sort(path_costs.begin(), path_costs.end());
    ll ans = base + path_costs[0] + path_costs[1] + 2 * a[root];
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}