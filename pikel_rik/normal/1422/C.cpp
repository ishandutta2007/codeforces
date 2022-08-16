#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int N = 1e5 + 5;

template <const int M>
struct ModInt {
    int val;
    ModInt(ll x = 0): val((x % M + M) % M) {}
    ModInt pow(ll n) const { ModInt ans = 1, x = val; while (n) { if (n & 1) ans *= x; x *= x; n /= 2; } return ans; }
    ModInt inverse() const { return pow(M - 2); }
    ModInt operator- () const { return M - val; }
    ModInt operator+ (ModInt m) const { int res = val + m.val; return res < M ? res : res - M; }
    ModInt operator- (ModInt m) const { int res = val - m.val; return res < 0 ? res + M : res; }
    ModInt operator* (ModInt m) const { return val * (ll)m.val % M; }
    ModInt operator/ (ModInt m) const { return *this * m.inverse(); }
    ModInt operator+=(ModInt m) { return *this = *this + m; }
    ModInt operator-=(ModInt m) { return *this = *this - m; }
    ModInt operator*=(ModInt m) { return *this = *this * m; }
    ModInt operator/=(ModInt m) { return *this = *this / m; }

    friend ModInt operator+(int lhs, ModInt m) { return m + lhs; }
    friend ModInt operator-(int lhs, ModInt m) { return m - lhs; }
    friend ModInt operator*(int lhs, ModInt m) { return m * lhs; }
    friend ModInt operator/(int lhs, ModInt m) { return m / lhs; }
    friend ModInt operator+(ll  lhs, ModInt m) { return m + lhs; }
    friend ModInt operator-(ll  lhs, ModInt m) { return m - lhs; }
    friend ModInt operator*(ll  lhs, ModInt m) { return m * lhs; }
    friend ModInt operator/(ll  lhs, ModInt m) { return m / lhs; }

    friend ostream& operator<<(ostream& os, const ModInt& m) {
        os << m.val;
        return os;
    }
    friend istream& operator>>(istream& is, ModInt& m) {
        ll x; is >> x; m = x;
        return is;
    }
};

using mint = ModInt<mod>;

int n;
string s;
mint pref[N], pw[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    pw[0] = 1;
    for (int i = 1; i < N; i++) pw[i] = 10 * pw[i - 1];

    cin >> s;
    n = s.length();

    pref[0] = s[0] - '0';
    for (int i = 1; i < n; i++) {
        pref[i] = 10 * pref[i - 1] + s[i] - '0';
    }

    mint cur_num = pref[n - 1];

    for (int i = 1; i < n; i++) {
        pref[i] += pref[i - 1];
    }

    mint ans = pref[n - 1] - cur_num;

    for (int i = 0; i < n - 1; i++) {
        cur_num -= pw[n - i - 1] * (s[i] - '0');
        ans += (i ? pref[i - 1] * pw[n - i - 1] : 0) + (i + 1) * cur_num;
    }
    cout << ans << '\n';
    return 0;
}