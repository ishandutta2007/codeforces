//#pragma GCC optimize("O3", "no-stack-protector")
//#pragma GCC target("sse4", "avx", "popcnt", "lzcnt", "sse3", "sse4.1", "sse4.2", "sse2", "tune=native")
//#pragma GCC optimize ("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using old = long double;

const int N = 200000;

int h[N], p[N];
ll s[N];
ll kek[N];
ll ans;
vector<int> g[N];

void dfs(int v) {
    for (int u : g[v]) {
        if (s[u] == -1) {
            s[u] = s[v];
        }
        dfs(u);
    }
}

void lol(int v) {
    for (int u : g[v]) {
        lol(u);
    }
    if (h[v] % 2 == 0) {
        ll t = INT32_MAX;
        for (int u : g[v]) {
            t = min(t, kek[u]);
        }
        for (int u : g[v]) {
            kek[u] -= t;
        }
        if (t < INT32_MAX) {
            kek[v] += t;
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    h[1] = 1;
    for (int i = 2; i <= n; ++i) {
        cin >> p[i];
        h[i] = h[p[i]] + 1;
        g[p[i]].push_back(i);
    }
    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
    }
    dfs(1);
    for (int i = 1; i <= n; ++i) {
        kek[i] = s[i] - s[p[i]];
        if (kek[i] < 0) {
            cout << -1;
            return 0;
        }
    }
    lol(1);
    for (int i = 1; i <= n; ++i) {
        ans += kek[i];
    }
    cout << ans;
    return 0;
}