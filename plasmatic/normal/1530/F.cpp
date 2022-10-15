// ./f-bingo.yml
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

/*
 * ax + by = gcd(a, b)
 *
 * we know
 * bx' + (a%b)y' = gcd(a, b)
 *
 * bx' + (a-b*(a//b))y' = gcd(a, b)
 * bx' + ay' - b*(a//b)y' = gcd(a, b)
 * ay' + b(x' - (a//b)y') = gcd(a, b)
 */
template <typename T> T extgcd(T a, T b, T &x, T &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    T x0, y0, res = extgcd(b, a%b, x0, y0);
    x = y0;
    y = x0 - (a / b) * y0;
    return res;
}
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

#define popcount __builtin_popcount

// using MI = double;
using MI = ModInt<int, 31607>;

const int MN = 21;
int N;
MI P[MN][MN], IP[MN][MN];

MI co(int k) { return (k & 1) ? 1 : -1; }

const MI P1 = (MI)1, N1 = (MI)-1;

const int MV = 1e4 + 1;
MI inv[MV];
int mark[MN][MN];

MI colp[MN], initp = 1;
inline void markcell(int r, int c) {
    if (mark[r][c] == 0) {
        colp[c] *= IP[r][c];
        initp *= P[r][c];
    }
    mark[r][c]++;
}
inline void unmarkcell(int r, int c) {
    if (mark[r][c] == 1) {
        colp[c] *= P[r][c];
        initp *= IP[r][c];
    }
    mark[r][c]--;
}

MI ans = 0;
void rec(int cur, int cnt) {
    if (cur == N+2) {
        MI acc = colp[0]-1;
        for (auto l = 1; l < N; l++) {
            acc -= colp[l] * acc;
        }

        ans += initp * acc * co(cnt+1);

        return;
    }

    if (cur == 0) {
        rec(cur+1, cnt);

        for (auto i = 0; i < N; i++)
            markcell(i, i);

        rec(cur+1, cnt+1);

        for (auto i = 0; i < N; i++)
            unmarkcell(i, i);
    }
    else if (cur == 1) {
        rec(cur+1, cnt);

        for (auto i = 0; i < N; i++)
            markcell(i, N-i-1);

        rec(cur+1, cnt+1);

        for (auto i = 0; i < N; i++)
            unmarkcell(i, N-i-1);
    }
    else {
        int r = cur-2;

        rec(cur+1, cnt);

        for (auto i = 0; i < N; i++)
            markcell(r, i);

        rec(cur+1, cnt+1);

        for (auto i = 0; i < N; i++)
            unmarkcell(r, i);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    fill(colp, colp+N, P1);
    for (auto i = 0; i < N; i++)
        for (auto j = 0; j < N; j++) {
            cin >> P[i][j];
            P[i][j] /= 10000;
            IP[i][j] = 1 / P[i][j];
            colp[j] *= P[i][j];
        }
    
    rec(0, 0);

    int msub = 1<<N;
    // Brute force
    // for (auto i = 0; i < 4; i++) { 
    //     for (auto j = 0; j < msub; j++) {
    //         MI sumc = 0;
    //         for (auto k = 0; k < msub; k++) {
    //             if (!i && !j && !k) continue;
    //             MI cco = co(popcount(i) + popcount(j) + popcount(k));
    //
    //             vector<vector<bool>> mark(N, vector<bool>(N));
    //             if (i & 1)
    //                 for (auto l = 0; l < N; l++)
    //                     mark[l][l] = true;
    //             if (i & 2)
    //                 for (auto l = 0; l < N; l++)
    //                     mark[l][N-l-1] = true;
    //             for (auto l = 0; l < N; l++) {
    //                 if ((j >> l) & 1)
    //                     for (auto m = 0; m < N; m++)
    //                         mark[l][m] = true;
    //             }
    //             for (auto l = 0; l < N; l++) {
    //                 if ((k >> l) & 1)
    //                     for (auto m = 0; m < N; m++)
    //                         mark[m][l] = true;
    //             }
    //
    //             MI pro = 1;
    //             for (auto l = 0; l < N; l++)
    //                 for (auto m = 0; m < N; m++)
    //                     if (mark[l][m])
    //                         pro *= P[l][m];
    //             // ans += cco * pro;
    //
    //             sumc += cco * pro;
    //         }
    //         cout<<"i="<<(i)<<", "; cout<<"j="<<(j)<<", "; cout<<"sumc="<<(sumc)<<", "; cout << endl; // db i,j,sumc
    //     }
    // }

    cout << (P1+ans)() << '\n';

    return 0;
}