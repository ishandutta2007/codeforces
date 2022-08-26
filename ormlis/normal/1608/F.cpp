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

const int INFi = 2e9;
const ll INF = 2e18;
const int maxN = 2e5;
const int LG = 30;


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

const int maxF = 2e5 + 5;
int fact[maxF];
int rfact[maxF];

void init() {
    fact[0] = 1;
    for (int i = 1; i < maxF; ++i) fact[i] = mul(fact[i - 1], i);
    rfact[maxF - 1] = rev(fact[maxF - 1]);
    for (int i = maxF - 1; i >= 1; --i) {
        rfact[i - 1] = mul(rfact[i], i);
    }
}

int C(int n, int k) {
    if (k < 0 || n < k) return 0;
    return mul(fact[n], mul(rfact[k], rfact[n - k]));
}

void add2(int &a, int b) {
    a = add(a, b);
}

void solve() {
    init();
    int n;
    cin >> n;
    int k;
    cin >> k;
    vi b(n);
    rep(i, n) cin >> b[i];
    vi l(n + 1), r(n + 1);
    rep(i, n) l[i + 1] = b[i] - k;
    rep(i, n) r[i + 1] = b[i] + k;
    for (int i = 1; i <= n; ++i) {
        l[i] = max(l[i - 1], l[i]);
        r[i] = min(r[i], i);
        if (l[i] > r[i]) {
            cout << "0\n";
            return;
        }
    }
    vvi dp(1, vi(n + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        vvi dp2(r[i] - l[i] + 1, vi(n + 1, 0));
        vvi dp3(r[i] - l[i] + 1, vi(n + 1, 0));
        for (int was = l[i - 1]; was <= r[i - 1]; ++was) {
            int t = was - l[i - 1];
            for (int cnt = 0; cnt < i; ++cnt) {
                if (dp[t][cnt] == 0) continue;
                if (l[i] <= was && was <= r[i]) {
                    add2(dp2[was - l[i]][cnt], mul(dp[t][cnt], was + cnt));
                    add2(dp2[was - l[i]][cnt + 1], mul(cnt + 1, dp[t][cnt]));
                }
                for (int nxt = max(was + 1, l[i]); nxt <= r[i]; ++nxt) {
                    if (cnt < nxt - was - 1) break;
                    add2(dp3[nxt - l[i]][cnt - (nxt - was - 1)], dp[t][cnt]);
                    break;
                }
            }
        }
        rep(j, r[i] - l[i]) {
            for(int t = n; t >= 1; --t) {
                dp3[j + 1][t - 1] = add(dp3[j + 1][t - 1], dp3[j][t]);
            }
        }
        rep(j, r[i] - l[i] + 1) rep(t, n + 1) dp2[j][t] = add(dp2[j][t], dp3[j][t]);
        swap(dp, dp2);
    }
    int ans = 0;
    for (int to = 0; to <= r[n] - l[n]; ++to) {
        rep(cnt, n + 1) {
            if (dp[to][cnt] == 0) continue;
            ans = add(ans, mul(dp[to][cnt], C(n - (to + l[n]), cnt)));
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(20 - 7) << fixed;
    int t = 1;
    range(i, t) {
        solve();
    }
    return 0;
}