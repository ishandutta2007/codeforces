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

constexpr int MOD = 1e9 + 7;
using Mint = Modular<integral_constant<decay<decltype(MOD)>::type, MOD>>;

template<typename T>
class Matrix {

  private:

    vector<vector<T>> M;

  public:

    Matrix() {}

    Matrix(int n, int m) {
        M.assign(n, vector<T>(m, 0));
    }

    size_t size() {
        return M.size();
    }

    vector<T>& operator[](int i) { return M[i]; }
    const vector<T>& operator[](int i) const { return M[i]; }

    friend Matrix operator*(Matrix a, Matrix b) {
        assert(a[0].size() == b.size());
        Matrix res(a.size(), b[0].size());
        for (int i = 0; i < a.size(); i++) {
            for (int j = 0; j < b[0].size(); j++) {
                for (int k = 0; k < b.size(); k++) {
                    res[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        return res;
    }

};

Mint DP(int N, int K, int M) {
    vector<vector<vector<Mint>>> DP(N + 2, vector<vector<Mint>>(K + 2, vector<Mint>(1 << M, 0)));
    DP[0][0][0] = 1;
    
    for (int n = 0; n < N; n++) { // first n planets
        for (int k = 0; k <= K; k++) { // visited k planets
            for (int mask = 0; mask < (1 << M); mask++) { // last mask planets
                int next_mask = (mask << 1) % (1 << M);

                /* Do not visit n-th planet */
                DP[n + 1][k][next_mask] += DP[n][k][mask];

                /* Visit n-th planet, use combinatorics to count variations regarding mask */
                DP[n + 1][k + 1][next_mask ^ 1] += DP[n][k][mask] * (1 + __builtin_popcount(mask));

            }
        }
    }    

    Mint ans = 0;
    for (int mask = 0; mask < (1 << M); mask++) {
        ans += DP[N][K][mask];
    }
    return ans;
}


template<typename T>
T power(T n, long long x) {
    if (x == 1) {
        return n;
    }
    if (x & 1) {
        return n * power(n, x - 1);
    }
    T res = power(n, x / 2);
    return res * res;
}


Mint MatrixExponentiation(int N, int K, int M) {
    vector<vector<int>> name(K + 1, vector<int>(1 << M, -1));
    int cnt = 0;
    for (int k = 0; k <= K; k++) {
        for (int mask = 0; mask < (1 << M); mask++) {
            name[k][mask] = cnt++; 
        }
    }

    Matrix<Mint> Transition(cnt, cnt);
    Matrix<Mint> Base(cnt, 1);

    for (int k = 0; k <= K; k++) {
        for (int mask = 0; mask < (1 << M); mask++) {
            int next_mask = (mask << 1) % (1 << M);
            Transition[name[k][next_mask]][name[k][mask]] = 1;
            if (k < K) {
                Transition[name[k + 1][next_mask ^ 1]][name[k][mask]] = 1 + __builtin_popcount(mask);
            }
        }
    }

    Base[name[0][0]][0] = 1;

    Matrix<Mint> ans = power(Transition, N) * Base;
    Mint res = 0;

    for (int mask = 0; mask < (1 << M); mask++) {
        res += ans[name[K][mask]][0];
    }

    return res;
}

int main() {
    int N, K, M;
    cin >> N >> K >> M;

    cout << MatrixExponentiation(N, K, M) << "\n";
    return 0;
}