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
const int N = 19;

int n, m, a[N], d[N][N];
ll dp[19][262144];

int pop(int x) {
    int c = 0;
    for (int i = 0; i < n; i++) {
        if (x & (1 << i))
            c += 1;
    }
    return c;
}

ll recurse(int mask, int last) {
    if (pop(mask) == m)
        return 0;

    if (dp[last][mask] != -1)
        return dp[last][mask];

    ll best = 0;
    for (int i = 0; i < n; i++) {
        if (!(mask & (1 << i)))
            best = max(best, d[last][i+1] + a[i+1] + recurse(mask | (1 << i), i + 1));
    }
    return dp[last][mask] = best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    memset(dp, -1, sizeof(dp));

    int k;
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 0; i < k; i++) {
        int u, v, w; cin >> u >> v >> w;
        d[u][v] = w;
    }

    ll best = 0;
    for (int i = 0; i < n; i++) {
        best = max(best, a[i+1] + recurse(1 << i, i + 1));
    }

    cout << best << "\n";
    return 0;
}