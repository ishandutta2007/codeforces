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
const int maxN = 1e6 + 5;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    ll p, f; cin >> p >> f;
    ll cnts, cntw; cin >> cnts >> cntw;
    ll s, w; cin >> s >> w;
    if (s > w) {
        swap(s, w);
        swap(cnts, cntw);
    }
    ll ans = 0;
    for(ll cnt = 0; cnt <= cntw; ++cnt) {
        if (cnt * w > p) break;
        ll m1 = min((p - cnt * w) / s, cnts);
        ll m2 = min(f / s, (cnts - m1));
        ll x2 = min((f - m2 * s) / w, cntw - cnt);
        ans = max(ans, m1 + cnt + m2 + x2);
    }
    cout << ans << "\n";
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