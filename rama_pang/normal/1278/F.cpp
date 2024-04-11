
#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Modular {
    
  private:

    using Type = typename decay<decltype(T::value)>::type;
    Type value;

  public:

    Modular() { value = 0; }

    template <typename U>
    Modular(const U& x) { value = normalize(x); }

    template<typename U>
    Type normalize(const U& x) {
        Type res;
        if (-mod() <= x && x < mod()) {
            res = static_cast<Type>(x);
        } else {
            res = static_cast<Type>(x % mod());
        }
        if (res < 0) {
            res += mod();
        }
        return res;
    }

    explicit operator Type() const { return value; }
    template <typename U> explicit operator U() const { return static_cast<U>(value); }
    constexpr static Type mod() { return T::value; }

    Modular power(Modular n, Type x) {
        assert(x >= 0);
        Modular res = 1;
        for (; x; x /= 2, n *= n) if (x & 1) res *= n;
        return res;
    }

    Type inverse(Type a, Type m) {
        Type x = 0, y = 1;
        while (a != 0) {
            Type q = m / a;
            m -= q * a; swap(a, m);
            x -= q * y; swap(x, y);
        }
        assert(m == 1);
        return x;
    }

    Modular& operator+=(const Modular& o) { if ((value += o.value) >= mod()) value -= mod(); return *this; }
    template <typename U> Modular& operator+=(const U& o) { return *this += Modular(o); }

    Modular& operator-=(const Modular& o) { if ((value -= o.value) < 0) value += mod(); return *this; }
    template <typename U> Modular& operator-=(const U& o) { return *this -= Modular(o); }

    Modular& operator*=(const Modular& o) { value = normalize(1ll * value * o.value); return *this; }
    template <typename U> Modular& operator*=(const U& o) { return *this *= Modular(o); }

    Modular& operator/=(const Modular &o) { return *this *= Modular(inverse(o.value, mod())); }
    template <typename U> Modular& operator/=(const U& o) { return *this /= Modular(o); }
    
    Modular operator+() { return Modular(+value); }
    Modular operator-() { return Modular(-value); }

    Modular& operator++() { return *this += 1; }
    Modular& operator--() { return *this -= 1; }

    friend ostream& operator<<(ostream &os, const Modular &x) { os << x.value; return os; }
    friend istream& operator>>(istream &is, Modular &x) { 
        typename common_type<Type, int64_t>::type in;
        is >> in; 
        x.value = x.normalize(in);
        return is; 
    }

    friend bool operator==(const Modular& a, const Modular& b) { return a.value == b.value; }
    template<typename U> friend bool operator==(const Modular &a, U b) { return a == Modular(b); }
    template<typename U> friend bool operator==(U a, const Modular &b) { return Modular(a) == b; }

    friend bool operator!=(const Modular& a, const Modular& b) { return a.value != b.value; }
    template<typename U> friend bool operator!=(const Modular &a, U b) { return a != Modular(b); }
    template<typename U> friend bool operator!=(U a, const Modular &b) { return Modular(a) != b; }
    
    friend bool operator>(const Modular& a, const Modular& b) { return a.value > b.value; }
    template<typename U> friend bool operator>(const Modular &a, U b) { return a > Modular(b); }
    template<typename U> friend bool operator>(U a, const Modular &b) { return Modular(a) > b; }

    friend bool operator<(const Modular& a, const Modular& b) { return a.value < b.value; }
    template<typename U> friend bool operator<(const Modular &a, U b) { return a < Modular(b); }
    template<typename U> friend bool operator<(U a, const Modular &b) { return Modular(a) < b; }

    friend bool operator>=(const Modular& a, const Modular& b) { return a.value >= b.value; }
    template<typename U> friend bool operator>=(const Modular &a, U b) { return a >= Modular(b); }
    template<typename U> friend bool operator>=(U a, const Modular &b) { return Modular(a) <= b; }

    friend bool operator<=(const Modular& a, const Modular& b) { return a.value <= b.value; }
    template<typename U> friend bool operator<=(const Modular &a, U b) { return a <= Modular(b); }
    template<typename U> friend bool operator<=(U a, const Modular &b) { return Modular(a) <= b; }
    
    friend Modular operator+(const Modular &a, const Modular& b) { return Modular(a) += b; }
    template <typename U> friend Modular operator+(const Modular &a, const U& b) { return Modular(a) += Modular(b); }
    template <typename U> friend Modular operator+(const U& a, const Modular &b) { return Modular(a) += b; }

    friend Modular operator-(const Modular &a, const Modular& b) { return Modular(a) -= b; }
    template <typename U> friend Modular operator-(const Modular &a, const U& b) { return Modular(a) -= Modular(b); }
    template <typename U> friend Modular operator-(const U& a, const Modular &b) { return Modular(a) -= b; }
    
    friend Modular operator*(const Modular &a, const Modular& b) { return Modular(a) *= b; }
    template <typename U> friend Modular operator*(const Modular &a, const U& b) { return Modular(a) *= Modular(b); }
    template <typename U> friend Modular operator*(const U& a, const Modular &b) { return Modular(a) *= b; }
        
    friend Modular operator/(const Modular &a, const Modular& b) { return Modular(a) /= b; }
    template <typename U> friend Modular operator/(const Modular &a, const U& b) { return Modular(a) /= Modular(b); }
    template <typename U> friend Modular operator/(const U& a, const Modular &b) { return Modular(a) /= b; }
    
};

constexpr int MOD = 998244353;
using Mint = Modular<integral_constant<decay<decltype(MOD)>::type, MOD>>;

/**
 * x ^ k is equal the number of ordered k-tuple. For every k-tuple
 * (a1, a2, a3, ..., ak) the probability of getting it is equal
 * 1 / (m ^ d), where d is the number of distince digits.
**/
template<typename T, typename U>
T power(T n, U x) {
    assert(x >= 0);
    T res = 1;
    for (; x; x /= 2, n *= n) if (x & 1) res *= n;
    return res;
}

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<Mint>> dp(K + 2, vector<Mint>(K + 2));
    dp[0][0] = 1;

    for (int tuple = 0; tuple <= K; tuple++) {
        for (int distinct = 0; distinct <= tuple; distinct++) {
            dp[tuple + 1][distinct] += distinct * dp[tuple][distinct];
            dp[tuple + 1][distinct + 1] += (N - distinct) * dp[tuple][distinct];
        }
    }

    Mint ans = 0;

    for (int distinct = 1; distinct <= K; distinct++) {
        ans += dp[K][distinct] / power((Mint)M, distinct);
    }

    cout << ans << "\n";
    return 0;
}