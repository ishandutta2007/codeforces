#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
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

const int INFi = 2e9;
const ll INF = 2e18;
const int maxN = 2e5 + 30;
const int LG = 20;

void solve() {
    int n;
    cin >> n;
    vl val(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> val[i];
        val[i] = -val[i];
    }
    for (int i = 1; i <= n; ++i) {
        ll x;
        cin >> x;
        if (i != 1) val[i] += x;
    }
    vl coef(n + 1);
    coef[1] = 1;
    ll C = 0, D = 0;
    vector<ar<ll, 3>> events;
    for (int i = 1; i <= n; ++i) {
        for (int j = i * 2; j <= n; j += i) {
            val[j] -= val[i];
            coef[j] -= coef[i];
        }
        // x * coef[i] + val[i] == 0
        if (val[i] < 0) {
            C -= coef[i];
            D -= val[i];
            if (coef[i] > 0) {
                // x * coef[i] + val[i] > 0
                // x * coef[i] > -val[i]
                events.push_back({(-val[i] + coef[i] - 1) / coef[i], 2 * coef[i], 2 * val[i]});
            }
        } else {
            C += coef[i];
            D += val[i];
            if (coef[i] < 0) {
                // x * coef[i] + val[i] < 0
                // x > -val[i] / coef[i]
                events.push_back({(val[i] - coef[i] - 1) / (-coef[i]), -2 * coef[i], -2 * val[i]});
            }
        }
    }
    sort(all(events));
    int j = 0;
    int q;
    cin >> q;
    vi x(q);
    rep(i, q) cin >> x[i];
    vi ord(q);
    iota(all(ord), 0);
    sort(all(ord), [&](const int &i, const int &j) {
        return x[i] < x[j];
    });
    vl ans(q);
    for (auto &i : ord) {
        while (j < events.size() && events[j][0] <= x[i]) {
            C += events[j][1];
            D += events[j][2];
            j++;
        }
        ans[i] = C * x[i] + D;
    }
    rep(i, q) cout << ans[i] << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int t = 1;
//    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}