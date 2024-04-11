#include<bits/stdc++.h>

using namespace std;

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

#define ll long long
#define pb push_back
#define ld long double

const int MOD = 1e9 + 7, INF = 1e9;

int add(int a, int b) {
    return a + b >= MOD ? a + b - MOD : a + b;
}

int sub(int a, int b) {
    return a - b < 0 ? a - b + MOD : a - b;
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q;
    while (q--) {
        string s, t;
        cin >> s >> t;
        int n = s.size(), m = t.size();
        vector<int> pos;
        for (int i = 0; i + m <= n; i++) {
            if (s.substr(i, m) == t) {
                pos.pb(i);
            }
        }
        if (pos.size() == 0) {
            cout << 0 << ' ' << 1 << endl;
        } else {
            vector<pair<int,int>> dp(n, {INF, INF});
            for (auto l : pos) {
                int i = l + m - 1;
                if (pos[0] + m <= l || i >= n) {
                    break;
                }
                dp[i] = {1, 1};
            }
            int ans = INF, cnt = 0;
            for (int i = m - 1; i < n; i++) {
                if (pos.back() <= i) {
                    if (dp[i].first < ans) {
                        ans = dp[i].first;
                        cnt = dp[i].second;
                    } else if (dp[i].first == ans) {
                        cnt = add(cnt, dp[i].second);
                    }
                } else {
                    int j = upper_bound(pos.begin(), pos.end(), i) - pos.begin();
                    int p = pos[j];
                    for (int k = j; k < pos.size(); k++) {
                        int ind = pos[k] + m - 1;
                        if (p + m <= pos[k] || ind >= n) {
                            break;
                        }
                        if (dp[i].first + 1 < dp[ind].first) {
                            dp[ind] = {dp[i].first + 1, dp[i].second};
                        } else if (dp[i].first + 1 == dp[ind].first) {
                            dp[ind].second = add(dp[ind].second, dp[i].second);
                        }
                    }
                }
            }
            cout << ans << ' ' << cnt << endl;
        }
    }
    return 0;
}