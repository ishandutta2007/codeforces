#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define ar array
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()


typedef long long ll;
typedef long double ld;
using namespace std;

// using namespace __gnu_pbds;

const ll INF = 1e18 + 5;
const int INFi = 2e9;
const int maxN = 1e6 + 1000;
const int md = 1e9 + 123;
const int md2 = 1e9 + 7;

void solve() {
    int n; cin >> n;
    vector<int> c(n), a(n), b(n);
    range(i, n) cin >> c[i];
    range(i, n) cin >> a[i];
    range(i, n) cin >> b[i];
    ll ans = 0;
    ll cur = abs(a[1] - b[1]) + 1;
    for(int i = 1; i < n; ++i) {
        ans = max(ans, cur + c[i]);
        if (i + 1 != n) {
            ll z = abs(a[i + 1] - b[i + 1]);
            if (z == 0) {
                cur = 1;
            } else {
                cur = max(cur + c[i] - (z - 1), z + 1);
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
     cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}