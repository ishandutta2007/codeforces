#include <bits/stdc++.h>


#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) (int)(a.size())
#define each(x, a) for (auto &x : a)
#define ar array
#define vec vector
#define range(i, n) rep(i, n)

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pair<int, int>>;
using vvi = vector<vi>;

int Bit(int mask, int b) { return (mask >> b) & 1; }

template<class T>
bool ckmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool ckmax(T &a, const T &b) {
    if (b > a) {
        a = b;
        return true;
    }
    return false;
}

const int INFi = 1e9 + 10;
const ll INF = 2e18;
const int maxN = 4e5 + 10;
const int LG = 100;

void solve() {
    int n;
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];
    sort(all(a));
    ll sum = accumulate(all(a), 0ll);
    ll mx = *max_element(all(a));
    ll mn = *min_element(all(a));
    ll k1 = sum + 1ll * mn * (n - 2);
    ll k2 = sum + 1ll * mx * (n - 2);
    if (k1 > 0 && k2 > 0) {
        cout << "INF\n";
        return;
    }
    if (k1 < 0 && k2 < 0) {
        cout << "INF\n";
        return;
    }
    vl pref(n + 1);
    pref[0] = 0;
    ll ans = -INF;
    for (int i = 1; i <= n; ++i) pref[i] = pref[i - 1] + a[i - 1];
    for (int k = 1; k < n; ++k) {
        ll s = pref[k] * a[n - 1] + (pref[n] - pref[k]) * a[0];
        s -= 1ll * a[n - 1] * a[0];
        ll r = pref[n];
        r += 1ll * k * a[n - 1];
        r += 1ll * (n - k) * a[0];
        r -= a[0] + a[n - 1];
        // val = s + r * x
        ll L = -INF;
        ll R = INF;
        if (k != 1) {
            // a[k - 1] + t <= 0
            R = -a[k - 1];
        }
        if (k + 1 != n) {
            // a[k] + t >= 0
            L = -a[k];
        }
        // [L, R]
        if (r == 0) {
            ans = max(ans, s);
        } else if (r > 0) {
            ans = max(ans, s + 1ll * r * R);
        } else {
            ans = max(ans, s + 1ll * r * L);
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
//    cout << setprecision(15) << fixed;
    int t = 1;
    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}