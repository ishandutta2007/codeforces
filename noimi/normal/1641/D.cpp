#pragma region Macros
//#pragma GCC target("avx2")
// #pragma GCC optimize("O3")
// #pragma comment(linker, "/stack:200000000")
#ifdef ONLINE_JUDGE
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("popcnt")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,avx2,tune=native")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,avx2")
// #pragma GCC target("avx2")
#endif
#pragma GCC optimize("Ofast")
#ifdef noimi
#define oj_local(a, b) b
#else
#define oj_local(a, b) a
#endif

#define LOCAL if(oj_local(0, 1))
#define OJ if(oj_local(1, 0))

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
#include <immintrin.h>
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
#include <typeinfo>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

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
#define per0(n) for(int jidlsjf = 0; jidlsjf < n; ++jidlsjf)
#define per1(i, n) for(ll i = (n)-1; i >= 0; --i)
#define per2(i, a, b) for(ll i = (a)-1; i >= b; --i)
#define per3(i, a, b, c) for(ll i = (a)-1; i >= b; i -= c)
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
#define rng(v, l, r) v.begin() + l, v.begin() + r
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
void YES(bool t = 1) { cout << YESNO[t] << endl; }
void NO(bool t = 1) { YES(!t); }
void Yes(bool t = 1) { cout << YesNo[t] << endl; }
void No(bool t = 1) { Yes(!t); }
void yes(bool t = 1) { cout << yesno[t] << endl; }
void no(bool t = 1) { yes(!t); }
void first(bool t = 1) { cout << firstsecond[t] << endl; }
void First(bool t = 1) { cout << FirstSecond[t] << endl; }
void possible(bool t = 1) { cout << possiblestr[t] << endl; }
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

// x in [l, r)
template <class T, class S> bool inc(const T &x, const S &l, const S &r) { return l <= x and x < r; }

constexpr ll ten(int n) { return n == 0 ? 1 : ten(n - 1) * 10; }
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

namespace RollingHashes {
constexpr ll MOD = (1LL << 61) - 1;

struct modint {

    ll a;

    constexpr modint(const ll x = 0) noexcept : a((x % MOD + MOD) % MOD) {}
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
        modint res = *this;
        --*this;
        return res;
    }
    constexpr modint &operator+=(const modint rhs) noexcept {
        a += rhs.a;
        if(a >= MOD) { a -= MOD; }
        return *this;
    }
    constexpr modint &operator-=(const modint rhs) noexcept {
        if(a < rhs.a) { a += MOD; }
        a -= rhs.a;
        return *this;
    }
    constexpr modint &operator*=(const modint rhs) noexcept {
        i128 t = (i128)(a) * (i128)(rhs.a);
        t = (t >> 61) + (t & MOD);
        if(t >= MOD) t -= MOD;
        a = t;
        return *this;
    }
    constexpr modint pow(long long n) const noexcept {
        if(n < 0) {
            n %= MOD - 1;
            n = (MOD - 1) + n;
        }
        modint x = *this, r = 1;
        while(n) {
            if(n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }
    constexpr modint &operator/=(const modint rhs) noexcept { return (*this *= rhs.pow(MOD - 2)); }
    constexpr modint inv() const noexcept { return pow(MOD - 2); }
    constexpr friend modint operator+(const modint &lhs, const modint &rhs) { return modint(lhs) += modint(rhs); }
    constexpr friend modint operator-(const modint &lhs, const modint &rhs) { return modint(lhs) -= modint(rhs); }
    constexpr friend modint operator*(const modint &lhs, const modint &rhs) { return modint(lhs) *= modint(rhs); }
    constexpr friend modint operator/(const modint &lhs, const modint &rhs) { return modint(lhs) /= modint(rhs); }
    constexpr friend modint operator==(const modint &lhs, const modint &rhs) { return lhs.a == rhs.a; }
    constexpr friend modint operator!=(const modint &lhs, const modint &rhs) { return lhs.a != rhs.a; }
    // constexpr friend modint operator^=(const modint &lhs, const modint &rhs) { return modint(lhs) ^= modint(rhs); }
};
using mint = modint;
using Hash = mint;
static mint base = 5454547;
vector<mint> p{1};
void calc_pow(int N) {
    while(si(p) < N) p.eb(p.back() * base);
}
struct RollingHash {
    vector<mint> h;
    RollingHash(const string &s) {
        int sz = (int)s.size();
        h.assign(sz + 1, 0);
        p[0] = 1;
        if(sz + 1 > (int)p.size()) {
            int psz = p.size();
            p.resize(sz + 1);
            for(int i = psz; i < sz + 1; i++) p[i] = p[i - 1] * base;
        }
        for(int i = 0; i < sz; i++) { h[i + 1] = h[i] * base + s[i]; }
    }

    ll get(int l, int r) const {
        mint res = h[r] + MOD - h[l] * p[r - l];
        return res.a;
    }

    ll connect(ull h1, ull h2, int h2len) const {
        mint res = h1 * p[h2len] + h2;
        return res.a;
    }

    int LCP(const RollingHash &b, int l1, int r1, int l2, int r2) {
        int len = min(r1 - l1, r2 - l2);
        int low = -1, high = len + 1;
        while(high - low > 1) {
            int mid = (low + high) / 2;
            if(get(l1, l1 + mid) == b.get(l2, l2 + mid))
                low = mid;
            else
                high = mid;
        }
        return (low);
    }
    RollingHash() = default;
};
template <class T> ll get_hash(const vector<T> &v) {
    mint res;
    rep(i, si(v)) res += p[i] * v[i];
    return res.a;
}
} // namespace RollingHashes
using namespace RollingHashes;
#line 2 "hashmap/hashmap.hpp"

#line 2 "hashmap/hashmap-base.hpp"

namespace HashMapImpl {
using u32 = uint32_t;
using u64 = uint64_t;

template <typename Key, typename Data> struct HashMapBase;

template <typename Key, typename Data> struct itrB : iterator<bidirectional_iterator_tag, Data, ptrdiff_t, Data *, Data &> {
    using base = iterator<bidirectional_iterator_tag, Data, ptrdiff_t, Data *, Data &>;
    using ptr = typename base::pointer;
    using ref = typename base::reference;

    u32 i;
    HashMapBase<Key, Data> *p;

    explicit constexpr itrB() : i(0), p(nullptr) {}
    explicit constexpr itrB(u32 _i, HashMapBase<Key, Data> *_p) : i(_i), p(_p) {}
    explicit constexpr itrB(u32 _i, const HashMapBase<Key, Data> *_p) : i(_i), p(const_cast<HashMapBase<Key, Data> *>(_p)) {}
    friend void swap(itrB &l, itrB &r) { swap(l.i, r.i), swap(l.p, r.p); }
    friend bool operator==(const itrB &l, const itrB &r) { return l.i == r.i; }
    friend bool operator!=(const itrB &l, const itrB &r) { return l.i != r.i; }
    const ref operator*() const { return const_cast<const HashMapBase<Key, Data> *>(p)->data[i]; }
    ref operator*() { return p->data[i]; }
    ptr operator->() const { return &(p->data[i]); }

    itrB &operator++() {
        assert(i != p->cap && "itr::operator++()");
        do {
            i++;
            if(i == p->cap) break;
            if(p->flag[i] == true && p->dflag[i] == false) break;
        } while(true);
        return (*this);
    }
    itrB operator++(int) {
        itrB it(*this);
        ++(*this);
        return it;
    }
    itrB &operator--() {
        do {
            i--;
            if(p->flag[i] == true && p->dflag[i] == false) break;
            assert(i != 0 && "itr::operator--()");
        } while(true);
        return (*this);
    }
    itrB operator--(int) {
        itrB it(*this);
        --(*this);
        return it;
    }
};

template <typename Key, typename Data> struct HashMapBase {
    using u32 = uint32_t;
    using u64 = uint64_t;
    using iterator = itrB<Key, Data>;
    using itr = iterator;

  protected:
    template <typename K> inline u64 randomized(const K &key) const { return u64(key) ^ r; }

    template <typename K, enable_if_t<is_same<K, Key>::value, nullptr_t> = nullptr, enable_if_t<is_integral<K>::value, nullptr_t> = nullptr>
    inline u32 inner_hash(const K &key) const {
        return (randomized(key) * 11995408973635179863ULL) >> shift;
    }
    template <typename K, enable_if_t<is_same<K, Key>::value, nullptr_t> = nullptr, enable_if_t<is_integral<decltype(K::first)>::value, nullptr_t> = nullptr,
              enable_if_t<is_integral<decltype(K::second)>::value, nullptr_t> = nullptr>
    inline u32 inner_hash(const K &key) const {
        u64 a = randomized(key.first), b = randomized(key.second);
        a *= 11995408973635179863ULL;
        b *= 10150724397891781847ULL;
        return (a + b) >> shift;
    }
    template <typename K, enable_if_t<is_same<K, Key>::value, nullptr_t> = nullptr,
              enable_if_t<is_integral<typename K::value_type>::value, nullptr_t> = nullptr>
    inline u32 inner_hash(const K &key) const {
        static constexpr u64 mod = (1LL << 61) - 1;
        static constexpr u64 base = 950699498548472943ULL;
        u64 res = 0;
        for(auto &elem : key) {
            __uint128_t x = __uint128_t(res) * base + (randomized(elem) & mod);
            res = (x & mod) + (x >> 61);
        }
        __uint128_t x = __uint128_t(res) * base;
        res = (x & mod) + (x >> 61);
        if(res >= mod) res -= mod;
        return res >> (shift - 3);
    }

    template <typename D = Data, enable_if_t<is_same<D, Key>::value, nullptr_t> = nullptr> inline u32 hash(const D &dat) const { return inner_hash(dat); }
    template <typename D = Data, enable_if_t<is_same<decltype(D::first), Key>::value, nullptr_t> = nullptr> inline u32 hash(const D &dat) const {
        return inner_hash(dat.first);
    }

    template <typename D = Data, enable_if_t<is_same<D, Key>::value, nullptr_t> = nullptr> inline Key dtok(const D &dat) const { return dat; }
    template <typename D = Data, enable_if_t<is_same<decltype(D::first), Key>::value, nullptr_t> = nullptr> inline Key dtok(const D &dat) const {
        return dat.first;
    }

    void reallocate(u32 ncap) {
        vector<Data> ndata(ncap);
        vector<bool> nf(ncap);
        shift = 64 - __lg(ncap);
        for(u32 i = 0; i < cap; i++) {
            if(flag[i] == true && dflag[i] == false) {
                u32 h = hash(data[i]);
                while(nf[h]) h = (h + 1) & (ncap - 1);
                ndata[h] = move(data[i]);
                nf[h] = true;
            }
        }
        data.swap(ndata);
        flag.swap(nf);
        cap = ncap;
        dflag.resize(cap);
        fill(std::begin(dflag), std::end(dflag), false);
    }

    inline bool extend_rate(u32 x) const { return x * 2 >= cap; }

    inline bool shrink_rate(u32 x) const { return HASHMAP_DEFAULT_SIZE < cap && x * 10 <= cap; }

    inline void extend() { reallocate(cap << 1); }

    inline void shrink() { reallocate(cap >> 1); }

  public:
    u32 cap, s;
    vector<Data> data;
    vector<bool> flag, dflag;
    u32 shift;
    static u64 r;
    static constexpr uint32_t HASHMAP_DEFAULT_SIZE = 4;

    explicit HashMapBase() : cap(HASHMAP_DEFAULT_SIZE), s(0), data(cap), flag(cap), dflag(cap), shift(64 - __lg(cap)) {}

    itr begin() const {
        u32 h = 0;
        while(h != cap) {
            if(flag[h] == true && dflag[h] == false) break;
            h++;
        }
        return itr(h, this);
    }
    itr end() const { return itr(this->cap, this); }

    friend itr begin(const HashMapBase &h) { return h.begin(); }
    friend itr end(const HashMapBase &h) { return h.end(); }

    itr find(const Key &key) const {
        u32 h = inner_hash(key);
        while(true) {
            if(flag[h] == false) return this->end();
            if(dtok(data[h]) == key) {
                if(dflag[h] == true) return this->end();
                return itr(h, this);
            }
            h = (h + 1) & (cap - 1);
        }
    }

    bool contain(const Key &key) const { return find(key) != this->end(); }

    itr insert(const Data &d) {
        u32 h = hash(d);
        while(true) {
            if(flag[h] == false) {
                if(extend_rate(s + 1)) {
                    extend();
                    h = hash(d);
                    continue;
                }
                data[h] = d;
                flag[h] = true;
                ++s;
                return itr(h, this);
            }
            if(dtok(data[h]) == dtok(d)) {
                if(dflag[h] == true) {
                    data[h] = d;
                    dflag[h] = false;
                    ++s;
                }
                return itr(h, this);
            }
            h = (h + 1) & (cap - 1);
        }
    }

    // tips for speed up :
    // if return value is unnecessary, make argument_2 false.
    itr erase(itr it, bool get_next = true) {
        if(it == this->end()) return this->end();
        s--;
        if(shrink_rate(s)) {
            Data d = data[it.i];
            shrink();
            it = find(dtok(d));
        }
        int ni = (it.i + 1) & (cap - 1);
        if(this->flag[ni]) {
            this->dflag[it.i] = true;
        } else {
            this->flag[it.i] = false;
        }
        if(get_next) ++it;
        return it;
    }

    itr erase(const Key &key) { return erase(find(key)); }

    bool empty() const { return s == 0; }

    int size() const { return s; }

    void clear() {
        fill(std::begin(flag), std::end(flag), false);
        fill(std::begin(dflag), std::end(dflag), false);
        s = 0;
    }

    void reserve(int n) {
        if(n <= 0) return;
        n = 1 << min(23, __lg(n) + 2);
        if(cap < u32(n)) reallocate(n);
    }
};

template <typename Key, typename Data>
uint64_t HashMapBase<Key, Data>::r = chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count();

} // namespace HashMapImpl

/**
 * @brief Hash Map(base)()
 */
#line 4 "hashmap/hashmap.hpp"

template <typename Key, typename Val> struct HashMap : HashMapImpl::HashMapBase<Key, pair<Key, Val>> {
    using base = typename HashMapImpl::HashMapBase<Key, pair<Key, Val>>;
    using HashMapImpl::HashMapBase<Key, pair<Key, Val>>::HashMapBase;
    using Data = pair<Key, Val>;

    Val &operator[](const Key &k) {
        typename base::u32 h = base::inner_hash(k);
        while(true) {
            if(base::flag[h] == false) {
                if(base::extend_rate(base::s + 1)) {
                    base::extend();
                    h = base::hash(k);
                    continue;
                }
                base::data[h].first = k;
                base::data[h].second = Val();
                base::flag[h] = true;
                ++base::s;
                return base::data[h].second;
            }
            if(base::data[h].first == k) {
                if(base::dflag[h] == true) base::data[h].second = Val();
                return base::data[h].second;
            }
            h = (h + 1) & (base::cap - 1);
        }
    }

    typename base::itr emplace(const Key &key, const Val &val) { return base::insert(Data(key, val)); }
};

/*
 * @brief ()
 * @docs docs/hashmap/hashmap.md
 **/

// a[i]  a[i] + b[j] \in [L, R)  j 
// a  b 
template <class T> vector<pair<int, int>> syakutoriRange(const vector<T> &a, const vector<T> &b, T L, T R) {
    int n = a.size();
    vector<pair<int, int>> res(n);
    int l = b.size(), r = b.size();
    for(int i = 0; i < n; i++) {
        while(l and b[l - 1] + a[i] >= L) l--;
        while(r and b[r - 1] + a[i] >= R) r--;
        res[i] = pair(l, r);
    }
    return res;
}

int main() {
    INT(n, m);
    vi w(n);
    calc_pow(10);

    vector<tuple<ll, bool, int>> mp;
    vvc<int> a(n);
    rep(i, n) {
        rep(j, m) a[i].eb(in());
        w[i] = in();
        SORT(a[i]);
        rep(b, 1 << m) {
            if(!b) continue;
            vl v;
            rep(j, m) if(b >> j & 1) v.eb(a[i][j]);
            ll h = get_hash(v);
            mp.eb(h, si(v) & 1, w[i]);
        }
    }
    vvc<int> add;
    vvc<int> del;
    SORT(mp);
    rep(i, si(mp)) {
        int j = i;
        auto &tmp = (get<1>(mp[i]) ? del : add);
        tmp.eb(vi());
        while(j < si(mp) and get<0>(mp[i]) == get<0>(mp[j])) {
            tmp.back().eb(get<2>(mp[j]));
            j++;
        }
        if(tmp.back().size() == 1) tmp.pop_back();
        i = j - 1;
    }
    SORT(w);
    add.eb(w);

    ll res = bin_search(ten(9) * 2 + 1, -1LL, [&](int x) {
        ll res = 0;
        fore(v, add) {
            for(auto &&[l, r] : syakutoriRange(v, v, 0, x + 1)) res += r - l;
            fore(e, v) if(inc(e + e, 0, x + 1)) res--;
        }
        fore(v, del) {
            for(auto &&[l, r] : syakutoriRange(v, v, 0, x + 1)) res -= r - l;
            fore(e, v) if(inc(e + e, 0, x + 1)) res++;
        }
        return res;
    });
    if(res == ten(9) * 2 + 1)
        OUT(-1);
    else
        OUT(res);
}