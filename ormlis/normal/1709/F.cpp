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
const int maxN = 1e6;
const int md = 998244353;

int add(int a, int b) {
    if (a + b >= md) return a + b - md;
    return a + b;
}

int sub(int a, int b) {
    if (a - b < 0) return a - b + md;
    return a - b;
}

int mul(int a, int b) {
    return (1ll * a * b) % md;
}

int binpow(int a, int b) {
    if (b <= 0) return 1;
    if (b % 2) return mul(a, binpow(a, b - 1));
    int m = binpow(a, b / 2);
    return mul(m, m);
}

int rev(int a) {
    return binpow(a, md - 2);
}

int psq[maxN];

void init() {
    int s = 31;
    for (int i = (1 << 23); i >= 1; i /= 2, s = mul(s, s)) {
        if (i < maxN) psq[i] = s;
    }
}

void fft(vector<int> &s, vector<int> &res, int n, int x, int ss = 0, int step = 1, int rs = 0) {
    if (n == 1) {
        res[rs] = s[ss];
        return;
    }
    fft(s, res, n / 2, mul(x, x), ss, step * 2, rs);
    fft(s, res, n / 2, mul(x, x), ss + step, step * 2, rs + n / 2);
    int c = 1;
    for (int i = rs; i < rs + n / 2; ++i) {
        auto a = res[i], b = res[i + n / 2];
        res[i] = add(a, mul(b, c));
        res[i + n / 2] = sub(a, mul(b, c));
        c = mul(c, x);
    }
}

vector<int> multiply(vector<int> &a, vector<int> &b) {
    vector<int> as(all(a)), bs(all(b));
    int n = 1;
    while (n < a.size() || n < b.size()) n *= 2;
    n *= 2;
    as.resize(n);
    bs.resize(n);
    int t = psq[n];
    vector<int> resa(n), resb(n);
    fft(as, resa, n, t);
    fft(bs, resb, n, t);
    range(i, n)resa[i] = mul(resa[i], resb[i]);
    t = rev(t);
    fft(resa, as, n, t);
    int rn = rev(n);
    range(i, n) as[i] = mul(as[i], rn);
    return as;
}

void solve() {
    init();
    int n, k, f; cin >> n >> k >> f;
    vi dp(k + 1, 1);
    rep(_, n - 1) {
        auto dp2 = multiply(dp, dp);
        vi dp3(k + 1, 0);
        int sum = 0;
        rep(i, dp2.size()) sum = add(sum, dp2[i]);
        for(int x = 0; x <= k; ++x) {
            // x == c
            dp3[x] = add(dp3[x], sum);
            if (x < dp2.size()) sum = sub(sum, dp2[x]);
            // c > x
            dp3[x] = add(dp3[x], mul(dp2[x], k - x));
        }
        swap(dp, dp3);
    }
    auto dp2 = multiply(dp, dp);
    dp2.resize(f + 1);
    cout << dp2[f] << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int t = 1;
    // cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}