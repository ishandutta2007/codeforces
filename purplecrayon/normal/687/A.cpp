#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e5+10, MOD = 1e9+7;

int n, m, col[MAXN];
vector<int> adj[MAXN];

bool dfs(int c, int b) {
    col[c] = b;
    for (auto nxt : adj[c]) {
        if (col[nxt] == -1) {
            if (dfs(nxt, b^1)) return 1;
        } else {
            if (col[nxt] == col[c]) return 1;
        }
    }
    return 0;
}
void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) { 
        int a, b; cin >> a >> b, --a, --b;
        adj[a].push_back(b), adj[b].push_back(a);
    }
    memset(col, -1, sizeof(col));
    for (int i = 0; i < n; i++) if (col[i] == -1) {
        if (dfs(i, 0)) {
            cout << -1 << '\n';
            return;
        }
    }
    vector<int> a, b;
    for (int i = 0; i < n; i++) {
        if (col[i]) b.push_back(i);
        else a.push_back(i);
    }

    auto pr = [&](vector<int> v) {
        cout << sz(v) << '\n';
        for (auto c : v) cout << c+1 << ' ';
        cout << '\n';
    };

    pr(a), pr(b);
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}