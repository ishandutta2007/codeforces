#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <cstring>
#include <bitset>
#include <unordered_map>
#include <cmath>
#include <iomanip>

#define ar array
#define all(arr) arr.begin(), arr.end()
#define rall(arr) arr.rbegin(), arr.rend()
#define range(i, n) for (int i=0; i < n; ++i)

typedef long long ll;
using namespace std;

const int md = 998244353;

int add(int a, int b) {
    if (a + b >= md) return a + b - md;
    return a + b;
}

void solve() {
    string s;
    cin >> s;
    string t;
    cin >> t;
    int m = t.size();
    while (s.size() != t.size()) t += "?";
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    range(i, n) {
        if (s[0] == t[i] || t[i] == '?') {
            dp[i][i] = 2;
        }
    }
    int ans = 0;
    for (int i = 1; i < n; ++i) {
        for (int l = 0; l + i < n; ++l) {
            if (s[i] == t[l] || t[l] == '?') dp[l][l + i] = add(dp[l][l + i], dp[l + 1][l + i]);
            if (s[i] == t[l + i] || t[l + i] == '?') dp[l][l + i] = add(dp[l][l + i], dp[l][l + i - 1]);
        }
    }
    for(int i = m - 1; i < n; ++i) ans = add(ans, dp[0][i]);
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << setprecision(15) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}