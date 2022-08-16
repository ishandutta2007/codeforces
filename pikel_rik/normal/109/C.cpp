#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const int N = 1e5 + 5;

int n, dp[N];
vector<pair<int, int>> g[N];
ll ans;

bool isLucky(int x) {
    while (x) {
        if (x % 10 != 4 and x % 10 != 7)
            return false;
        x /= 10;
    }
    return true;
}

void dfs(int x = 1, int p = 0, bool c = false) {
    dp[x] = c;

    int cnt = 0;
    for (auto &[v, w] : g[x]) {
        if (v == p) continue;
        if (!isLucky(w))
            dfs(v, x, true), dp[x] += (!c ? 1 : 0) + dp[v], cnt++;
        else dfs(v, x, false);
    }

    if (!c) dp[x] -= cnt - 1;

    if (!c and dp[x] > 0)
        ans -= 2 * dp[x] * (ll)(dp[x] - 1) * (n - dp[x]) + dp[x] * (ll)(dp[x] - 1) * (dp[x] - 2);
//    cout << x << " " << dp[x] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    ans = n * (ll)(n - 1) * (n - 2);

    for (int i = 1; i < n; i++) {
        int u, v, w; cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }

    dfs();
    cout << ans << "\n";
    return 0;
}