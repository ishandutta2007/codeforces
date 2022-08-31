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
const int maxN = 100;
const int md2 = 998244353;
const int md3 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int> (m));
    range(i, n) range(j, m) cin >> a[i][j];
    vector<int> cnt1(n + m - 1, 0), cnt2(n + m - 1, 0);
    range(i, n) {
        range(j, m) {
            if (i + j == n + m - 2 - i - j) continue;
            if (a[i][j]) cnt1[min(i+j, n+m-2-i-j)]++;
            else cnt2[min(i+j, n+m-2-i-j)]++;
        }
    }
    int ans = 0;
    range(i, n + m - 1) {
        ans += min(cnt1[i], cnt2[i]);
    }
    cout << ans << "\n";
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