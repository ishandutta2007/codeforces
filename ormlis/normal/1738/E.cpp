#include "bits/stdc++.h"

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

const int INFi = 1e9;
const ll INF = 2e18;
const int LG = 20;

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

int pw(int a, ll b) {
    int res = 1;
    for (; b; b >>= 1, a = mul(a, a)) if (b & 1) res = mul(res, a);
    return res;
}

int rev(int a) {
    return pw(a, md - 2);
}
const int maxN = 2e5 + 5;
int fact[maxN];
int rfact[maxN];

void init() {
    fact[0] = 1;
    for (int i = 1; i < maxN; ++i) fact[i] = mul(fact[i - 1], i);
    rfact[maxN - 1] = rev(fact[maxN - 1]);
    for (int i = maxN - 1; i >= 1; --i) {
        rfact[i - 1] = mul(rfact[i], i);
    }
}

int C(int n, int k) {
    if (k < 0 || n < k) return 0;
    return mul(fact[n], mul(rfact[k], rfact[n - k]));
}

void solve() {
    int n;
    cin >> n;
    vl a(n), p(n + 1), s(n + 1);
    rep(i, n) {
        cin >> a[i];
    }
    int ml = 1;
    rep(i, n) p[i + 1] = p[i] + a[i];
    for(int i = 1; i < n; ++i) {
        if (p[i] * 2 == p[n]) {
            ml = mul(ml, 2);
        }
    }
    int ans = ml;
    map<ll, int> cnt1, cnt2;

    for(int i = 1; i < n; ++i) {
        if (p[i] * 2 < p[n]) cnt1[p[i]]++;
    }
    for(int i = 1; i < n; ++i) {
        ll v = p[n] - p[i];
        if (v * 2 < p[n]) {
            cnt2[v]++;
        }
    }
    for(auto [x, y] : cnt1) {
        int ways = 0;
        for(int k = 0; k <= y; ++k) {
            ways = add(ways, mul(C(cnt2[x], k), C(y, k)));
        }
        ans = mul(ans, ways);
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
//    cout << setprecision(15) << fixed;
    int t = 1;
    init();
    cin >> t;
    rep(_, t) {
        solve();
    }
    return 0;
}