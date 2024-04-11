

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

const int md = 998244353;

int add(int a, int b) {
    return a + b >= md ? a + b - md : a + b;
}

int sub(int a, int b) {
    return a - b < 0 ? a - b + md : a - b;
}

int mul(int a, int b) {
    return (1ll * a * b) % md;
}

int binpow(int a, ll b) {
    int res = 1;
    for (; b; b >>= 1, a = mul(a, a)) if (b & 1) res = mul(res, a);
    return res;
}

int rev(int a) {
    return binpow(a, md - 2);
}

// source : https://github.com/ShahjalalShohag/code-library/blob/master/Math/BerleKamp%20Massey.cpp
const int N = 3e5 + 9, mod = 998244353;

template<int32_t MOD>
struct modint {
    int32_t value;

    modint() = default;

    modint(int32_t value_) : value(value_) {}

    inline modint<MOD> operator+(modint<MOD> other) const {
        int32_t c = this->value + other.value;
        return modint<MOD>(c >= MOD ? c - MOD : c);
    }

    inline modint<MOD> operator-(modint<MOD> other) const {
        int32_t c = this->value - other.value;
        return modint<MOD>(c < 0 ? c + MOD : c);
    }

    inline modint<MOD> operator*(modint<MOD> other) const {
        int32_t c = (int64_t) this->value * other.value % MOD;
        return modint<MOD>(c < 0 ? c + MOD : c);
    }

    inline modint<MOD> &operator+=(modint<MOD> other) {
        this->value += other.value;
        if (this->value >= MOD) this->value -= MOD;
        return *this;
    }

    inline modint<MOD> &operator-=(modint<MOD> other) {
        this->value -= other.value;
        if (this->value < 0) this->value += MOD;
        return *this;
    }

    inline modint<MOD> &operator*=(modint<MOD> other) {
        this->value = (int64_t) this->value * other.value % MOD;
        if (this->value < 0) this->value += MOD;
        return *this;
    }

    inline modint<MOD> operator-() const {
        return modint<MOD>(this->value ? MOD - this->value : 0);
    }

    modint<MOD> pow(uint64_t k) const {
        modint<MOD> x = *this, y = 1;
        for (; k; k >>= 1) {
            if (k & 1) y *= x;
            x *= x;
        }
        return y;
    }

    modint<MOD> inv() const { return pow(MOD - 2); }  // MOD must be a prime
    inline modint<MOD> operator/(modint<MOD> other) const { return *this * other.inv(); }

    inline modint<MOD> operator/=(modint<MOD> other) { return *this *= other.inv(); }

    inline bool operator==(modint<MOD> other) const { return value == other.value; }

    inline bool operator!=(modint<MOD> other) const { return value != other.value; }

    inline bool operator<(modint<MOD> other) const { return value < other.value; }

    inline bool operator>(modint<MOD> other) const { return value > other.value; }
};

template<int32_t MOD>
modint<MOD> operator*(int64_t value, modint<MOD> n) { return modint<MOD>(value) * n; }

template<int32_t MOD>
modint<MOD> operator*(int32_t value, modint<MOD> n) { return modint<MOD>(value % MOD) * n; }

template<int32_t MOD>
istream &operator>>(istream &in, modint<MOD> &n) { return in >> n.value; }

template<int32_t MOD>
ostream &operator<<(ostream &out, modint<MOD> n) { return out << n.value; }

using mint = modint<mod>;

vector<mint> BerlekampMassey(vector<mint> S) {
    int n = (int) S.size(), L = 0, m = 0;
    vector<mint> C(n), B(n), T;
    C[0] = B[0] = 1;
    mint b = 1;
    for (int i = 0; i < n; i++) {
        ++m;
        mint d = S[i];
        for (int j = 1; j <= L; j++) d += C[j] * S[i - j];
        if (d == 0) continue;
        T = C;
        mint coef = d * b.inv();
        for (int j = m; j < n; j++) C[j] -= coef * B[j - m];
        if (2 * L > i) continue;
        L = i + 1 - L;
        B = T;
        b = d;
        m = 0;
    }
    C.resize(L + 1);
    C.erase(C.begin());
    for (auto &x: C) x *= -1;
    return C;
}

vector<mint> combine(int n, vector<mint> &a, vector<mint> &b, vector<mint> &tr) {
    vector<mint> res(n * 2 + 1, 0);
    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < n + 1; j++) res[i + j] += a[i] * b[j];
    }
    for (int i = 2 * n; i > n; --i) {
        for (int j = 0; j < n; j++) res[i - 1 - j] += res[i] * tr[j];
    }
    res.resize(n + 1);
    return res;
};

// transition -> for(i = 0; i < x; i++) f[n] += tr[i] * f[n-i-1]
// S contains initial values, k is 0 indexed
mint LinearRecurrence(vector<mint> &S, vector<mint> &tr, long long k) {
    int n = S.size();
    assert(n == (int) tr.size());
    if (n == 0) return 0;
    if (k < n) return S[k];
    vector<mint> pol(n + 1), e(pol);
    pol[0] = e[1] = 1;
    for (++k; k; k /= 2) {
        if (k % 2) pol = combine(n, pol, e, tr);
        e = combine(n, e, e, tr);
    }
    mint res = 0;
    for (int i = 0; i < n; i++) res += pol[i + 1] * S[i];
    return res;
}

const int T = 100;
int dp[T][12][12][12];
int val[T][12][12];

void precalc() {
    dp[0][0][0][0] = 1;
    for (int t = 1; t < T; ++t) {
        rep(i, 12) {
            if (i > t - 1) break;
            rep(j, 12) {
                if (i > j) continue;
                rep(e, 12) {
                    if (dp[i][j][e] == 0) continue;
                    int value = dp[t - 1][i][j][e];
                    for (int d = 0; d + j <= 11 && d < t; ++d) {
                        int e2 = e;
                        if (i < d) e2++;
                        if (e2 > 11) break;
                        dp[t][d][j + d][e2] = add(dp[t][d][j + d][e2], value);
                    }
                }
            }
        }
        rep(i, 12) {
            rep(j, 12) {
                rep(d, 12) {
                    val[t][i][j] = add(val[t][i][j], dp[t][d][i][j]);
                }
            }
        }
    }
}

void solve() {
    int n, k, x;
    cin >> n >> k >> x;
    n--;
    vector<mint> a;
    for(int i = 1; i < T; ++i) {
        a.emplace_back(val[i][k][x]);
    }
    auto res = BerlekampMassey(a);
    a.resize(res.size());
    auto ans = LinearRecurrence(a, res, n);
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
//    cout << setprecision(15) << fixed;
    int t = 1;
    precalc();
    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}