#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <iomanip>
#include <queue>
#include <cassert>
using namespace std;
#define ld double
#define debug(x) cout << #x << " is " << x << '\n';
#pragma GCC optimize("O3")
void dfs(int v, vector <bool>& used, vector <int> &ts, vector <vector <int>> &g) {
    used[v] = true;
    for (auto u : g[v]) {
        if (!used[u]) dfs(u, used, ts, g);
    }
    ts.push_back(v);
}
void dfs2(int v, vector <int>& col, vector <vector <int>>& rev, int c) {
    col[v] = c;
    for (auto u : rev[v]) {
        if (col[u] == 0) 
            dfs2(u, col, rev, c);
    }
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    while (tt --> 0) {
        int n; cin >> n;
        vector <string> a(n), b(n);
        for (auto& x : a) cin >> x;
        for (auto& x : b) cin >> x;
        vector <vector <int>> g(4 * n), rev(4 * n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (a[i][j] == b[i][j]) {
                    g[i].push_back(2 * n + j);
                    g[n + i].push_back(2 * n + n + j);
                    g[2 * n + j].push_back(i);
                    g[2 * n + n + j].push_back(n + i);
                }
                else {
                    g[i].push_back(2 * n + n + j);
                    g[n + i].push_back(2 * n + j);
                    g[2 * n + j].push_back(n + i);
                    g[2 * n + n + j].push_back(i);
                }
            }
        }
        rev = g;
        vector <bool> used(4 * n);
        vector <int> ts;
        for (int i = 0; i < 4 * n; ++i) {
            if (!used[i]) {
                dfs(i, used, ts, g);
            }
        }
        reverse(ts.begin(), ts.end());
        vector <int> col(4 * n);
        int c = 1;
        for (auto x : ts) {
            if (col[x] == 0)
                dfs2(x, col, rev, c++);
        }
        bool f = true;
        for (int i = 0; i < n; ++i) {
            if (col[i] == col[n + i]) f = false;
            if (col[2 * n + i] == col[2 * n + n + i]) f = false;
        }
        cout << (f ? "YES" : "NO") << '\n';
    }
    return 0;
}