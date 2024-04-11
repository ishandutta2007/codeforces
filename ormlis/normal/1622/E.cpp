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
const int maxN = 605;
const int LG = 20;

const int md = 998244353;

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
    int n, m; cin >> n >> m;
    vi x(n);
    rep(i, n) cin >> x[i];
    vi s(m);
    vi c(m);
    rep(i, n) {
        rep(j, m) {
            char w; cin >> w;
            if (w == '1') s[j] |= (1 << i);
        }
    }
    rep(i, m) c[i] = __builtin_popcount(s[i]);
    vi coef(m);
    ll ans = -1;
    vi p(m);
    rep(mask, 1 << n) {
        ll cur = 0;
        rep(i, n) {
            if (mask & (1 << i)) {
                cur += x[i];
            } else {
                cur -= x[i];
            }
        }
        vi h(50);
        vi st(50);
        int mid = 25;
        rep(i, m) {
            int cnt = __builtin_popcount(mask & s[i]);
            coef[i] = c[i] - cnt * 2;
            h[coef[i] + mid]++;
        }
        int t = 1;
        rep(i, 50) {
            int j = i - mid;
            st[i] = t;
            while(h[i]) {
                cur += j * t;
                h[i]--;
                t++;
            }
        }
        if (cur <= ans) continue;
        ans = cur;
        rep(i, m) {
            int w = coef[i] + mid;
            p[i] = st[w]++;
        }
    }
    rep(i, m) cout << p[i] << ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(20 - 7) << fixed;
    int t = 1;
    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}