#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

using namespace std;

const ll INF = 1e18;
const int INFi = 2e9;
const int maxN = 1e5 + 5;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    ll p, q;
    cin >> p >> q;
    ll ans = 1;
    ll p2 = p;
    for (ll i = 2; i * i <= q; ++i) {
        if (q % i == 0) {
            ll cnt = 1;
            while (q % i == 0) {
                cnt *= i;
                q /= i;
            }
            ll cnt2 = 1;
            while (p2 % i == 0) {
                cnt2 *= i;
                p2 /= i;
            }
            ll kek = p;
            while (cnt2 >= cnt) {
                kek /= i;
                cnt2 /= i;
            }
            ans = max(ans, kek);
        }
    }
    if (q != 1) {
        ll i = q;
        ll cnt = 1;
        while (q % i == 0) {
            cnt *= i;
            q /= i;
        }
        ll cnt2 = 1;
        while (p2 % i == 0) {
            cnt2 *= i;
            p2 /= i;
        }
        ll kek = p;
        while (cnt2 >= cnt) {
            kek /= i;
            cnt2 /= i;
        }
        ans = max(ans, kek);
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