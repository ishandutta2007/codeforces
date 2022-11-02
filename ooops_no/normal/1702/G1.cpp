#include<bits/stdc++.h>

using namespace std;

mt19937 rnd(51);

#define ll long long
#define pb push_back
#define ld long double

const int N = 2e5 + 10;
vector<int> g[N], tin(N), tout(N), d(N);
int cnt = 0, po[20][N];

void dfs(int v, int p) {
    tin[v] = cnt++;
    for (auto to : g[v]) {
        if (to != p) {
            d[to] = d[v] + 1;
            po[0][to] = v;
            dfs(to, v);
        }
    }
    tout[v] = cnt++;
}

bool is_parent(int a, int b) {
    return tin[a] <= tin[b] && tout[b] <= tout[a];
}

int lca(int a, int b) {
    if (d[a] < d[b]) {
        swap(a, b);
    }
    for (int i = 19; i >= 0; i--) {
        if (d[po[i][a]] >= d[b]) {
            a = po[i][a];
        }
    }
    if (a == b) return a;
    for (int i = 19; i >= 0; i--) {
        if (po[i][a] != po[i][b]) {
            a = po[i][a];
            b = po[i][b];
        }
    }
    return po[0][a];
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs(0, -1);
    for (int i = 1; i < 20; i++) {
        for (int j = 0; j < n; j++) {
            po[i][j] = po[i - 1][po[i - 1][j]];
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int k;
        cin >> k;
        vector<int> vert(k);
        int now = -1;
        for (int i = 0; i < k; i++) {
            cin >> vert[i];
            vert[i]--;
            if (now == -1 || d[vert[i]] > d[now]) {
                now = vert[i];
            }
        }
        int v = -1;
        for (int i = 0; i < k; i++) {
            if (!is_parent(vert[i], now)) {
                if (v == -1 || d[vert[i]] > d[v]) {
                    v = vert[i];
                }
            }
        }
        if (v == -1) {
            cout << "YES\n";
            continue;
        }
        int g = lca(v, now);
        bool bad = 0;
        for (int i = 0; i < k; i++) {
            if (is_parent(g, vert[i])) {
                if (!is_parent(vert[i], v) && !is_parent(vert[i], now)) {
                    bad = 1;
                }
            } else {
                bad = 1;
            }
        }
        cout << (!bad ? "YES\n" : "NO\n");
    }
    return 0;
}