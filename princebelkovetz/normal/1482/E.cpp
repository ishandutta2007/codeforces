#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <iomanip>
#include <cassert>
#include <functional>
using namespace std;
#define ld long double
#define debug(x) cout << #x << " actually equals " << x << '\n';
constexpr int mod = 1e9 + 7;
#pragma GCC optimize("O3")
vector <vector <int>> g;
vector <int> pr, col;
vector <pair <int, int>> edges;
int dfs(int v, int p = 1) {
    for (auto u : g[v]) {
        if (u == p) continue;
        if (pr[u]) {
            pr[u] = v;
            return u;
        }
        pr[u] = v;
        int res = dfs(u, v);
        if (res) return res;
    }
    return 0;
}
void tree(int v, int p = 1, int c = 1) {
    col[v] = c;
    for (auto u : g[v]) {
        if (u == p) continue;
        tree(u, v, 3 - c);
    }
}
vector <int> rec(vector <int> &cyc) {
    int n = cyc.size();
    set <int> vert;
    set <pair <int, int>> have;
    map <int, int> id;
    for (auto& x : cyc)
        vert.insert(x);
    for (int i = 0; i < n; ++i) {
        id[cyc[i]] = i;
        int a = cyc[i], b = cyc[(i + 1) % n];
        have.insert({ a, b });
        have.insert({ b, a });
    }
    for (auto& x : edges) {
        if (have.find(x) != have.end()) continue;
        if (vert.find(x.first) == vert.end()) continue;
        if (vert.find(x.second) == vert.end()) continue;
        int v1 = id[x.first], v2 = id[x.second];
        if (rand() % 2)
            swap(x.first, x.second);
        int cur = id[x.first];
        vector <int> newcyc = { x.first };
        while (newcyc.back() != x.second) {
            cur = (cur + 1) % n;
            newcyc.push_back(cyc[cur]);
        }
        return rec(newcyc);
    }
    return cyc;
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout << fixed << setprecision(6);
    int n, m, k; cin >> n >> m >> k;
    int need = (k + 1) / 2;
    g.resize(n + 1);
    pr.resize(n + 1);
    col.resize(n + 1);
    for (int u, v, i = 0; i < m; ++i) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        edges.push_back({ u, v });
    }
    int res = dfs(1);
    vector <int> cyc;
    if (res) {
        cyc.push_back(res);
        res = pr[res];
        while (res != cyc[0]) {
            cyc.push_back(res);
            res = pr[res];
        }
        cyc = rec(cyc);
        if (cyc.size() <= k) {
            cout << "2\n" << cyc.size() << '\n';
            for (auto x : cyc) cout << x << ' ';
            cout << '\n';
        }
        else {
            cout << "1\n";
            for (int i = 0; i < need; ++i)
                cout << cyc[2 * i] << ' ';
            cout << '\n';
        }
    }
    else {
        cout << "1\n";
        tree(1);
        vector <int> a, b;
        for (int i = 1; i <= n; ++i) {
            if (col[i] == 1)
                a.push_back(i);
            else
                b.push_back(i);
        }
        for (int i = 0; i < need; ++i) {
            if (a.size() >= need) cout << a[i];
            else cout << b[i];
            cout << ' ';
        }
    }
    return 0;
}