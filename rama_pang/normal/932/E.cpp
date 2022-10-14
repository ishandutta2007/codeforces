#include <bits/stdc++.h>
using namespace std;

template<typename T, typename U>
T power(T n, U x) {
    assert(x >= 0);
    T res = 1;
    for (; x; x /= 2, n *= n) if (x & 1) res *= n;
    return res;
}

template<typename T>
T inverse(T a, T m) {
    T x = 0, y = 1;
    while (a != 0) {
        T q = m / a;
        m -= q * a; swap(a, m);
        x -= q * y; swap(x, y);
    }
    assert(m == 1);
    return x;
}

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

constexpr int MOD = 1e9 + 7;
using Mint = Modular<integral_constant<decay<decltype(MOD)>::type, MOD>>;

int main() {
    int N, K;
    cin >> N >> K;

    /* EV(size ^ K) = for all K-tuples, sum of Probability(t) */
    /* Probability(t) = 1 / (2 ^ distinct elements) */
    vector<vector<Mint>> DP(K + 2, vector<Mint>(K + 2, 0));
    DP[0][0] = 1;

    for (int tuple = 0; tuple <= K; tuple++) {
        for (int distinct = 0; distinct <= tuple; distinct++) {
            DP[tuple + 1][distinct] += distinct * DP[tuple][distinct];
            DP[tuple + 1][distinct + 1] += (N - distinct) * DP[tuple][distinct];
        }
    }

    /* Find EV(size ^ K) */
    Mint ans = 0;
    for (int distinct = 1; distinct <= K; distinct++) {
        ans += DP[K][distinct] / power((Mint)2, distinct);
    }

    /* Multiply it by number of possibilities to get sum(size ^ K) */
    ans *= power((Mint)2, N);

    cout << ans << "\n";
    return 0;
}