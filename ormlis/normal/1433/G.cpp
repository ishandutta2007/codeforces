#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <map>
#include <unordered_set>
#include <tuple>
#include <queue>
#include <set>
#include <cstring>
#include <functional>
#include <random>
#include <chrono>
#include <cassert>
#include <iomanip>
// #include <ext/pb_ds/assoc_container.hpp>

// using namespace __gnu_pbds;

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

const ll INF = 1e18;
const int INFi = 2e9;
const int maxN = 2e3 + 1;
const int md1 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

vector<pair<int, int>> g[maxN];

vector<int> djsk(int n, int start) {
    vector<int> dist(n, INFi);
    dist[start] = 0;
    set<pair<int, int>> s;
    range(i, n) s.insert({dist[i], i});
    while (!s.empty()) {
        auto[w, v] = *s.begin();
        s.erase(s.begin());
        for (auto &[u, w2] : g[v]) {
            if (dist[u] > w + w2) {
                s.erase({dist[u], u});
                dist[u] = w + w2;
                s.insert({dist[u], u});
            }
        }
    }
    return dist;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> dist(n);
    vector<pair<int, int>> edges;
    range(i, m) {
        int x, y, w;
        cin >> x >> y >> w;
        x--;
        y--;
        g[x].emplace_back(y, w);
        g[y].emplace_back(x, w);
        edges.emplace_back(x, y);
    }
    range(i, n) dist[i] = djsk(n, i);
    vector<pair<int, int>> a(k);
    range(i, k) {
        cin >> a[i].first >> a[i].second;
        a[i].first--;
        a[i].second--;
    }
    ll ans = INF;
    range(i, m) {
        auto[u, v] = edges[i];
        ll res = 0;
        range(j, k) {
            auto[a1, b1] = a[j];
            res += min(dist[a1][b1], min(dist[a1][u] + dist[v][b1], dist[a1][v] + dist[u][b1]));
        }
        ans = min(ans, res);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}