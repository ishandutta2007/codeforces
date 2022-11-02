#include<bits/stdc++.h>

using namespace std;

mt19937 rnd(51);

#define ll long long
#define pb push_back
#define ld long double

const int N = 1e5 + 10;
vector<int> g[N];
int po[20][N], d[N], ans[N], cnt[N];

struct dsu {
    vector<int> par;
    dsu(int n) {
        par.resize(n);
        iota(par.begin(), par.end(), 0);
    }
    int find_set(int v) {
        if (v == par[v]) {
            return v;
        } else {
            return par[v] = find_set(par[v]);
        }
    }
    bool union_set(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a == b) {
            return 0;
        } else {
            par[b] = a;
            return 1;
        }
    }
};

struct edge {
    int a, b;
};

void dfs(int v, int p) {
    for (auto to : g[v]) {
        if (to != p) {
            d[to] = d[v] + 1;
            po[0][to] = v;
            dfs(to, v);
        }
    }
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
    if (a == b) {
        return a;
    }
    for (int i = 19; i >= 0; i--) {
        if (po[i][a] != po[i][b]) {
            a = po[i][a];
            b = po[i][b];
        }
    }
    return po[0][a];
}

bool is_parent(int a, int b) {
    return lca(a, b) == a;
}

void zhfs(int v, int p, int need, int res) {
    res += cnt[v];
    if (res == need) {
        ans[v] = 1;
    }
    for (auto to : g[v]) {
        if (to != p) {
            zhfs(to, v, need, res);
        }
    }
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<edge> e, not_used;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        e.pb({a, b});
    }
    dsu gr(n);
    for (int i = 0; i < m; i++) {
        if (gr.union_set(e[i].a, e[i].b)) {
            g[e[i].a].pb(e[i].b);
            g[e[i].b].pb(e[i].a);
        } else {
            not_used.pb({e[i].a, e[i].b});
        }
    }
    dfs(0, -1);
    for (int i = 1; i < 20; i++) {
        for (int j = 0; j < n; j++) {
            po[i][j] = po[i - 1][po[i - 1][j]];
        }
    }
    for (int i = 0; i < not_used.size(); i++) {
        int a = not_used[i].a, b = not_used[i].b;
        if (d[a] > d[b]) {
            swap(a, b);
        }
        if (!is_parent(a, b)) {
            cnt[a]++, cnt[b]++;
        } else {
            int v = b;
            for (int j = 19; j >= 0; j--) {
                if (d[po[j][v]] > d[a]) {
                    v = po[j][v];
                }
            }
            cnt[0]++, cnt[b]++, cnt[v]--;
        }
    }
    zhfs(0, -1, m - n + 1, 0);
    for (int i = 0; i < n; i++) {
        cout << ans[i];
    }
    cout << endl;
    return 0;
}