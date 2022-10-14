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
    template <typename U>
    explicit operator U() const { return static_cast<U>(value); }
    constexpr static Type mod() { return T::value; }

    friend Modular power(Modular n, Type x) {
        assert(x >= 0);
        Modular res = 1;
        for (; x; x /= 2, n *= n) if (x & 1) res *= n;
        return res;
    }

    friend Modular inverse(Modular n) {
        assert(n.value != 0);
        return power(n, mod() - 2);
    }

    Modular operator -() { return Modular(-value); }
    Modular& operator +=(const Modular& o) { if ((value += o.value) >= mod()) value -= mod(); return *this; }
    template <typename U> Modular& operator +=(const U& o) { return *this += Modular(o); }
    Modular& operator -=(const Modular& o) { if ((value -= o.value) < 0) value += mod(); return *this; }
    template <typename U> Modular& operator -=(const U& o) { return *this -= Modular(o); }
    Modular& operator ++() { return *this += 1; }
    Modular& operator --() { return *this -= 1; }
    Modular& operator *=(const Modular& o) { value = normalize(1ll * value * o.value); return *this; }
    template <typename U> Modular& operator *=(const U& o) { return *this *= Modular(o); }
    Modular& operator /=(const Modular &o) { return *this *= inverse(o); }
    template <typename U> Modular& operator /=(const U& o) { return *this /= Modular(o); }

    friend istream& operator >>(istream &is, Modular &x) { 
        typename common_type<Type, int64_t>::type in;
        is >> in; 
        x.value = x.normalize(in);
        return is; 
    }
    friend ostream& operator <<(ostream &os, const Modular &x) { os << x.value; return os; }

    friend bool operator ==(const Modular& a, const Modular& b) { return a.value == b.value; }
    template<typename U> friend bool operator ==(const Modular &a, U b) { return a == Modular(b); }
    template<typename U> friend bool operator ==(U a, const Modular &b) { return Modular(a) == b; }

    friend bool operator !=(const Modular& a, const Modular& b) { return a.value != b.value; }
    template<typename U> friend bool operator !=(const Modular &a, U b) { return a != Modular(b); }
    template<typename U> friend bool operator !=(U a, const Modular &b) { return Modular(a) != b; }
    
    friend bool operator >(const Modular& a, const Modular& b) { return a.value > b.value; }
    template<typename U> friend bool operator >(const Modular &a, U b) { return a > Modular(b); }
    template<typename U> friend bool operator >(U a, const Modular &b) { return Modular(a) > b; }

    friend bool operator <(const Modular& a, const Modular& b) { return a.value < b.value; }
    template<typename U> friend bool operator <(const Modular &a, U b) { return a < Modular(b); }
    template<typename U> friend bool operator <(U a, const Modular &b) { return Modular(a) < b; }

    friend bool operator >=(const Modular& a, const Modular& b) { return a.value >= b.value; }
    template<typename U> friend bool operator >=(const Modular &a, U b) { return a >= Modular(b); }
    template<typename U> friend bool operator >=(U a, const Modular &b) { return Modular(a) <= b; }

    friend bool operator <=(const Modular& a, const Modular& b) { return a.value <= b.value; }
    template<typename U> friend bool operator <=(const Modular &a, U b) { return a <= Modular(b); }
    template<typename U> friend bool operator <=(U a, const Modular &b) { return Modular(a) <= b; }
    
    friend Modular operator +(const Modular &a, const Modular& b) { return Modular(a) += b; }
    template <typename U> friend Modular operator +(const Modular &a, const U& b) { return Modular(a) += Modular(b); }
    template <typename U> friend Modular operator +(const U& a, const Modular &b) { return Modular(a) += b; }

    friend Modular operator -(const Modular &a, const Modular& b) { return Modular(a) -= b; }
    template <typename U> friend Modular operator -(const Modular &a, const U& b) { return Modular(a) -= Modular(b); }
    template <typename U> friend Modular operator -(const U& a, const Modular &b) { return Modular(a) -= b; }
    
    friend Modular operator *(const Modular &a, const Modular& b) { return Modular(a) *= b; }
    template <typename U> friend Modular operator *(const Modular &a, const U& b) { return Modular(a) *= Modular(b); }
    template <typename U> friend Modular operator *(const U& a, const Modular &b) { return Modular(a) *= b; }
        
    friend Modular operator /(const Modular &a, const Modular& b) { return Modular(a) /= b; }
    template <typename U> friend Modular operator /(const Modular &a, const U& b) { return Modular(a) /= Modular(b); }
    template <typename U> friend Modular operator /(const U& a, const Modular &b) { return Modular(a) /= b; }
    
};

constexpr int MOD = 998244353;
using Mint = Modular<integral_constant<decay<decltype(MOD)>::type, MOD>>;

struct SegmentTree {
    int N;
    vector<Mint> product; // W[tl] * W[tl + 1] * ... * W[tr]
    vector<Mint> tree; // DP[tl...tr]

    void init(vector<Mint> W) { // 1-index
        product.resize(4 * W.size());
        tree.resize(4 * W.size());
        build(1, 1, W.size() - 1, W);
        N = W.size() - 1;
    }

    void build(int n, int tl, int tr, vector<Mint>& W) {
        if (tl == tr) {
            tree[n] = product[n] = W[tl];
            return;
        }
        int mid = (tl + tr) / 2;
        build(n * 2, tl, mid, W);
        build(n * 2 + 1, mid + 1, tr, W);
        product[n] = product[n * 2] * product[n * 2 + 1];
        tree[n] = tree[n * 2] * product[n * 2 + 1] + tree[n * 2 + 1];
    }

    pair<Mint, Mint> query(int n, int tl, int tr, int le, int ri) { // {product, DP}
        if (tr < le || ri < tl || tr < tl) {
            return {1, 0};
        }
        if (le <= tl && tr <= ri) {
            return {product[n], tree[n]};
        }

        int mid = (tl + tr) / 2;
        pair<Mint, Mint> lc = query(n * 2, tl, mid, le, ri);
        pair<Mint, Mint> rc = query(n * 2 + 1, mid + 1, tr, le, ri);
        pair<Mint, Mint> res;
        res.first = lc.first * rc.first;
        res.second = lc.second * rc.first + rc.second;
        return res;
    }

    Mint query(int le, int ri) {
        return query(1, 1, N, le, ri).second;
    }

};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N, Q;
    cin >> N >> Q;
    vector<Mint> W(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> W[i];
        W[i] = 100 / W[i];
    }

    SegmentTree seg;
    seg.init(W);

    set<int> checkpoints;
    checkpoints.insert(1);
    checkpoints.insert(N + 1);
    Mint ans = seg.query(1, N);

    for (int i = 0, c; i < Q; i++) {
        cin >> c;
        if (checkpoints.count(c) == 1) {
            auto l = checkpoints.lower_bound(c); l--;
            auto r = checkpoints.upper_bound(c);
            ans += seg.query(*l, *r - 1);
            ans -= seg.query(*l, c - 1);
            ans -= seg.query(c, *r - 1);
            checkpoints.erase(c);
        } else {
            auto l = checkpoints.lower_bound(c); l--;
            auto r = checkpoints.upper_bound(c);
            ans -= seg.query(*l, *r - 1);
            ans += seg.query(*l, c - 1);
            ans += seg.query(c, *r - 1);
            checkpoints.insert(c);
        }

        cout << ans << "\n";
    }

    return 0;
}