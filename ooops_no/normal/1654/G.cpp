#include<bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
#define ld double
#define ll __int128

mt19937 rnd(51);

const int N = 2e5 + 10, INF = 1e18;
vector<int> g[N], d(N, INF), sz(N), used(N), ans(N, -INF), ok(N), arr[2];
vector<vector<int>> all;

void zhfs(int v, int p) {
    sz[v] = 1;
    for (auto to : g[v]) {
        if (to != p && !used[to]) {
            zhfs(to, v);
            sz[v] += sz[to];
        }
    }
}

int find_centroid(int v, int p, int n) {
    for (auto to : g[v]) {
        if (to != p && !used[to] && sz[to] > n / 2) {
            return find_centroid(to, v, n);
        }
    }
    return v;
}

void dfs1(int v, int p, int mn, int cnt, int d1) {
    if (ok[v]) {
        arr[abs(cnt) % 2][-mn] = max(arr[abs(cnt) % 2][-mn], d1 + d[v] + cnt);
    }
    for (auto to : g[v]) {
        if (to != p && !used[to] && d[to] <= d[v]) {
            int nw = cnt;
            if (d[to] == d[v]) nw--;
            else nw++;
            dfs1(to, v, min(mn, nw), nw, d1 + 1);
        }
    }
}

void dfs2(int v, int p, int mx, int cnt, int d1) {
    if (mx == cnt) {
        if (mx % 2 == 0) {
            ans[v] = max(ans[v], max(arr[0][mx] + mx, arr[1][mx] + mx - 1) + d1);
        } else {
            ans[v] = max(ans[v], max(arr[0][mx] + mx - 1, arr[1][mx] + mx) + d1);
        }
    }
    for (auto to : g[v]) {
        if (to != p && !used[to] && d[to] >= d[v]) {
            int nw = cnt;
            if (d[to] == d[v]) nw--;
            else nw++;
            dfs2(to, v, max(mx, nw), nw, d1 + 1);
        }
    }
}

void solve(int v) {
    all.clear();
    zhfs(v, -1);
    arr[0].clear();
    arr[1].clear();
    arr[0].resize(sz[v] + 1, -INF);
    arr[1].resize(sz[v] + 1, -INF);
    dfs1(v, -1, 0, 0, 0);
    for (int i = 1; i <= sz[v]; i++) {
        arr[0][i] = max(arr[0][i], arr[0][i - 1]);
        arr[1][i] = max(arr[1][i], arr[1][i - 1]);
    }
    dfs2(v, -1, 0, 0, 0);
    used[v] = 1;
    for (auto to : g[v]) {
        if (!used[to]) {
            solve(find_centroid(to, v, sz[to]));
        }
    }
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    deque<int> q;
    for (int i = 0; i < n; i++) {
        int l;
        cin >> l;
        if (l == 1) {
            d[i] = 0;
            q.pb(i);
        }
    }
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    while (q.size() > 0) {
        int v = q.front();
        q.pop_front();
        for (auto to : g[v]) {
            if (d[to] == INF) {
                d[to] = d[v] + 1;
                q.pb(to);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (auto to : g[i]) {
            if (d[to] == d[i]) {
                ok[i] = 1;
            }
        }
    }
    zhfs(0, -1);
    solve(find_centroid(0, -1, n));
    for (int i = 0; i < n; i++) {
        cout << max(ans[i], d[i]) << ' ';
    }
    cout << endl;
    return 0;
}