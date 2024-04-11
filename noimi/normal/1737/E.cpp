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

namespace modular {
constexpr ll MOD = 1000000007;
const int MAXN = 11000000;
template <ll Modulus> class modint;
#define mint modint<MOD>
#define vmint vector<mint>
vector<mint> Inv;
mint inv(int x);
template <ll Modulus> class modint {

  public:
    static constexpr int mod() { return Modulus; }
    ll a;

    constexpr modint(const ll x = 0) noexcept : a(((x % Modulus) + Modulus) % Modulus) {}
    constexpr ll &value() noexcept { return a; }
    constexpr const ll &value() const noexcept { return a; }
    constexpr modint operator-() const noexcept { return modint() - *this; }
    constexpr modint operator+() const noexcept { return *this; }
    constexpr modint &operator++() noexcept {
        if(++a == MOD) a = 0;
        return *this;
    }
    constexpr modint &operator--() noexcept {
        if(!a) a = MOD;
        a--;
        return *this;
    }
    constexpr modint operator++(int) {
        modint res = *this;
        ++*this;
        return res;
    }
    constexpr modint operator--(int) {
        mint res = *this;
        --*this;
        return res;
    }
    constexpr modint &operator+=(const modint rhs) noexcept {
        a += rhs.a;
        if(a >= Modulus) { a -= Modulus; }
        return *this;
    }
    constexpr modint &operator-=(const modint rhs) noexcept {
        if(a < rhs.a) { a += Modulus; }
        a -= rhs.a;
        return *this;
    }
    constexpr modint &operator*=(const modint rhs) noexcept {
        a = a * rhs.a % Modulus;
        return *this;
    }
    constexpr modint &operator/=(const modint rhs) noexcept {
        a = a * (modular::inv(rhs.a)).a % Modulus;
        return *this;
    }
    constexpr modint pow(long long n) const noexcept {
        if(n < 0) {
            n %= Modulus - 1;
            n = (Modulus - 1) + n;
        }
        modint x = *this, r = 1;
        while(n) {
            if(n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }
    constexpr modint inv() const noexcept { return pow(Modulus - 2); }
    constexpr friend modint operator+(const modint &lhs, const modint &rhs) { return modint(lhs) += modint(rhs); }
    constexpr friend modint operator-(const modint &lhs, const modint &rhs) { return modint(lhs) -= modint(rhs); }
    constexpr friend modint operator*(const modint &lhs, const modint &rhs) { return modint(lhs) *= modint(rhs); }
    constexpr friend modint operator/(const modint &lhs, const modint &rhs) { return modint(lhs) /= modint(rhs); }
    constexpr friend modint operator==(const modint &lhs, const modint &rhs) { return lhs.a == rhs.a; }
    constexpr friend modint operator!=(const modint &lhs, const modint &rhs) { return lhs.a != rhs.a; }
    // constexpr friend modint operator^=(const modint &lhs, const modint &rhs) { return modint(lhs) ^= modint(rhs); }
};
vmint Fact{1, 1}, Ifact{1, 1};
mint inv(int n) {
    if(n > MAXN) return (mint(n)).pow(MOD - 2);
    if(Inv.empty()) Inv.emplace_back(0), Inv.emplace_back(1);
    if(Inv.size() > n)
        return Inv[n];
    else {
        for(int i = Inv.size(); i <= n; ++i) {
            auto [y, x] = div(int(MOD), i);
            Inv.emplace_back(Inv[x] * (-y));
        }
        return Inv[n];
    }
}
mint fact(int n) {
    if(Fact.size() > n)
        return Fact[n];
    else
        for(int i = Fact.size(); i <= n; ++i) Fact.emplace_back(Fact[i - 1] * i);
    return Fact[n];
}
mint ifact(int n) {
    if(Ifact.size() > n)
        return Ifact[n];
    else
        for(int i = Ifact.size(); i <= n; ++i) Ifact.emplace_back(Ifact[i - 1] * inv(i));
    return Ifact[n];
}
mint modpow(ll a, ll n) { return mint(a).pow(n); }
mint inv(mint a) { return inv(a.a); }
mint ifact(mint a) { return ifact(a.a); }
mint fact(mint a) { return fact(a.a); }
mint modpow(mint a, ll n) { return modpow(a.a, n); }
mint C(int a, int b) {
    if(a < 0 || b < 0) return 0;
    if(a < b) return 0;
    if(a > MAXN) {
        mint res = 1;
        rep(i, b) res *= a - i, res /= i + 1;
        return res;
    }
    return fact(a) * ifact(b) * ifact(a - b);
}
mint P(int a, int b) {
    if(a < 0 || b < 0) return 0;
    if(a < b) return 0;
    if(a > MAXN) {
        mint res = 1;
        rep(i, b) res *= a - i;
        return res;
    }
    return fact(a) * ifact(a - b);
}
ostream &operator<<(ostream &os, mint a) {
    os << a.a;
    return os;
}
istream &operator>>(istream &is, mint &a) {
    ll x;
    is >> x;
    a = x;
    return is;
}
struct modinfo {
    int mod, root;
};
constexpr modinfo base0{1045430273, 3};
constexpr modinfo base1{1051721729, 6};
constexpr modinfo base2{1053818881, 7};
using mint0 = modint<base0.mod>;
using mint1 = modint<base1.mod>;
using mint2 = modint<base2.mod>;
using Poly = vmint;
template <int mod> void FMT(vector<modint<mod>> &f, bool inv = false) {
    using V = vector<modint<mod>>;
    static V g(30), ig(30);
    if(g.front().a == 0) {
        modint<mod> root = 2;
        while((root.pow((mod - 1) / 2)).a == 1) root += 1;
        rep(i, 30) g[i] = -(root.pow((mod - 1) >> (i + 2))), ig[i] = g[i].inv();
    }
    int n = size(f);
    if(!inv) {
        for(int m = n; m >>= 1;) {
            modint<mod> w = 1;
            for(int s = 0, k = 0; s < n; s += 2 * m) {
                for(int i = s, j = s + m; i < s + m; ++i, ++j) {
                    auto x = f[i], y = f[j] * w;
                    if(x.a >= mod) x.a -= mod;
                    f[i].a = x.a + y.a, f[j].a = x.a + (mod - y.a);
                }
                w *= g[__builtin_ctz(++k)];
            }
        }
    } else {
        for(int m = 1; m < n; m *= 2) {
            modint<mod> w = 1;
            for(int s = 0, k = 0; s < n; s += 2 * m) {
                for(int i = s, j = s + m; i < s + m; ++i, ++j) {
                    auto x = f[i], y = f[j];
                    f[i] = x + y, f[j].a = x.a + (mod - y.a), f[j] *= w;
                }
                w *= ig[__builtin_ctz(++k)];
            }
        }
    }
    modint<mod> c;
    if(inv)
        c = modint<mod>(n).inv();
    else
        c = 1;
    for(auto &&e : f) e *= c;
}
Poly operator-(Poly f) {
    for(auto &&e : f) e = -e;
    return f;
}
Poly &operator+=(Poly &l, const Poly &r) {
    l.resize(max(l.size(), r.size()));
    rep(i, r.size()) l[i] += r[i];
    return l;
}
Poly operator+(Poly l, const Poly &r) { return l += r; }
Poly &operator-=(Poly &l, const Poly &r) {
    l.resize(max(l.size(), r.size()));
    rep(i, r.size()) l[i] -= r[i];
    return l;
}
Poly operator-(Poly l, const Poly &r) { return l -= r; }
Poly &operator<<=(Poly &f, size_t n) { return f.insert(f.begin(), n, 0), f; }
Poly operator<<(Poly f, size_t n) { return f <<= n; }
Poly &operator>>=(Poly &f, size_t n) { return f.erase(f.begin(), f.begin() + min(f.size(), n)), f; }
Poly operator>>(Poly f, size_t n) { return f >>= n; }

constexpr int mod0 = 998244353, mod1 = 1300234241, mod2 = 1484783617;
using M0 = modint<mod0>;
using M1 = modint<mod1>;
using M2 = modint<mod2>;

template <int mod> void mul(vector<modint<mod>> &l, vector<modint<mod>> &r) {
    int n = size(l), m = size(r), sz = 1 << __lg(2 * (n + m - 1) - 1);
    l.resize(sz), FMT<mod>(l);
    r.resize(sz), FMT<mod>(r);
    rep(i, sz) l[i] *= r[i];
    FMT<mod>(l, true);
    l.resize(n + m - 1);
}
Poly operator*(const Poly &l, const Poly &r) {
    if(l.empty() or r.empty()) return Poly();
    int n = size(l), m = size(r), sz = 1 << __lg(2 * (n + m - 1) - 1);
    vector<M0> l0(n), r0(m);
    vector<M1> l1(n), r1(m);
    vector<M2> l2(n), r2(m);
    rep(i, n) l0[i] = l[i].a, l1[i] = l[i].a, l2[i] = l[i].a;
    rep(i, m) r0[i] = r[i].a, r1[i] = r[i].a, r2[i] = r[i].a;
    mul<mod0>(l0, r0), mul<mod1>(l1, r1), mul<mod2>(l2, r2);
    Poly res(n + m - 1);
    // garner
    static constexpr M1 inv0 = 613999507;
    static constexpr M2 inv1 = 1147332803, inv0m1 = 45381342;
    static constexpr mint m0 = mod0, m0m1 = m0 * mod1;
    rep(i, n + m - 1) {
        int y0 = l0[i].a;
        int y1 = (inv0 * (l1[i] - y0)).a;
        int y2 = (inv0m1 * (l2[i] - y0) - inv1 * y1).a;
        res[i] = m0 * y1 + m0m1 * y2 + y0;
    }
    return res;
}
Poly &operator*=(Poly &l, const Poly &r) { return l = l * r; }
Poly integ(const Poly &f) {
    Poly res(f.size() + 1);
    for(int i = 1; i < (int)res.size(); ++i) res[i] = f[i - 1] / i;
    return res;
}
struct Prd {
    deque<Poly> deq;
    Prd() = default;
    void emplace(const Poly &f) { deq.emplace_back(f); }
    Poly calc() {
        if(deq.empty()) return {1};
        sort(all(deq), [&](const Poly &f, const Poly &g) { return si(f) < si(g); });
        while(deq.size() > 1) {
            deq.emplace_back(deq[0] * deq[1]);
            for(int i = 0; i < 2; ++i) deq.pop_front();
        }
        return deq.front();
    }
};
Poly prd(vector<Poly> &v) {
    Prd p;
    for(auto &e : v) p.emplace(e);
    return p.calc();
}
// Poly deriv(const Poly &f) {
//     if(f.size() == 0) return Poly();
//     Poly res(f.size() - 1);
//     rep(i, res.size()) res[i] = f[i + 1] * (i + 1);
//     return res;
// }
ostream &operator<<(ostream &os, const Poly &a) {
    for(auto e : a) cout << e.a << " ";
    return os;
}

vmint power_table(mint x, int len) {
    vmint res(len + 1);
    res[0] = 1;
    rep(i, len) res[i + 1] = res[i] * x;
    return res;
}
} // namespace modular
using namespace modular;

namespace segtree_impl {

namespace internal {

// @param n `0 <= n`
// @return minimum non-negative `x` s.t. `n <= 2**x`
int ceil_pow2(int n) {
    int x = 0;
    while((1U << x) < (unsigned int)(n)) x++;
    return x;
}

// @param n `1 <= n`
// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
constexpr int bsf_constexpr(unsigned int n) {
    int x = 0;
    while(!(n & (1 << x))) x++;
    return x;
}

// @param n `1 <= n`
// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
int bsf(unsigned int n) {
#ifdef _MSC_VER
    unsigned long index;
    _BitScanForward(&index, n);
    return index;
#else
    return __builtin_ctz(n);
#endif
}

} // namespace internal

} // namespace segtree_impl

namespace segtree_impl {

template <class S, S (*op)(S, S), S (*e)()> struct segtree {
  public:
    segtree() : segtree(0) {}
    explicit segtree(int n) : segtree(std::vector<S>(n, e())) {}
    explicit segtree(const std::vector<S> &v) : _n(int(v.size())) {
        log = internal::ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        for(int i = 0; i < _n; i++) d[size + i] = v[i];
        for(int i = size - 1; i >= 1; i--) { update(i); }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        d[p] = x;
        for(int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) const {
        assert(0 <= p && p < _n);
        return d[p + size];
    }

    S operator[](int k) const { return get(k); }

    S prod(int l, int r) const {
#ifdef ONLINE_JUDGE
        if(l < 0) l = 0;
        if(r > _n) r = _n;
        if(l > r) return e();
#endif
        assert(0 <= l && l <= r && r <= _n);
        S sml = e(), smr = e();
        l += size;
        r += size;

        while(l < r) {
            if(l & 1) sml = op(sml, d[l++]);
            if(r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }

    S all_prod() const { return d[1]; }

    template <bool (*f)(S)> int max_right(int l) const {
        return max_right(l, [](S x) { return f(x); });
    }
    template <class F> int max_right(int l, F f) const {
#ifdef ONLINE_JUDGE
        if(l < 0) l = 0;
        if(l > _n) l = _n;
#endif
        assert(0 <= l && l <= _n);
        assert(f(e()));
        if(l == _n) return _n;
        l += size;
        S sm = e();
        do {
            while(l % 2 == 0) l >>= 1;
            if(!f(op(sm, d[l]))) {
                while(l < size) {
                    l = (2 * l);
                    if(f(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while((l & -l) != l);
        return _n;
    }

    template <bool (*f)(S)> int min_left(int r) const {
        return min_left(r, [](S x) { return f(x); });
    }
    template <class F> int min_left(int r, F f) const {
#ifdef ONLINE_JUDGE
        if(r < 0) r = 0;
        if(r > _n) r = _n;
#endif
        assert(0 <= r && r <= _n);
        assert(f(e()));
        if(r == 0) return 0;
        r += size;
        S sm = e();
        do {
            r--;
            while(r > 1 && (r % 2)) r >>= 1;
            if(!f(op(d[r], sm))) {
                while(r < size) {
                    r = (2 * r + 1);
                    if(f(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while((r & -r) != r);
        return 0;
    }

    friend std::ostream &operator<<(std::ostream &os, segtree &ls) {
        os << "{";
        for(int i = 0; i < ls._n; i++) os << ls.get(i) << (i == ls._n - 1 ? "" : ", ");
        return os << "}";
    }

  private:
    int _n, size, log;
    std::vector<S> d;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};

template <class T> constexpr T inf = std::numeric_limits<T>::max() / 2;
template <class T, class U> constexpr std::pair<T, U> inf<std::pair<T, U>> = {inf<T>, inf<U>};
template <typename T> T min_func(T x, T y) { return min(x, y); }
template <typename T> T max_func(T x, T y) { return max(x, y); }
template <typename T> T plus_func(T x, T y) { return x + y; }
template <typename T, int ID> T set_func(T x, T y) { return (y == ID ? x : y); }
template <typename T> T min_e() { return inf<T>; }
template <typename T> T max_e() { return -inf<T>; }
template <typename T> T plus_e() { return T(); }

template <typename T> using RST = segtree<T, plus_func<T>, plus_e<T>>;
template <typename T> using RmT = segtree<T, min_func<T>, min_e<T>>;
template <typename T> using RMT = segtree<T, max_func<T>, max_e<T>>;

} // namespace segtree_impl
using segtree_impl::RmT;
using segtree_impl::RMT;
using segtree_impl::RST;
using segtree_impl::segtree;

int main() {
    TEST {
        INT(n);
        RST<mint> seg(n);
        vmint ans(n);
        auto p = power_table(2, n);
        ans[n - 1] += p[n / 2];
        per(i, n) {
            int r = i * 2 + 1;
            mint k = seg.prod(i, min(r, n));
            if((i + 1) > n - (i + 1)) k += 1;

            seg.set(i, k);

            ans[i] += k * p[(i + 1) / 2];
        }

        mint ip = p[n].inv();
        fore(e, ans) OUT(e * ip);
    }
}