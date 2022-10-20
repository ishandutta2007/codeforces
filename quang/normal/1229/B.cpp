#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
const int MOD = 1000000007;

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
long long x[N];
vector<pair<long long, int>> ls[N];
int res = 0;

void addToLs(vector<pair<long long, int>> &ls, pair<long long, int> u) {
    if (ls.back().first == u.first) ls.back().second += u.second;
    else ls.push_back(u);
}

void dfs(int u, int p) {
    ls[u].push_back({x[u], 1});
    long long last = x[u];
    for (auto val : ls[p]) {
        last = __gcd(last, val.first);
        addToLs(ls[u], {last, val.second});
    }
    for (auto val : ls[u]) {
        res = add(res, mul(val.first % MOD, val.second));
    }
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    cout << res << endl;
    return 0;
}