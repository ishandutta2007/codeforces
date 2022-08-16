#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 2e5 + 5;

int n, a[N], cnt[N], dp[N][2][2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i], cnt[a[i]]++;

    memset(dp, -1, sizeof(dp));
    function<int(int, int, int)> recurse = [&] (int i, int f1, int f2) {
        if (i == n + 2)
            return 0;
        if (dp[i][f1][f2] != -1)
            return dp[i][f1][f2];

        if (cnt[i] == 1) {
            int ans = 0;
            ans = max(ans, !f1 + recurse(i + 1, f2, 0));
            ans = max(ans, !f2 + recurse(i + 1, 1, 0));
            ans = max(ans, 1 + recurse(i + 1, f2, 1));
            return dp[i][f1][f2] = ans;
        }
        else if (cnt[i] == 2) {
            int ans = 0;
            ans = max(ans, !f1 + !f2 + recurse(i + 1, 1, 0));
            ans = max(ans, !f1 + 1 + recurse(i + 1, f2, 1));
            ans = max(ans, !f2 + 1 + recurse(i + 1, 1, 1));
            return dp[i][f1][f2] = ans;
        }
        else if (cnt[i] >= 3) {
            return dp[i][f1][f2] = !f1 + !f2 + 1 + recurse(i + 1, 1, 1);
        }
        return dp[i][f1][f2] = recurse(i + 1, f2, 0);
    };

    int mx = recurse(1, 0, 0);

    memset(dp, -1, sizeof(dp));
    recurse = [&] (int i, int f1, int f2) {
        if (i == n + 2)
            return 0;
        if (dp[i][f1][f2] != -1)
            return dp[i][f1][f2];

        if (cnt[i]) {
            int ans = INT_MAX;
            ans = min(ans, !f1 + recurse(i + 1, f2, 0));
            ans = min(ans, !f2 + recurse(i + 1, 1, 0));
            ans = min(ans, 1 + recurse(i + 1, f2, 1));
            return dp[i][f1][f2] = ans;
        }
        return dp[i][f1][f2] = recurse(i + 1, f2, 0);
    };

    int mn = recurse(1, 0, 0);
    cout << mn << ' ' << mx << '\n';
    return 0;
}