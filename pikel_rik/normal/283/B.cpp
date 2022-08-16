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
const int inf = INT_MAX;
const int N = 2e5 + 5;

int n, a[N], dp[N][2];
bool visited[N][2];

int dfs(int x, int par) {
    if (x <= 0 or x > n)
        return 1;

    if (dp[x][par] != -1)
        return dp[x][par];
    if (visited[x][par])
        return dp[x][par] = 2;

    visited[x][par] = true;
    if (par)
        return dp[x][par] = dfs(x - a[x], 1 - par);
    return dp[x][par] = dfs(x + a[x], 1 - par);
}

ll val[N][2];
ll find(int x, int par) {
    if (x <= 0 or x > n)
        return 0;
    if (dp[x][par] == 2)
        return val[x][par] = -1;

    if (val[x][par] != 0)
        return val[x][par];
    if (par)
        return val[x][par] = a[x] + find(x - a[x], 1 - par);
    return val[x][par] = a[x] + find(x + a[x], 1 - par);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    memset(dp, -1, sizeof(dp));

    cin >> n;
    for (int i = 2; i <= n; i++) cin >> a[i];

    dp[1][0] = 2; dp[1][1] = 3;
    for (int i = 2; i <= n; i++) {
        if (!visited[i][0])
            dfs(i, 0);
        if (!visited[i][1])
            dfs(i, 1);
    }

    for (int i = 2; i <= n; i++) {
        find(i, 1);
    }

    for (int i = 1; i <= n - 1; i++) {
        if (dp[1 + i][1] == 2)
            cout << -1 << "\n";
        else {
            if (dp[1 + i][1] == 1)
                cout << i + val[1 + i][1] << "\n";
            else cout << 2 * i + val[1 + i][1] << "\n";
        }
    }
    return 0;
}