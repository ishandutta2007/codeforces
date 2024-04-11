#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 100 + 5;

int n, a[N], m, dp[20][1 << 20];
bitset<1 << 20> visited[20];
pair<char, int> q[20];

int recurse(int i, int mask) {
    if (i == m) {
        return 0;
    }
    if (visited[i][mask])
        return dp[i][mask];

    if (q[i].second == 1) {
        dp[i][mask] = INT_MIN;
        for (int j = 0; j < m; j++) {
            if (!(mask & (1 << j))) {
                dp[i][mask] = max(dp[i][mask], (q[i].first == 'p' ? a[j] : 0) + recurse(i + 1, mask | (1 << j)));
            }
        }
    } else {
        dp[i][mask] = INT_MAX;
        for (int j = 0; j < m; j++) {
            if (!(mask & (1 << j))) {
                dp[i][mask] = min(dp[i][mask], (q[i].first == 'p' ? -a[j] : 0) + recurse(i + 1, mask | (1 << j)));
            }
        }
    }
    visited[i][mask] = true;
    return dp[i][mask];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a, a + n, greater<>());
    n = min(n, m);

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> q[i].first >> q[i].second;
    }

    cout << recurse(0, 0) << '\n';
    return 0;
}