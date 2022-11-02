#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")

#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

void initIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
}

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using graph = vector<vector<int>>;

const ld eps = 1e-9;
const int mod = 1000000007;
const ll inf = 3000000000000000007ll;

#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define f first
#define s second
#define sz(a) signed((a).size())
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define by_key(...) [](const auto &a, const auto &b) { return a.__VA_ARGS__ < b.__VA_ARGS__; }

#ifdef DEBUG
    mt19937 gen(857204);
#else
    mt19937 gen(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

void flush() { cout << flush; }
void flushln() { cout << endl; }
void println() { cout << '\n'; }
template<class T> void print(const T &x) { cout << x; }
template<class T> void read(T &x) { cin >> x; }
template<class T, class ...U> void read(T &x, U& ... u) { read(x); read(u...); }
template<class T, class ...U> void print(const T &x, const U& ... u) { print(x); print(u...); }
template<class T, class ...U> void println(const T &x, const U& ... u) { print(x); println(u...); }

#ifdef DEBUG
    namespace TypeTraits {
        template<class T> constexpr bool IsString = false;
        template<> constexpr bool IsString<string> = true;
        template<class T, class = void> struct IsIterableStruct : false_type{};
        template<class T>
        struct IsIterableStruct<
            T,
            void_t<
                decltype(begin(declval<T>())),
                decltype(end(declval<T>()))
            >
        > : true_type{};
        template<class T> constexpr bool IsIterable = IsIterableStruct<T>::value;
        template<class T> constexpr bool NonStringIterable = !IsString<T> && IsIterable<T>;
        template<class T> constexpr bool DoubleIterable = IsIterable<decltype(*begin(declval<T>()))>;
    };
    // Declaration (for cross-recursion)
    template<class T>
    auto pdbg(const T&x) -> enable_if_t<!TypeTraits::NonStringIterable<T>, string>;
    string pdbg(const string &x);
    template<class T>
    auto pdbg(const T &x) -> enable_if_t<TypeTraits::NonStringIterable<T>, string>;
    template<class T, class U>
    string pdbg(const pair<T, U> &x);

    // Implementation
    template<class T>
    auto pdbg(const T &x) -> enable_if_t<!TypeTraits::NonStringIterable<T>, string> {
        stringstream ss;
        ss << x;
        return ss.str();
    }
    template<class T, class U>
    string pdbg(const pair<T, U> &x) {
        return "{" + pdbg(x.f) + "," + pdbg(x.s) + "}";
    }
    string pdbg(const string &x) {
        return "\"" + x + "\"";
    }
    template<class T>
    auto pdbg(const T &x) -> enable_if_t<TypeTraits::NonStringIterable<T>, string> {
        auto begin = x.begin();
        auto end = x.end();
        string del = "";
        if (TypeTraits::DoubleIterable<T>) {
            del = "\n";
        }
        string ans;
        ans += "{" + del;
        if (begin != end) ans += pdbg(*begin++);
        while (begin != end) {
            ans += "," + del + pdbg(*begin++);
        }
        ans += del + "}";
        return ans;
    }
    template<class T> string dbgout(const T &x) { return pdbg(x); }
    template<class T, class... U>
    string dbgout(T const &t, const U &... u) {
        string ans = pdbg(t);
        ans += ", ";
        ans += dbgout(u...);
        return ans;
    }
    #define dbg(...) print("[", #__VA_ARGS__, "] = ", dbgout(__VA_ARGS__)), flushln()
    #define msg(...) print("[", __VA_ARGS__, "]"), flushln()
#else
    #define dbg(...) 0
    #define msg(...) 0
#endif

template<class T, class U> inline bool chmin(T &x, const U& y) { return y < x ? x = y, 1 : 0; }
template<class T, class U> inline bool chmax(T &x, const U& y) { return y > x ? x = y, 1 : 0; }
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }
template<class T, class U> inline istream& operator>>(istream& str, pair<T, U> &p) { return str >> p.f >> p.s; }
template<class T> inline istream& operator>>(istream& str, vector<T> &a) { for (auto &i : a) str >> i; return str; }
template<class T> inline T sorted(T a) { sort(a); return a; }

template<class T, const T& (*cmp)(const T&, const T&) = min>
struct sparse {
    int N, LOG;
    vector<int> mx;
    vector<vector<T>> val;
    //array a must not be empty
    sparse(const vector<T> &a) {
        N = sz(a), LOG = log2(N) + 1;
        mx = vector<int>(N + 1);
        for (int i = 2; i < sz(mx); ++i) mx[i] = mx[i >> 1] + 1;
        val = vector<vector<T>>(LOG, vector<T>(N));
        for (int i = 0; i < N; ++i) val[0][i] = a[i];
        for (int l = 1; l < LOG; ++l)
            for (int i = 0, next = 1 << (l - 1); next < N; ++i, ++next)
                val[l][i] = cmp(val[l - 1][i], val[l - 1][next]);
    }
    //[l, r] range query
    T get(int l, int r) {
        ++r;
        int len = mx[r - l];
        return cmp(val[len][l], val[len][r - (1 << len)]);
    }
};

template<class T> 
struct sparseind {
    vector<T> a;
    vector<vector<int>> ind;
    function<bool(T, T)> cmp;
    int minind(int l, int r) {
        return cmp(a[l], a[r]) ? l : r;
    }
    sparseind() {}
    sparseind(const vector<T> &_a, function<bool(T, T)> _cmp = less<T>()) : a(_a), cmp(_cmp) {
        int log = log2(sz(a));
        ind.resize(log + 1);
        ind[0].resize(sz(a));
        iota(all(ind[0]), 0);
        for (int l = 1; l <= log; ++l) {
            int was = 1 << (l - 1);
            int len = 1 << l;
            ind[l].resize(sz(a) - len + 1);
            for (int i = 0; i + len <= sz(a); ++i) {
                dbg(l, i);
                ind[l][i] = minind(ind[l - 1][i], ind[l - 1][i + was]);
            }
        }
    }
    int getind(int l, int r) {
        ++r;
        int len = 31 - __builtin_clz(r - l);
        return minind(ind[len][l], ind[len][r - (1 << len)]);
    }
    T getval(int l, int r) {
        return a[getind(l, r)];
    }
};

//works in linear time and memory online
template<class T>
struct mintable {
    typedef unsigned int mask;
    static const int B = 8 * sizeof(mask);
    static const int L = log2(B);
    vector<T> a;
    function<bool(T, T)> cmp;
    sparseind<T> sp;
    vector<int> ind;
    vector<int> masks;
    int minind(int l, int r) {
        return cmp(a[l], a[r]) ? l : r;
    }
    inline int last(mask m) { return B - __builtin_clz(m) - 1; }
    inline int first(mask m) { return __builtin_ctz(m); }
    mintable(const vector<T> &_a, function<bool(T, T)> _cmp = less<T>()) : a(_a), cmp(_cmp) {
        vector<T> v((sz(a) + B - 1) / B);
        ind.resize(sz(v));
        for (int i = 0; i < sz(v); ++i)
            ind[i] = i * B;
        for (int i = 0; i < sz(a); ++i)
            ind[i >> L] = minind(ind[i >> L], i);
        for (int i = 0; i < sz(v); ++i) v[i] = a[ind[i]];
        sp = sparseind<T>(v, cmp);
        masks.resize(sz(a));
        for (int i = 0; i < sz(v); ++i) {
            int from = i * B;
            mask que = 0;
            for (int j = from; j < from + B && j < sz(a); ++j) {
                while (que && cmp(a[j], a[last(que) + from]))
                    que ^= 1 << last(que);
                que ^= 1 << (j - from);
                masks[j] = que;
            }
        }
    }
    int getind(int i, int l, int r) {
        return first(masks[(i << L) + r] >> l) + (i << L) + l;
    }
    int getind(int l, int r) {
        int il = l >> L, ir = r >> L;
        if (il == ir)
            return getind(il, l & (B - 1), r & (B - 1));
        int ans = minind(getind(il, l & (B - 1), B - 1),
                            getind(ir, 0, r & (B - 1)));
        if (ir > il + 1)
            ans = minind(ans, ind[sp.getind(il + 1, ir - 1)]);
        return ans;
    }
    T getval(int l, int r) {
        return a[getind(l, r)];
    }
};

graph G;
vector<bool> used;

void dfs(int v) {
    if (used[v]) return;
    used[v] = true;
    for (auto i : G[v]) {
        dfs(i);
    }
}

signed main() {
    initIO();
    int n, m;
    read(n, m);
    int sz = (n + 1) * (m + 1);
    G = graph(sz);
    used = vector<bool>(sz);
    auto ind = [&](int i, int j) {
        return i * (m + 1) + j;
    };
    vector<vector<char>> s(n + 1, vector<char>(m + 1, '.'));
    for (int i = 1; i <= n; ++i) {
        string t;
        read(t);
        for (int j = 1; j <= m; ++j) {
            s[i][j] = t[j - 1];
        }
    }
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            if (j != 0 || i == i) {
                if (j + 1 <= m && s[i][j] == '.' && s[i][j + 1] == '.') {
                    G[ind(i, j)].pb(ind(i, j + 1));
                }
                if (i + 1 <= n && s[i][j] == '.' && s[i + 1][j] == '.') {
                    G[ind(i, j)].pb(ind(i + 1, j));
                }
            }
        }
    }
    vector<vector<int>> goleft(n + 1, vector<int>(m + 1, mod));
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            if (i == 0 || j == 0) {
                goleft[i][j] = 0;
                continue;
            }
            if (s[i][j] != '.') continue;
            goleft[i][j] = min(j, min(goleft[i - 1][j], goleft[i][j - 1]));
        }
    }
    // dbg(goleft);
    dfs(ind(0, 0));
    vector<int> mx(m + 1, -1);
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            if (s[i][j] == '.' && !used[ind(i, j)]) {
                // dbg(i, j, goleft[i][j]);
                chmax(mx[j], goleft[i][j]);
            }
        }
    }
    vector<int> bad(m + 1, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (s[i + 1][j] != '.' && s[i][j + 1] != '.' && s[i + 1][j + 1] != '.') {
                bad[j]++;
            }
        }
    }
    for (int i = 1; i < sz(bad); ++i) {
        bad[i] += bad[i - 1];
    }
    mintable<int> mx_table(mx, greater<int>());
    int q;
    read(q);
    while (q--) {
        int l, r;
        read(l, r);
        println(mx_table.getval(l, r) <= l && bad[r - 1] - bad[l - 1] == 0 ? "YES" : "NO");
    }
    #ifdef DEBUG
        cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    #endif
    return 0;
}