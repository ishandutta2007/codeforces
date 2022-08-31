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

int n, c[N];
ll dp[N][2], old[2];
vector<int> g[N];

void dfs(int x, int p) {
    dp[x][0] = 1 - c[x];
    dp[x][1] = c[x];

    for (int &i : g[x]) {
        if (i == p) continue;
        dfs(i, x);

        old[0] = dp[x][0];
        old[1] = dp[x][1];
        dp[x][0] = dp[x][1] = 0;

        dp[x][0] = old[0] * dp[i][1] % mod;
        dp[x][1] = old[1] * dp[i][1] % mod;

        dp[x][1] = (dp[x][1] + old[1] * dp[i][0]) % mod;
        dp[x][1] = (dp[x][1] + old[0] * dp[i][1]) % mod;

        dp[x][0] = (dp[x][0] + old[0] * dp[i][0]) % mod;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int p; cin >> p;
        g[i + 1].push_back(p);
        g[p].push_back(i + 1);
    }

    for (int i = 0; i < n; i++) cin >> c[i];

    dfs(0, -1);
    cout << dp[0][1] << "\n";
    return 0;
}