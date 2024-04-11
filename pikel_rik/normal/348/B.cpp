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
const int N = 1e5 + 5;

int n, a[N];
vector<int> g[N];

ll lcm[N], dp[N];

void dfs(int x, int p = 0) {
    if (g[x].size() <= 1 and p) {
        dp[x] = a[x];
        return;
    }

    ld actual = 1;
    ll mn = LLONG_MAX;

    for (int &i : g[x]) {
        if (i == p) continue;
        dfs(i, x);
        mn = min(mn, dp[i]);
        actual *= lcm[i] / __gcd(lcm[x], lcm[i]);
        lcm[x] *= lcm[i] / __gcd(lcm[x], lcm[i]);
    }

    ll lo = 0, hi = (mn + lcm[x] - 1) / lcm[x];

    while (lo < hi) {
        ll mid = lo + (hi - lo + 1) / 2;
        if (mid * lcm[x] <= mn)
            lo = mid;
        else hi = mid - 1;
    }

    dp[x] = lo * lcm[x] * (g[x].size() - (x != 1));

    if (x != 1) {
        actual *= (g[x].size() - 1);
        lcm[x] *= (g[x].size() - 1);

        if (actual > 1e13) {
            cout << accumulate(a, a + n + 1, 0ll) << "\n";
            exit(0);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], lcm[i] = 1;

    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1);
    cout << accumulate(a, a + n + 1, 0ll) - dp[1] << "\n";
    return 0;
}