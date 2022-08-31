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
const int N = 300 + 5;

int n, l[N], c[N], best = INT_MAX;

map<int, int> dp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> l[i];
    for (int i = 0; i < n; i++) cin >> c[i];

    int g = 0;
    for (int i = 0; i < n; i++) g = __gcd(g, l[i]);

    if (g != 1) {
        cout << "-1\n";
        return 0;
    }

    dp[0] = 0;
    dp[l[0]] = c[0];

    for (int i = 1; i < n; i++) {
        for (auto p : dp) {
            int cur_g = p.first, co = p.second;
            cur_g = __gcd(cur_g, l[i]);

            if (dp[cur_g])
                dp[cur_g] = min(dp[cur_g], co + c[i]);
            else dp[cur_g] = c[i] + co;
        }
    }

    cout << dp[1] << "\n";
    return 0;
}