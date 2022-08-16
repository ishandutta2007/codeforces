#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e5+10, MOD = 1e9+7;

int n, k, a[MAXN], sub[MAXN];
vector<int> adj[MAXN];

int dfs(int c, int p) {
    sub[c] = a[c];
    for (auto nxt : adj[c]) if (nxt != p) sub[c] ^= dfs(nxt, c);
    return sub[c];
}
void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) adj[i].clear();
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b, --a, --b;
        adj[a].push_back(b), adj[b].push_back(a);
    }
    int x = 0;
    for (int i = 0; i < n; i++) x ^= a[i];
    if (x == 0) {
        cout << "YES\n";
        return;
    }
    if (k == 2) {
        cout << "NO\n";
        return;
    }
    dfs(0, -1);
    int ans = 0;
    for (int i = 1; i < n; i++) {
        if (sub[i] == x || sub[i] == 0) ans++;
    }
    if (ans >= 2) cout << "YES\n";
    else cout << "NO\n";
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}