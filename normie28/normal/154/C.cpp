#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
int mod1 = 1000012309;
int mod2 = 1000008271;
int c1 = 1002583;
int c2 = 1000037;
 
int binpow(int a, int p) {
    int res = 1;
    while (p > 0) {
        if (p & 1) {
            res *= a;
        }
        a *= a;
        p >>= 1;
    }
    return res;
}
 
main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    int cntall = 0;
    int cnt0 = 0;
    vector<vector<int>> g(n + 1, vector<int>());
    vector<pair<int, int>> edges;
    int u, v;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        edges.push_back({u, v});
    }
    int ans = 0;
    map<pair<int, int>, int> cnt;
    for (int i = 1; i <= n; ++i) {
        sort(g[i].begin(), g[i].end());
        int h1 = 0;
        int h2 = 0;
        for (int j = 0; j < g[i].size(); ++j) {
            h1 *= c1;
            h1 += g[i][j];
            h1 %= mod1;
            h2 *= c2;
            h2 += g[i][j];
            h2 %= mod2;
        }
        ++cnt[{h1, h2}];
        g[i].push_back(i);
        sort(g[i].begin(), g[i].end());
        h1 = 0;
        h2 = 0;
        for (int j = 0; j < g[i].size(); ++j) {
            h1 *= c1;
            h1 += g[i][j];
            h1 %= mod1;
            h2 *= c2;
            h2 += g[i][j];
            h2 %= mod2;
        }
        ++cnt[{h1, h2}];
    }
    for (pair<pair<int, int>, int> kek : cnt) {
        ans += kek.second * (kek.second - 1) / 2;
    }
    cout << ans;
}