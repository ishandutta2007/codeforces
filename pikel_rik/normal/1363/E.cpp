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
const int N = 2e5 + 5;

int n, a[N], b[N], c[N];
vector<int> g[N];

ll cost[N];
pair<int, int> dp[N];

void dfs(int x, int p = -1, int low = 1) {
    if (b[x] != c[x] and b[x] == 0)
        dp[x].first += 1;
    else if (b[x] != c[x])
        dp[x].second += 1;

    if (a[x] < a[low])
        low = x;

    for (int &i : g[x]) {
        if (i == p) continue;
        dfs(i, x, low);

        cost[x] += cost[i];
        dp[x].first += dp[i].first;
        dp[x].second += dp[i].second;
    }

    if (low == x) {
        int temp = min(dp[x].first, dp[x].second);
        dp[x].first -= temp;
        dp[x].second -= temp;
        cost[x] += 2 * temp * (ll)a[x];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i] >> b[i] >> c[i];

    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1);
    if (dp[1].first == 0 and dp[1].second == 0) {
        cout << cost[1] << "\n";
        return 0;
    }

    cout << "-1\n";
    return 0;
}