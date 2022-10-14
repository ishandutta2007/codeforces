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

constexpr int MOD = 998244353;
using Mint = Modular<integral_constant<decay<decltype(MOD)>::type, MOD>>;

#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target ("sse,sse2,sse3,ssse3,avx,avx2,fma,mmx,tune=native")

int N, K;
int A[1005];
Mint memo[1005][1005];
int vis[1005][1005];
int nxt[1005];

Mint dp(int a, int n, int k) { // dp_a = num of subsequence with beuaty at least k. Ans = dp_1 + dp_2 + dp_3 + ... dp_maxA
    if (k == K) {
        return 1;
    }
    if (n >= N) {
        return 0;
    }
    if (vis[n][k]) {
        return memo[n][k];
    }

    Mint& res = memo[n][k] = 0;
    vis[n][k] = 1;

    if (nxt[n] == -1) {
        nxt[n] = lower_bound(A + n + 1, A + N, A[n] + a) - A;
    }

    res += dp(a, nxt[n], k + 1);
    res += dp(a, n + 1, k);

    return res;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    sort(A, A + N); // order of elements doesn't matter

    Mint ans = 0;
    for (int val = 1; val * (K - 1) < 100005; val++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < K; j++) {
                vis[i][j] = 0;
            }
            nxt[i] = -1;
        }
        ans += dp(val, 0, 0);
    }

    cout << ans << "\n";
    return 0;
}