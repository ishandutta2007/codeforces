#pragma region Macros
#if defined(noimi) && defined(_GLIBCXX_DEBUG) && defined(_GLIBCXX_DEBUG_PEDANTIC)
#pragma comment(linker, "/stack:200000000")
#include <stdc++.h>
#pragma GCC optimize("O3")
#else
#pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("popcnt")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,avx2,tune=native")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,avx2")
// #pragma GCC target("avx2")
// #include <bits/stdc++.h>
// #include <bits/stdc++.h>

#include <immintrin.h>

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cfenv>
#include <cfloat>
#include <chrono>
#include <cinttypes>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdarg>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <fstream>
#include <functional>
#include <initializer_list>
#include <iomanip>
#include <ios>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <streambuf>
#include <string>
#include <tuple>
#include <type_traits>
#endif
#include <cstdint>
#include <immintrin.h>
#include <variant>

#ifdef noimi
#define oj_local(a, b) b
#else
#define oj_local(a, b) a
#endif

#define LOCAL if(oj_local(0, 1))
#define OJ if(oj_local(1, 0))

using namespace std;
using ll = long long;
using ull = unsigned long long int;
using i128 = __int128_t;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using ld = long double;
template <typename T> using vc = vector<T>;
template <typename T> using vvc = vector<vc<T>>;
template <typename T> using vvvc = vector<vvc<T>>;
using vi = vc<int>;
using vl = vc<ll>;
using vpi = vc<pii>;
using vpl = vc<pll>;
template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
template <typename T> int si(const T &x) { return x.size(); }
template <class T, class S> inline bool chmax(T &a, const S &b) { return (a < b ? a = b, 1 : 0); }
template <class T, class S> inline bool chmin(T &a, const S &b) { return (a > b ? a = b, 1 : 0); }
vi iota(int n) {
    vi a(n);
    return iota(a.begin(), a.end(), 0), a;
}
template <typename T> vi iota(const vector<T> &a, bool greater = false) {
    vi res(a.size());
    iota(res.begin(), res.end(), 0);
    sort(res.begin(), res.end(), [&](int i, int j) {
        if(greater) return a[i] > a[j];
        return a[i] < a[j];
    });
    return res;
}

// macros
#define overload5(a, b, c, d, e, name, ...) name
#define overload4(a, b, c, d, name, ...) name
#define endl '\n'
#define REP0(n) for(ll jidlsjf = 0; jidlsjf < n; ++jidlsjf)
#define REP1(i, n) for(ll i = 0; i < (n); ++i)
#define REP2(i, a, b) for(ll i = (a); i < (b); ++i)
#define REP3(i, a, b, c) for(ll i = (a); i < (b); i += (c))
#define rep(...) overload4(__VA_ARGS__, REP3, REP2, REP1, REP0)(__VA_ARGS__)
#define per0(n) for(int jidlsjf = 0; jidlsjf < (n); ++jidlsjf)
#define per1(i, n) for(ll i = (n)-1; i >= 0; --i)
#define per2(i, a, b) for(ll i = (a)-1; i >= b; --i)
#define per3(i, a, b, c) for(ll i = (a)-1; i >= (b); i -= (c))
#define per(...) overload4(__VA_ARGS__, per3, per2, per1, per0)(__VA_ARGS__)
#define fore0(a) rep(a.size())
#define fore1(i, a) for(auto &&i : a)
#define fore2(a, b, v) for(auto &&[a, b] : v)
#define fore3(a, b, c, v) for(auto &&[a, b, c] : v)
#define fore4(a, b, c, d, v) for(auto &&[a, b, c, d] : v)
#define fore(...) overload5(__VA_ARGS__, fore4, fore3, fore2, fore1, fore0)(__VA_ARGS__)
#define fi first
#define se second
#define pb push_back
#define ppb pop_back
#define ppf pop_front
#define eb emplace_back
#define drop(s) cout << #s << endl, exit(0)
#define si(c) (int)(c).size()
#define lb(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define ub(c, x) distance((c).begin(), upper_bound(all(c), (x)))
#define rng(v, l, r) v.begin() + (l), v.begin() + (r)
#define all(c) begin(c), end(c)
#define rall(c) rbegin(c), rend(c)
#define SORT(v) sort(all(v))
#define REV(v) reverse(all(v))
#define UNIQUE(x) SORT(x), x.erase(unique(all(x)), x.end())
template <typename T = ll, typename S> T SUM(const S &v) { return accumulate(all(v), T(0)); }
#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))
#define overload2(_1, _2, name, ...) name
#define vec(type, name, ...) vector<type> name(__VA_ARGS__)
#define vv(type, name, h, ...) vector<vector<type>> name(h, vector<type>(__VA_ARGS__))
#define vvv(type, name, h, w, ...) vector<vector<vector<type>>> name(h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))
#define vvvv(type, name, a, b, c, ...)                                                                                                                         \
    vector<vector<vector<vector<type>>>> name(a, vector<vector<vector<type>>>(b, vector<vector<type>>(c, vector<type>(__VA_ARGS__))))
constexpr pii dx4[4] = {pii{1, 0}, pii{0, 1}, pii{-1, 0}, pii{0, -1}};
constexpr pii dx8[8] = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};

namespace yesno_impl {
const string YESNO[2] = {"NO", "YES"};
const string YesNo[2] = {"No", "Yes"};
const string yesno[2] = {"no", "yes"};
const string firstsecond[2] = {"second", "first"};
const string FirstSecond[2] = {"Second", "First"};
const string possiblestr[2] = {"impossible", "possible"};
const string Possiblestr[2] = {"Impossible", "Possible"};
void YES(bool t = 1) { cout << YESNO[t] << endl; }
void NO(bool t = 1) { YES(!t); }
void Yes(bool t = 1) { cout << YesNo[t] << endl; }
void No(bool t = 1) { Yes(!t); }
void yes(bool t = 1) { cout << yesno[t] << endl; }
void no(bool t = 1) { yes(!t); }
void first(bool t = 1) { cout << firstsecond[t] << endl; }
void First(bool t = 1) { cout << FirstSecond[t] << endl; }
void possible(bool t = 1) { cout << possiblestr[t] << endl; }
void Possible(bool t = 1) { cout << Possiblestr[t] << endl; }
}; // namespace yesno_impl
using namespace yesno_impl;

#define INT(...)                                                                                                                                               \
    int __VA_ARGS__;                                                                                                                                           \
    IN(__VA_ARGS__)
#define LL(...)                                                                                                                                                \
    ll __VA_ARGS__;                                                                                                                                            \
    IN(__VA_ARGS__)
#define STR(...)                                                                                                                                               \
    string __VA_ARGS__;                                                                                                                                        \
    IN(__VA_ARGS__)
#define CHR(...)                                                                                                                                               \
    char __VA_ARGS__;                                                                                                                                          \
    IN(__VA_ARGS__)
#define DBL(...)                                                                                                                                               \
    double __VA_ARGS__;                                                                                                                                        \
    IN(__VA_ARGS__)
#define VEC(type, name, size)                                                                                                                                  \
    vector<type> name(size);                                                                                                                                   \
    IN(name)
#define VEC2(type, name1, name2, size)                                                                                                                         \
    vector<type> name1(size), name2(size);                                                                                                                     \
    for(int i = 0; i < size; i++) IN(name1[i], name2[i])
#define VEC3(type, name1, name2, name3, size)                                                                                                                  \
    vector<type> name1(size), name2(size), name3(size);                                                                                                        \
    for(int i = 0; i < size; i++) IN(name1[i], name2[i], name3[i])
#define VEC4(type, name1, name2, name3, name4, size)                                                                                                           \
    vector<type> name1(size), name2(size), name3(size), name4(size);                                                                                           \
    for(int i = 0; i < size; i++) IN(name1[i], name2[i], name3[i], name4[i]);
#define VV(type, name, h, w)                                                                                                                                   \
    vector<vector<type>> name(h, vector<type>(w));                                                                                                             \
    IN(name)
int scan() { return getchar(); }
void scan(int &a) { cin >> a; }
void scan(long long &a) { cin >> a; }
void scan(char &a) { cin >> a; }
void scan(double &a) { cin >> a; }
void scan(string &a) { cin >> a; }
template <class T, class S> void scan(pair<T, S> &p) { scan(p.first), scan(p.second); }
template <class T> void scan(vector<T> &);
template <class T> void scan(vector<T> &a) {
    for(auto &i : a) scan(i);
}
template <class T> void scan(T &a) { cin >> a; }
void IN() {}
template <class Head, class... Tail> void IN(Head &head, Tail &...tail) {
    scan(head);
    IN(tail...);
}

template <typename T, typename S> T ceil(T x, S y) {
    assert(y);
    return (y < 0 ? ceil(-x, -y) : (x > 0 ? (x + y - 1) / y : x / y));
}

template <typename T, typename S> T floor(T x, S y) {
    assert(y);
    return (y < 0 ? floor(-x, -y) : (x > 0 ? x / y : x / y - (x % y == 0 ? 0 : 1)));
}
template <class T> T POW(T x, int n) {
    T res = 1;
    for(; n; n >>= 1, x *= x)
        if(n & 1) res *= x;
    return res;
}
template <class T, class S> T POW(T x, S n, const ll &mod) {
    T res = 1;
    x %= mod;
    for(; n; n >>= 1, x = x * x % mod)
        if(n & 1) res = res * x % mod;
    return res;
}
vector<pll> factor(ll x) {
    vector<pll> ans;
    for(ll i = 2; i * i <= x; i++)
        if(x % i == 0) {
            ans.push_back({i, 1});
            while((x /= i) % i == 0) ans.back().second++;
        }
    if(x != 1) ans.push_back({x, 1});
    return ans;
}
template <class T> vector<T> divisor(T x) {
    vector<T> ans;
    for(T i = 1; i * i <= x; i++)
        if(x % i == 0) {
            ans.pb(i);
            if(i * i != x) ans.pb(x / i);
        }
    return ans;
}
template <typename T> void zip(vector<T> &x) {
    vector<T> y = x;
    UNIQUE(y);
    for(int i = 0; i < x.size(); ++i) { x[i] = lb(y, x[i]); }
}
template <class S> void fold_in(vector<S> &v) {}
template <typename Head, typename... Tail, class S> void fold_in(vector<S> &v, Head &&a, Tail &&...tail) {
    for(auto e : a) v.emplace_back(e);
    fold_in(v, tail...);
}
template <class S> void renumber(vector<S> &v) {}
template <typename Head, typename... Tail, class S> void renumber(vector<S> &v, Head &&a, Tail &&...tail) {
    for(auto &&e : a) e = lb(v, e);
    renumber(v, tail...);
}
template <class S, class... Args> vector<S> zip(vector<S> &head, Args &&...args) {
    vector<S> v;
    fold_in(v, head, args...);
    sort(all(v)), v.erase(unique(all(v)), v.end());
    renumber(v, head, args...);
    return v;
}
template <typename T> vector<T> RUI(const vector<T> &v) {
    vector<T> res(v.size() + 1);
    for(int i = 0; i < v.size(); i++) res[i + 1] = res[i] + v[i];
    return res;
}
template <typename T> void zeta_subset(vector<T> &f) {
    int n = f.size();
    for(int i = 1; i < n; i <<= 1) rep(b, n) if(!(i & b)) f[b] += f[b | i];
}
template <typename T> void zeta_superset(vector<T> &f) {
    int n = f.size();
    for(int i = 1; i < n; i <<= 1) rep(b, n) if(!(i & b)) f[b | i] += f[b];
}
template <typename T> void mobius_subset(vector<T> &f) {
    int n = f.size();
    for(int i = 1; i < n; i <<= 1) rep(b, n) if(!(i & b)) f[b] -= f[b | i];
}
template <typename T> void mobius_superset(vector<T> &f) {
    int n = f.size();
    for(int i = 1; i < n; i <<= 1) rep(b, n) if(!(i & b)) f[b | i] -= f[b];
}
//  90 
template <typename T> void rot(vector<vector<T>> &v) {
    if(empty(v)) return;
    int n = v.size(), m = v[0].size();
    vector res(m, vector<T>(n));
    rep(i, n) rep(j, m) res[m - 1 - j][i] = v[i][j];
    v.swap(res);
}
// x in [l, r)
template <class T, class S> bool inc(const T &x, const S &l, const S &r) { return l <= x and x < r; }

// 
constexpr ll ten(int n) { return n == 0 ? 1 : ten(n - 1) * 10; }
constexpr ll tri(ll n) { return n * (n + 1) / 2; }
// l + ... + r
constexpr ll tri(ll l, ll r) { return (l + r) * (r - l + 1) / 2; }
ll max(int x, ll y) { return max((ll)x, y); }
ll max(ll x, int y) { return max(x, (ll)y); }
int min(int x, ll y) { return min((ll)x, y); }
int min(ll x, int y) { return min(x, (ll)y); }
// bit 
ll pow2(int i) { return 1LL << i; }
int topbit(signed t) { return t == 0 ? -1 : 31 - __builtin_clz(t); }
int topbit(ll t) { return t == 0 ? -1 : 63 - __builtin_clzll(t); }
int lowbit(signed a) { return a == 0 ? 32 : __builtin_ctz(a); }
int lowbit(ll a) { return a == 0 ? 64 : __builtin_ctzll(a); }
// int allbit(int n) { return (1 << n) - 1; }
constexpr ll mask(int n) { return (1LL << n) - 1; }
// int popcount(signed t) { return __builtin_popcount(t); }
// int popcount(ll t) { return __builtin_popcountll(t); }
int popcount(uint64_t t) { return __builtin_popcountll(t); }
static inline uint64_t popcount64(uint64_t x) {
    uint64_t m1 = 0x5555555555555555ll;
    uint64_t m2 = 0x3333333333333333ll;
    uint64_t m4 = 0x0F0F0F0F0F0F0F0Fll;
    uint64_t h01 = 0x0101010101010101ll;

    x -= (x >> 1) & m1;
    x = (x & m2) + ((x >> 2) & m2);
    x = (x + (x >> 4)) & m4;

    return (x * h01) >> 56;
}
bool ispow2(int i) { return i && (i & -i) == i; }

ll rnd(ll l, ll r) { //[l, r)
#ifdef noimi
    static mt19937_64 gen;
#else
    static mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
#endif
    return uniform_int_distribution<ll>(l, r - 1)(gen);
}
ll rnd(ll n) { return rnd(0, n); }

template <class t> void random_shuffle(vc<t> &a) { rep(i, si(a)) swap(a[i], a[rnd(0, i + 1)]); }

int in() {
    int x;
    cin >> x;
    return x;
}
ll lin() {
    unsigned long long x;
    cin >> x;
    return x;
}

template <class T, class S> pair<T, S> operator-(const pair<T, S> &x) { return pair<T, S>(-x.first, -x.second); }
template <class T, class S> pair<T, S> operator-(const pair<T, S> &x, const pair<T, S> &y) { return pair<T, S>(x.fi - y.fi, x.se - y.se); }
template <class T, class S> pair<T, S> operator+(const pair<T, S> &x, const pair<T, S> &y) { return pair<T, S>(x.fi + y.fi, x.se + y.se); }
template <class T> pair<T, T> operator&(const pair<T, T> &l, const pair<T, T> &r) { return pair<T, T>(max(l.fi, r.fi), min(l.se, r.se)); }
template <class T, class S> pair<T, S> operator+=(pair<T, S> &l, const pair<T, S> &r) { return l = l + r; }
template <class T, class S> pair<T, S> operator-=(pair<T, S> &l, const pair<T, S> &r) { return l = l - r; }
template <class T> bool intersect(const pair<T, T> &l, const pair<T, T> &r) { return (l.se < r.se ? r.fi < l.se : l.fi < r.se); }

template <typename T> struct edge {
    int from, to;
    T cost;
    int id;
    edge(int to, T cost) : from(-1), to(to), cost(cost) {}
    edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}
    edge(int from, int to, T cost, int id) : from(from), to(to), cost(cost), id(id) {}
    constexpr bool operator<(const edge<T> &rhs) const noexcept { return cost < rhs.cost; }
    edge &operator=(const int &x) {
        to = x;
        return *this;
    }
    operator int() const { return to; }
    friend ostream operator<<(ostream &os, edge &e) { return os << e.to; }
};
template <typename T> using Edges = vector<edge<T>>;

using Tree = vector<vector<int>>;
using Graph = vector<vector<int>>;
template <class T> using Wgraph = vector<vector<edge<T>>>;
Graph getG(int n, int m = -1, bool directed = false, int margin = 1) {
    Tree res(n);
    if(m == -1) m = n - 1;
    while(m--) {
        int a, b;
        cin >> a >> b;
        a -= margin, b -= margin;
        res[a].emplace_back(b);
        if(!directed) res[b].emplace_back(a);
    }
    return res;
}
Graph getTreeFromPar(int n, int margin = 1) {
    Graph res(n);
    for(int i = 1; i < n; i++) {
        int a;
        cin >> a;
        res[a - margin].emplace_back(i);
    }
    return res;
}
template <class T> Wgraph<T> getWg(int n, int m = -1, bool directed = false, int margin = 1) {
    Wgraph<T> res(n);
    if(m == -1) m = n - 1;
    while(m--) {
        int a, b;
        T c;
        scan(a), scan(b), scan(c);
        a -= margin, b -= margin;
        res[a].emplace_back(b, c);
        if(!directed) res[b].emplace_back(a, c);
    }
    return res;
}
void add(Graph &G, int x, int y) { G[x].eb(y), G[y].eb(x); }
template <class S, class T> void add(Wgraph<S> &G, int x, int y, T c) { G[x].eb(y, c), G[y].eb(x, c); }

#define TEST                                                                                                                                                   \
    INT(testcases);                                                                                                                                            \
    while(testcases--)

i128 abs(const i128 &x) { return x > 0 ? x : -x; }
istream &operator>>(istream &is, i128 &v) {
    string s;
    is >> s;
    v = 0;
    for(int i = 0; i < (int)s.size(); i++) {
        if(isdigit(s[i])) { v = v * 10 + s[i] - '0'; }
    }
    if(s[0] == '-') { v *= -1; }
    return is;
}

ostream &operator<<(ostream &os, const i128 &v) {
    if(v == 0) { return (os << "0"); }
    i128 num = v;
    if(v < 0) {
        os << '-';
        num = -num;
    }
    string s;
    for(; num > 0; num /= 10) { s.push_back((char)(num % 10) + '0'); }
    reverse(s.begin(), s.end());
    return (os << s);
}
namespace aux {
template <typename T, unsigned N, unsigned L> struct tp {
    static void output(std::ostream &os, const T &v) {
        os << std::get<N>(v) << (&os == &cerr ? ", " : " ");
        tp<T, N + 1, L>::output(os, v);
    }
};
template <typename T, unsigned N> struct tp<T, N, N> {
    static void output(std::ostream &os, const T &v) { os << std::get<N>(v); }
};
} // namespace aux
template <typename... Ts> std::ostream &operator<<(std::ostream &os, const std::tuple<Ts...> &t) {
    if(&os == &cerr) { os << '('; }
    aux::tp<std::tuple<Ts...>, 0, sizeof...(Ts) - 1>::output(os, t);
    if(&os == &cerr) { os << ')'; }
    return os;
}
template <class T, class S> ostream &operator<<(ostream &os, const pair<T, S> &p) {
    if(&os == &cerr) { return os << "(" << p.first << ", " << p.second << ")"; }
    return os << p.first << " " << p.second;
}
template <class Ch, class Tr, class Container> std::basic_ostream<Ch, Tr> &operator<<(std::basic_ostream<Ch, Tr> &os, const Container &x) {
    bool f = true;
    if(&os == &cerr) os << "[";
    for(auto &y : x) {
        if(&os == &cerr)
            os << (f ? "" : ", ") << y;
        else
            os << (f ? "" : " ") << y;
        f = false;
    }
    if(&os == &cerr) os << "]";
    return os;
}

#ifdef noimi
#undef endl
void debug() { cerr << endl; }
void debug(bool) { cerr << endl; }
template <class Head, class... Tail> void debug(bool is_front, Head head, Tail... tail) {
    if(!is_front) cerr << ", ";
    cerr << head;
    debug(false, tail...);
}

#define dump(args...)                                                                                                                                          \
    {                                                                                                                                                          \
        vector<string> _debug = _split(#args, ',');                                                                                                            \
        err(true, begin(_debug), args);                                                                                                                        \
    }

vector<string> _split(const string &s, char c) {
    vector<string> v;
    stringstream ss(s);
    string x;
    while(getline(ss, x, c)) {
        if(empty(v))
            v.eb(x);
        else {
            bool flag = false;
            for(auto [c, d] : {pair('(', ')'), pair('[', ']'), pair('{', '}')}) {
                if(count(all(v.back()), c) != count(all(v.back()), d)) flag = true;
            }
            if(flag)
                v.back() += "," + x;
            else
                v.eb(x);
        }
    }
    return move(v);
}

void err(bool, vector<string>::iterator) { cerr << endl; }
template <typename T, typename... Args> void err(bool is_front, vector<string>::iterator it, T a, Args... args) {
    if(!is_front) cerr << ", ";
    cerr << it->substr((*it)[0] == ' ', (*it).size()) << " = " << a, err(false, ++it, args...);
}

// #define dump(...) cerr << #__VA_ARGS__ << " : ", debug(true, __VA_ARGS__)
#else
#define dump(...) static_cast<void>(0)
#define dbg(...) static_cast<void>(0)
#endif
void OUT() { cout << endl; }
template <class Head, class... Tail> void OUT(const Head &head, const Tail &...tail) {
    cout << head;
    if(sizeof...(tail)) cout << ' ';
    OUT(tail...);
}

template <typename T> static constexpr T inf = numeric_limits<T>::max() / 2;
template <class T, class S> constexpr pair<T, S> inf<pair<T, S>> = {inf<T>, inf<S>};

template <class F> struct REC {
    F f;
    REC(F &&f_) : f(std::forward<F>(f_)) {}
    template <class... Args> auto operator()(Args &&...args) const { return f(*this, std::forward<Args>(args)...); }
};

template <class S> vector<pair<S, int>> runLength(const vector<S> &v) {
    vector<pair<S, int>> res;
    for(auto &e : v) {
        if(res.empty() or res.back().fi != e)
            res.eb(e, 1);
        else
            res.back().se++;
    }
    return res;
}
vector<pair<char, int>> runLength(const string &v) {
    vector<pair<char, int>> res;
    for(auto &e : v) {
        if(res.empty() or res.back().fi != e)
            res.eb(e, 1);
        else
            res.back().se++;
    }
    return res;
}

int toint(const char &c, const char start = 'a') { return c - start; }
int toint(const char &c, const string &chars) { return find(all(chars), c) - begin(chars); }
int alphabets_to_int(const char &c) { return (islower(c) ? c - 'a' : c - 'A' + 26); }
template <typename T> auto toint(const T &v, const char &start = 'a') {
    vector<decltype(toint(v[0]))> ret;
    ret.reserve(v.size());
    for(auto &&e : v) ret.emplace_back(toint(e, start));
    return ret;
}
template <typename T> auto toint(const T &v, const string &start) {
    vector<decltype(toint(v[0]))> ret;
    ret.reserve(v.size());
    for(auto &&e : v) ret.emplace_back(toint(e, start));
    return ret;
}
// a -> 0, A -> 26
template <typename T> auto alphabets_to_int(const T &s) {
    vector<decltype(alphabets_to_int(s[0]))> res;
    res.reserve(s.size());
    for(auto &&e : s) { res.emplace_back(alphabets_to_int(e)); }
    return res;
}

template <class T, class F> T bin_search(T ok, T ng, const F &f) {
    while(abs(ok - ng) > 1) {
        T mid = ok + ng >> 1;
        (f(mid) ? ok : ng) = mid;
    }
    return ok;
}
template <class T, class F> T bin_search_double(T ok, T ng, const F &f, int iter = 80) {
    while(iter--) {
        T mid = (ok + ng) / 2;
        (f(mid) ? ok : ng) = mid;
    }
    return ok;
}

struct Setup_io {
    Setup_io() {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        cout << fixed << setprecision(11);
    }
} setup_io;

#pragma endregion

int main() {
    TEST {
        INT(n);
        vi ans(n);
        rep(i, n) ans[i] = i + 1;
        if(~n & 1) {
            rep(i, 0, n - 2, 2) { swap(ans[i], ans[i + 1]); }
            OUT(ans);
        } else {
            rep(i, 1, n - 2, 2) swap(ans[i], ans[i + 1]);
            OUT(ans);
        }
    }
}