#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

using namespace std;

const ll INF = 4e18;
const int INFi = 2e9;
const int maxN = 5e5 + 5;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    range(i, n) cin >> a[i];
    if (n == 1) {
        cout << a[0] << "\n";
        return;
    }
    vector<ll> pref(n), suf(n);
    pref[0] = a[0];
    pref[1] = a[1];
    suf[n - 1] = a[n - 1];
    suf[n - 2] = a[n - 2];
    for (int i = 2; i < n; ++i) pref[i] = a[i] + pref[i - 2];
    for (int i = n - 3; i >= 0; --i) suf[i] = a[i] + suf[i + 2];
    ll ans = INF;
    range(i, n - 1) {
        ll cur = 0;
        if (i != 0) {
            cur += pref[i-1];
        }
        if (i != n - 2) {
            cur += suf[i + 2];
        }
        ans = min(ans, cur);
    }
    ans = min(ans, pref[n - 2]);
    ll sum = 0;
    range(i, n) sum += a[i];
    cout << sum - ans << "\n";
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