#pragma GCC optimize("O3")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
//#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end(), [](auto &a, auto &b) {
        return a.second > b.second || a.second == b.second && a.first > b.first;
    });
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        p[i] = a[n - i - 1].second;
    }
    vector<pair<int, ll>> dp(n);
    int ans = INT32_MAX;
    ll cnt = 0;
    for (int i = 0; i < n; i++) {
        int pos = lower_bound(p.begin(), p.end(), a[i].first) - p.begin();
        pos = n - pos - 1;
        dp[i] = { a[i].second, 1 };
        if (pos >= 0) {
            dp[i].first = dp[pos].first - a[i].first + a[i].second;
            dp[i].second = dp[pos].second;
        }
        if (dp[i].first == ans) {
            (cnt += dp[i].second) %= mod;
        }
        if (dp[i].first < ans) {
            ans = dp[i].first;
            cnt = dp[i].second;
        }
        dp[i] = { ans, cnt };
    }
    cout << dp[n - 1].second;
    return 0;
}