#include <bits/stdc++.h>
using namespace std;

const int INF = 1000000007;

pair<int, int> calc(int n, int cost, int l, vector<int> &a) {
    vector<pair<int, int>> dp(n+1);
    for (int i = 1; i <= n; i++) {
        dp[i] = {INF, INF};
    }
    dp[0] = {0, 0};

    for (int i = 0; i < n; i++) {
        dp[i+1] = min(dp[i+1], make_pair(dp[i].first + a[i], dp[i].second));
        dp[min(n, i+l)] = min(dp[min(n, i+l)], make_pair(dp[i].first + cost, dp[i].second + 1));
    }

    return dp[n];
}

int solve(int n, int k, int l, vector<int> &a) {
    int L = 0, R = n;
    int res = 0;

    while (L <= R) {
        int mid = (L + R)/2;

        int sumcost, op;
        tie(sumcost, op) = calc(n, mid, l, a);

        if (op > k) {
            L = mid+1;
            res = mid;
        } else {
            R = mid-1;
        }
    }

    int sumcost, op; tie(sumcost, op) = calc(n, res, l, a);
    if (op <= k) return 0;

    tie(sumcost, op) = calc(n, res+1, l, a);
    return sumcost - 1LL*(res+1)*k;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, k, l;
    cin >> n >> k >> l;
    string s; cin >> s;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = (s[i] <= 'z' && s[i] >= 'a');
    }
    int ans = solve(n, k, l, a);

    for (int i = 0; i < n; i++) {
        a[i] = 1 - a[i];
    }
    ans = min(ans, solve(n, k, l, a));

    cout << ans << '\n';

    return 0;
}