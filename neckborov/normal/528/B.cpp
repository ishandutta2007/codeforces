//#pragma GCC optimize("O3")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
//#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;


const ld INF = 1e18;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<pair<int, int>> segs;
    for (int i = 0; i < n; i++) {
        int x, w;
        cin >> x >> w;
        segs.emplace_back(x - w, x + w);
    }
    sort(segs.begin(), segs.end(), [](auto &a, auto &b) {
        return a.second < b.second || a.second == b.second && a.first < b.first;
    });
    vector<int> pnt(n);
    for (int i = 0; i < n; i++) {
        pnt[i] = segs[i].second;
    }
    vector<int> dp(n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int pos = upper_bound(pnt.begin(), pnt.end(), segs[i].first) - pnt.begin() - 1;
        if (i) {
            dp[i] = dp[i - 1];
        } else {
            dp[i] = 1;
        }
        if (pos >= 0) {
            dp[i] = max(dp[i], dp[pos] + 1);
        }
        ans = max(ans, dp[i]);
    }
    cout << ans;
    return 0;
}