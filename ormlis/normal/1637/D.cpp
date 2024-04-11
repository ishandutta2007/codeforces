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
const int maxN = 1e5 + 30;
const int LG = 19;

void solve() {
    int n; cin >> n;
    vi a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    rep(i, n) if (a[i] > b[i]) swap(a[i], b[i]);
    vi c(n);
    rep(i, n) c[i] = b[i] - a[i];
    int C = accumulate(all(c), 0);
    vector<int> dp(C + 1, -2);
    dp[0] = -1;
    rep(i, n) {
        if (c[i] == 0) continue;
        for(int x = C; x >= c[i]; --x) {
            if (dp[x] == -2 && dp[x - c[i]] != -2) {
                dp[x] = i;
            }
        }
    }
    int res = 0;
    rep(i, C) {
        if (dp[i] == -2) continue;
        if (max(res, C - res) > max(i, C - i)) res = i;
    }
    while(res != 0) {
        swap(a[dp[res]], b[dp[res]]);
        res -= c[dp[res]];
    }
    ll ans = 0;
    rep(i, n) {
        rep(j, i) {
            ans += 1ll * (a[i] + a[j]) * (a[i] + a[j]);
            ans += 1ll * (b[i] + b[j]) * (b[i] + b[j]);
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //cout << setprecision(20 - 7) << fixed;
    int t = 1;
    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}