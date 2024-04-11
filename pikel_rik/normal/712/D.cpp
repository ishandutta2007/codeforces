#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = INT_MAX;

template <const int M> struct ModInt {
    int val;
    ModInt(ll x = 0): val((x % M + M) % M) {}

    ModInt<M> pow(ll n) const {
        ModInt<M> ans = 1, x = val;
        while (n) {
            if (n & 1) ans *= val;
            x *= x;
            n /= 2;
        }
        return ans;
    }

    ModInt<M> inverse() const { return pow(M - 2); }
    ModInt operator+ (const ModInt<M>& m) { return (val + m.val) % M; }
    ModInt operator- (const ModInt<M>& m) { return ((val - m.val) % M + M) % M; }
    ModInt operator* (const ModInt<M>& m) { return val * (ll) m.val % M; }
    ModInt operator/ (const ModInt<M>& m) { return *this * m.inverse(); }
    ModInt operator+=(const ModInt<M>& m) { return *this = *this + m; }
    ModInt operator-=(const ModInt<M>& m) { return *this = *this - m; }
    ModInt operator*=(const ModInt<M>& m) { return *this = *this * m; }
    ModInt operator/=(const ModInt<M>& m) { return *this = *this / m; }

    friend ostream &operator<<(ostream &os, const ModInt &m) {
        os << m.val;
        return os;
    }
};

using mint = ModInt<mod>;
const int Z = 101000;

int a, b, k, t;
mint dp[2 * Z + 1], pref[2 * Z + 1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> a >> b >> k >> t;

    dp[Z] = 1;

    for (int i = 0; i < t; i++) {
        for (int j = -i * k; j <= i * k; j++) {
            pref[Z + j - k] += dp[Z + j];
            pref[Z + j + k + 1] -= dp[Z + j];
        }
        mint sum = 0;
        for (int j = -(i + 1) * k; j <= (i + 1) * k + 1; j++) {
            sum += pref[Z + j];
            dp[Z + j] = sum;
            pref[Z + j] = 0;
        }
    }

    for (int i = -100 * 1000 - 100; i <= 100 * 1000 + 100; i++) {
        dp[Z + i] += dp[Z + i - 1];
    }

    mint ans = 0;
    for (int i = -100 * 1000; i <= 100 * 1000; i++) {
        ans += (dp[Z + i] - dp[Z + i - 1]) * dp[Z + i + a - b - 1];
    }

    cout << ans << '\n';
    return 0;
}