#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

int n, dp[MAXN], deg[MAXN];
vector<int> adj[MAXN];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) adj[i].clear();
    fill(deg, deg+n, 0);
    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        deg[i] = k;
        while (k--) {
            int c; cin >> c, --c;
            adj[c].push_back(i);
        }
    }
    fill(dp, dp+n, 0);
    vector<int> q; q.reserve(n);
    for (int a = 0; a < n; a++) {
        if (deg[a] == 0) {
            q.push_back(a);
        }
    }
    for (int rep = 0; rep < sz(q); rep++) {
        int c = q[rep];
        for (auto nxt : adj[c]) {
            deg[nxt]--;
            dp[nxt] = max(dp[nxt], dp[c]+(nxt < c));
            if (deg[nxt] == 0) {
                q.push_back(nxt);
            }
        }
    }
    if (sz(q) != n) {
        cout << -1 << '\n';
        return;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) ans = max(ans, dp[i]);
    cout << ans+1 << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}