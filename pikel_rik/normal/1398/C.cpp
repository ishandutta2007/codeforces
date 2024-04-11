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

const int Z = 10*N;
int n, a[N], dp[20*N + 1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> n >> s;

        for (int i = 1; i <= n; i++)
            a[i] = s[i - 1] - '0' - 1;

        for (int i = -n; i <= 9*n; i++)
            dp[Z + i] = 0;

        ll ans = 0;
        int sum = 0;

        dp[Z] = 1;
        for (int i = 1; i <= n; i++) {
            sum += a[i];
            ans += dp[Z + sum];
            dp[Z + sum]++;
        }

        cout << ans << "\n";
    }
    return 0;
}