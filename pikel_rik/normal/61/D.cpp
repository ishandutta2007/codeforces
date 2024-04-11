#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 1e5 + 5;

int n;
vector<pair<int, int>> g[N];

int c = 0;
ll dp[N][2];

void dfs(int u, int p) {
    for (auto &[v, w] : g[u]) {
        if (v == p) continue;
        dfs(v, u);
        dp[u][0] += 2 * w + dp[v][0]; //dp[2][0] = 8, dp[2][1] =
    }

    dp[u][1] = dp[u][0];

    for (auto &[v, w] : g[u]) {
        if (v == p) continue;
        dp[u][1] = min(dp[u][1], dp[u][0] - 2 * w - dp[v][0] + w + dp[v][1]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v, w; cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }

    dfs(1, 0);
    cout << dp[1][1] << "\n";
    return 0;
}