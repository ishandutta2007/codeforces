#include<bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
#define ld double
#define ll __int128

mt19937 rnd(51);

const int N = 1e5 + 10;
vector<int> ans(N), g[N];

void dfs(int v, int p, int d) {
    ans[v] = (d == 0 ? g[v].size() : -(int)(g[v].size()));
    for (auto to : g[v]) {
        if (to != p) {
            dfs(to, v, d ^ 1);
        }
    }
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            g[i].clear();
        }
        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            g[a].pb(b);
            g[b].pb(a);
        }
        dfs(0, -1, 0);
        for (int i = 0; i < n; i++) {
            cout << ans[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}