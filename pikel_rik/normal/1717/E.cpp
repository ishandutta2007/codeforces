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

template<int N>
struct spf_sieve {
    std::vector<int> primes;
    std::array<int, N + 1> spf;

    spf_sieve() : spf() {
        for (int i = 2; i <= N; i++) {
            if (spf[i] == 0) {
                spf[i] = i;
                primes.push_back(i);
            }
            for (int j = 0; j < (int) primes.size() && i * primes[j] <= N; j++) {
                spf[i * primes[j]] = primes[j];
                if (i % primes[j] == 0) {
                    break;
                }
            }
        }
    }

    bool is_prime(int x) const {
        return spf[x] == x;
    }

    std::vector<std::pair<int, int>> prime_factors(int x) const {
        std::vector<std::pair<int, int>> factors;
        while (x != 1) {
            if (factors.empty() || factors.back().first != spf[x]) {
                factors.emplace_back(spf[x], 0);
            }
            factors.back().second++;
            x /= spf[x];
        }
        return factors;
    }

    std::vector<int> divisors(int x) const {
        std::vector<int> divisors = {1};
        while (x > 1) {
            int p = spf[x], c = 0;
            while (x % p == 0) {
                x /= p, c += 1;
            }
            int sz = (int) divisors.size();
            for (int i = 1, pw = p; i <= c; i++, pw *= p) {
                for (int j = 0; j < sz; j++) {
                    divisors.push_back(divisors[j] * pw);
                }
            }
        }
        return divisors;
    }

    template<typename T, typename F>
    T compute_multiplicative_function(int x, F &&f) const {
        T result = T(1);
        while (x > 1) {
            int p = spf[x], c = 0;
            while (spf[x] == p) {
                x /= p, c += 1;
            }
            result *= f(p, c);
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    static spf_sieve<100000> sieve;

    int n;
    cin >> n;

//    gcd(a, b) = d: for each c, contribution will be c * d times no of coprime pairs a, b s.t. a*d + b*d = n - c

    // no of coprime pairs a, b s.t. a + b = k

    vector<mint> coprime_pairs(n + 1);
    for (int i = 1; i <= n; i++) {
        coprime_pairs[i] = i - 1;
        for (int d : sieve.divisors(i)) {
            coprime_pairs[i] -= (d != 1) * coprime_pairs[i / d];
        }
    }

    mint ans = 0;
    for (int c = 1; c <= n - 2; c++) {
        for (int d : sieve.divisors(n - c)) {
            ans += lcm((long long)c, d) * coprime_pairs[(n - c) / d];
        }
    }
    cout << ans << '\n';
    return 0;
}