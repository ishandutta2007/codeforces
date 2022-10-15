// ./f-telepanting.yml
#include <bits/stdc++.h>
using namespace std;

// Defines
#define fs first
#define sn second
#define pb push_back
#define eb emplace_back
#define mpr make_pair
#define mtp make_tuple
#define all(x) (x).begin(), (x).end()
// Basic type definitions
#if __cplusplus == 201703L // CPP17 only things
template <typename T> using opt_ref = optional<reference_wrapper<T>>; // for some templates
#endif
using ll = long long; using ull = unsigned long long; using ld = long double;
using pii = pair<int, int>; using pll = pair<long long, long long>;
#ifdef __GNUG__
// PBDS order statistic tree
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T, class comp = less<T>> using os_tree = tree<T, null_type, comp, rb_tree_tag, tree_order_statistics_node_update>;
template <typename K, typename V, class comp = less<K>> using treemap = tree<K, V, comp, rb_tree_tag, tree_order_statistics_node_update>;
// HashSet
#include <ext/pb_ds/assoc_container.hpp>
template <typename T, class Hash> using hashset = gp_hash_table<T, null_type, Hash>;
template <typename K, typename V, class Hash> using hashmap = gp_hash_table<K, V, Hash>;
const ll RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash { ll operator()(ll x) const { return x ^ RANDOM; } };
#endif
// More utilities
int SZ(string &v) { return v.length(); }
template <typename C> int SZ(C &v) { return v.size(); }
template <typename C> void UNIQUE(vector<C> &v) { sort(v.begin(), v.end()); v.resize(unique(v.begin(), v.end()) - v.begin()); }
template <typename T, typename U> void maxa(T &a, U b) { a = max(a, b); }
template <typename T, typename U> void mina(T &a, U b) { a = min(a, b); }
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

// based on Tourist modInt orz
template <typename MD> struct _ModInt {
    using T = typename decay<decltype(MD::value)>::type;
    static_assert(sizeof(T) >= 4, "size of T must be at least 32 bits");
    static_assert(sizeof(T) <= 8, "size of T must be at most 64 bits");
    static_assert(is_integral<T>::value, "T must be an integral type");
#ifdef __SIZEOF_INT128__
    using mul_t = typename conditional<sizeof(T) <= 4, int64_t, __int128>::type;
#else
    using mul_t = int64_t;
    static_assert(sizeof(T) <= 4, "int128 not available, cannot use 64-bit size of T");
#endif

    constexpr static T mod() { return MD::value; }

    template <typename U> static T normalize(const U& x) {
        T res = x;
        res %= mod();
        if (res < 0) res += mod();
        return res;
    }

    T value;
    constexpr _ModInt() : value() {}
    template <typename U> _ModInt(const U& x) { value = normalize(x); }
    const T& operator()() const { return value; }
    template <typename U> operator U() const { return static_cast<U>(value); }

    // FastPow
    template <typename U> static _ModInt pow(_ModInt x, U y) {
        _ModInt res(1);
        for (; y; y /= 2) {
            if (y & 1) res *= x;
            x *= x;
        }
        return res;
    }
    static _ModInt inv(const _ModInt &x) {
        T inv, _; extgcd(x.value, mod(), inv, _);
        return _ModInt(inv);
    }

    // Arithmetic Operators w/ _ModInt
    // Assignment operators here
    _ModInt& operator+=(const _ModInt &o) { if ((value += o.value) >= mod()) value -= mod(); return *this; }
    template <typename U> _ModInt& operator+=(const U &o) { return *this += _ModInt(o); }
    _ModInt& operator-=(const _ModInt &o) { if ((value -= o.value) < 0) value += mod(); return *this; }
    template <typename U> _ModInt& operator-=(const U &o) { return *this -= _ModInt(o); }
    _ModInt& operator++() { return *this += 1; }
    _ModInt operator++(int) { _ModInt res(*this); *this += 1; return res; }
    _ModInt& operator--() { return *this -= 1; }
    _ModInt operator--(int) { _ModInt res(*this); *this -= 1; return res; }
    _ModInt& operator*=(const _ModInt &o) { value = (mul_t)value * o.value % mod(); if (value < 0) value += mod(); return *this; } // make sure cast to mul_t!!!
    template <typename U> _ModInt& operator*=(const U &o) { return *this *= _ModInt(o); }
    _ModInt& operator/=(const _ModInt &o) { return *this *= inv(o.value); }
    template <typename U> _ModInt& operator/=(const U &o) { return *this /= _ModInt(o); }
    _ModInt operator-() const { return _ModInt(value); }
    // Other Operators
    T& operator()() { return value; }
    // Definitions of some operators
};
// Binary operators
#define OP_CMP(op) template <typename T> bool operator op(const _ModInt<T> &lhs, const _ModInt<T> &rhs) { return lhs.value op rhs.value; } \
    template <typename T, typename U> bool operator op(const _ModInt<T> &lhs, U rhs) { return lhs op _ModInt<T>(rhs); } \
    template <typename T, typename U> bool operator op(U lhs, const _ModInt<T> &rhs) { return _ModInt<T>(lhs) op rhs; }
#define OP_ARI(op) template <typename T> _ModInt<T> operator op(const _ModInt<T> &lhs, const _ModInt<T> &rhs) { return _ModInt<T>(lhs) op##= rhs; } \
    template <typename T, typename U> _ModInt<T> operator op(U lhs, const _ModInt<T> &rhs) { return _ModInt<T>(lhs) op##= rhs; } \
    template <typename T, typename U> _ModInt<T> operator op(const _ModInt<T> &lhs, U rhs) { return _ModInt<T>(lhs) op##= rhs; }
OP_CMP(==) OP_CMP(!=) OP_CMP(<) OP_CMP(>) OP_CMP(<=) OP_CMP(>=)
OP_ARI(+) OP_ARI(-) OP_ARI(*) OP_ARI(/)
#undef OP_CMP
#undef OP_ARI
template <typename T> istream& operator>>(istream& in, _ModInt<T> &o) { return in >> o(); }
template <typename T> ostream& operator<<(ostream& out, _ModInt<T> &o) { return out << o(); }

// Definitions
template <typename T, T mod> using ModInt = _ModInt<integral_constant<T, mod>>;
template <typename T> struct VarMod {
    static T value;
    static void read(istream& in) { in >> value; }
    static void set(T v0) { value = v0; }
};
template <typename T> using VarModInt = _ModInt<VarMod<T>>;

using MI = ModInt<int, 998244353>;

// Template is 1-indexed (by default).  Can be made 0-indexed by modifying Comp
// Example: update = point increment, range sum
// In the function applyUpdate, updates are applied from `v` to `to`
struct Comp {
    using Data = MI;
    const Data vdef = 0;
    void applyUpdate(Data &to, Data &v) { to += v; }
    int transformInd(int idx, int N) { return idx; }
};
template <typename Comp> struct BIT {
    using Data = typename Comp::Data; Comp C;
    int N; vector<Data> bit;
    void init(int n0) {
        N = n0;
        bit.assign(N + 1, C.vdef);
    }
    void update(int x, Data v) {
        x = C.transformInd(x, N);
        for (; x <= N; x += x & -x)
            C.applyUpdate(bit[x], v);
    }
    Data query(int x) {
        x = C.transformInd(x, N);
        Data res = C.vdef;
        for (; x; x -= x & -x)
            C.applyUpdate(res, bit[x]);
        return res;
    }
};

// template is 1-indexed
template <typename T> struct Ranks {
    vector<T> ranks;
    void init() {
        sort(ranks.begin(), ranks.end());
        ranks.resize(unique(ranks.begin(), ranks.end()) - ranks.begin());
    }
    template <typename It> void init(It st, It en) { ranks = vector<T>(st, en); init(); }
    void add(T v) { ranks.push_back(v); }
    int get(T v) { return lower_bound(ranks.begin(), ranks.end(), v) - ranks.begin() + 1; }
    int size() { return ranks.size(); }
};

const int MN = 2e5 + 1;
int N,
    X[MN], Y[MN], S[MN], xc[MN], yc[MN];
Ranks<int> rs;

MI dp[MN];
BIT<Comp> bit;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (auto i = 1; i <= N; i++) {
        cin >> X[i] >> Y[i] >> S[i];
        rs.add(X[i]);
        rs.add(Y[i]);
        rs.add(S[i]);
    }
    rs.init();
    for (auto i = 1; i <= N; i++) {
        xc[i] = rs.get(X[i]);
        yc[i] = rs.get(Y[i]);
    }

    bit.init(SZ(rs));
    fill(dp+1, dp+N+1, 1);
    for (auto i = N; i >= 1; i--) {
        dp[i] += bit.query(xc[i]);
        dp[i] -= int(S[i] == 0);

        bit.update(yc[i], dp[i]);
        bit.update(xc[i], -dp[i]);
    }

    MI ans = X[N]+1;
    for (auto i = 1; i <= N; i++) {
        ans += dp[i] * (X[i]-Y[i]);
    }
    cout << (ans) << '\n';

    return 0;
}