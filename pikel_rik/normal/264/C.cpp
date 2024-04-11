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

int n, v[N], c[N];
ll dp[N];
bool visited[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int q;
    cin >> n >> q;

    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i < n; i++) cin >> c[i];

    while (q--) {
        int a, b;
        cin >> a >> b;

        for (int i = 1; i <= n; i++) dp[i] = -100000000000000LL;
        for (int i = 1; i <= n; i++) visited[i] = false;

        ll max1 = 0, max2 = 0;

        for (int i = 0; i < n; i++) {
            ll temp = max(dp[c[i]] + v[i] * (ll)a, (max1 == dp[c[i]] ? max2 : max1) + v[i] * (ll)b);
            if (temp > dp[c[i]]) {
                if (max1 == dp[c[i]]) max1 = temp;
                else {
                    ll temp1 = temp;
                    if (temp > max1) swap(max1, temp1);
                    if (temp > max2) swap(max2, temp1);
                }
                dp[c[i]] = temp;
            }
        }

        cout << max1 << "\n";
    }
    return 0;
}