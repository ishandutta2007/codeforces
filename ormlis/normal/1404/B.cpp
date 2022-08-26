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

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

using namespace std;

const ll INF = 1e18;
const int INFi = 2e9;
const int maxN = 2e5 + 5;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

vector<int> g[maxN];
int d = -1;
int a, b, da, db;
void dfs(int v, int p, int h) {
    if (v == b) d = h;
    for(auto &u: g[v]) {
        if (u == p) continue;
        dfs(u, v, h + 1);
    }
}
int h[maxN];
void dfs2(int v, int p) {
    h[v] = 0;
    for(auto &u: g[v]) {
        if (u == p) continue;
        dfs2(u, v);
        h[v] = max(h[v], h[u] + 1);
    }
}
bool bad = false;
void dfs4(int v, int p, int k) {
    vector<pair<int, int>> to;
    int cmax = k;
    for(auto &u: g[v]) {
        if (u == p) continue;
        to.emplace_back(u, cmax + 1);
        cmax = max(h[u] + 1, cmax);
    }
    cmax = k;
    for(int i = (int)to.size() - 1; i >= 0; --i) {
        to[i].second = max(to[i].second, cmax + 1);
        cmax = max(h[to[i].first] + 1, cmax);
    }
    cmax = max(h[v], k);
    if (cmax <= da) bad = true;
    for(auto &w: to) {
        dfs4(w.first, v, w.second);
    }
}

void solve() {
    int n; cin >> n >> a >> b >> da >> db;
    for(int i = 1; i <= n; ++i) g[i].clear();
    for(int i = 1; i <= n; ++i) h[i] = 0;
    bad = false;
    range(_, n - 1) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(a, -1, 0);
    if (da * 2 >= db || d <= da) {
        cout << "Alice\n";
        return;
    }
    dfs2(a, -1);
    dfs4(a, -1, 0);
    if (bad) {
        cout << "Alice\n";
        return;
    }
    cout << "Bob\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}