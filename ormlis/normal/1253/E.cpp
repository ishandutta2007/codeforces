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
const int maxN = 2e5+1;
ll md = 1000000007;

//double getTime() { return clock() / (double) CLOCKS_PER_SEC;};


void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> xs(n);
    range(i, n) cin >> xs[i].first >> xs[i].second;
    vector<int> dp(m + 1, 0), mn(m + 1, 0);
    for (int i = 1; i <= m; ++i) {
        dp[i] = INFi;
        range(j, n) {
            int c = abs(xs[j].first - i) - xs[j].second;
            c = max(c, 0);
            int l = xs[j].first - xs[j].second - c - 1;
            l = max(l, 0);
            dp[i] = min(dp[i], mn[l] + c);
        }
        mn[i] = min(mn[i-1]+1, dp[i]);
    }
    cout << dp[m];
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