//#pragma GCC optimize("O3")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
//#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const int M = 9;
const int N = 100100;

int cnt[1 << M];
int dp[1 << M], num[1 << M];
int comb[1 << M];
pair<int, int> kek[1 << M];
int fren[N], pizza[N], cost[N];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    int topkek = 1 << M;
    fill(dp, dp + topkek, INT32_MAX);
    fill(comb, comb + topkek, INT32_MAX);
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        while (k--) {
            int t;
            cin >> t;
            fren[i] |= 1 << (t - 1);
        }
    }
    for (int i = 0; i < m; i++) {
        int k;
        cin >> cost[i] >> k;
        while (k--) {
            int t;
            cin >> t;
            pizza[i] |= 1 << (t - 1);
        }
        if (cost[i] < dp[pizza[i]]) {
            dp[pizza[i]] = cost[i];
            num[pizza[i]] = i + 1;
        }
    }
    for (int mask = 1; mask < topkek; mask++) {
        for (int i = 0; i < n; i++) {
            if ((mask | fren[i]) == mask) {
                cnt[mask]++;
            }
        }
    }
    int max_cnt = 0;
    int min_sum = INT32_MAX;
    for (int i = 0; i < topkek; i++) {
        if (dp[i] == INT32_MAX) {
            continue;
        }
        for (int j = 0; j < topkek; j++) {
            if (dp[j] == INT32_MAX) {
                continue;
            }
            if (dp[i] + dp[j] < comb[i | j]) {
                comb[i | j] = dp[i] + dp[j];
                kek[i | j] = { num[i], num[j] };
            }
        }
    }
    pair<int, int> ans = { -1, -1 };
    for (int mask = 0; mask < topkek; mask++) {
        if (comb[mask] == INT32_MAX) {
            continue;
        }
        if (cnt[mask] > max_cnt || cnt[mask] == max_cnt && comb[mask] < min_sum) {
            min_sum = comb[mask];
            max_cnt = cnt[mask];
            ans = kek[mask];
        }
    }
    if (ans.first == ans.second) {
        int q = -1;
        for (int i = 0; i < m; i++) {
            if (i == ans.first - 1) {
                continue;
            }
            if (q == -1 || cost[i] < cost[q]) {
                q = i;
            }
        }
        ans.second = q + 1;
    }
    cout << ans.first << ' ' << ans.second;
    return 0;
}