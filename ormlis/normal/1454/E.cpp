#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

using namespace __gnu_pbds;
using namespace std;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 2e5 + 5;
const int md2 = 998244353;
const int md = 1e9 + 9;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

ll ans = 0;
vector<int> g[maxN];
int h[maxN];
int n;

pair<int, int> dfs(int v, int p) {
    int res = 1;
    int uu = -1;
    int fu = 0;
    for (auto &u: g[v]) {
        if (u == p) continue;
        if (h[u] < h[v] && h[u]) {
            uu = u;
            fu = 0;
            continue;
        }
        if (h[u]) continue;
        h[u] = h[v] + 1;
        auto[d, u2] = dfs(u, v);
        if (u2 != -1) {
            uu = u2;
            fu = d;
        }
        res += d;
    }
    if (uu != -1) {
        int k = res;
        if (uu == v) {
            k = n - fu;
            uu = -1;
        } else {
            k = res - fu;
        }
        ans += 1ll * k * (n - k);
    }
    return {res, uu};
}


void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        h[i] = 0;
        g[i].clear();
    }
    range(_, n) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ans = 1ll * n * (n - 1);
    h[1] = 1;
    dfs(1, -1);
    cout << ans / 2 << "\n";
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