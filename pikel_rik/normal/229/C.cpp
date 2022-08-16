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
const int N = 1e6 + 5;

int n, m, g[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        g[u]++;
        g[v]++;
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ll d1 = g[i], d2 = n - g[i] - 1;
        ans += d1 * d1 - d1 + d2 * d2 - d2 - d2 * d1;
    }

    cout << ans / 6 << "\n";
    return 0;
}