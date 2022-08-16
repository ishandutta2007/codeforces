#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 1e6+10, MOD = 998244353;

int n, ans[N];
vector<int> adj[N];

void dfs(int c, int p, int b) {
    ans[c] = b * sz(adj[c]);
    for (auto nxt : adj[c]) if (nxt != p)
        dfs(nxt, c, -b);
}
void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) adj[i].clear();
    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b, --a, --b;
        adj[a].push_back(b), adj[b].push_back(a);
    }
    dfs(0, -1, 1);
    for (int i = 0; i < n; i++) cout << ans[i] << ' ';
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}