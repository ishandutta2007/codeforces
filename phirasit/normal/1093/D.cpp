#include <cassert>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

const int N = 3e5 + 10;

vector<int> adj[N];
int col[N], pass[N];
int n, m;

int a = 0, b = 0;

const long long mod = 998244353;

long long pow(long long a, long long b) {
    if (b == 0) return 1;
    if (b & 1ll) return a * pow(a, b-1) % mod;
    long long r = pow(a, b >> 1);
    return r * r % mod;
}

bool dfs(int u, int c) {
    if (pass[u]) {
        return col[u] != c;
    }

    pass[u] = 1;
    col[u] = c;
    (c ? a : b)++;
    
    bool err = false;
    for (int v : adj[u]) {
        err |= dfs(v, !c);
    }

    return err;
}


void solve(void) {

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        pass[i] = 0;
        adj[i].clear();
    }

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool err = false;
    long long ans = 1ll;
    for (int i = 1; i <= n; ++i) {
        if (!pass[i]) {
            a = b = 0;
            err |= dfs(i, 0);
            ans = (ans * (pow(2, a) + pow(2, b))) % mod;
        }
    }

    if (err) ans = 0ll;
    cout << ans << "\n";
}

int main() {

    cin.sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}