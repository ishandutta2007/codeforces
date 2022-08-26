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
const int maxN = 5e6 + 30;
const int LG = 100;

const int md = 998244353; //1e9 + 7, 1e9 + 9

inline int add(const int &a, const int &b) {
    return a + b >= md ? a + b - md : a + b;
}

inline int sub(const int &a, const int &b) {
    return a - b < 0 ? a - b + md : a - b;
}

inline int mul(const int &a, const int &b) {
    return (1ll * a * b) % md;
}

int binpow(int a, int b) {
    int res = 1;
    for (; b; b >>= 1, a = mul(a, a)) if (b & 1) res = mul(res, a);
    return res;
}

int rev(int a) {
    return binpow(a, md - 2);
}

void solve() {
    int n;
    cin >> n;
    vi x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];
    vvi d(n, vi(n));
    rep(i, n) rep(j, n) d[i][j] = abs(x[i] - x[j]) + abs(y[i] - y[j]);
    rep(i, n) d[i][i] = INFi;
    vi mn(n);
    rep(i, n) mn[i] = *min_element(all(d[i]));
    vi dp(n + 1);
    dp[0] = 1;
    vi szs;
    vi uu(n);
    rep(i, n) {
        if (uu[i]) continue;
        vi kek;
        kek.push_back(i);
        rep(t, n) if (mn[i] == d[t][i]) kek.push_back(t);
        if (kek.size() != 1) {
            bool ok = true;
            int need = d[kek[0]][kek[1]];
            vi u(n);
            for (auto a : kek) {
                u[a] = 1;
            }
            for (auto a : kek) {
                rep(j, n) {
                    if (j == a) continue;
                    if (u[j]) {
                        ok &= (d[a][j] == need);
                    } else {
                        ok &= (d[a][j] > need);
                    }
                }
            }
            if (!ok) {
                repr(was, n) dp[was + 1] = mul(dp[was], n - was);
                dp[0] = 0;
                uu[i] = 1;
                continue;
            }
        }
        auto dp2 = dp;
        rep(_, kek.size()) {
            repr(was, n) dp[was + 1] = mul(dp[was], n - was);
            dp[0] = 0;
        }
        rep(was, n) dp[was + 1] = add(dp[was + 1], mul(dp2[was], n - was));
        for(auto x : kek) uu[x] = 1;
    }
    int ans = 0;
    rep(i, n + 1) ans = add(ans, dp[i]);
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
//    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int t = 1;
//    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}