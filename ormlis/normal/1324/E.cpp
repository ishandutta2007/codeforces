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
const int maxN = 1e6 + 1;
ll md = 1000000007;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int n, h, l, r; cin >> n >> h >> l >> r;
    vector<int> dp(h, -INFi);
    vector<int> a(n);
    range(i, n) cin >> a[i];
    dp[0] = 0;
    range(i, n) {
        vector<int> new_dp(h, -INFi);
        range(j, h) {
            int x = (j + a[i]) % h;
            int y = (j + a[i] - 1) % h;
            new_dp[x] = max(new_dp[x], dp[j]);
            new_dp[y] = max(new_dp[y], dp[j]);
        }
        for(int j = l; j <= r; ++j) new_dp[j] += 1;
        dp = new_dp;
    }
    cout << *max_element(all(dp));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests=1;
    range(_, tests) {
        solve();
    }
    return 0;
}