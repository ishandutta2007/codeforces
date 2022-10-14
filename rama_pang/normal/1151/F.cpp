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

struct Matrix {
    vector<vector<Mint>> M;
    
    Matrix(int n, int m) {
        M.assign(n, vector<Mint>(m, 0));
    }

    vector<Mint>& operator[](int i) { return M[i]; }
    const vector<Mint>& operator[](int i) const { return M[i]; }

    friend Matrix operator*(Matrix a, Matrix b) {
        int i = a.M.size();
        int j = b.M[0].size();
        assert(a.M[0].size() == b.M.size());
        int k = a.M[0].size();

        Matrix res(i, j);
        
        for (int ii = 0; ii < i; ii++) {
            for (int jj = 0; jj < j; jj++) {
                for (int kk = 0; kk < k; kk++) {
                    res[ii][jj] += a[ii][kk] * b[kk][jj];
                }
            }
        }

        return res;
    }

};


template<typename T>
T power(T n, int x) {
    if (x == 1) {
        return n;
    }
    if (x <= 5 || x % 2 == 1) {
        return n * power(n, x - 1);
    }
    T res = power(n, x / 2);
    return res * res;
}


int N, K;
int cnt; // number of zeroes

Mint dp(int op, int zero) { // operations left, and number of zeroes in prefix of size cnt
    if (zero < 0 || zero > cnt) {
        return 0;
    }
    if (op == 0) {
        if (zero == cnt) {
            return 1;
        } else {
            return 0;
        }
    }

    Mint pref0 = zero;
    Mint pref1 = cnt - zero;
    Mint suff0 = cnt - zero;
    Mint suff1 = N - 2 * cnt + zero;
    
    Mint res = 0;
    res += pref1 * suff0 * dp(op - 1, zero + 1);
    res += pref0 * suff1 * dp(op - 1, zero - 1);
    Mint other = N * ( N - 1) / 2;
    other -= pref1 * suff0;
    other -= pref0 * suff1;
    res += other * dp(op - 1, zero);
    return res;
}

/*
    dp(0)
    dp(1)
    dp(2)
    
    dp(0) * other + dp(1) * stuff
    dp(1) * other + dp(0) * stuff + dp(2) * stuff
    dp(2) * other + dp(1) * stuff

    other   stuff
    stuff   other   stuff
            stuff   other

*/

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        if (A[i] == 0) {
            cnt++;
        }
    }
    int pref = 0;
    for (int i = 0; i < cnt; i++) {
        if (A[i] == 0) {
            pref++;
        }
    }

    Matrix DP(cnt + 1, 1);
    DP[pref][0] = 1;

    Matrix Transition(cnt + 1, cnt + 1); // DP Transition
    for (int zero = 0; zero <= cnt; zero++) {
        Mint pref0 = zero;
        Mint pref1 = cnt - zero;
        Mint suff0 = cnt - zero;
        Mint suff1 = N - 2 * cnt + zero;
        Mint other = N * ( N - 1) / 2;
        other -= pref1 * suff0;
        other -= pref0 * suff1;

        Transition[zero][zero] = other;
        if (zero - 1 >= 0) {
            Transition[zero - 1][zero] = pref0 * suff1;
        }
        if (zero + 1 <= cnt) {
            Transition[zero + 1][zero] = pref1 * suff0;
        }
    }

    DP = power(Transition, K) * DP; // After K transitions
    Mint all = power((Mint)N * (N - 1) / 2, K); // all possibilities

    cout << (DP[cnt][0] / all) << "\n";
    return 0;
}