#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

using namespace __gnu_pbds;
using namespace std;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 4e5 + 1;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> l(m), r(m);
    range(i, m) cin >> l[i] >> r[i];
    ll ans = 0;
    for (int Ar = k; Ar <= n; ++Ar) {
        vector<ll> psum(n * 3 + 5);
        vector<ll> dsum(n * 3 + 5);
        range(i, m) {
            int L = max(l[i], Ar - k + 1);
            int R = min(r[i], Ar);
            int len = max(0, R - L + 1);
            psum[0] += len;
            dsum[l[i] + len] += 1;
            int xl = min(l[i] + k, r[i] + 1);
            dsum[xl] -= 1;
            int xr = max(l[i] + k, r[i] + 1);
            dsum[xr] -= 1;
            dsum[r[i] - len + k + 1] += 1;
        }
        ll c = 0;
        ll s = 0;
        for (int i = 0; i <= n; ++i) {
            s += psum[i];
            c += dsum[i];
            s += c;
            if (i >= k) ans = max(ans, s);
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}