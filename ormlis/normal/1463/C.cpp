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
    int n; cin >> n;
    vector<ll> t(n), x(n);
    range(i, n) cin >> t[i] >> x[i];
    t.push_back(INF);
    int ans = 0;
    ll T = 0;
    ll X = 0;
    ll v = 0;
    ll Tc = 0;
    range(i, n) {
        X += v * (min(t[i], T) - Tc);
        Tc = min(t[i], T);
        if (T <= t[i]) {
            T = t[i] + abs(X - x[i]);
            Tc = t[i];
            if (X > x[i]) v = -1;
            else v = 1;
        }
        ll where = X + v * (min(T, t[i + 1]) - Tc);
        if (min(where, X) <= x[i] && x[i] <= max(where, X)) {
            ans++;
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