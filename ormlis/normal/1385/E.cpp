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
const int maxN = 2e5 + 1;
const int md2 = 998244353;
const int md3 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

vector<int> g[maxN];
vector<int> ts;
int used[maxN];

void dfs(int v) {
    used[v] = 1;
    for (auto &u: g[v]) {
        if (used[u]) continue;
        dfs(u);
    }
    ts.push_back(v);
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edges;
    ts.clear();
    for (int i = 1; i <= n; ++i) {
        used[i] = 0;
        g[i].clear();
    }
    range(_, m) {
        int tt;
        cin >> tt;
        int u, v;
        cin >> u >> v;
        if (tt) g[u].push_back(v);
        edges.emplace_back(u, v);
    }
    for (int i = 1; i <= n; ++i) {
        if (!used[i]) dfs(i);
    }
    vector<int> order(n + 1);
    range(i, n) order[ts[i]] = i;
    for (int i = 1; i <= n; ++i) {
        for (auto &u: g[i]) {
            if (order[u] > order[i]) {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
    for (auto &[u, v] : edges) {
        if (order[u] < order[v]) swap(u, v);
        cout << u << " " << v << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}