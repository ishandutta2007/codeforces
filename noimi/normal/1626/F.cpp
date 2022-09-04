#pragma region Macros
//#pragma GCC target("avx2")
// #pragma GCC optimize("O3")
// #pragma comment(linker, "/stack:200000000")
#ifdef ONLINE_JUDGE
// #pragma GCC optimize("unroll-loops")
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

namespace Modular998 {
#line 1 "a.cpp"

#line 2 "library/fps/berlekamp-massey.hpp"

template <typename mint> vector<mint> BerlekampMassey(const vector<mint> &s) {
    const int N = (int)s.size();
    vector<mint> b, c;
    b.reserve(N + 1);
    c.reserve(N + 1);
    b.push_back(mint(1));
    c.push_back(mint(1));
    mint y = mint(1);
    for(int ed = 1; ed <= N; ed++) {
        int l = int(c.size()), m = int(b.size());
        mint x = 0;
        for(int i = 0; i < l; i++) x += c[i] * s[ed - l + i];
        b.emplace_back(mint(0));
        m++;
        if(x == mint(0)) continue;
        mint freq = x / y;
        if(l < m) {
            auto tmp = c;
            c.insert(begin(c), m - l, mint(0));
            for(int i = 0; i < m; i++) c[m - 1 - i] -= freq * b[m - 1 - i];
            b = tmp;
            y = x;
        } else {
            for(int i = 0; i < m; i++) c[l - 1 - i] -= freq * b[m - 1 - i];
        }
    }
    reverse(begin(c), end(c));
    return c;
}

#line 2 "library/modulo/binomial.hpp"

template <typename T> struct Binomial {
    vector<T> f, g, h;
    Binomial(int MAX = 0) : f(1, T(1)), g(1, T(1)), h(1, T(1)) {
        while(MAX >= (int)f.size()) extend();
    }

    void extend() {
        int n = f.size();
        int m = n * 2;
        f.resize(m);
        g.resize(m);
        h.resize(m);
        for(int i = n; i < m; i++) f[i] = f[i - 1] * T(i);
        g[m - 1] = f[m - 1].inverse();
        h[m - 1] = g[m - 1] * f[m - 2];
        for(int i = m - 2; i >= n; i--) {
            g[i] = g[i + 1] * T(i + 1);
            h[i] = g[i] * f[i - 1];
        }
    }

    T fac(int i) {
        if(i < 0) return T(0);
        while(i >= (int)f.size()) extend();
        return f[i];
    }

    T finv(int i) {
        if(i < 0) return T(0);
        while(i >= (int)g.size()) extend();
        return g[i];
    }

    T inv(int i) {
        if(i < 0) return -inv(-i);
        while(i >= (int)h.size()) extend();
        return h[i];
    }

    T C(int n, int r) {
        if(n < 0 || n < r || r < 0) return T(0);
        return fac(n) * finv(n - r) * finv(r);
    }

    inline T operator()(int n, int r) { return C(n, r); }

    template <typename I> T multinomial(const vector<I> &r) {
        static_assert(is_integral<I>::value == true);
        int n = 0;
        for(auto &x : r) {
            if(x < 0) return T(0);
            n += x;
        }
        T res = fac(n);
        for(auto &x : r) res *= finv(x);
        return res;
    }

    template <typename I> T operator()(const vector<I> &r) { return multinomial(r); }

    T C_naive(int n, int r) {
        if(n < 0 || n < r || r < 0) return T(0);
        T ret = T(1);
        r = min(r, n - r);
        for(int i = 1; i <= r; ++i) ret *= inv(i) * (n--);
        return ret;
    }

    T P(int n, int r) {
        if(n < 0 || n < r || r < 0) return T(0);
        return fac(n) * finv(n - r);
    }

    T H(int n, int r) {
        if(n < 0 || r < 0) return T(0);
        return r == 0 ? 1 : C(n + r - 1, r);
    }
};

#line 2 "library/modint/montgomery-modint.hpp"

template <uint32_t mod> struct LazyMontgomeryModInt {
    using mint = LazyMontgomeryModInt;
    using i32 = int32_t;
    using u32 = uint32_t;
    using u64 = uint64_t;

    static constexpr u32 get_r() {
        u32 ret = mod;
        for(i32 i = 0; i < 4; ++i) ret *= 2 - mod * ret;
        return ret;
    }

    static constexpr u32 r = get_r();
    static constexpr u32 n2 = -u64(mod) % mod;
    static_assert(r * mod == 1, "invalid, r * mod != 1");
    static_assert(mod < (1 << 30), "invalid, mod >= 2 ^ 30");
    static_assert((mod & 1) == 1, "invalid, mod % 2 == 0");

    u32 a;

    constexpr LazyMontgomeryModInt() : a(0) {}
    constexpr LazyMontgomeryModInt(const int64_t &b) : a(reduce(u64(b % mod + mod) * n2)){};

    static constexpr u32 reduce(const u64 &b) { return (b + u64(u32(b) * u32(-r)) * mod) >> 32; }

    constexpr mint &operator+=(const mint &b) {
        if(i32(a += b.a - 2 * mod) < 0) a += 2 * mod;
        return *this;
    }

    constexpr mint &operator-=(const mint &b) {
        if(i32(a -= b.a) < 0) a += 2 * mod;
        return *this;
    }

    constexpr mint &operator*=(const mint &b) {
        a = reduce(u64(a) * b.a);
        return *this;
    }

    constexpr mint &operator/=(const mint &b) {
        *this *= b.inverse();
        return *this;
    }

    constexpr mint operator+(const mint &b) const { return mint(*this) += b; }
    constexpr mint operator-(const mint &b) const { return mint(*this) -= b; }
    constexpr mint operator*(const mint &b) const { return mint(*this) *= b; }
    constexpr mint operator/(const mint &b) const { return mint(*this) /= b; }
    constexpr bool operator==(const mint &b) const { return (a >= mod ? a - mod : a) == (b.a >= mod ? b.a - mod : b.a); }
    constexpr bool operator!=(const mint &b) const { return (a >= mod ? a - mod : a) != (b.a >= mod ? b.a - mod : b.a); }
    constexpr mint operator-() const { return mint() - mint(*this); }

    constexpr mint pow(u64 n) const {
        mint ret(1), mul(*this);
        while(n > 0) {
            if(n & 1) ret *= mul;
            mul *= mul;
            n >>= 1;
        }
        return ret;
    }

    constexpr mint inverse() const { return pow(mod - 2); }

    friend ostream &operator<<(ostream &os, const mint &b) { return os << b.get(); }

    friend istream &operator>>(istream &is, mint &b) {
        int64_t t;
        is >> t;
        b = LazyMontgomeryModInt<mod>(t);
        return (is);
    }

    constexpr u32 get() const {
        u32 ret = reduce(a);
        return ret >= mod ? ret - mod : ret;
    }

    static constexpr u32 get_mod() { return mod; }
};
#line 2 "library/fps/ntt-friendly-fps.hpp"

#line 2 "library/ntt/ntt-avx2.hpp"

#line 2 "library/modint/simd-montgomery.hpp"

#include <immintrin.h>

__attribute__((target("sse4.2"))) inline __m128i my128_mullo_epu32(const __m128i &a, const __m128i &b) { return _mm_mullo_epi32(a, b); }

__attribute__((target("sse4.2"))) inline __m128i my128_mulhi_epu32(const __m128i &a, const __m128i &b) {
    __m128i a13 = _mm_shuffle_epi32(a, 0xF5);
    __m128i b13 = _mm_shuffle_epi32(b, 0xF5);
    __m128i prod02 = _mm_mul_epu32(a, b);
    __m128i prod13 = _mm_mul_epu32(a13, b13);
    __m128i prod = _mm_unpackhi_epi64(_mm_unpacklo_epi32(prod02, prod13), _mm_unpackhi_epi32(prod02, prod13));
    return prod;
}

__attribute__((target("sse4.2"))) inline __m128i montgomery_mul_128(const __m128i &a, const __m128i &b, const __m128i &r, const __m128i &m1) {
    return _mm_sub_epi32(_mm_add_epi32(my128_mulhi_epu32(a, b), m1), my128_mulhi_epu32(my128_mullo_epu32(my128_mullo_epu32(a, b), r), m1));
}

__attribute__((target("sse4.2"))) inline __m128i montgomery_add_128(const __m128i &a, const __m128i &b, const __m128i &m2, const __m128i &m0) {
    __m128i ret = _mm_sub_epi32(_mm_add_epi32(a, b), m2);
    return _mm_add_epi32(_mm_and_si128(_mm_cmpgt_epi32(m0, ret), m2), ret);
}

__attribute__((target("sse4.2"))) inline __m128i montgomery_sub_128(const __m128i &a, const __m128i &b, const __m128i &m2, const __m128i &m0) {
    __m128i ret = _mm_sub_epi32(a, b);
    return _mm_add_epi32(_mm_and_si128(_mm_cmpgt_epi32(m0, ret), m2), ret);
}

__attribute__((target("avx2"))) inline __m256i my256_mullo_epu32(const __m256i &a, const __m256i &b) { return _mm256_mullo_epi32(a, b); }

__attribute__((target("avx2"))) inline __m256i my256_mulhi_epu32(const __m256i &a, const __m256i &b) {
    __m256i a13 = _mm256_shuffle_epi32(a, 0xF5);
    __m256i b13 = _mm256_shuffle_epi32(b, 0xF5);
    __m256i prod02 = _mm256_mul_epu32(a, b);
    __m256i prod13 = _mm256_mul_epu32(a13, b13);
    __m256i prod = _mm256_unpackhi_epi64(_mm256_unpacklo_epi32(prod02, prod13), _mm256_unpackhi_epi32(prod02, prod13));
    return prod;
}

__attribute__((target("avx2"))) inline __m256i montgomery_mul_256(const __m256i &a, const __m256i &b, const __m256i &r, const __m256i &m1) {
    return _mm256_sub_epi32(_mm256_add_epi32(my256_mulhi_epu32(a, b), m1), my256_mulhi_epu32(my256_mullo_epu32(my256_mullo_epu32(a, b), r), m1));
}

__attribute__((target("avx2"))) inline __m256i montgomery_add_256(const __m256i &a, const __m256i &b, const __m256i &m2, const __m256i &m0) {
    __m256i ret = _mm256_sub_epi32(_mm256_add_epi32(a, b), m2);
    return _mm256_add_epi32(_mm256_and_si256(_mm256_cmpgt_epi32(m0, ret), m2), ret);
}

__attribute__((target("avx2"))) inline __m256i montgomery_sub_256(const __m256i &a, const __m256i &b, const __m256i &m2, const __m256i &m0) {
    __m256i ret = _mm256_sub_epi32(a, b);
    return _mm256_add_epi32(_mm256_and_si256(_mm256_cmpgt_epi32(m0, ret), m2), ret);
}
#line 4 "library/ntt/ntt-avx2.hpp"

namespace ntt_inner {
using u64 = uint64_t;
constexpr uint32_t get_pr(uint32_t mod) {
    if(mod == 2) return 1;
    u64 ds[32] = {};
    int idx = 0;
    u64 m = mod - 1;
    for(u64 i = 2; i * i <= m; ++i) {
        if(m % i == 0) {
            ds[idx++] = i;
            while(m % i == 0) m /= i;
        }
    }
    if(m != 1) ds[idx++] = m;

    uint32_t pr = 2;
    while(1) {
        int flg = 1;
        for(int i = 0; i < idx; ++i) {
            u64 a = pr, b = (mod - 1) / ds[i], r = 1;
            while(b) {
                if(b & 1) r = r * a % mod;
                a = a * a % mod;
                b >>= 1;
            }
            if(r == 1) {
                flg = 0;
                break;
            }
        }
        if(flg == 1) break;
        ++pr;
    }
    return pr;
}

constexpr int SZ_FFT_BUF = 1 << 23;
uint32_t _buf1[SZ_FFT_BUF] __attribute__((aligned(64)));
uint32_t _buf2[SZ_FFT_BUF] __attribute__((aligned(64)));
} // namespace ntt_inner

template <typename mint> struct NTT {
    static constexpr uint32_t mod = mint::get_mod();
    static constexpr uint32_t pr = ntt_inner::get_pr(mint::get_mod());
    static constexpr int level = __builtin_ctzll(mod - 1);
    mint dw[level], dy[level];
    mint *buf1, *buf2;

    constexpr NTT() {
        setwy(level);
        union raw_cast {
            mint dat;
            uint32_t _;
        };
        buf1 = &(((raw_cast *)(ntt_inner::_buf1))->dat);
        buf2 = &(((raw_cast *)(ntt_inner::_buf2))->dat);
    }

    constexpr void setwy(int k) {
        mint w[level], y[level];
        w[k - 1] = mint(pr).pow((mod - 1) / (1 << k));
        y[k - 1] = w[k - 1].inverse();
        for(int i = k - 2; i > 0; --i) w[i] = w[i + 1] * w[i + 1], y[i] = y[i + 1] * y[i + 1];
        dw[0] = dy[0] = w[1] * w[1];
        dw[1] = w[1], dy[1] = y[1], dw[2] = w[2], dy[2] = y[2];
        for(int i = 3; i < k; ++i) {
            dw[i] = dw[i - 1] * y[i - 2] * w[i];
            dy[i] = dy[i - 1] * w[i - 2] * y[i];
        }
    }

    __attribute__((target("avx2"))) void ntt(mint *a, int n) {
        int k = n ? __builtin_ctz(n) : 0;
        if(k == 0) return;
        if(k == 1) {
            mint a1 = a[1];
            a[1] = a[0] - a[1];
            a[0] = a[0] + a1;
            return;
        }
        if(k & 1) {
            int v = 1 << (k - 1);
            if(v < 8) {
                for(int j = 0; j < v; ++j) {
                    mint ajv = a[j + v];
                    a[j + v] = a[j] - ajv;
                    a[j] += ajv;
                }
            } else {
                const __m256i m0 = _mm256_set1_epi32(0);
                const __m256i m2 = _mm256_set1_epi32(mod + mod);
                int j0 = 0;
                int j1 = v;
                for(; j0 < v; j0 += 8, j1 += 8) {
                    __m256i T0 = _mm256_loadu_si256((__m256i *)(a + j0));
                    __m256i T1 = _mm256_loadu_si256((__m256i *)(a + j1));
                    __m256i naj = montgomery_add_256(T0, T1, m2, m0);
                    __m256i najv = montgomery_sub_256(T0, T1, m2, m0);
                    _mm256_storeu_si256((__m256i *)(a + j0), naj);
                    _mm256_storeu_si256((__m256i *)(a + j1), najv);
                }
            }
        }
        int u = 1 << (2 + (k & 1));
        int v = 1 << (k - 2 - (k & 1));
        mint one = mint(1);
        mint imag = dw[1];
        while(v) {
            if(v == 1) {
                mint ww = one, xx = one, wx = one;
                for(int jh = 0; jh < u;) {
                    ww = xx * xx, wx = ww * xx;
                    mint t0 = a[jh + 0], t1 = a[jh + 1] * xx;
                    mint t2 = a[jh + 2] * ww, t3 = a[jh + 3] * wx;
                    mint t0p2 = t0 + t2, t1p3 = t1 + t3;
                    mint t0m2 = t0 - t2, t1m3 = (t1 - t3) * imag;
                    a[jh + 0] = t0p2 + t1p3, a[jh + 1] = t0p2 - t1p3;
                    a[jh + 2] = t0m2 + t1m3, a[jh + 3] = t0m2 - t1m3;
                    xx *= dw[__builtin_ctz((jh += 4))];
                }
            } else if(v == 4) {
                const __m128i m0 = _mm_set1_epi32(0);
                const __m128i m1 = _mm_set1_epi32(mod);
                const __m128i m2 = _mm_set1_epi32(mod + mod);
                const __m128i r = _mm_set1_epi32(mint::r);
                const __m128i Imag = _mm_set1_epi32(imag.a);
                mint ww = one, xx = one, wx = one;
                for(int jh = 0; jh < u;) {
                    if(jh == 0) {
                        int j0 = 0;
                        int j1 = v;
                        int j2 = j1 + v;
                        int j3 = j2 + v;
                        int je = v;
                        for(; j0 < je; j0 += 4, j1 += 4, j2 += 4, j3 += 4) {
                            const __m128i T0 = _mm_loadu_si128((__m128i *)(a + j0));
                            const __m128i T1 = _mm_loadu_si128((__m128i *)(a + j1));
                            const __m128i T2 = _mm_loadu_si128((__m128i *)(a + j2));
                            const __m128i T3 = _mm_loadu_si128((__m128i *)(a + j3));
                            const __m128i T0P2 = montgomery_add_128(T0, T2, m2, m0);
                            const __m128i T1P3 = montgomery_add_128(T1, T3, m2, m0);
                            const __m128i T0M2 = montgomery_sub_128(T0, T2, m2, m0);
                            const __m128i T1M3 = montgomery_mul_128(montgomery_sub_128(T1, T3, m2, m0), Imag, r, m1);
                            _mm_storeu_si128((__m128i *)(a + j0), montgomery_add_128(T0P2, T1P3, m2, m0));
                            _mm_storeu_si128((__m128i *)(a + j1), montgomery_sub_128(T0P2, T1P3, m2, m0));
                            _mm_storeu_si128((__m128i *)(a + j2), montgomery_add_128(T0M2, T1M3, m2, m0));
                            _mm_storeu_si128((__m128i *)(a + j3), montgomery_sub_128(T0M2, T1M3, m2, m0));
                        }
                    } else {
                        ww = xx * xx, wx = ww * xx;
                        const __m128i WW = _mm_set1_epi32(ww.a);
                        const __m128i WX = _mm_set1_epi32(wx.a);
                        const __m128i XX = _mm_set1_epi32(xx.a);
                        int j0 = jh * v;
                        int j1 = j0 + v;
                        int j2 = j1 + v;
                        int j3 = j2 + v;
                        int je = j1;
                        for(; j0 < je; j0 += 4, j1 += 4, j2 += 4, j3 += 4) {
                            const __m128i T0 = _mm_loadu_si128((__m128i *)(a + j0));
                            const __m128i T1 = _mm_loadu_si128((__m128i *)(a + j1));
                            const __m128i T2 = _mm_loadu_si128((__m128i *)(a + j2));
                            const __m128i T3 = _mm_loadu_si128((__m128i *)(a + j3));
                            const __m128i MT1 = montgomery_mul_128(T1, XX, r, m1);
                            const __m128i MT2 = montgomery_mul_128(T2, WW, r, m1);
                            const __m128i MT3 = montgomery_mul_128(T3, WX, r, m1);
                            const __m128i T0P2 = montgomery_add_128(T0, MT2, m2, m0);
                            const __m128i T1P3 = montgomery_add_128(MT1, MT3, m2, m0);
                            const __m128i T0M2 = montgomery_sub_128(T0, MT2, m2, m0);
                            const __m128i T1M3 = montgomery_mul_128(montgomery_sub_128(MT1, MT3, m2, m0), Imag, r, m1);
                            _mm_storeu_si128((__m128i *)(a + j0), montgomery_add_128(T0P2, T1P3, m2, m0));
                            _mm_storeu_si128((__m128i *)(a + j1), montgomery_sub_128(T0P2, T1P3, m2, m0));
                            _mm_storeu_si128((__m128i *)(a + j2), montgomery_add_128(T0M2, T1M3, m2, m0));
                            _mm_storeu_si128((__m128i *)(a + j3), montgomery_sub_128(T0M2, T1M3, m2, m0));
                        }
                    }
                    xx *= dw[__builtin_ctz((jh += 4))];
                }
            } else {
                const __m256i m0 = _mm256_set1_epi32(0);
                const __m256i m1 = _mm256_set1_epi32(mod);
                const __m256i m2 = _mm256_set1_epi32(mod + mod);
                const __m256i r = _mm256_set1_epi32(mint::r);
                const __m256i Imag = _mm256_set1_epi32(imag.a);
                mint ww = one, xx = one, wx = one;
                for(int jh = 0; jh < u;) {
                    if(jh == 0) {
                        int j0 = 0;
                        int j1 = v;
                        int j2 = j1 + v;
                        int j3 = j2 + v;
                        int je = v;
                        for(; j0 < je; j0 += 8, j1 += 8, j2 += 8, j3 += 8) {
                            const __m256i T0 = _mm256_loadu_si256((__m256i *)(a + j0));
                            const __m256i T1 = _mm256_loadu_si256((__m256i *)(a + j1));
                            const __m256i T2 = _mm256_loadu_si256((__m256i *)(a + j2));
                            const __m256i T3 = _mm256_loadu_si256((__m256i *)(a + j3));
                            const __m256i T0P2 = montgomery_add_256(T0, T2, m2, m0);
                            const __m256i T1P3 = montgomery_add_256(T1, T3, m2, m0);
                            const __m256i T0M2 = montgomery_sub_256(T0, T2, m2, m0);
                            const __m256i T1M3 = montgomery_mul_256(montgomery_sub_256(T1, T3, m2, m0), Imag, r, m1);
                            _mm256_storeu_si256((__m256i *)(a + j0), montgomery_add_256(T0P2, T1P3, m2, m0));
                            _mm256_storeu_si256((__m256i *)(a + j1), montgomery_sub_256(T0P2, T1P3, m2, m0));
                            _mm256_storeu_si256((__m256i *)(a + j2), montgomery_add_256(T0M2, T1M3, m2, m0));
                            _mm256_storeu_si256((__m256i *)(a + j3), montgomery_sub_256(T0M2, T1M3, m2, m0));
                        }
                    } else {
                        ww = xx * xx, wx = ww * xx;
                        const __m256i WW = _mm256_set1_epi32(ww.a);
                        const __m256i WX = _mm256_set1_epi32(wx.a);
                        const __m256i XX = _mm256_set1_epi32(xx.a);
                        int j0 = jh * v;
                        int j1 = j0 + v;
                        int j2 = j1 + v;
                        int j3 = j2 + v;
                        int je = j1;
                        for(; j0 < je; j0 += 8, j1 += 8, j2 += 8, j3 += 8) {
                            const __m256i T0 = _mm256_loadu_si256((__m256i *)(a + j0));
                            const __m256i T1 = _mm256_loadu_si256((__m256i *)(a + j1));
                            const __m256i T2 = _mm256_loadu_si256((__m256i *)(a + j2));
                            const __m256i T3 = _mm256_loadu_si256((__m256i *)(a + j3));
                            const __m256i MT1 = montgomery_mul_256(T1, XX, r, m1);
                            const __m256i MT2 = montgomery_mul_256(T2, WW, r, m1);
                            const __m256i MT3 = montgomery_mul_256(T3, WX, r, m1);
                            const __m256i T0P2 = montgomery_add_256(T0, MT2, m2, m0);
                            const __m256i T1P3 = montgomery_add_256(MT1, MT3, m2, m0);
                            const __m256i T0M2 = montgomery_sub_256(T0, MT2, m2, m0);
                            const __m256i T1M3 = montgomery_mul_256(montgomery_sub_256(MT1, MT3, m2, m0), Imag, r, m1);
                            _mm256_storeu_si256((__m256i *)(a + j0), montgomery_add_256(T0P2, T1P3, m2, m0));
                            _mm256_storeu_si256((__m256i *)(a + j1), montgomery_sub_256(T0P2, T1P3, m2, m0));
                            _mm256_storeu_si256((__m256i *)(a + j2), montgomery_add_256(T0M2, T1M3, m2, m0));
                            _mm256_storeu_si256((__m256i *)(a + j3), montgomery_sub_256(T0M2, T1M3, m2, m0));
                        }
                    }
                    xx *= dw[__builtin_ctz((jh += 4))];
                }
            }
            u <<= 2;
            v >>= 2;
        }
    }

    __attribute__((target("avx2"))) void intt(mint *a, int n, int normalize = true) {
        int k = n ? __builtin_ctz(n) : 0;
        if(k == 0) return;
        if(k == 1) {
            mint a1 = a[1];
            a[1] = a[0] - a[1];
            a[0] = a[0] + a1;
            if(normalize) {
                a[0] *= mint(2).inverse();
                a[1] *= mint(2).inverse();
            }
            return;
        }
        int u = 1 << (k - 2);
        int v = 1;
        mint one = mint(1);
        mint imag = dy[1];
        while(u) {
            if(v == 1) {
                mint ww = one, xx = one, yy = one;
                u <<= 2;
                for(int jh = 0; jh < u;) {
                    ww = xx * xx, yy = xx * imag;
                    mint t0 = a[jh + 0], t1 = a[jh + 1];
                    mint t2 = a[jh + 2], t3 = a[jh + 3];
                    mint t0p1 = t0 + t1, t2p3 = t2 + t3;
                    mint t0m1 = (t0 - t1) * xx, t2m3 = (t2 - t3) * yy;
                    a[jh + 0] = t0p1 + t2p3, a[jh + 2] = (t0p1 - t2p3) * ww;
                    a[jh + 1] = t0m1 + t2m3, a[jh + 3] = (t0m1 - t2m3) * ww;
                    xx *= dy[__builtin_ctz(jh += 4)];
                }
            } else if(v == 4) {
                const __m128i m0 = _mm_set1_epi32(0);
                const __m128i m1 = _mm_set1_epi32(mod);
                const __m128i m2 = _mm_set1_epi32(mod + mod);
                const __m128i r = _mm_set1_epi32(mint::r);
                const __m128i Imag = _mm_set1_epi32(imag.a);
                mint ww = one, xx = one, yy = one;
                u <<= 2;
                for(int jh = 0; jh < u;) {
                    if(jh == 0) {
                        int j0 = 0;
                        int j1 = v;
                        int j2 = v + v;
                        int j3 = j2 + v;
                        for(; j0 < v; j0 += 4, j1 += 4, j2 += 4, j3 += 4) {
                            const __m128i T0 = _mm_loadu_si128((__m128i *)(a + j0));
                            const __m128i T1 = _mm_loadu_si128((__m128i *)(a + j1));
                            const __m128i T2 = _mm_loadu_si128((__m128i *)(a + j2));
                            const __m128i T3 = _mm_loadu_si128((__m128i *)(a + j3));
                            const __m128i T0P1 = montgomery_add_128(T0, T1, m2, m0);
                            const __m128i T2P3 = montgomery_add_128(T2, T3, m2, m0);
                            const __m128i T0M1 = montgomery_sub_128(T0, T1, m2, m0);
                            const __m128i T2M3 = montgomery_mul_128(montgomery_sub_128(T2, T3, m2, m0), Imag, r, m1);
                            _mm_storeu_si128((__m128i *)(a + j0), montgomery_add_128(T0P1, T2P3, m2, m0));
                            _mm_storeu_si128((__m128i *)(a + j2), montgomery_sub_128(T0P1, T2P3, m2, m0));
                            _mm_storeu_si128((__m128i *)(a + j1), montgomery_add_128(T0M1, T2M3, m2, m0));
                            _mm_storeu_si128((__m128i *)(a + j3), montgomery_sub_128(T0M1, T2M3, m2, m0));
                        }
                    } else {
                        ww = xx * xx, yy = xx * imag;
                        const __m128i WW = _mm_set1_epi32(ww.a);
                        const __m128i XX = _mm_set1_epi32(xx.a);
                        const __m128i YY = _mm_set1_epi32(yy.a);
                        int j0 = jh * v;
                        int j1 = j0 + v;
                        int j2 = j1 + v;
                        int j3 = j2 + v;
                        int je = j1;
                        for(; j0 < je; j0 += 4, j1 += 4, j2 += 4, j3 += 4) {
                            const __m128i T0 = _mm_loadu_si128((__m128i *)(a + j0));
                            const __m128i T1 = _mm_loadu_si128((__m128i *)(a + j1));
                            const __m128i T2 = _mm_loadu_si128((__m128i *)(a + j2));
                            const __m128i T3 = _mm_loadu_si128((__m128i *)(a + j3));
                            const __m128i T0P1 = montgomery_add_128(T0, T1, m2, m0);
                            const __m128i T2P3 = montgomery_add_128(T2, T3, m2, m0);
                            const __m128i T0M1 = montgomery_mul_128(montgomery_sub_128(T0, T1, m2, m0), XX, r, m1);
                            __m128i T2M3 = montgomery_mul_128(montgomery_sub_128(T2, T3, m2, m0), YY, r, m1);
                            _mm_storeu_si128((__m128i *)(a + j0), montgomery_add_128(T0P1, T2P3, m2, m0));
                            _mm_storeu_si128((__m128i *)(a + j2), montgomery_mul_128(montgomery_sub_128(T0P1, T2P3, m2, m0), WW, r, m1));
                            _mm_storeu_si128((__m128i *)(a + j1), montgomery_add_128(T0M1, T2M3, m2, m0));
                            _mm_storeu_si128((__m128i *)(a + j3), montgomery_mul_128(montgomery_sub_128(T0M1, T2M3, m2, m0), WW, r, m1));
                        }
                    }
                    xx *= dy[__builtin_ctz(jh += 4)];
                }
            } else {
                const __m256i m0 = _mm256_set1_epi32(0);
                const __m256i m1 = _mm256_set1_epi32(mod);
                const __m256i m2 = _mm256_set1_epi32(mod + mod);
                const __m256i r = _mm256_set1_epi32(mint::r);
                const __m256i Imag = _mm256_set1_epi32(imag.a);
                mint ww = one, xx = one, yy = one;
                u <<= 2;
                for(int jh = 0; jh < u;) {
                    if(jh == 0) {
                        int j0 = 0;
                        int j1 = v;
                        int j2 = v + v;
                        int j3 = j2 + v;
                        for(; j0 < v; j0 += 8, j1 += 8, j2 += 8, j3 += 8) {
                            const __m256i T0 = _mm256_loadu_si256((__m256i *)(a + j0));
                            const __m256i T1 = _mm256_loadu_si256((__m256i *)(a + j1));
                            const __m256i T2 = _mm256_loadu_si256((__m256i *)(a + j2));
                            const __m256i T3 = _mm256_loadu_si256((__m256i *)(a + j3));
                            const __m256i T0P1 = montgomery_add_256(T0, T1, m2, m0);
                            const __m256i T2P3 = montgomery_add_256(T2, T3, m2, m0);
                            const __m256i T0M1 = montgomery_sub_256(T0, T1, m2, m0);
                            const __m256i T2M3 = montgomery_mul_256(montgomery_sub_256(T2, T3, m2, m0), Imag, r, m1);
                            _mm256_storeu_si256((__m256i *)(a + j0), montgomery_add_256(T0P1, T2P3, m2, m0));
                            _mm256_storeu_si256((__m256i *)(a + j2), montgomery_sub_256(T0P1, T2P3, m2, m0));
                            _mm256_storeu_si256((__m256i *)(a + j1), montgomery_add_256(T0M1, T2M3, m2, m0));
                            _mm256_storeu_si256((__m256i *)(a + j3), montgomery_sub_256(T0M1, T2M3, m2, m0));
                        }
                    } else {
                        ww = xx * xx, yy = xx * imag;
                        const __m256i WW = _mm256_set1_epi32(ww.a);
                        const __m256i XX = _mm256_set1_epi32(xx.a);
                        const __m256i YY = _mm256_set1_epi32(yy.a);
                        int j0 = jh * v;
                        int j1 = j0 + v;
                        int j2 = j1 + v;
                        int j3 = j2 + v;
                        int je = j1;
                        for(; j0 < je; j0 += 8, j1 += 8, j2 += 8, j3 += 8) {
                            const __m256i T0 = _mm256_loadu_si256((__m256i *)(a + j0));
                            const __m256i T1 = _mm256_loadu_si256((__m256i *)(a + j1));
                            const __m256i T2 = _mm256_loadu_si256((__m256i *)(a + j2));
                            const __m256i T3 = _mm256_loadu_si256((__m256i *)(a + j3));
                            const __m256i T0P1 = montgomery_add_256(T0, T1, m2, m0);
                            const __m256i T2P3 = montgomery_add_256(T2, T3, m2, m0);
                            const __m256i T0M1 = montgomery_mul_256(montgomery_sub_256(T0, T1, m2, m0), XX, r, m1);
                            const __m256i T2M3 = montgomery_mul_256(montgomery_sub_256(T2, T3, m2, m0), YY, r, m1);
                            _mm256_storeu_si256((__m256i *)(a + j0), montgomery_add_256(T0P1, T2P3, m2, m0));
                            _mm256_storeu_si256((__m256i *)(a + j2), montgomery_mul_256(montgomery_sub_256(T0P1, T2P3, m2, m0), WW, r, m1));
                            _mm256_storeu_si256((__m256i *)(a + j1), montgomery_add_256(T0M1, T2M3, m2, m0));
                            _mm256_storeu_si256((__m256i *)(a + j3), montgomery_mul_256(montgomery_sub_256(T0M1, T2M3, m2, m0), WW, r, m1));
                        }
                    }
                    xx *= dy[__builtin_ctz(jh += 4)];
                }
            }
            u >>= 4;
            v <<= 2;
        }
        if(k & 1) {
            v = 1 << (k - 1);
            if(v < 8) {
                for(int j = 0; j < v; ++j) {
                    mint ajv = a[j] - a[j + v];
                    a[j] += a[j + v];
                    a[j + v] = ajv;
                }
            } else {
                const __m256i m0 = _mm256_set1_epi32(0);
                const __m256i m2 = _mm256_set1_epi32(mod + mod);
                int j0 = 0;
                int j1 = v;
                for(; j0 < v; j0 += 8, j1 += 8) {
                    const __m256i T0 = _mm256_loadu_si256((__m256i *)(a + j0));
                    const __m256i T1 = _mm256_loadu_si256((__m256i *)(a + j1));
                    __m256i naj = montgomery_add_256(T0, T1, m2, m0);
                    __m256i najv = montgomery_sub_256(T0, T1, m2, m0);
                    _mm256_storeu_si256((__m256i *)(a + j0), naj);
                    _mm256_storeu_si256((__m256i *)(a + j1), najv);
                }
            }
        }
        if(normalize) {
            mint invn = mint(n).inverse();
            for(int i = 0; i < n; i++) a[i] *= invn;
        }
    }

    __attribute__((target("avx2"))) void inplace_multiply(int l1, int l2, int zero_padding = true) {
        int l = l1 + l2 - 1;
        int M = 4;
        while(M < l) M <<= 1;
        if(zero_padding) {
            for(int i = l1; i < M; i++) ntt_inner::_buf1[i] = 0;
            for(int i = l2; i < M; i++) ntt_inner::_buf2[i] = 0;
        }
        const __m256i m0 = _mm256_set1_epi32(0);
        const __m256i m1 = _mm256_set1_epi32(mod);
        const __m256i r = _mm256_set1_epi32(mint::r);
        const __m256i N2 = _mm256_set1_epi32(mint::n2);
        for(int i = 0; i < l1; i += 8) {
            __m256i a = _mm256_loadu_si256((__m256i *)(ntt_inner::_buf1 + i));
            __m256i b = montgomery_mul_256(a, N2, r, m1);
            _mm256_storeu_si256((__m256i *)(ntt_inner::_buf1 + i), b);
        }
        for(int i = 0; i < l2; i += 8) {
            __m256i a = _mm256_loadu_si256((__m256i *)(ntt_inner::_buf2 + i));
            __m256i b = montgomery_mul_256(a, N2, r, m1);
            _mm256_storeu_si256((__m256i *)(ntt_inner::_buf2 + i), b);
        }
        ntt(buf1, M);
        ntt(buf2, M);
        for(int i = 0; i < M; i += 8) {
            __m256i a = _mm256_loadu_si256((__m256i *)(ntt_inner::_buf1 + i));
            __m256i b = _mm256_loadu_si256((__m256i *)(ntt_inner::_buf2 + i));
            __m256i c = montgomery_mul_256(a, b, r, m1);
            _mm256_storeu_si256((__m256i *)(ntt_inner::_buf1 + i), c);
        }
        intt(buf1, M, false);
        const __m256i INVM = _mm256_set1_epi32((mint(M).inverse()).a);
        for(int i = 0; i < l; i += 8) {
            __m256i a = _mm256_loadu_si256((__m256i *)(ntt_inner::_buf1 + i));
            __m256i b = montgomery_mul_256(a, INVM, r, m1);
            __m256i c = my256_mulhi_epu32(my256_mullo_epu32(b, r), m1);
            __m256i d = _mm256_and_si256(_mm256_cmpgt_epi32(c, m0), m1);
            __m256i e = _mm256_sub_epi32(d, c);
            _mm256_storeu_si256((__m256i *)(ntt_inner::_buf1 + i), e);
        }
    }

    void ntt(vector<mint> &a) {
        int M = (int)a.size();
        for(int i = 0; i < M; i++) buf1[i].a = a[i].a;
        ntt(buf1, M);
        for(int i = 0; i < M; i++) a[i].a = buf1[i].a;
    }

    void intt(vector<mint> &a) {
        int M = (int)a.size();
        for(int i = 0; i < M; i++) buf1[i].a = a[i].a;
        intt(buf1, M, true);
        for(int i = 0; i < M; i++) a[i].a = buf1[i].a;
    }

    vector<mint> multiply(const vector<mint> &a, const vector<mint> &b) {
        if(a.size() == 0 && b.size() == 0) return vector<mint>{};
        int l = a.size() + b.size() - 1;
        if(min<int>(a.size(), b.size()) <= 40) {
            vector<mint> s(l);
            for(int i = 0; i < (int)a.size(); ++i)
                for(int j = 0; j < (int)b.size(); ++j) s[i + j] += a[i] * b[j];
            return s;
        }
        assert(l <= ntt_inner::SZ_FFT_BUF);
        int M = 4;
        while(M < l) M <<= 1;
        for(int i = 0; i < (int)a.size(); ++i) buf1[i].a = a[i].a;
        for(int i = (int)a.size(); i < M; ++i) buf1[i].a = 0;
        for(int i = 0; i < (int)b.size(); ++i) buf2[i].a = b[i].a;
        for(int i = (int)b.size(); i < M; ++i) buf2[i].a = 0;
        ntt(buf1, M);
        ntt(buf2, M);
        for(int i = 0; i < M; ++i) buf1[i].a = mint::reduce(uint64_t(buf1[i].a) * buf2[i].a);
        intt(buf1, M, false);
        vector<mint> s(l);
        mint invm = mint(M).inverse();
        for(int i = 0; i < l; ++i) s[i] = buf1[i] * invm;
        return s;
    }

    void ntt_doubling(vector<mint> &a) {
        int M = (int)a.size();
        for(int i = 0; i < M; i++) buf1[i].a = a[i].a;
        intt(buf1, M);
        mint r = 1, zeta = mint(pr).pow((mint::get_mod() - 1) / (M << 1));
        for(int i = 0; i < M; i++) buf1[i] *= r, r *= zeta;
        ntt(buf1, M);
        a.resize(2 * M);
        for(int i = 0; i < M; i++) a[M + i].a = buf1[i].a;
    }
};
#line 2 "library/fps/formal-power-series.hpp"

using mint = LazyMontgomeryModInt<998244353>;
using vmint = vector<mint>;
Binomial<mint> binomial;
mint inv(int i) { return binomial.inv(i); }
mint C(int r, int c) { return binomial.C(r, c); }
mint P(int r, int c) { return binomial.P(r, c); }
mint fact(int r) { return binomial.fac(r); }
mint ifact(int r) { return binomial.finv(r); }

} // namespace Modular998

using namespace Modular998;

mint dp[720720];

int main() {
    INT(n, a0, x, y, k, M);
    constexpr ll L = 720720;
    binomial = Binomial<mint>((int)L + 1);
    vmint dp(L);
    mint ans;

    mint T = mint(k) * mint(n).pow(k - 1);
    ll e = a0;
    rep(n) {
        int s = e % L;
        dp[s] += 1;
        ans += T * (e - s);
        e = (e * x + y) % M;
    }

    mint S = mint(n).pow(k - 1);
    rep(m, 1, k + 1) {
        rep(i, L) {
            ans += dp[i] * i * S;
            mint mem = dp[i];
            dp[i] *= n - 1;
            dp[i - i % m] += mem;
        }
        S *= inv(n);
    }
    OUT(ans);
}