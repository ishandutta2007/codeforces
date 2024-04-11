#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = 1e9 + 1;
const int N = 5e3 + 5;

int n, T, dp[N][N];
vector<pair<int, int>> g[N];

int recurse(int i, int j) {
    if (dp[i][j] != -1)
        return dp[i][j];

    if (j == 1)
        return dp[i][j] = inf;

    dp[i][j] = inf;
    for (auto &[v, w] : g[i]) {
        int temp = recurse(v, j - 1);
        if (w + temp <= T)
            dp[i][j] = min(dp[i][j], w + temp);
    }
    return dp[i][j];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    memset(dp, -1, sizeof(dp));

    int m;
    cin >> n >> m >> T;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].emplace_back(v, w);
    }

    int best = 0;
    dp[n][1] = 0;

    for (int i = 2; i <= n; i++) {
        if (recurse(1, i) != inf)
            best = i;
    }

    int i = 1, j = best;
    vector<int> ans;

    while (j > 0) {
        ans.push_back(i);
        for (auto &[v, w] : g[i]) {
            if (dp[v][j - 1] + w == dp[i][j]) {
                i = v;
                break;
            }
        }
        j--;
    }

    cout << ans.size() << "\n";
    for (int i : ans) cout << i << " "; cout << "\n";
    return 0;
}