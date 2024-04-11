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
    int x, y;
    cin >> x >> y;
    vector<int> c(6);
    range(i, 6) cin >> c[i];
    range(i, 20) {
        range(j, 6) {
            c[j] = min(c[(j + 5) % 6] + c[(j + 1) % 6], c[j]);
        }
    }
    ll ans = 0;
    if (x > 0 && y > 0) {
        int e = min(x, y);
        ans += 1ll * e * c[0];
        x -= e;
        y -= e;
    }
    if (x < 0 && y < 0) {
        int e = -max(x, y);
        ans += 1ll * e * c[3];
        x += e;
        y += e;
    }
    if (x < 0) {
        ans += 1ll * (-x) * c[2];
    } else {
        ans += 1ll * x * c[5];
    }
    if (y < 0) {
        ans += 1ll * (-y) * c[4];
    } else {
        ans += 1ll * y * c[1];
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