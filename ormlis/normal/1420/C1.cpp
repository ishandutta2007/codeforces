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
const int maxN = 3e5 + 5;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int n, q; cin >> n >> q;
    vector<ll> a(n);
    range(i, n) cin >> a[i];
    vector<vector<ll>> dp(n, vector<ll> (2, 0));
    dp[0][0] = 0;
    dp[0][1] = a[0];
    for(int i = 1; i < n; ++i) {
        dp[i][0] = max(dp[i-1][0], dp[i-1][1] - a[i]);
        dp[i][1] = max(dp[i-1][1], dp[i-1][0] + a[i]);
    }
    cout << max(dp[n-1][0], dp[n-1][1]) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}