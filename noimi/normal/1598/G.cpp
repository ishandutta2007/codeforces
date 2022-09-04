#pragma region Macros
#pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,avx2,tune=native")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,avx2")
// #pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define ll long long
using ld = long double;
#define rep2(i, a, b) for(ll i = (a); i <= (b); i++)
#define rep3(i, a, b) for(ll i = (a); i >= (b); --i)
#define rep(i, n) for(ll i = 0; i < n; ++i)
#define each(i, a) for(auto &&i : a)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define eb emplace_back
#define vi vector<int>
#define vll vector<ll>
#define vpi vector<pii>
#define vpll vector<pll>
#define overload2(_1, _2, name, ...) name
#define vec(type, name, ...) vector<type> name(__VA_ARGS__)
#define VEC(type, name, size)                                                                                                                                  \
    vector<type> name(size);                                                                                                                                   \
    IN(name)
#define VEC2(type, name1, name2, size)                                                                                                                         \
    vector<type> name1(size), name2(size);                                                                                                                     \
    for(int i = 0; i < size; i++) IN(name1[i], name2[i])
#define VEC3(type, name1, name2, name3, size)                                                                                                                  \
    vector<type> name1(size), name2(size), name3(size);                                                                                                        \
    for(int i = 0; i < size; i++) IN(name1[i], name2[i], name3[i])
#define vv(type, name, h, ...) vector<vector<type>> name(h, vector<type>(__VA_ARGS__))
#define VV(type, name, h, w)                                                                                                                                   \
    vector<vector<type>> name(h, vector<type>(w));                                                                                                             \
    IN(name)
#define vvv(type, name, h, w, ...) vector<vector<vector<type>>> name(h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))
#define vvvv(type, name, a, b, c, ...)                                                                                                                         \
    vector<vector<vector<vector<type>>>> name(a, vector<vector<vector<type>>>(b, vector<vector<type>>(c, vector<type>(__VA_ARGS__))))
#define mt make_tuple
#define fi first
#define se second
#define all(c) begin(c), end(c)
#define rall(c) rbegin(c), rend(c)
#define SORT(v) sort(all(v))
#define REV(v) reverse(all(v))
template <class T = ll, class S> T SUM(const S &v) { return accumulate(all(v), T(0)); }
#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))
#define lb(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define ub(c, x) distance((c).begin(), upper_bound(all(c), (x)))
using namespace std;
constexpr pii dx4[4] = {pii{1, 0}, pii{0, 1}, pii{-1, 0}, pii{0, -1}};
constexpr pii dx8[8] = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
const string YESNO[2] = {"NO", "YES"};
const string YesNo[2] = {"No", "Yes"};
const string yesno[2] = {"no", "yes"};
void YES(bool t = 1) { cout << YESNO[t] << endl; }
void NO(bool t = 1) { YES(!t); }
void Yes(bool t = 1) { cout << YesNo[t] << endl; }
void No(bool t = 1) { Yes(!t); }
void yes(bool t = 1) { cout << yesno[t] << endl; }
void no(bool t = 1) { yes(!t); }
template <class T> using vc = vector<T>;
template <class T> using vvc = vector<vc<T>>;
template <class T> using vvvc = vector<vvc<T>>;
template <class T> using vvvvc = vector<vvvc<T>>;
template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
#define si(c) (int)(c).size()
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

template <class T, class S> inline bool chmax(T &a, const S &b) { return (a < b ? a = b, 1 : 0); }
template <class T, class S> inline bool chmin(T &a, const S &b) { return (a > b ? a = b, 1 : 0); }
vi iota(int n) {
    vi a(n);
    iota(all(a), 0);
    return a;
}
template <typename T> vi iota(vector<T> &a, bool greater = false) {
    vi res(a.size());
    iota(all(res), 0);
    sort(all(res), [&](int i, int j) {
        if(greater) return a[i] > a[j];
        return a[i] < a[j];
    });
    return res;
}
#define UNIQUE(x) sort(all(x)), x.erase(unique(all(x)), x.end())

template <class T> T ceil(T x, T y) {
    assert(y >= 1);
    return (x > 0 ? (x + y - 1) / y : x / y);
}

template <class T> T floor(T x, T y) {
    assert(y >= 1);
    return (x > 0 ? x / y : (x + y - 1) / y);
}
template <class T> T POW(T x, int n) {
    T res = 1;
    for(; n; n >>= 1, x *= x)
        if(n & 1) res *= x;
    return res;
}
template <class T, class S> T POW(T x, S n, const ll &mod) {
    T res = 1;
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

// x in [l, r)
template <class T, class S> bool inc(const T &x, const S &l, const S &r) { return l <= x and x < r; }
// (a, b) in [lx, rx) * [ly, ry)
template <class T, class S> bool inc(const pair<T, T> &x, const S &lx, const S &ly, const S &rx, const S &ry) { return inc(x.fi, lx, rx) && inc(x.se, ly, ry); }

constexpr ll ten(int n) { return n == 0 ? 1 : ten(n - 1) * 10; }
// bit 
ll pow2(int i) { return 1LL << i; }
int topbit(signed t) { return t == 0 ? -1 : 31 - __builtin_clz(t); }
int topbit(ll t) { return t == 0 ? -1 : 63 - __builtin_clzll(t); }
int lowbit(signed a) { return a == 0 ? 32 : __builtin_ctz(a); }
int lowbit(ll a) { return a == 0 ? 64 : __builtin_ctzll(a); }
// int allbit(int n) { return (1 << n) - 1; }
ll allbit(ll n) { return (1LL << n) - 1; }
int popcount(signed t) { return __builtin_popcount(t); }
int popcount(ll t) { return __builtin_popcountll(t); }
bool ispow2(int i) { return i && (i & -i) == i; }

ll rnd(ll l, ll r) { //[l, r)
#ifdef _LOCAL
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

template <class T> ll operator*(const pair<T, T> &x, const pair<T, T> &y) { return (ll)x.fi * y.fi + (ll)x.se * y.se; }

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
        cin >> a >> b >> c;
        a -= margin, b -= margin;
        res[a].emplace_back(b, c);
        if(!directed) res[b].emplace_back(a, c);
    }
    return res;
}
void add(Graph &G, int x, int y) { G[x].eb(y), G[y].eb(x); }
template <class S, class T> void add(Wgraph<S> &G, int x, int y, T c) { G[x].eb(y, c), G[y].eb(x, c); }

#define i128 __int128_t
#define ull unsigned long long int
#define TEST                                                                                                                                                   \
    INT(testcases);                                                                                                                                            \
    while(testcases--)
template <class T> ostream &operator<<(ostream &os, const vector<T> &v) {
    for(auto it = begin(v); it != end(v); ++it) {
        if(it == begin(v))
            os << *it;
        else
            os << " " << *it;
    }
    return os;
}
template <class T, class S> ostream &operator<<(ostream &os, const pair<T, S> &p) {
    os << p.first << " " << p.second;
    return os;
}
template <class S, class T> string to_string(pair<S, T> p) { return "(" + to_string(p.first) + "," + to_string(p.second) + ")"; }
string to_string(string s) { return "\"" + s + "\""; }
string to_string(char c) { return string(1, c); }
template <class T> string to_string(vector<T> s) {
    string res = "{";
    for(auto it = s.begin(); it != s.end(); it++) res += to_string(*it) + (next(it) == s.end() ? "" : ", ");
    return res + "}";
}
template <class T> string to_string(set<T> s) {
    string res = "{";
    for(auto it = s.begin(); it != s.end(); it++) res += to_string(*it), res += (next(it) == end(s) ? "" : ", ");
    return res + "}";
}

#define endl '\n'

#ifdef _LOCAL
void dump() { cerr << endl; }
template <class Head, class... Tail> void dump(Head head, Tail... tail) {
    cerr << to_string(head) << " ";
    dump(tail...);
}
#undef endl
#define debug(x)                                                                                                                                               \
    cout << #x << ": ";                                                                                                                                        \
    dump(x)
#else
void dump() {}
template <class Head, class... Tail> void dump(Head head, Tail... tail) {}
#define debug(x)
#endif
template <class T> void print(const T &a) { cout << a; }
void OUT() { cout << endl; }
template <class Head, class... Tail> void OUT(const Head &head, const Tail &...tail) {
    print(head);
    if(sizeof...(tail)) cout << ' ';
    OUT(tail...);
}

template <typename T> static constexpr T inf = numeric_limits<T>::max() / 2;
struct Setup_io {
    Setup_io() {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        cout << fixed << setprecision(15);
    }
} setup_io;
#define drop(s) cout << #s << endl, exit(0)

template <int N> struct ndFORarray {
    std::array<int, N> v;
    ndFORarray(std::array<int, N> v_) : v(v_) {}
    struct ndFORitr {
        const std::array<int, N> &v;
        std::array<int, N> tmp;
        bool is_end;
        ndFORitr(const std::array<int, N> &v_) : v(v_), tmp(), is_end(false) {}
        bool operator!=(const ndFORitr &) const { return !is_end; }
        void operator++() {
            int pos = N - 1;
            while(pos != -1) {
                tmp[pos] += 1;
                if(tmp[pos] == v[pos]) {
                    tmp[pos] = 0;
                    pos -= 1;
                } else {
                    break;
                }
            }
            if(pos == -1) { is_end = true; }
        }
        const std::array<int, N> &operator*() const { return tmp; }
    };
    ndFORitr begin() const { return ndFORitr(v); }
    ndFORitr end() const { return ndFORitr(v); }
};

struct ndFORvector {
    std::vector<int> v;
    ndFORvector(std::vector<int> v_) : v(v_) {}
    struct ndFORitr {
        const std::vector<int> &v;
        std::vector<int> tmp;
        bool is_end;
        ndFORitr(const std::vector<int> &v_) : v(v_), tmp(v.size(), 0), is_end(false) {}
        bool operator!=(const ndFORitr &) const { return !is_end; }
        void operator++() {
            int pos = v.size() - 1;
            while(pos != -1) {
                tmp[pos] += 1;
                if(tmp[pos] == v[pos]) {
                    tmp[pos] = 0;
                    pos -= 1;
                } else {
                    break;
                }
            }
            if(pos == -1) { is_end = true; }
        }
        const std::vector<int> &operator*() const { return tmp; }
    };
    ndFORitr begin() const { return ndFORitr(v); }
    ndFORitr end() const { return ndFORitr(v); }
};

auto ndFOR(std::vector<int> v) { return ndFORvector(v); }
template <class... Ts> auto ndFOR(Ts... v) { return ndFORarray<std::tuple_size<std::tuple<Ts...>>::value>({v...}); }
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

template <class T = int> struct Imos {
    int n;
    vector<T> a;
    Imos(int _n) : n(_n), a(_n + 1) {}
    void add(int l, int r, T val = 1) {
        if(l >= r) return;
        l = clamp(l, 0, n);
        r = clamp(r, 0, n + 1);
        a[l] += val;
        if(r <= n) a[r] -= val;
    }
    void build() {
        for(int i = 0; i < n; i++) a[i + 1] += a[i];
    }
    const T &operator[](int k) { return a[k]; }
};

template <class T> struct RUI {
    vector<T> a;
    RUI(const vector<T> &v) : a(v.size() + 1) {
        for(int i = 0; i < v.size(); i++) a[i + 1] = a[i] + v[i];
    }
    T get(int l, int r) { return a[r] - a[l]; }
};

template <class T, class F> T bin_search(T ok, T ng, const F &f) {
    while(abs(ok - ng) > 1) {
        T mid = ok + ng >> 1;
        (f(mid) ? ok : ng) = mid;
    }
    return ok;
}
#pragma endregion

const vector<int> MODS{
    1000000007, 1000000009, 1000000021, 1000000033, 1000000087, 1000000093, 1000000097, 1000000103, 1000000123, 1000000181, 1000000207, 1000000223, 1000000241,
    1000000271, 1000000289, 1000000297, 1000000321, 1000000349, 1000000363, 1000000403, 1000000409, 1000000411, 1000000427, 1000000433, 1000000439, 1000000447,
    1000000453, 1000000459, 1000000483, 1000000513, 1000000531, 1000000579, 1000000607, 1000000613, 1000000637, 1000000663, 1000000711, 1000000753, 1000000787,
    1000000801, 1000000829, 1000000861, 1000000871, 1000000891, 1000000901, 1000000919, 1000000931, 1000000933, 1000000993, 1000001011, 1000001021, 1000001053,
    1000001087, 1000001099, 1000001137, 1000001161, 1000001203, 1000001213, 1000001237, 1000001263, 1000001269, 1000001273, 1000001279, 1000001311, 1000001329,
    1000001333, 1000001351, 1000001371, 1000001393, 1000001413, 1000001447, 1000001449, 1000001491, 1000001501, 1000001531, 1000001537, 1000001539, 1000001581,
    1000001617, 1000001621, 1000001633, 1000001647, 1000001663, 1000001677, 1000001699, 1000001759, 1000001773, 1000001789, 1000001791, 1000001801, 1000001803,
    1000001819, 1000001857, 1000001887, 1000001917, 1000001927, 1000001957, 1000001963, 1000001969, 1000002043, 1000002089, 1000002103, 1000002139, 1000002149,
    1000002161, 1000002173, 1000002187, 1000002193, 1000002233, 1000002239, 1000002277, 1000002307, 1000002359, 1000002361, 1000002431, 1000002449, 1000002457,
    1000002499, 1000002571, 1000002581, 1000002607, 1000002631, 1000002637, 1000002649, 1000002667, 1000002727, 1000002791, 1000002803, 1000002821, 1000002823,
    1000002827, 1000002907, 1000002937, 1000002989, 1000003009, 1000003013, 1000003051, 1000003057, 1000003097, 1000003111, 1000003133, 1000003153, 1000003157,
    1000003163, 1000003211, 1000003241, 1000003247, 1000003253, 1000003267, 1000003271, 1000003273, 1000003283, 1000003309, 1000003337, 1000003351, 1000003357,
    1000003373, 1000003379, 1000003397, 1000003469, 1000003471, 1000003513, 1000003519, 1000003559, 1000003577, 1000003579, 1000003601, 1000003621, 1000003643,
    1000003651, 1000003663, 1000003679, 1000003709, 1000003747, 1000003751, 1000003769, 1000003777, 1000003787, 1000003793, 1000003843, 1000003853, 1000003871,
    1000003889, 1000003891, 1000003909, 1000003919, 1000003931, 1000003951, 1000003957, 1000003967, 1000003987, 1000003999, 1000004023, 1000004059, 1000004099,
    1000004119, 1000004123, 1000004207, 1000004233, 1000004249, 1000004251, 1000004263, 1000004321, 1000004329, 1000004381, 1000004389, 1000004437, 1000004449,
    1000004459, 1000004497, 1000004507, 1000004519, 1000004539, 1000004567, 1000004569, 1000004581, 1000004609, 1000004611, 1000004627, 1000004633, 1000004647,
    1000004693, 1000004699, 1000004717, 1000004771, 1000004777, 1000004783, 1000004791, 1000004807, 1000004839, 1000004843, 1000004849, 1000004857, 1000004867,
    1000004869, 1000004891, 1000004893, 1000004897, 1000004927, 1000004933, 1000004977, 1000004981, 1000005001, 1000005029, 1000005053, 1000005067, 1000005103,
    1000005133, 1000005187, 1000005197, 1000005203, 1000005233, 1000005277, 1000005287, 1000005299, 1000005317, 1000005329, 1000005341, 1000005353, 1000005361,
    1000005403, 1000005407, 1000005437, 1000005443, 1000005449, 1000005451, 1000005469, 1000005491, 1000005527, 1000005541, 1000005547, 1000005583, 1000005631,
    1000005647, 1000005683, 1000005731, 1000005737, 1000005751, 1000005763, 1000005791, 1000005823, 1000005827, 1000005833, 1000005847, 1000005863, 1000005899,
    1000005907, 1000005947, 1000005953, 1000005959, 1000005971, 1000005973, 1000005991, 1000005997, 1000006019, 1000006027, 1000006037, 1000006039, 1000006061,
    1000006093, 1000006099, 1000006127, 1000006129, 1000006177, 1000006193, 1000006211, 1000006223, 1000006229, 1000006307, 1000006313, 1000006331, 1000006349,
    1000006379, 1000006393, 1000006417, 1000006421, 1000006457, 1000006459, 1000006477, 1000006541, 1000006571, 1000006577, 1000006583, 1000006607, 1000006621,
    1000006661, 1000006663, 1000006697, 1000006717, 1000006751, 1000006781, 1000006837, 1000006867, 1000006901, 1000006957, 1000006961, 1000006967, 1000006981,
    1000007003, 1000007023, 1000007027, 1000007089, 1000007117, 1000007137, 1000007147, 1000007159, 1000007191, 1000007209, 1000007237, 1000007243, 1000007257,
    1000007279, 1000007321, 1000007347, 1000007383, 1000007389, 1000007417, 1000007429, 1000007447, 1000007453, 1000007467, 1000007479, 1000007497, 1000007513,
    1000007521, 1000007531, 1000007537, 1000007557, 1000007633, 1000007647, 1000007651, 1000007653, 1000007681, 1000007707, 1000007719, 1000007741, 1000007759,
    1000007773, 1000007803, 1000007819, 1000007837, 1000007873, 1000007887, 1000007909, 1000007923, 1000007927, 1000007929, 1000007941, 1000008041, 1000008083,
    1000008089, 1000008101, 1000008109, 1000008127, 1000008173, 1000008181, 1000008223, 1000008257, 1000008259, 1000008271, 1000008277, 1000008311, 1000008313,
    1000008343, 1000008349, 1000008397, 1000008403, 1000008419, 1000008431, 1000008439, 1000008487, 1000008511, 1000008557, 1000008593, 1000008617, 1000008637,
    1000008649, 1000008661, 1000008671, 1000008679, 1000008719, 1000008727, 1000008761, 1000008773, 1000008791, 1000008797, 1000008803, 1000008811, 1000008829,
    1000008853, 1000008899, 1000008917, 1000008937, 1000008967, 1000009009, 1000009013, 1000009063, 1000009081, 1000009093, 1000009099, 1000009123, 1000009133,
    1000009163, 1000009183, 1000009211, 1000009223, 1000009259, 1000009277, 1000009279, 1000009289, 1000009301, 1000009321, 1000009331, 1000009363, 1000009399,
    1000009403, 1000009421, 1000009441, 1000009457, 1000009469, 1000009487, 1000009519, 1000009529, 1000009531, 1000009541, 1000009559, 1000009561, 1000009567,
    1000009573, 1000009579, 1000009597, 1000009601, 1000009609, 1000009631, 1000009651, 1000009667, 1000009679, 1000009711, 1000009733, 1000009739, 1000009757,
    1000009789, 1000009831, 1000009859, 1000009867, 1000009961, 1000009999};

vi mods;

int mul(int x, int y, int i) { return 1LL * x * y % mods[i]; }
int add(int x, int y, int i) { return ((x += y) >= mods[i] ? x - mods[i] : x); }
int sub(int x, int y, int i) { return ((x -= y) < 0 ? x + mods[i] : x); }

template <typename T = long long> struct SegmentTree {
    using F = function<T(T, T)>;
#define clz(x) __builtin_clz(x)

    SegmentTree(int n, const F f, const T &unit) : f(f), unit(unit), sz(n - 1 ? 1 << (32 - clz(n - 1)) : 1) { seg.assign(2 * sz, unit); }

    SegmentTree(vector<T> &a, const F f, const T &unit) : f(f), sz((int)a.size() > 1 ? 1 << (32 - clz(a.size() - 1)) : 1), unit(unit) {
        int n0 = a.size();
        seg.assign(2 * sz, unit);
        for(int i = 0; i < n0; ++i) seg[i + sz] = a[i];
        for(int i = sz - 1; i > 0; --i) seg[i] = f(seg[i << 1], seg[(i << 1) | 1]);
    }
    const int sz;
    vector<T> seg;
    const F f;
    const T unit;

    void set(int k, T x) { seg[k + sz] = x; }

    void build() {
        for(int i = sz - 1; i > 0; --i) seg[i] = f(seg[i << 1], seg[(i << 1) | 1]);
    }

    T query(int l, int r) {
        T x = unit;
        for(int d = r - l; d >= 1; d = r - l) {
            int L = l | ((1U << 31) >> clz(d));
            int k = __builtin_ctz(L);
            x = f(x, seg[(sz | l) >> k]);
            l += L & (-L);
        }
        return x;
    }

    void update(int i, T x) {
        int k = i + sz;
        seg[k] = x;
        for(k = k >> 1; k > 0; k >>= 1) { seg[k] = f(seg[k << 1], seg[(k << 1) | 1]); }
    }

    void add(int i, T x) {
        int k = i + sz;
        seg[k] += x;
        for(k = k >> 1; k > 0; k >>= 1) { seg[k] = f(seg[k << 1], seg[(k << 1) | 1]); }
    }
    SegmentTree() = default;
    T operator[](int k) const { return seg[sz + k]; }
};

template <typename T> ostream &operator<<(ostream &os, SegmentTree<T> &seg) {
    rep(i, seg.sz) os << seg[i] << " ";
    os << endl;
    return os;
}
template <typename T> struct RMQ : SegmentTree<T> {
    RMQ(int n)
        : SegmentTree<T>(
              n, [](T i, T j) { return max(i, j); }, numeric_limits<T>::min()) {}
    RMQ(vector<T> &a)
        : SegmentTree<T>(
              a, [](T i, T j) { return max(i, j); }, numeric_limits<T>::min()) {}
};

template <typename T> struct RmQ : SegmentTree<T> {
    RmQ(int n)
        : SegmentTree<T>(
              n, [](T i, T j) { return min(i, j); }, numeric_limits<T>::max()) {}
    RmQ(vector<T> &a)
        : SegmentTree<T>(
              a, [](T i, T j) { return min(i, j); }, numeric_limits<T>::max()) {}
};

template <typename T> struct RST : SegmentTree<T> {
    RST(int n) : SegmentTree<T>(n, plus<T>(), 0) {}
    RST(vector<T> &a) : SegmentTree<T>(a, plus<T>(), 0) {}
};

constexpr int M = 8;
struct S {
    array<int, M> a, m;
    S() { rep(i, M) a[i] = 0, m[i] = 1; }
};

S f(S x, S y) {
    S res;
    rep(i, M) {
        res.a[i] = add(mul(x.a[i], y.m[i], i), y.a[i], i);
        res.m[i] = mul(x.m[i], y.m[i], i);
    }
    return res;
}

// string ver
vector<int> z_algorithm(const string &s) {
    int n = s.size();
    vector<int> res(n);
    for(int i = 1, j = 0; i < s.size(); i++) {
        if(i + res[i - j] < j + res[j]) {
            res[i] = res[i - j];
        } else {
            int k = max(0, j + res[j] - i);
            while(i + k < n and s[k] == s[i + k]) ++k;
            res[i] = k, j = i;
        }
    }
    res[0] = n;
    return res;
}

int main() {
    {
        set<int> s;
        while(si(s) < M) {
            int i = MODS[rnd(si(MODS))];
            s.emplace(i);
        }
        for(auto e : s) mods.eb(e);
    }

    STR(s, x);
    int n = si(s);

    vector<array<int, M>> rui(n + 1);
    rep(i, M) rui[0][i] = 0;
    rep(i, n) {
        rep(j, M) { rui[i + 1][j] = add(mul(rui[i][j], 10, j), s[i] - '0', j); }
    }

    vector<array<int, M>> pows(n + 1);
    rep(i, M) pows[0][i] = 1;
    rep(i, M) pows[1][i] = 10;
    rep2(i, 1, n - 1) { rep(j, M) pows[i + 1][j] = mul(pows[i][j], pows[1][j], j); }

    int m = si(x);
    array<int, M> ans;
    rep(i, M) ans[i] = 0;
    for(auto e : x) {
        rep(i, M) { ans[i] = add(mul(ans[i], 10, i), e - '0', i); }
    }

    auto query = [&](int l, int r) {
        array<int, M> res;
        rep(i, M) res[i] = sub(rui[r][i], mul(rui[l][i], pows[r - l][i], i), i);
        return res;
    };

    auto rx = x;
    reverse(all(rx));
    auto check = [&](int i, int p, int q) {
        auto x = query(i, i + p), y = query(i + p, i + p + q);
        bool flag = true;
        rep(k, M) flag &= (add(x[k], y[k], k) == ans[k]);
        if(flag) {
            {
                int car = 0;
                int a = i + p - 1, b = i + p + q - 1;
                rep(t, si(rx)) {
                    int to = rx[t] - '0';
                    int A = (a >= i ? s[a] - '0' : 0);
                    int B = (b >= i + p ? s[b] - '0' : 0);
                    if((car + A + B) % 10 != to) return;
                    if(car + A + B >= 10)
                        car = 1;
                    else
                        car = 0;
                    a--, b--;
                }
                if(car) return;
            }
            OUT(i + 1, i + p);
            OUT(i + p + 1, i + p + q);
            exit(0);
        }
    };
    rep(i, n) {
        if(i + (m - 1) * 2 > n) break;
        check(i, m - 1, m - 1);
    }

    // L  m
    auto z = z_algorithm(x + s);
    z.erase(begin(z), begin(z) + m);
    rep(i, n) {
        int r = m - z[i];
        if(r and i + m + r <= n) { check(i, m, r); }
        if(r > 1 and i + m + r - 1 <= n) { check(i, m, r - 1); }
    }

    // R  m
    rep(i, n) {
        int r = m - z[i];
        if(r and i + m <= n and i >= r) check(i - r, r, m);
        if(r > 1 and i + m <= n and i >= r - 1) check(i - (r - 1), r - 1, m);
    }

    assert(0);
}