#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define ar array
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()


typedef long long ll;
typedef long double ld;
using namespace std;

// using namespace __gnu_pbds;

const ll INF = 1e18 + 5;
const int INFi = 2e9;
const int maxN = 3e5 + 1;
const int md2 = 998244353;
const int md = 1e9 + 7;


vector<int> g[maxN];
int up[maxN][20];
int h[maxN];

void dfs(int v, int p) {
    up[v][0] = p;
    for (int i = 1; i < 20; ++i) up[v][i] = up[up[v][i - 1]][i - 1];
    for (auto &u : g[v]) {
        if (u == p) continue;
        h[u] = h[v] + 1;
        dfs(u, v);
    }
}

int lca(int v, int u) {
    if (h[v] < h[u]) swap(u, v);
    for (int i = 19; i >= 0; --i) {
        if (h[up[v][i]] >= h[u]) v = up[v][i];
    }
    if (u == v) return v;
    for (int i = 19; i >= 0; --i) {
        if (up[v][i] != up[u][i]) v = up[v][i], u = up[u][i];
    }
    return up[v][0];
}

int dist(int a, int b) {
    return h[a] + h[b] - 2 * h[lca(a, b)];
}

int kth_ancestor(int v, int k) {
    for (int i = 19; i >= 0; --i) {
        if ((1 << i) & k) v = up[v][i];
    }
    return v;
}

vector<int> add[maxN];
int res_simple[maxN];
int res2[maxN];
int cnt1[maxN];
map<pair<int, int>, int> cnt2[maxN];
int cnt3[maxN];
int sum2[maxN];
int start[maxN];
int cnt4[maxN];

vector<int> stk;

int dfs2(int v, int p) {
    stk.push_back(0);
    for (auto &u : g[v]) {
        if (u == p) continue;
        res_simple[v] += dfs2(u, v);
        res2[v] += res_simple[u];
    }
    for (auto &hh : add[v]) {
        stk[hh]++;
        res_simple[v]++;
    }
    int x = stk.back();
    stk.pop_back();
    return res_simple[v] - x;
}

void solve() {
    int n;
    cin >> n;
    range(_, n - 1) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 1);
    int m;
    cin >> m;
    vector<pair<int, int>> qs(m);
    ll answer = 0;
    range(i, m) {
        int u, v;
        cin >> u >> v;
        if (h[u] > h[v]) swap(u, v);
        qs[i] = {u, v};
        if (u == v) {
            answer += cnt3[u];
            cnt3[u]++;
            continue;
        }
        int w = lca(v, u);
        if (w == u) {
            add[v].push_back(h[u] + 1);
            start[v]++;
            continue;
        }
        if (h[v] - 1 != h[w]) add[v].push_back(h[w] + 2);
        if (h[u] - 1 != h[w]) add[u].push_back(h[w] + 2);
        int pv = kth_ancestor(v, h[v] - h[w] - 1);
        int pu = kth_ancestor(u, h[u] - h[w] - 1);
        cnt1[pv]++;
        cnt1[pu]++;
        cnt2[w][{min(pu, pv), max(pu, pv)}]++;
        sum2[w]++;
        start[u]++;
        start[v]++;
    }
    dfs2(1, 1);
    range(i, m) {
        auto[u, v] = qs[i];
        if (u == v) {
            answer += res2[u];
            answer += start[u];
            cnt4[u]++;
            continue;
        }
        int w = lca(u, v);
        if (u == w) {
            answer += cnt3[u] - cnt4[u];
            answer += sum2[w];
            answer += start[u];
            int pv = kth_ancestor(v, h[v] - h[w] - 1);
            answer -= cnt1[pv];
            answer += res2[w] - res_simple[pv];
            res2[w]--;
            res_simple[pv]--;
            continue;
        }
        int pv = kth_ancestor(v, h[v] - h[w] - 1);
        int pu = kth_ancestor(u, h[u] - h[w] - 1);
        answer += cnt3[w];
        answer += start[w];
        answer += res2[w] - res_simple[pv] - res_simple[pu];
        answer += sum2[w];
        answer -= cnt1[pv] + cnt1[pu];
        answer += cnt2[w][{min(pu, pv), max(pu, pv)}];
        cnt2[w][{min(pu, pv), max(pu, pv)}]--;
        sum2[w]--;
        cnt1[pv]--;
        cnt1[pu]--;
    }
    cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}