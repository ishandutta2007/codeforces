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
const int LG = 20;
const int maxN = 2e5;

// source : https://blog.shahjalalshohag.com/topic-list/
const int mod = 1e9 + 7;

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

void solve() {
    int ansn, ansm;
    cin >> ansn >> ansm;
    if (ansn + 1 < ansm) {
        cout << "0\n";
        return;
    }
    int n = ansn;
    int m = ansn + 1;
    vector<vector<mint>> dp(n + 1, vector<mint>(m + 1));
    // dp[n][m] = ans for n, m
    dp[0][1] = 1;
    for (int k = 0; k <= n; ++k) {
        vector<vector<mint>> dp2(n + 1, vector<mint>(m + 1));
        for (int s = 0; s <= m; ++s) {
            if (dp[k][s] == 0) continue;
            mint val = dp[k][s];
            for (int dx = 0; dx + k + 1 <= n && dx <= k; ++dx) {
                for (int x = 0; x <= m; ++x) {
                    if (dx == k && x == s + 1) break;
                    dp2[dx + k + 1][min(x, s)] += 2 * val * dp[dx][x];
                }
            }
            if (k * 2 + 1 <= n) dp2[k * 2 + 1][s] -= val * val;
        }

        rep(k2, n + 1) {
            rep(s2, m + 1) {
                if (dp2[k2][s2] == 0) continue;
                for (int k3 = n; k3 >= 0; --k3) {
                    for (int s3 = m; s3 >= 0; --s3) {
                        if (dp[k3][s3] == 0) continue;
                        mint val = dp[k3][s3];
                        for (int t = 1; k3 + t * k2 <= n && s3 + t * s2 <= m; ++t) {
                            val *= (dp2[k2][s2] + t - 1);
                            val /= t;
                            int K = k3 + k2 * t;
                            int S = s3 + s2 * t;
                            dp[K][S] += val;
                        }
                    }
                }
            }
        }
    }
    cout << dp[ansn][ansm] << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int t = 1;
    //cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}