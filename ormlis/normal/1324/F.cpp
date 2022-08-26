#include <iostream>
#include <random>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <bitset>
#include <iomanip>
#include <queue>
#include <cmath>
#include <chrono>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;
const ll INF = 1e18;
const int INFi = 1e9 * 2;
const int maxN = 1e6 + 1;
ll md = 1000000007;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

vector<int> g[maxN];
int color[maxN];
int ans[maxN];

void dfs1(int v, int p) {
    if (color[v]) ans[v] = 1;
    else ans[v] = -1;
    for(auto &u: g[v]) {
        if (u == p) continue;
        dfs1(u, v);
        if (ans[u] > 0) ans[v] += ans[u];
    }
}

void dfs2(int v, int p, int c) {
    if (c > 0) ans[v] += c;
    for(auto &u: g[v]) {
        if (u == p) continue;
        if (ans[u] > 0) dfs2(u, v, ans[v] - ans[u]);
        else dfs2(u, v, ans[v]);
    }
}

void solve() {
    int n; cin >> n;
    range(i, n) cin >> color[i+1];
    range(i, n - 1) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs1(1, -1);
    dfs2(1, -1, 0);
    range(i, n) {
        cout << ans[i+1] << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests=1;
    range(_, tests) {
        solve();
    }
    return 0;
}