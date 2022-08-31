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
    int n, q; cin >> n >> q;
    vector<ll> a(n);
    range(i, n) cin >> a[i];
    ll ans = 0;
    vector<ll> cur(n, 0);

    auto check = [&] (int i) {
        ll need = 0;
        if ((i == 0 || a[i] > a[i-1]) && (i == n - 1 || a[i] > a[i+1])) {
            need = 1;
        } else if ((i != 0 && a[i] < a[i-1]) && (i != n - 1 && a[i] < a[i+1])) {
            need = -1;
        }
        ans -= cur[i] * a[i];
        ans += need * a[i];
        cur[i] = need;
    };

    range(i, n) {
        check(i);
    }
        cout << ans << "\n";

    range(_, q) {
        int l, r; cin >> l >> r;
        l--; r--;
        ans -= cur[l] * a[l];
        cur[l] = 0;
        ans -= cur[r] * a[r];
        cur[r] = 0;
        swap(a[l], a[r]);
        check(l);
        check(r);
        if (l != 0) check(l-1);
        if (r != 0) check(r-1);
        if (l != n - 1) check(l+1);
        if (r != n - 1) check(r+1);
        cout << ans << "\n";
    }
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