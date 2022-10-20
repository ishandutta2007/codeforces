#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;
#define int long long

inline int add(int u, int v) {return (u += v) >= MOD ? u - MOD : u;}
inline int sub(int u, int v) {return (u -= v) < 0 ? u + MOD : u;}
inline int mul(int u, int v) {return (long long)u * v % MOD;}
inline int power(int u, int v) {int res = 1;for (; v; v >>= 1, u = mul(u, u)) if (v & 1) res = mul(res, u); return res;}
inline int inv(int u) {return power(u, MOD - 2);}
inline void addTo(int &u, int v) {u = add(u, v);}
inline void subTo(int &u, int v) {u = sub(u, v);}
inline void mulTo(int &u, int v) {u = mul(u, v);}

const int N = 200010;
const int LOG = 25;
const long long INF = 1e18;

int n, m;
vector<int> adj[2][N];
pair<int, long long> res;

long long dist[LOG][N];
bool used[LOG][N];

void update(int u, long long v) {
    while (u < 18) {
        if (v >= (1ll << u)) {
            v -= (1ll << u);
            u++;
        } else break;
    }
    res = min(res, {u, v});
}

void small() {
    for (int i = 0; i < LOG; i++) fill(dist[i] + 1, dist[i] + n + 1, INF);
    dist[0][1] = 0;
    
    set<pair<long long, pair<int, int>>> s;
    s.insert({0ll, {0, 1}});
    while (!s.empty()) {
        pair<int, int> u = s.begin()->second;
        // cout << u.first << ' ' << u.second << ' ' << dist[u.first][u.second] << endl;
        s.erase(s.begin());
        if (used[u.first][u.second]) continue;
        used[u.first][u.second] = 1;

        // trans
        if (u.first + 1 < LOG) {
            long long newDist = dist[u.first][u.second] + (1ll << u.first);
            if (newDist < dist[u.first + 1][u.second]) {
                dist[u.first + 1][u.second] = newDist;
                s.insert({newDist, {u.first + 1, u.second}});
            }
        }

        // go
        int newDist = dist[u.first][u.second] + 1;
        for (int v : adj[u.first % 2][u.second]) {
            if (dist[u.first][v] > newDist) {
                dist[u.first][v] = newDist;
                s.insert({newDist, {u.first, v}});
            }
        }
    }
    for (int i = 0; i < LOG; i++) {
        // cout << "# " << i << ' ' << dist[i][n] << endl;
        if (dist[i][n] < INF) update(0, dist[i][n]);
    }
}

pair<int, long long> d[2][N];
bool used2[2][N];

void large() {
    for (int i = 0; i < 2; i++) fill(d[i] + 1, d[i] + n + 1, make_pair(N, INF));
    d[0][1] = {0, 0};
    set< pair<pair<int, long long>, pair<int, int>> > s; 
    s.insert({ {0, 0}, {0, 1} });
    while (!s.empty()) {
        auto val = s.begin()->first;
        auto u = s.begin()->second;
        s.erase(s.begin());
        if (used2[u.first][u.second]) continue;
        used2[u.first][u.second] = 1;

        // trans
        pair<int, long long> newDist = {val.first + 1, val.second};
        if (d[u.first ^ 1][u.second] > newDist) {
            d[u.first ^ 1][u.second] = newDist;
            s.insert({ newDist, {u.first^1, u.second} });
        }

        // go
        newDist = {val.first, val.second + 1};
        for (auto v : adj[u.first][u.second]) {
            if (d[u.first][v] > newDist) {
                d[u.first][v] = newDist;
                s.insert({ newDist, {u.first, v}});
            }
        }
    }
    for (int i = 0; i < 2; i++) if (d[i][n].first < N) update(d[i][n].first, d[i][n].second);
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[0][u].push_back(v);
        adj[1][v].push_back(u);
    }

    res = {N * 2, INF};

    small();
    large();

    // cout << res.first << ' ' << res.second << '\n';
    int ans = 1;
    for (int i = 1; i <= res.first; i++) ans = mul(ans, 2);
    ans = sub(ans, 1);
    ans = add(ans, res.second % MOD);
    cout << ans << '\n';
    return 0;
}