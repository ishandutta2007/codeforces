#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 998244353;
const int K = 20;

int n, da[N];
vector<int> adj[N];

void dfs_one(int c, int p, int d) {
    da[c] = d;
    for (auto nxt : adj[c]) if (nxt != p)
        dfs_one(nxt, c, d+1);
}
int dfs(int c, int p, int d) {
    int ans = da[c];
    for (auto nxt : adj[c]) if (nxt != p && d+1 < da[nxt]) {
        ans = max(ans, dfs(nxt, c, d+1));
    }
    return ans;
}
void solve() {
    cin >> n;
    int x; cin >> x, --x;
    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b, --a, --b;
        adj[a].push_back(b), adj[b].push_back(a);
    }
    dfs_one(0, -1, 0);
    int ans = dfs(x, -1, 0);
    cout << 2 * ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}