#include <bits/stdc++.h>

using namespace std;

const int N = 200010;
const int MOD = 998244353;

inline int add(int u, int v) {
    return (u += v) >= MOD ? u - MOD : u;
}

inline int sub(int u, int v) {
    return (u -= v) < 0 ? u + MOD : u;
}

inline int mul(int u, int v) {
    return (long long) u * v % MOD;
}

int n;
vector<int> adj[N];
int f[N], g[N];

void dfs(int u) {
    if (adj[u].empty()) {
        f[u] = g[u] = 1;
        return;
    }
    int zero = 1;
    int both = 1;
    for (int v : adj[u]) {
        dfs(v);
        zero = mul(zero, f[v]);
        both = mul(both, add(f[v], g[v]));
    }
    vector<int> pref(adj[u].size());
    vector<int> suff(adj[u].size());
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (i == 0) pref[i] = f[v];
        else pref[i] = mul(f[v], pref[i - 1]);
    }
    for (int i = adj[u].size() - 1; i >= 0; i--) {
        int v = adj[u][i];
        if (i + 1 == adj[u].size()) suff[i] = f[v];
        else suff[i] = mul(f[v], suff[i + 1]);
    }
    int one = 0;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        int foo = g[v];
        if (i > 0) foo = mul(foo, pref[i - 1]);
        if (i + 1 < adj[u].size()) foo = mul(foo, suff[i + 1]);
        // cout << v << ' ' << foo << endl;
        one = add(one, foo);
    }
    f[u] = sub(both, one);
    g[u] = sub(both, zero);
    // cout << "in " << u << ' ' << f[u] << ' ' << g[u] << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int u;
        cin >> u;
        adj[u].push_back(i);
    }
    dfs(1);
    cout << f[1] << endl;
    return 0;
}