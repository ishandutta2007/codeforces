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
    int n, d, m;
    cin >> n >> d >> m;
    vector<int> a(n);
    range(i, n) cin >> a[i];
    sort(rall(a));
    int re = 0;
    while (re < n && a[re] > m) re++;
    ll ans = 0;
    vector<ll> pref(n);
    pref[0] = a[0];
    range(i, n - 1) pref[i + 1] = pref[i] + a[i + 1];

    auto su = [&](ll l, ll r) {
        if (l > r) return 0LL;
        if (l == 0) return pref[r];
        return pref[r] - pref[l - 1];
    };
    ans = max(ans, su(re, n - 1));
    ll ss = 0;
    range(big, n + 1) {
        if (big > re) break;
        ll biggest = max(1ll * (big - 1) * (d + 1) + 1, 0ll);
        if (biggest > n) break;
        ll lowest = n - (int) biggest;
        ans = max(ans, su(re, min(1ll * n - 1, re + lowest - 1)) + ss);
        ss += a[big];
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //cout << setprecision(15) << fixed;
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}