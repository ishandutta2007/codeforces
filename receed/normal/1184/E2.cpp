#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ld = long double;

const int N = 1000002, L = 18;
int up[L][N], mx[L][N];
int p[N], it[N], d[N];
vector<pair<int, int>> g[N];

int getp(int v) {
    if (p[v] != v)
        p[v] = getp(p[v]);
    return p[v];
}

void dfs(int v, int pr) {
    up[0][v] = pr;
    for (auto &pp : g[v])
        if (pp.first != pr) {
            d[pp.first] = d[v] + 1;
            mx[0][pp.first] = pp.second;
            dfs(pp.first, v);
        }
}

int lca(int u, int v) {
    if (d[u] < d[v])
        swap(u, v);
    int res = 0;
    for (int i = L - 1; i >= 0; i--)
        if (d[up[i][u]] >= d[v]) {
            res = max(res, mx[i][u]);
            u = up[i][u];
        }
    if (u == v)
        return res;
    for (int i = L - 1; i >= 0; i--)
        if (up[i][u] != up[i][v]) {
            res = max(res, max(mx[i][u], mx[i][v]));
            u = up[i][u];
            v = up[i][v];
        }
    res = max(res, max(mx[0][u], mx[0][v]));
    return res;
}

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        p[i] = i;
    vector<vector<int>> e(m, vector<int>(4));
    rep(i, m) {
        cin >> e[i][1] >> e[i][2] >> e[i][0];
        e[i][3] = i;
    }
    sort(e.begin(), e.end());
    rep(i, m) {
        int v1 = getp(e[i][1]), v2 = getp(e[i][2]);
        if (v1 != v2) {
            it[e[i][3]] = 1;
            p[v1] = v2;
            g[v1].push_back({v2, e[i][0]});
            g[v2].push_back({v1, e[i][0]});
        }
    }
    dfs(1, 1);
    rep(i, L - 1)
        for (int j = 1; j <= n; j++) {
            up[i + 1][j] = up[i][up[i][j]];
            mx[i + 1][j] = max(mx[i][j], mx[i][up[i][j]]);
        }
    vector<pair<int, int>> ans;
    for (auto &pp : e) {
        if (it[pp[3]])
            continue;
        ans.push_back({pp[3], lca(pp[1], pp[2])});
    }
    sort(all(ans));
    for (auto &pp : ans)
        cout << pp.second << '\n';
}