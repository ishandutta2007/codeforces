#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <map>
#include <unordered_set>
#include <tuple>
#include <queue>
#include <set>
#include <cstring>
#include <functional>
#include <random>
#include <chrono>
#include <cassert>
#include <iomanip>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

const ll INF = 1e18;
const int INFi = 2e9;
const int maxN = 1e5 + 1;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }


int dp[maxN], x[maxN], y[maxN];
int t[maxN];

void solve() {
    int r, n;
    cin >> r >> n;
    int ans = 0;
    x[0] = y[0] = 1;
    for (int i = 1; i <= n; ++i) {
        cin >> t[i] >> x[i] >> y[i];
        dp[i] = -1;
        for (int j = max(0, i - r * 4); j < i; ++j) {
            if (dp[j] == -1) continue;
            int d = t[i] - t[j] - abs(x[i] - x[j]) - abs(y[i] - y[j]);
            if (d >= 0 && dp[i] < dp[j] + 1) dp[i] = dp[j] + 1;
        }
        if (ans < dp[i]) ans = dp[i];
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}