#include <bits/stdc++.h>

using namespace std;

const int N = 300010;
const int MOD = 998244353;

inline int add(int u, int v) {
    u += v;
    if (u >= MOD) u -= MOD;
    return u;
}

inline int sub(int u, int v) {
    u -= v;
    if (u < 0) u += MOD;
    return u;
}

inline int mul(int u, int v) {
    return (long long)u * v % MOD;
}

inline int power(int u, int v) {
    int res = 1;
    while (v) {
        if (v & 1) res = mul(res, u);
        u = mul(u, u);
        v >>= 1;
    }
    return res;
}

inline int inv(int u) {
    return power(u, MOD - 2);
}

int n;
vector<int> adj[N];
int dp[3][N];

void dfs(int u, int p) {
    if (u != 1 && adj[u].size() == 1) {
        dp[0][u] = dp[1][u] = 0;
        dp[2][u] = 1;
        return;
    }
    for (int i = 0; i < adj[u].size(); i++) {
        if (adj[u][i] == p) {
            adj[u].erase(adj[u].begin() + i);
            break;
        }
    }
    dp[2][u] = 1;
    dp[0][u] = 1;
    vector<int> pref(adj[u].size());
    vector<int> suff(adj[u].size());
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        dfs(v, u);
        dp[2][u] = mul(dp[2][u], add(dp[2][v], dp[1][v]));
        dp[0][u] = mul(dp[0][u], add(dp[2][v], mul(2, dp[1][v])));
        suff[i] = pref[i] = add(dp[2][v], mul(2, dp[1][v]));
    }
    dp[0][u] = sub(dp[0][u], dp[2][u]);
    dp[1][u] = 0;

    for (int i = 1; i < adj[u].size(); i++) {
        pref[i] = mul(pref[i], pref[i - 1]);
    }
    for (int i = (int)adj[u].size() - 2; i >= 0; i--) {
        suff[i] = mul(suff[i], suff[i + 1]);
    }

    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        int foo = 1;
        if (i > 0) foo = mul(foo, pref[i - 1]);
        if (i + 1 < adj[u].size()) foo = mul(foo, suff[i + 1]);
        foo = mul(foo, add(dp[0][v], dp[2][v]));
        dp[1][u] = add(dp[1][u], foo);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    dfs(1, 0);
    cout << add(dp[1][1], dp[2][1]) << endl;
    return 0;
}