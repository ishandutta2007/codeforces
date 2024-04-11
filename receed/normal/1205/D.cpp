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

const int N = 1002;
vector<int> g[N];
int sz[N], n, par[N], t[N], val[N];
int r1, r2, rd;

void csz(int v, int p) {
    sz[v] = 1;
    for (int u : g[v])
        if (u != p) {
            csz(u, v);
            sz[v] += sz[u];
        }
}

int fc(int v, int p) {
    int mv = -1;
    for (int u : g[v])
        if (u != p && (mv == -1 || sz[u] > sz[mv]))
            mv = u;
    if (sz[mv] * 2 > n)
        return fc(mv, v);
    return v;
}

int getp(int v) {
    if (par[v] != v)
        par[v] = getp(par[v]);
    return par[v];
}

void dfs2(int v, int p) {
    if (t[v]) {
        r1++;
        val[v] = r1;
    }
    else {
        r2 += rd;
        val[v] = r2;
    }
    cout << p << ' ' << v << ' ' << val[v] - val[p] << '\n';
    for (int u : g[v])
        if (u != p) {
            t[u] = t[v];
            dfs2(u, v);
        }
}


int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int u, v;
    cin >> n;
    if (n == 1)
        return 0;
    rep(i, n - 1) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    csz(1, 0);
    int c = fc(1, 0);
    csz(c, 0);
    set<pair<int, int>> s;
    for (int u : g[c]) {
        par[u] = u;
        s.insert({sz[u], u});
    }
    while (s.size() > 2) {
        u = (*s.begin()).second;
        s.erase(s.begin());
        v = (*s.begin()).second;
        s.erase(s.begin());
        sz[u] += sz[v];
        par[v] = u;
        s.insert({sz[u], u});
    }
    int v1 = (*s.begin()).second;
    for (int i = 1; i <= n; i++)
        if (getp(i) == v1)
            t[i] = 1;
    rd = sz[v1] + 1;
    for (int u : g[c])
        dfs2(u, c);
}