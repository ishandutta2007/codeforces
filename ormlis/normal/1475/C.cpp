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
const int maxN = 2e6 + 1000;
const int md2 = 998244353;
const int md3 = 1e9 + 7;

void solve() {
    int a, b, k; cin >> a >> b >> k;
    vector<int> A(a + 1), B(b + 1);
    range(i, k) {
        int x; cin >> x;
        A[x]++;
    }
    range(i, k) {
        int x; cin >> x;
        B[x]++;
    }
    ll ans = 1ll * k * (k - 1) / 2;
    range(i, a + 1) ans -= 1ll * A[i] * (A[i] - 1) / 2;
    range(i, b + 1) ans -= 1ll * B[i] * (B[i] - 1) / 2;
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