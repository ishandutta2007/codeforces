#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 3e5+10, MOD = 1e9+7;
const ll INF = 1e18+10;

int n;
vector<int> adj[N];
ll a[N], dp[N];

void dfs(int c, int p) {
    dp[c] = a[c];
    for (auto nxt : adj[c]) if (nxt != p) {
        dfs(nxt, c);
        dp[c] += max(0LL, dp[nxt]);
    }
}
void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b, --a, --b;
        adj[a].push_back(b), adj[b].push_back(a);
    }
    dfs(0, -1);
    ll ans = *max_element(dp, dp + n);

    int k = 0;
    if (ans < 0) {
        for (int i = 0; i < n; i++) if (a[i] == ans) k++;
    } else {
        queue<int> q;
        vector<int> deg(n);
        for (int i = 0; i < n; i++) deg[i] = sz(adj[i]);

        for (int i = 0; i < n; i++) if (deg[i] == 1) {
            q.push(i);
        }

        vector<bool> dead(n);
        while (sz(q)) {
            int c = q.front(); q.pop();
            dead[c] = 1;

            if (a[c] == ans) k++;
            else if (a[c] > 0) {
                for (auto nxt : adj[c]) if (!dead[nxt])
                    a[nxt] += a[c];
            }

            for (auto nxt : adj[c]) if (!dead[nxt]) {
                deg[nxt]--;
                if (deg[nxt] == 1)
                    q.push(nxt);
            }
        }
    }

    cout << ans * k << ' ' << k << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}