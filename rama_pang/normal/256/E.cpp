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

constexpr int MOD = 777777777;
using Mint = Modular<integral_constant<decay<decltype(MOD)>::type, MOD>>;

array<array<int, 4>, 4> W;

struct SegmentTree {
    struct Node {
        array<array<Mint, 4>, 4> M; // M[i][j] the number of ways of choosing i as the first element and j as the last element

        Node() {
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    M[i][j] = 0;
                }
            }
        }

        array<Mint, 4>& operator[](int i) {
            return M[i];
        }

        const array<Mint, 4>& operator[](int i) const {
            return M[i];
        }

        Node merge(Node a, Node b) {
            Node res;
            for (int i = 1; i < 4; i++) {
                for (int j = 1; j < 4; j++) {
                    for (int k = 1; k < 4; k++) {
                        for (int l = 1; l < 4; l++) {
                            if (W[k][l] == 1) {
                                res[i][j] += a[i][k] * b[l][j];
                            }
                        }
                    }
                }
            }
            return res;
        }
    };

    int N;
    vector<Node> tree;

    void init(int n) {
        N = n;
        tree.resize(4 * n);
        build(1, 0, n - 1);
    }

    void build(int n, int tl, int tr) {
        if (tl == tr) {
            for (int i = 1; i < 4; i++) {
                tree[n][i][i] = 1;
            }
            return;
        }
        int mid = (tl + tr) / 2;
        build(n * 2, tl, mid);
        build(n * 2 + 1, mid + 1, tr);
        tree[n] = tree[n].merge(tree[n * 2], tree[n * 2 + 1]);
    }

    void update(int n, int tl, int tr, int p, int x) {
        if (tl == tr) {
            for (int i = 1; i < 4; i++) {
                tree[n][i][i] = (x == 0);
            }
            tree[n][x][x] = 1;
            return;
        }
        int mid = (tl + tr) / 2;
        if (p <= mid) {
            update(n * 2, tl, mid, p, x);
        } else {
            update(n * 2 + 1, mid + 1, tr, p, x);
        }
        tree[n] = tree[n].merge(tree[n * 2], tree[n * 2 + 1]);
    }

    void update(int p, int x) {
        return update(1, 0, N - 1, p, x);
    }

    Mint query() {
        Mint ans = 0;
        for (int i = 1; i < 4; i++) {
            for (int j = 1; j < 4; j++) {
                ans += tree[1][i][j];
            }
        }
        return ans;
    }
};

SegmentTree seg;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            cin >> W[i][j];
        }
    }

    seg.init(N);

    for (int i = 0; i < M; i++) {
        int p, x;
        cin >> p >> x;
        p--;
        seg.update(p, x);
        cout << seg.query() << "\n";
    }
    return 0;
}