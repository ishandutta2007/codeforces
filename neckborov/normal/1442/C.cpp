#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const int N = 2e5 + 5;
const int M = 20;
const int mod = 998244353;

ll binpow(ll a, int p) {
    ll res = 1;
    while (p) {
        if (p & 1) {
            (res *= a) %= mod; 
        }
        p >>= 1;
        (a *= a) %= mod;
    }
    return res;
}

int dist[M][N];
pair<int, int> dist2[N * 2];
vector<int> g[2][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[0][u].push_back(v);
        g[1][v].push_back(u);
    }
    for (int i = 0; i < M; i++) {
        fill(dist[i], dist[i] + N, (int)1e9);
    }
    dist[0][0] = 0;
    set<pair<int, pair<int, int>>> q;
    q.insert({0, {0, 0}});
    while (!q.empty()) {
        int swaps = q.begin()->second.first;
        int v = q.begin()->second.second;
        q.erase(q.begin());
        for (int to : g[swaps & 1][v]) {
            if (dist[swaps][v] + 1 < dist[swaps][to]) {
                q.erase({dist[swaps][to], {swaps, to}});
                dist[swaps][to] = dist[swaps][v] + 1;
                q.insert({dist[swaps][to], {swaps, to}});
            }
        }
        if (swaps + 1 < M && dist[swaps][v] + (1 << swaps) < dist[swaps + 1][v]) {
                q.erase({dist[swaps + 1][v], {swaps + 1, v}});
                dist[swaps + 1][v] = dist[swaps][v] + (1 << swaps);
                q.insert({dist[swaps + 1][v], {swaps + 1, v}});
        }
    }
    int ans = 1e9;
    for (int i = 0; i < M; i++) {
        ans = min(ans, dist[i][n - 1]);
    }
    if (ans < 1e9) {
        cout << ans << endl;
        return 0;
    }
    int asdasd = 1e9;
    fill(dist2, dist2 + N * 2, make_pair(asdasd, asdasd));
    dist2[0] = {0, 0};
    set<pair<pair<int, int>, int>> q2;
    q2.insert({{0, 0}, 0});
    while (!q2.empty()) {
        int state = q2.begin()->second & 1;
        int v = q2.begin()->second >> 1;
        auto kek = q2.begin()->first;
        kek.second++;
        q2.erase(q2.begin());
        for (int to : g[state][v]) {
            if (kek < dist2[to * 2 + state]) {
                q2.erase({dist2[to * 2 + state], to * 2 + state});
                dist2[to * 2 + state] = kek;
                q2.insert({dist2[to * 2 + state], to * 2 + state});
            }
        }
        kek.second--;
        kek.first++;
        int u = v * 2 + (state ^ 1);
        if (kek < dist2[u]) {
            q2.erase({dist2[u], u});
            dist2[u] = kek;
            q2.insert({dist2[u], u});
        }
    }
    auto kek = min(dist2[2 * n - 2], dist2[2 * n - 1]);
    cout << (binpow(2, kek.first) + mod - 1 + kek.second) % mod << endl;
    return 0;
}