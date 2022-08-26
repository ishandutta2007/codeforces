#include <bits/stdc++.h>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define ar array
#define all(a) (a).begin(), (a).end()
typedef long long ll;

using namespace std;

const ll INF = 2e18 + 5;
const int INFi = 1e9;
const int maxN = 1e5 + 5;
const int md2 = 998244353;
const int md = 999999001;

void solve() {
    int n, m; cin >> n >> m;
    vector<ll> a(n);
    range(i, n) cin >> a[i];
    ll g = 0;
    range(i, n - 1) {
        if (a[i + 1] - a[i] != 0) g = __gcd(g, abs(a[i + 1] - a[i]));
    }
    range(j, m) {
        ll b; cin >> b;
        cout << __gcd(g, a[0] + b) << ' ';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}