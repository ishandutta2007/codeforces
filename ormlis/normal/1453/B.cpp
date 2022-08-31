#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < (n); ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

// using namespace __gnu_pbds;
using namespace std;

const ll INF = 2e18;
const int INFi = 1e9;
const int maxN = 3e5 + 5;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n;
    cin >> n;
    ll ans = 0;
    vector<int> a(n);
    range(i, n) cin >> a[i];
    range(i, n - 1) {
        ans += abs(a[i] - a[i + 1]);
    }
    ll res = ans;
    range(i, n) {
        ll cur = ans;
        ll nxt;
        if (i) nxt = a[i - 1];
        else nxt = a[i + 1];
        if (i) cur += abs(nxt - a[i - 1]) - abs(a[i] - a[i - 1]);
        if (i + 1 < n) cur += abs(nxt - a[i + 1]) - abs(a[i] - a[i + 1]);
        res = min(res, cur);
    }
    cout << res << "\n";
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