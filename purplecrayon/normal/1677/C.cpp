#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 1e5+10, MOD = 1e9+7;

int n;
vector<int> adj[N];
bool vis[N];

int dfs(int c) { 
    vis[c] = 1;
    int ans = 1;
    for (auto nxt : adj[c]) if (!vis[nxt])
        ans += dfs(nxt);
    return ans;
}
void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) vis[i] = 0, adj[i].clear();
    vector<int> a(n), b(n);
    for (auto& x : a) cin >> x, --x;
    for (auto& x : b) cin >> x, --x;
    for (int i = 0; i < n; i++) {
        adj[a[i]].push_back(b[i]);
        adj[b[i]].push_back(a[i]);
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int c = dfs(i);
        cnt += c / 2;
    }
    ll ans = 0;
    for (int i = 0; i < cnt; i++) {
        ans -= 2 * i;
        ans += 2 * (n - i - 1);
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}