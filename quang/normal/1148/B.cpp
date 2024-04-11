#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int n, m, ta, tb, k;
int dp[N];
int a[N], b[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> ta >> tb >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += ta;
    }

    for (int i = 1; i <= m; i++) cin >> b[i];

    int cur = 0;
    dp[0] = 0;
    int res = 0;
    for (int i = 1; i <= m; i++) {
        while (cur < n && a[cur + 1] <= b[i]) {
            cur++;
        }
        dp[i] = min(dp[i - 1] + 1, cur);
        if (dp[i] <= k) {
            res = i + 1;
        }
    }
    if (res == m + 1) {
        cout << -1 << endl;
    } else {
        cout << b[res] + tb << endl;
    }
    return 0;
}