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
const int N = 1e2;
const int S = 1e4 + 5;

int n, k, a[N], b[N];
bitset<S> dp[S];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    dp[0][0] = true;
    for (int i = 0; i < n; i++) {
        for (int j = S - 1; j >= 0; j--) {
            if (!dp[j].count()) continue;
            if (j + a[i] < S)
                dp[j + a[i]] |= (dp[j] << b[i]);
        }
    }

    int best = -1;
    for (int i = 1; i < S; i++) {
        if (k * i >= S) break;
        if (dp[k*i][i])
            best = k * i;
    }

    cout << best << "\n";
    return 0;
}