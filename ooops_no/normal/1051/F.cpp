#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define ll __int128
#define int long long

mt19937 rnd(51);

const int N = 1e5 + 10, INF = 1e18;
vector<int> par(N), d(N), h(N);
vector<pair<int,int>> g[N], gr[N];
int po[20][N];

int find_set(int v) {
    if (v == par[v]) return v;
    else return par[v] = find_set(par[v]);
}

bool union_set(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a == b) return 0;
    par[b] = a;
    return 1;
}

struct edge {
    int a, b, c;
};

void dfs(int v, int p) {
    for (auto to : g[v]) {
        if (to.first != p) {
            d[to.first] = d[v] + to.second;
            h[to.first] = h[v] + 1;
            po[0][to.first] = v;
            dfs(to.first, v);
        }
    }
}

int lca(int a, int b) {
    if (h[a] < h[b]) {
        swap(a, b);
    }
    for (int i = 19; i >= 0; i--) {
        if (h[po[i][a]] >= h[b]) {
            a = po[i][a];
        }
    }
    if (a == b) return a;
    for (int i = 19; i >= 0; i--) {
        if (po[i][a] != po[i][b]) {
            a = po[i][a], b = po[i][b];
        }
    }
    return po[0][a];
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    iota(par.begin(), par.end(), 0);
    int n, m;
    cin >> n >> m;
    vector<edge> e;
    vector<int> check;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        e.pb({a, b, c});
        gr[a].pb({b, c});
        gr[b].pb({a, c});
    }
    int q;
    cin >> q;
    vector<pair<int,int>> u(q);
    vector<int> ans(q, INF);
    for (int i = 0; i < q; i++) {
        cin >> u[i].first >> u[i].second;
        u[i].first--, u[i].second--;
    }
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        if (union_set(e[i].a, e[i].b)) {
            g[e[i].a].pb({e[i].b, e[i].c});
            g[e[i].b].pb({e[i].a, e[i].c});
        } else {
            check.pb(e[i].a);
            check.pb(e[i].b);
            cnt++;
        }
    }
    for (auto v : check) {
        vector<int> d(n, INF);
        set<pair<int,int>> st;
        d[v] = 0;
        st.insert({0, v});
        while (st.size() > 0) {
            int v = st.begin()->second;
            st.erase(st.begin());
            for (auto to : gr[v]) {
                if (d[to.first] > d[v] + to.second) {
                    st.erase({d[to.first], to.first});
                    d[to.first] = d[v] + to.second;
                    st.insert({d[to.first], to.first});
                }
            }
        }
        for (int i = 0; i < q; i++) {
            ans[i] = min(ans[i], d[u[i].first] + d[u[i].second]);
        }
    }
    dfs(0, -1);
    for (int i = 1; i < 20; i++) {
        for (int j = 0; j < n; j++) {
            po[i][j] = po[i - 1][po[i - 1][j]];
        }
    }
    for (int i = 0; i < q; i++) {
        int g = lca(u[i].first, u[i].second);
        ans[i] = min(ans[i], d[u[i].first] + d[u[i].second] - 2 * d[g]);
    }
    for (int i = 0; i < q; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}