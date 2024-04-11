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

// Author: Mikhail Pogodin (okwedook)
//
// Implementatin of Disjoint Set Union
// Works in O(alpha(n)) ~ const per query
//
// Check tasks: codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/A

struct DSU {
    struct rnk {
        int val = 1;
        int get() const {
            return val;
        }
        void add(const rnk &r) {
            val += r.val;
        }
    };
    vector<int> p;
    vector<rnk> r;
    int comp = 0;
    DSU() {}
    DSU(int n) {
        p.resize(n);
        r.resize(n);
        iota(all(p), 0);
        comp = n;
    }
    // Returns head element in the set containing v
    int getp(int v) {
        return v == p[v] ? v : p[v] = getp(p[v]);
    }
    // True if a and b are in one component
    bool check(int a, int b) {
        return getp(a) == getp(b);
    }
    // Unites components containing a and b
    // Returns true if a and b are in diff components
    bool unite(int a, int b) {
        a = getp(a);
        b = getp(b);
        if (a == b) return false;
        --comp;
        if (r[a].get() > r[b].get()) swap(a, b);
        p[a] = b;
        r[b].add(r[a]);
        return true;
    }
};

graph tree, up;
vector<int> h, in, sub;
vector<bool> path;
vector<int> sum;
vector<int> order;
int cntsum = 0;
int currt = 0;

void add_range(int l, int r, int d) {
    sum[l] += d;
    sum[r] -= d;
}

void add_subtree(int v, int d) {
    // msg("ADD_SUBTREE")
    add_range(in[v], in[v] + sub[v], d);
}

void add_vert(int v, int d) {
    add_range(in[v], in[v] + 1, d);
}

void dfsh(int v, int p) {
    h[v] = p == -1 ? 0 : h[p] + 1;
    in[v] = currt++;
    sub[v] = 1;
    for (auto i : tree[v]) {
        if (i != p) {
            dfsh(i, v);
            sub[v] += sub[i];
        }
    }
}

void dfsans(int v, int p) {
    path[v] = true;
    order.pb(v);
    for (auto i : tree[v]) {
        if (i != p) {
            dfsans(i, v);
        }
    }
    dbg(v, path);
    for (auto u : up[v]) {
        ++cntsum;
        msg("ADD PAIR ", u, ' ', v);
        if (path[u]) {
            add_subtree(0, 1);
            add_subtree(order[h[u] + 1], -1);
            add_subtree(v, 1);
        } else {
            add_subtree(u, 1);
            add_subtree(v, 1);
        }
    }
    order.popb();
    path[v] = false;
}

signed main() {
    initIO();
    int n, m;
    read(n, m);
    DSU dsu(n);
    tree = graph(n);
    vector<pii> edge;
    for (int i = 0; i < m; ++i) {
        int u, v;
        read(u, v);
        --u, --v;
        if (dsu.unite(u, v)) {
            tree[u].pb(v);
            tree[v].pb(u);
        } else {
            edge.pb({u, v});
        }
    }
    h = in = sub = vector<int>(n);
    dfsh(0, -1);
    up = graph(n);
    for (auto &[u, v] : edge) {
        if (h[u] < h[v]) {
            swap(u, v);
        }
        // h[u] > h[v]
        up[u].pb(v);
    }
    path = vector<bool>(n);
    sum = vector<int>(n + 1);
    dfsans(0, -1);
    for (int i = 1; i < n; ++i) {
        sum[i] += sum[i - 1];
    }
    vector<bool> ans(n);
    for (int i = 0; i < n; ++i) {
        ans[i] = sum[in[i]] == cntsum;
    }
    for (auto i : ans) print(i);
    #ifdef DEBUG
        cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    #endif
    return 0;
}