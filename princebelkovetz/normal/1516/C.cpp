#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <iomanip>
#include <cassert>
#include <functional>
using namespace std;
#define int long long
#define ld long double
#define debug(x) cout << #x << " actually equals " << x << '\n';
constexpr int mod = 1e9 + 7;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n; cin >> n;
    vector <int> a(n);
    for (auto& x : a) cin >> x;
    int mn = 228;
    for (auto x : a) {
        int cur = 0;
        while (x & 1 ^ 1)
            x /= 2, cur++;
        mn = min(mn, cur);
    }
    int sum = 0;
    for (auto& x : a)
        x /= (1 << mn), sum += x;
    vector <bool> dp(sum + 1);
    dp[0] = true;
    for (auto x : a) {
        for (int i = sum; i >= x; --i)
            if (dp[i - x])
                dp[i] = true;
    }
    if (sum & 1 ^ 1 and dp[sum / 2]) {
        cout << "1\n";
        for (int i = 0; i < n; ++i) {
            if (a[i] & 1) {
                cout << i + 1 << '\n';
                return 0;
            }
        }
    }
    cout << "0\n";
    return 0;
}