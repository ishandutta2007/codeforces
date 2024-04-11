#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;
const int INF = 1e9;

int r, n;
pair<int, pair<int, int>> a[N];
int dp[N];
int maxDp[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> r >> n;
    dp[0] = 0;
    maxDp[0] = 0;
    a[0] = {0, {1, 1}};
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second.first >> a[i].second.second;
    }
    for (int i = 1; i <= n; i++) {
        dp[i] = -INF;
        for (int j = i - 1; j >= 0; j--) {
            int delta = a[i].first - a[j].first;
            if (delta >= 2 * r - 1) {
                dp[i] = max(dp[i], maxDp[j] + 1);
                break;
            } else {
                int dist = abs(a[i].second.first - a[j].second.first) + abs(a[i].second.second - a[j].second.second);
                if (dist <= delta) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    // cout << "here " << i << ' ' << j << endl;
                }
            }
        }

        // cout << i << ' ' << dp[i] << endl;
        maxDp[i] = max(dp[i], maxDp[i - 1]);
    }
    cout << maxDp[n] << endl;
    return 0;
}