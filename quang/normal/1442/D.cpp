#include <bits/stdc++.h>

using namespace std;

const int N = 3010;

int n, k;
vector<long long> a[N];
long long res = 0;

void relax(int u, vector<long long> &dp) {
    int sz = a[u].size() - 1;
    long long val = a[u].back();
    for (int i = k - sz; i >= 0; i--) {
        dp[i + sz] = max(dp[i + sz], dp[i] + val);
    }
}

void solve(int l, int r, vector<long long> &dp) {
    if (l == r) {
        for (int i = 0; i < a[l].size() && i <= k; i++) {
            res = max(res, dp[k - i] + a[l][i]);
        }
        return;
    } else {
        int m = l + r >> 1;
        vector<long long> left = dp;
        for (int i = m + 1; i <= r; i++) relax(i, left);
        solve(l, m, left);

        vector<long long> right = dp;
        for (int i = l; i <= m; i++) relax(i, right);
        solve(m + 1, r, right);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        int sz;
        cin >> sz;
        a[i].assign(sz + 1, 0);
        for (int j = 1; j <= sz; j++) {
            cin >> a[i][j];
            a[i][j] += a[i][j - 1];
        }
    }
    vector<long long> dp(k + 1, 0);
    solve(1, n, dp);
    cout << res << '\n';
    return 0;
}