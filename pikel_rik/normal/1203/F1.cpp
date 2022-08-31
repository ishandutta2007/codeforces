#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int N = 100 + 5;
const int R = 30000 + 5;

int n, r, a[N], b[N], dp[N][2*R];
vector<pair<int, int>> big, small;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> r;
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];

    for (int i = 0; i < n; i++) {
        if (b[i] >= 0) {
            big.emplace_back(a[i], b[i]);
        } else {
            a[i] = max(a[i], -b[i]);
            small.emplace_back(a[i], b[i]);
        }
    }

    int cur_cnt = 0;
    int cur = r;

    sort(big.begin(), big.end());

    for (int i = 0; i < big.size() and cur >= big[i].first; i++) {
        cur_cnt++;
        cur += big[i].second;
    }

    sort(small.begin(), small.end(), [&] (const pair<int, int>& a, const pair<int, int>& b) {
        return a.first + a.second > b.first + b.second;
    });

    memset(dp, -1, sizeof(dp));
    dp[0][cur] = cur_cnt;

    for (int i = 1; i <= small.size(); i++) {
        memcpy(dp[i], dp[i - 1], sizeof(dp[i]));
        for (int j = 0; j < 2 * R; j++) {
            if (dp[i - 1][j] != -1 and j >= small[i - 1].first and j + small[i - 1].second >= 0) {
                dp[i][j + small[i - 1].second] = max(dp[i][j + small[i - 1].second], 1 + dp[i - 1][j]);
            }
        }
    }

    int ans = 0;
    for (int j = 0; j < 2 * R; j++) {
        ans = max(ans, dp[small.size()][j]);
    }
    cout << (ans == n ? "YES" : "NO") << '\n';
    return 0;
}