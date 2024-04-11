#include <bits/stdc++.h>
using namespace std;

template<int M>
struct static_mint {
    static_assert(0 < M, "Module must be positive");

    constexpr static auto get_m() {
        return M;
    }

    int val;

    constexpr auto get_val() {
        return val;
    }

    constexpr static_mint() : val() {}

    constexpr static_mint(long long x) : val(x % M) { if (val < 0) val += M; }

    constexpr static_mint pow(long long n) const {
        static_mint ans = 1, x(*this);
        for (; n > 0; n /= 2) {
            if (n & 1) ans *= x;
            x *= x;
        }
        return ans;
    }

    constexpr static_mint inv() const {
        return pow(M - 2);
    }

    constexpr static_mint operator+() const {
        static_mint m;
        m.val = val;
        return m;
    }

    constexpr static_mint operator-() const {
        static_mint m;
        m.val = (val == 0 ? 0 : M - val);
        return m;
    }

    constexpr static_mint &operator+=(const static_mint &m) {
        if ((val += m.val) >= M) val -= M;
        return *this;
    }

    constexpr static_mint &operator-=(const static_mint &m) {
        if ((val -= m.val) < 0) val += M;
        return *this;
    }

    constexpr static_mint &operator*=(const static_mint &m) {
        val = (long long) val * m.val % M;
        return *this;
    }

    constexpr static_mint &operator/=(const static_mint &m) {
        val = (long long) val * m.inv().val % M;
        return *this;
    }

    constexpr friend static_mint operator+(const static_mint &lhs, const static_mint &rhs) {
        return static_mint(lhs) += rhs;
    }

    constexpr friend static_mint operator-(const static_mint &lhs, const static_mint &rhs) {
        return static_mint(lhs) -= rhs;
    }

    constexpr friend static_mint operator*(const static_mint &lhs, const static_mint &rhs) {
        return static_mint(lhs) *= rhs;
    }

    constexpr friend static_mint operator/(const static_mint &lhs, const static_mint &rhs) {
        return static_mint(lhs) /= rhs;
    }

    constexpr friend bool operator==(const static_mint &lhs, const static_mint &rhs) {
        return lhs.val == rhs.val;
    }

    constexpr friend bool operator!=(const static_mint &lhs, const static_mint &rhs) {
        return lhs.val != rhs.val;
    }

    constexpr static_mint &operator++() {
        return *this += 1;
    }

    constexpr static_mint &operator--() {
        return *this -= 1;
    }

    constexpr static_mint operator++(int) {
        static_mint result(*this);
        *this += 1;
        return result;
    }

    constexpr static_mint operator--(int) {
        static_mint result(*this);
        *this -= 1;
        return result;
    }

    template<typename T>
    constexpr explicit operator T() const {
        return T(val);
    }

    friend std::ostream &operator<<(std::ostream &os, const static_mint &m) {
        return os << m.val;
    }

    friend std::istream &operator>>(std::istream &is, static_mint &m) {
        long long x;
        return is >> x, m = x, is;
    }
};

using mint = static_mint<1000000007>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<mint> fact(n + 1), inv(n + 1);

    fact[0] = inv[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = i * fact[i - 1];
        inv[i] = fact[i].inv();
    }

    auto choose = [&](int n, int k) -> mint {
        return fact[n] * inv[k] * inv[n - k];
    };

    mint losers = 0;
    for (int len = k + 1; len <= n; len++) {
        losers += choose(n, len);
    }

    cout << mint(2).pow(n) - losers << '\n';
    return 0;
}