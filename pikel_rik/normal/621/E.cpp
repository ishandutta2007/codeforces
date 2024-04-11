#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 50000 + 5;

template <int M> struct ModInt {
    int val;
    ModInt(ll x = 0): val((x % M + M) % M) {}

    ModInt pow(ll n) const {
        ModInt ans = 1, x = val;
        while (n) {
            if (n & 1) ans *= x;
            x *= x;
            n /= 2;
        }
        return ans;
    }

    ModInt inverse() const { return pow(M - 2); }
    ModInt operator+ (const ModInt& m) { return val + m.val < M ? val + m.val : val + m.val - M; }
    ModInt operator- (const ModInt& m) { return val - m.val >= 0 ? val - m.val : val - m.val + M; }
    ModInt operator* (const ModInt& m) { return val * (ll) m.val % M; }
    ModInt operator/ (const ModInt& m) { return *this * m.inverse(); }
    ModInt operator+=(const ModInt& m) { return *this = *this + m; }
    ModInt operator-=(const ModInt& m) { return *this = *this - m; }
    ModInt operator*=(const ModInt& m) { return *this = *this * m; }
    ModInt operator/=(const ModInt& m) { return *this = *this / m; }

    friend ostream& operator<<(ostream& os, const ModInt& m) {
        os << m.val;
        return os;
    }
};

template <typename T> class matrix {
public:
    int n, m;
    vector<vector<T>> mat;

    matrix(): n(), m(), mat() {}
    matrix (int n, int m): n(n), m(m), mat(n, vector<T>(m)) {}

    matrix operator*(const matrix& rhs) {
        assert(m == rhs.n);
        matrix res(n, rhs.m);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < rhs.m; j++) {
                for (int k = 0; k < m; k++) {
                    res.mat[i][j] += mat[i][k] * rhs.mat[k][j];
                }
            }
        }
        return res;
    }

    matrix operator*=(const matrix& rhs) {
        return *this = *this * rhs;
    }
};

int n, b, k, x, cnt[10];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> b >> k >> x;
    for (int i = 0, d; i < n; i++) {
        cin >> d;
        cnt[d]++;
    }

    using mint = ModInt<mod>;
    matrix<mint> m(x, x);

    for (int i = 0; i < x; i++) {
        for (int j = 1; j <= 9; j++) {
            m.mat[i][(10 * i + j) % x] += cnt[j];
        }
    }

    matrix<mint> res(x, x);
    for (int i = 0; i < x; i++) res.mat[i][i] = 1;

    while (b) {
        if (b & 1) res *= m;
        m *= m;
        b /= 2;
    }

    cout << res.mat[0][k] << "\n";
    return 0;
}