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
int f[N];

int dfs(int u, int p) {
    int res = f[adj[u].size()];
    for (int v : adj[u]) {
        if (v == p) continue;
        int foo = dfs(v, u);
        res = mul(res, foo);
    }
    return res;
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
    f[0] = 1;
    for (int i = 1; i < N; i++) {
        f[i] = mul(f[i - 1], i);
    }
    cout << mul(dfs(1, 0), n) << endl;
    return 0;
}