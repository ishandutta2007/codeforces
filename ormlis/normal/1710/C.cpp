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
using i128 = __int128;
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
const int LG = 20;
const int maxN = 3e5 + 20;

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
    for(; b; b >>= 1, a = mul(a, a)) if (b & 1) res = mul(res,  a);
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

void solve() {
    string s; cin >> s;
    int N = 0;
    vi dp(1 << 3, 0);
    vi tdp(1 << 3, 0);
    vi good(1 << 3);
    rep(m, 1 << 3) {
        int x = m & 1;
        int y = m & 2;
        y >>= 1;
        if (x == y) continue;
        good[m] = 1;
    }
    good[0] = good[7] = -1;
    dp[7] = 1;
    tdp[7] = 1;
    ar<int, 2> kek = {0, 0};
    for(auto x : s) {
        vi dp2(8, 0);
        vi tdp2(8, 0);
        N = mul(N, 2);
        if (x == '1') {
            N = add(N, 1);
            rep(mask, 1 << 3) {
                rep(mask2, 1 << 3) {
                    int mask3 = mask & (mask2);
                    if (good[mask2] != 0) {
                        dp2[mask3] = add(dp2[mask3], dp[mask]);
                    }
                    if (good[mask2] != 1) {
                        tdp2[mask3] = add(tdp2[mask3], tdp[mask]);
                    }
                }
            }
        } else {
            rep(mask, 1 << 3) {
                rep(mask2, 1 << 3) {
                    int mask3 = mask & (mask2);
                    if (mask3) continue;
                    if (good[mask2] != 0) {
                        dp2[mask] = add(dp2[mask], dp[mask]);
                    }
                    if (good[mask2] != 1) {
                        tdp2[mask] = add(tdp2[mask], tdp[mask]);
                    }
                }
            }
        }
        swap(dp, dp2);
        swap(tdp, tdp2);
    }
    int s1 = 0, s2 = 0;
    rep(i, 8) s1 = add(s1, dp[i]);
    rep(i, 8) s2 = add(s2, tdp[i]);
    int res = mul(s1, 3);
    res = sub(res, mul(s2, 3));
    N = add(N, 1);
    res = add(res, N);
    cout << sub(mul(N, mul(N, N)), res) << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //cout << setprecision(15) << fixed;
    int t = 1;
    //cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}