#include <bits/stdc++.h>

using namespace std;

const int N = 500010;

int n, k;
long long f[2][N];
vector<pair<int, int>> adj[N];

void dfs(int u, int p) {
    f[0][u] = f[1][u] = 0;
    vector<long long> ls;
    long long tot = 0;
    for (auto v : adj[u]) {
        if (v.first == p) continue;
        dfs(v.first, u);
        ls.push_back(f[1][v.first] + v.second - f[0][v.first]);
        tot += f[0][v.first];
    }
    sort(ls.begin(), ls.end(), greater<long long>());
    long long sum = 0;
    for (int i = 0; i < min(k - 1, (int)ls.size()); i++) {
        sum += max(0ll, ls[i]);
    }
    f[1][u] = f[0][u] = tot + sum;
    if (ls.size() >= k) f[0][u] += max(0ll, ls[k - 1]);
}   

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n >> k;
        //init;
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
        cout << f[0][1] << '\n';
    }
    return 0;
}