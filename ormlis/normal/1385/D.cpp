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
// #include <ext/pb_ds/assoc_container.hpp>

// using namespace __gnu_pbds;

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
const unsigned maxN = 1e7 + 1;
const int md2 = 998244353;
const int md3 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    function<int(int, int, char)> dp = [&](int l, int r, char c) {
        int res1 = 0;
        for (int i = l; i < r; ++i) {
            if (s[i] != c) res1++;
        }
        if (l + 1 == r) return res1;
        int mid = (r + l) / 2;
        int res2 = dp(mid, r, c + 1);
        for (int i = l; i < mid; ++i) {
            if (s[i] != c) res2++;
        }
        int res3 = dp(l, mid, c + 1);
        for (int i = mid; i < r; ++i) {
            if (s[i] != c) res3++;
        }
        return min(res2, res3);
    };
    cout << dp(0, n, 'a') << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}