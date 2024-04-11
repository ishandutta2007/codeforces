#include <iostream>
#include <random>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <bitset>
#include <iomanip>
#include <queue>
#include <cmath>
#include <chrono>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;
const ll INF = 1e18;
const int INFi = 1e9 * 2;
const int maxN = 4000001;
ll md = 1000000007;

//double getTime() { return clock() / (double) CLOCKS_PER_SEC;};

void solve() {
    int n; cin >> n;
    int x; cin >> x;
    vector<ll> d(n*2);
    vector<pair<ll, ll>> c(n);
    range(i, n) {
        cin >> c[i].first >> c[i].second;
        d[i*2] = c[i].first;
        d[i*2+1] = c[i].second;
    }
    d.push_back(x);
    sort(all(d));
    vector<ll> dp(n*2+1);
    range(i, dp.size()) {
        dp[i] = abs(d[i] - x);
    }
    range(i, n) {
        vector<ll> new_dp(n*2+1);
        range(j, n*2+1) {
            if (c[i].first <= d[j] && d[j] <= c[i].second) {
                new_dp[j] = dp[j];
            } else {
                new_dp[j] = dp[j] + min(abs(c[i].first - d[j]), abs(c[i].second - d[j]));
            }
        }
        dp = new_dp;
        for(int j= 1; j < dp.size(); ++j) {
            if (dp[j] - dp[j-1] > d[j] - d[j-1]) {
                dp[j] = dp[j-1] + d[j] - d[j-1];
            }
        }

        for(int j= dp.size()-2; j >= 0; --j) {
            if (dp[j] - dp[j+1] > d[j+1] - d[j]) {
                dp[j] = dp[j+1] + d[j+1] - d[j];
            }
        }
    }
    cout << *min_element(all(dp));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
    range(_, tests) {
        solve();
    }
    return 0;
}