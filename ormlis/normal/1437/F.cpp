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
#include <numeric>
#include <random>
#include <chrono>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

using namespace std;

const ll INF = 1e18;
const int INFi = 2e9;
const int maxN = 3e5 + 5;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };


int add(int a, int b) {
    if (a + b >= md) return a + b - md;
    return a + b;
}

int sub(int a, int b) {
    if (a - b < 0) return a - b + md;
    return a - b;
}

int mul(int a, int b) {
    return (1ll * a * b) % md;
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>> suf(n + 1, vector<int>(n + 1, 0));
    auto get = [&](int l, int j) {
        if (l == n || j == n) return 0;
        return suf[l][j];
    };
    vector<int> a(n);
    range(i, n) cin >> a[i];
    sort(all(a));
    int ans = 0;
    for (int mxi = n - 1; mxi >= 0; --mxi) {
        int pr = 0;
        while (a[pr] * 2 <= a[mxi]) pr++;
        int nxt = n - 1;
        while (a[mxi] * 2 <= a[nxt]) nxt--;
        nxt++;
        dp[mxi][n - 1] = 1;
        for (int j = n - 2; j >= 0; --j) {
            dp[mxi][j] = add(mul(max(pr - j, 0), dp[mxi][j + 1]), get(nxt, j + 1));
        }
        range(j, n) suf[mxi][j] = add(suf[mxi + 1][j], dp[mxi][j]);
        ans = add(ans, dp[mxi][0]);
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}