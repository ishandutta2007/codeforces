#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <iomanip>
#include <queue>
#include <cassert>
#include <bitset>
#include <string>
#include <numeric>
#pragma GCC optimize("O3")

using namespace std;

#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
#define int long long

const int mod = 1e9 + 7, N = 4e2 + 2;

int solve(int k, vector <int>& a) {
    int n = a.size();
    vector <int> dp(n + 1);
    multiset <int> vals = { 0 };
    for (int i = 0; i < n; ++i) {
        dp[i + 1] = *(vals.begin()) + 2 * a[i];
        vals.insert(dp[i + 1]);
        if (vals.size() > k)
            vals.erase(vals.find(dp[i + 1 - k]));
    }
    return dp.back();
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(12);
    int tt; cin >> tt;
    while (tt--) {
        int n, k; cin >> n >> k;
        vector <int> a = { 0 }, b = { 0 };
        for (int x, i = 0; i < n; ++i) {
            cin >> x;
            if (x > 0) a.push_back(x);
            else b.push_back(-x);
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        cout << solve(k, a) + solve(k, b) - max(a.back(), b.back()) << '\n';
    }
}