#include <bits/stdc++.h>

using namespace std;

const int N = 200010;
const long long INF = 1e18;

int n;
vector<pair<int, int>> adj[N];
long long dp[2][N];
int centroid;
int numChild[N];

void dfs(int u, int p) {
    dp[1][u] = 0;
    dp[0][u] = INF;
    int found = 0;
    numChild[u] = 1;
    for (auto v : adj[u]) {
        if (v.first == p) continue;
        dfs(v.first, u);
        long long nxt[2] = {INF, INF};
        nxt[0] = min(nxt[0], dp[0][u] + dp[0][v.first]);
        nxt[1] = min(nxt[1], dp[1][u] + dp[0][v.first]);
        nxt[0] = min(nxt[0], dp[1][u] + dp[1][v.first] + v.second);
        nxt[1] = min(nxt[1], dp[0][u] + dp[1][v.first] + v.second);
        dp[0][u] = nxt[0];
        dp[1][u] = nxt[1];
        numChild[u] += numChild[v.first];
        found |= (numChild[v.first] * 2 > n);
    }
    found |= (n - numChild[u]) * 2 > n;
    if (!found) centroid = u;
}

long long calc(int u, int p) {
    numChild[u] = 1;
    long long res = 0;
    for (auto v : adj[u]) {
        if (v.first == p) continue;
        res += calc(v.first, u);
        res += 1ll * numChild[v.first] * v.second;
        numChild[u] += numChild[v.first];
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc; cin >> tc;
    while (tc--) {
        cin >> n;
        n *= 2;
        for (int i = 1; i <= n; i++) {
            adj[i].clear();
        }
        for (int i = 1; i < n; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        dfs(1, 0);
        cout << dp[0][1] << ' ' << calc(centroid, 0) << '\n';
    }       
    return 0;
}