#include <bits/stdc++.h>
using namespace std;

#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

int n, ans = 0;
vector<int> adj[MAXN];

int dfs(int c = 0, int p = -1) {
    int sub = 1;
    for (auto nxt : adj[c]) if (nxt != p) sub += dfs(nxt, c);
    if (c && (sub&1^1) && ((n-sub)&1^1)) ans++;
    return sub;
}
void solve() {
    cin >> n;
    if (n&1) { cout << -1 << '\n'; return; }
    
    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b, --a, --b;
        adj[a].push_back(b), adj[b].push_back(a);
    }
    dfs();
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}