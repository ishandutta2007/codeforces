#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 1e5+10, MOD = 1e9+7;

int n, m;
vector<ar<int, 2>> adj[N];
ll a[N], ans[N];
int col[N];
bool vis[N];

void dfs_col(int c, int b) {
    col[c] = b;
    for (auto [nxt, _] : adj[c]) if (col[nxt] == -1) {
        dfs_col(nxt, b ^ 1);
    }
}
void dfs_ans(int c) {
    vis[c] = 1;
    for (auto [nxt, i] : adj[c]) if (!vis[nxt] && col[nxt] != col[c]) {
        dfs_ans(nxt);
        ans[i] += a[nxt];
        a[c] -= a[nxt], a[nxt] -= a[nxt];
    }
}
void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b, --a, --b;
        adj[a].push_back({b, i}), adj[b].push_back({a, i});
    }
    memset(col, -1, sizeof(col));
    dfs_col(0, 0);
    ll one = 0, two = 0;
    for (int i = 0; i < n; i++) {
        if (col[i]) one += a[i];
        else two += a[i];
    }
    assert((one + two) % 2 == 0);

    for (int x = 0; x < n; x++) {
        for (auto [y, i] : adj[x]) if (col[x] == col[y]) {
            // assert(one % 2 == two % 2);
            if (col[x]) {
                ll d = (one - two) / 2;
                one -= 2 * d;
                ans[i] += d;
                a[x] -= d, a[y] -= d;
            } else {
                ll d = (two - one) / 2;
                two -= 2 * d;
                ans[i] += d;
                a[x] -= d, a[y] -= d;
            }
        }
    }

    if (one != two) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    memset(vis, 0, sizeof(vis));
    dfs_ans(0);
    for (int i = 0; i < m; i++) cout << ans[i] << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}