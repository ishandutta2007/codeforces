/**
 * Solution:
 * The maximum possible size of a good subset is when all members of the subset has exactly N/2 prime divisors. We can compute this with FFT (well, NTT) and smaller to larger trick, by setting the following as polynomials: f(x) = 1 + x + x^2 + .. + x^{cnt[j]}, for every occurence of j in prime divisors.
**/

#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int) x.size()

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

constexpr int md = 998244353;
using Mint = Modular<integral_constant<decay<decltype(md)>::type, md>>;

Mint power(Mint n, int x) {
    if (x == 0) return 1;
    if (x & 1) return n * power(n, x - 1);
    Mint res = power(n, x / 2);
    return res * res;
}

namespace FFT {
    const int MOD = (119 << 23) + 1;
    const int PRIMITIVE_ROOT = 62;
    // Also: (5 << 25 , 7 << 26, 479 << 21, 483 << 21) with same root (62)

    void genRoots(vector<Mint> &roots) {
        int n = sz(roots);
        Mint r = power(PRIMITIVE_ROOT, (MOD - 1) / n); // n-th root of unity
        roots[0] = 1;
        for (int i = 1; i < n; i++) {
            roots[i] = roots[i - 1] * r;
        }
    }

    void genRev(vector<int> &rev) {
        int n = rev.size();
        int lg = 0;
        while ((1 << lg) < n) lg++;

        for (int i = 1; i < n; i++) {
            int res = 0;
            for (int j = 0; j < lg; j++) {
                if (i & (1 << j)) {
                    res |= 1 << (lg - 1 - j);
                }
            }
            rev[i] = res;
        }
    }

    void fft(vector<int> &a, vector<Mint> &roots, vector<int> &rev, bool invert) {
        int n = a.size(); // length of polynom;
        for (int i = 0; i < n; i++) if (i < rev[i]) swap(a[i], a[rev[i]]);

        for (int len = 2; len <= n; len *= 2) {
            for (int i = 0; i < n; i += len) {
                for (int j = 0; j < len / 2; j++) {
                    int ind = n / len * j; if (invert && ind) ind = n - ind;

                    Mint u = a[i + j];
                    Mint v = a[i + j + len / 2] * roots[ind];
                    a[i + j] = (int) (u + v);
                    a[i + j + len / 2] = (int) (u - v);
                }
            }
        }

        if (invert) {
            Mint inv = Mint(1) / n;
            for (int i = 0; i < n; i++) {
                a[i] = (int) (inv * a[i]);
            }
        }
    }

    vector<int> convolution(vector<int> &a, vector<int> &b) {
        vector<int> res;
        int deg = sz(a) + sz(b) - 2;
        int len = 1;
        while (len <= deg) len *= 2;

        vector<Mint> roots(len); genRoots(roots);
        vector<int> rev(len); genRev(rev);

        a.resize(len), b.resize(len);
        fft(a, roots, rev, false), fft(b, roots, rev, false);

        res.resize(len);
        for (int i = 0; i < len; i++) res[i] = (int) ((Mint) a[i] * b[i]);
        
        fft(res, roots, rev, true);
        res.resize(deg + 1);
        return res;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N;
    cin >> N;
    map<int, int> cnt;
    for (int i = 0; i < N; i++) {
        int P;
        cin >> P;
        cnt[P]++;
    }

    auto vectorSizeSort = [&](const vector<int> &a, const vector<int> &b) {
        return a.size() > b.size();
    };

    priority_queue<vector<int>, vector<vector<int>>, decltype(vectorSizeSort)> pq(vectorSizeSort);
    for (auto &c : cnt) {
        if (c.second > 0) {
            pq.emplace(vector<int>(c.second + 1, 1)); // f(x) = 1 + x + ... + x^cnt
        }
    }

    while (pq.size() > 1) {
        vector<int> u, v;
        u = pq.top(); pq.pop();
        v = pq.top(); pq.pop();
        pq.emplace(FFT::convolution(u, v));
    }

    vector<int> res = pq.top();
    cout << res[N / 2] << "\n"; // all of numbers with the same number of factors divide each other. Maximum is at N / 2
    return 0;
}