#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;
const ll INF = 1e18;
const int INFi = 1e9 * 2;
const int maxN = 5e5 + 1;
const int P = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };
int n, k;
vector<vector<pair<int, int>>> g;
vector<ll> dp1, dp2;

void dfs(int v, int p) {
    vector<ll> impact;
    for(auto &u: g[v]) {
        if (u.first == p) continue;
        dfs(u.first, v);
        dp2[v] += dp1[u.first];
        ll we = u.second + dp2[u.first] - dp1[u.first];
        if (we > 0) impact.emplace_back(we);
    }
    sort(rall(impact));
    range(i, min(k - 1, (int)impact.size())) {
        dp2[v] += impact[i];
    }
    dp1[v] = dp2[v];
    if (impact.size() >= k) {
        dp1[v] += impact[k-1];
    }
}

void solve() {
    cin >> n >> k;
    g.clear();
    dp1.clear();
    dp2.clear();
    g.resize(n);
    dp1.resize(n);
    dp2.resize(n);
    range(i, n - 1) {
        int w, u, v; cin >> u >> v >> w;
        u--; v--;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    dfs(0, -1);
    cout << max(dp1[0], dp2[0]) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests; cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}