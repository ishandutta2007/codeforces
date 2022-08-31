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
const int maxN = 1e5 + 5;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll ans = a;
    ll e = min(c, d);
    if (a <= e * b) {
        cout << ans << "\n";
        return;
    }
    if (c <= d) {
        // x-a
        // x-2a+b*c
        // x-a-(x-2a+b*c) = a-b*c
        ll chng = a - b * c;
        if (chng > 0) {
            cout << "-1\n";
            return;
        } else {
            cout << ans << "\n";
            return;
        }
    }
    auto cnt_starts = [&](ll x) {
        if (x < 0) return 0ll;
        ll y = x / d + 1;
        return y;
    };

    auto check1 = [&](ll p) {
        ll x = p * d;
        ll cntsx = cnt_starts(x);
        ll z = -a * cntsx;
        ll w = x - c;
        ll cntsw = cnt_starts(w);
        z += cntsw * c * b;
        ll ost = cntsx - cntsw - 1;
        z += ost * (ost + 1) / 2 * d * b;
        return z;
    };

    auto check2 = [&](ll p) {
        return check1(p) <= check1(p + 1);
    };

    ll l = -1, r = 1e6 + 5;
    while (r - l > 1) {
        ll mid = (r + l) / 2;
        if (check2(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    if (r == 1e6+5) {
        cout << "-1\n";
    } else {
        cout << -check1(r) << "\n";
    }
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