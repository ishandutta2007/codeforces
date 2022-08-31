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
const int N = 2000 + 5;

int n, k, a[N], dp[N];

bool f(int x) {
    int ans = inf;
    for (int i = 0; i < n; i++) {
        dp[i] = i;
        for (int j = 0; j < i; j++) {
            if (abs(a[i] - a[j]) <= (i - j) * (ll)x)
                dp[i] = min(dp[i], dp[j] + i - j - 1);
        }
        ans = min(ans, dp[i] + n - i - 1);
    }
    return ans <= k;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];

    if (n == 1) {
        cout << "0\n";
        return 0;
    }

    int lo = 0, hi = 2e9;

    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (f(mid))
            hi = mid;
        else lo = mid + 1;
    }

    cout << lo << "\n";
    return 0;
}