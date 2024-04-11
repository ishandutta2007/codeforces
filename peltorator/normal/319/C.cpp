#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))

using namespace std;
typedef long long ll;

vector<ll> dp1d1d(int n, const function<ll(int, int)>& w) {
    vector<ll> dp(n, 0);
    deque<pair<int, int>> k = {{0, 1}};
    for (int i = 1; i < n; i++) {
        dp[i] = dp[k[0].first] + w(k[0].first, i);
        if (i == n - 1) {
            break;
        }
        ++k[0].second;
        if (sz(k) >= 2 && k[0].second == k[1].second) {
            k.pop_front();
        }
        while (!k.empty() && dp[k.back().first] + w(k.back().first, k.back().second) >= dp[i] + w(i, k.back().second)) {
            k.pop_back();
        }
        if (k.empty()) {
            k.push_back({i, i + 1});
        } else if (dp[k.back().first] + w(k.back().first, n - 1) >= dp[i] + w(i, n - 1)) {
            int left = k.back().second, right = n - 1;
            while (right - left > 1) {
                int mid = (left + right) / 2;
                if (dp[k.back().first] + w(k.back().first, mid) >= dp[i] + w(i, mid)) {
                    right = mid;
                } else {
                    left = mid;
                }
            }
            k.push_back({i, right});
        }
    }
    return dp;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& val : a) {
        cin >> val;
    }
    vector<int> b(n);
    for (int& val : b) {
        cin >> val;
    }
    auto w = [&](int l, int r) { return 1LL * b[l] * a[r]; };
    cout << dp1d1d(n, w).back() << endl;
}