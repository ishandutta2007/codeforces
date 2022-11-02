#include<bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
#define ld double
#define ll __int128

mt19937 rnd(51);

const int N = 2e5 + 10;
vector<int> color(N, -1), used(N), all;
vector<int> g[N], gr[N];
bool bad = 0;

void dfs(int v) {
    for (auto to : g[v]) {
        if (color[to] == -1) {
            color[to] = (color[v] ^ 1);
            dfs(to);
        }
        if (color[to] == color[v]) {
            bad = 1;
        }
    }
}

void zhfs(int v) {
    used[v] = 1;
    for (auto to : gr[v]) {
        if (!used[to]) {
            zhfs(to);
        }
    }
    all.pb(v);
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr;
    vector<int> ans(n), in(n);
    for (int i = 0; i < m; i++) {
        int t, a, b;
        cin >> t >> a >> b;
        a--, b--;
        g[a].pb(b);
        g[b].pb(a);
        arr.pb({t, a, b});
    }
    for (int i = 0; i < n; i++) {
        if (color[i] == -1) {
            color[i] = 0;
            dfs(i);
        }
    }
    if (bad) {
        cout << "NO\n";
        return 0;
    }
    for (auto to : arr) {
        int t = to[0], a = to[1], b = to[2];
        if (t == 1) {
            if (color[a] == 0) {
                gr[a].pb(b);
                in[b] = 1;
            } else {
                gr[b].pb(a);
                in[a] = 1;
            }
        } else {
            if (color[a] == 0) {
                gr[b].pb(a);
                in[a] = 1;
            } else {
                gr[a].pb(b);
                in[b] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (!used[i] && !in[i]) {
            zhfs(i);
        }
    }
    int now = n;
    for (auto v : all) {
        ans[v] = now--;
    }
    for (auto to : arr) {
        int t = to[0], a = to[1], b = to[2];
        if (t == 1) {
            if (color[a] == 0) {
                if (ans[a] >= ans[b]) bad = 1;
            } else {
                if (ans[b] >= ans[a]) bad = 1;
            }
        } else {
            if (color[a] == 0) {
                if (ans[b] >= ans[a]) bad = 1;
            } else {
                if (ans[a] >= ans[b]) bad = 1;
            }
        }
    }
    if (bad) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        cout << (color[i] == 0 ? "L" : "R") << ' ' << ans[i] << endl;
    }
    return 0;
}