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

int n, k, m, dp[1000][100][2][2], ten[1000];

int recurse(int pos = 0, int sum = 0, int f1 = 0, int f2 = 0) {
    if (pos == n)
        return f2;

    if (dp[pos][sum][f1][f2] != -1)
        return dp[pos][sum][f1][f2];

    int ans = 0;
    for (int i = (pos == n - 1); i <= 9; i++) {
        int p1 = pos + 1, p2 = (ten[pos] * i + sum) % k, p3 = i > 0 ? 1 : f1, p4 = f2 or (p2 == 0 and p3);
        ans = (ans + recurse(p1, p2, p3, p4)) % m;
    }
    return dp[pos][sum][f1][f2] = ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k >> m;
    ten[0] = 1;
    for (int i = 1; i < n; i++) {
        ten[i] = 10 * ten[i - 1] % k;
    }
    memset(dp, -1, sizeof(dp));
    cout << recurse() << "\n";
    return 0;
}