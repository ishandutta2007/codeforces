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

vector<ll> dijkstra(vector<vector<pair<int, ll>>> &G, int v) {
    vector<ll> ans(sz(G), inf);
    ans[v] = 0;
    auto cmp = [&](int i, int j) { return ans[i] > ans[j]; };
    priority_queue<int, vector<int>, decltype(cmp)> que(cmp);
    vector<bool> flag(sz(G));
    que.push(v);
    while (!que.empty()) {
        auto f = que.top();
        que.pop();
        if (flag[f]) continue;
        flag[f] = true;
        for (auto i : G[f])
            if (chmin(ans[i.f], ans[f] + i.s)) {
                que.push(i.f);
                flag[i.f] = false;
            }
    }
    return ans;
}

ll get(tuple<int, int, ll> x) {
    auto [u, v, w] = x;
    return w;
}

void solve() {
    int n, m;
    read(n, m);
    int MX = n;
    vector<vector<ll>> dist(n, vector<ll>(n, inf));
    vector<vector<int>> neigh(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        read(u, v, w);
        --u, --v;
        chmin(dist[u][v], w);
        chmin(dist[v][u], w);
        neigh[u].pb(v);
        neigh[v].pb(u);
    }
    vector<tuple<int, int, ll>> edges;
    for (int u = 0; u < n; ++u) {
        for (int v = 0; v < n; ++v) {
            if (dist[u][v] < inf) {
                edges.pb({u, v, dist[u][v]});
            }
        }
    }
    for (auto &i : neigh) {
        sort(i);
        i.resize(unique(all(i)) - i.begin());
    }
    sort(all(edges), [&](tuple<int, int, ll> a, tuple<int, int, ll> b) {
        return get(a) < get(b);
    });
    for (int i = 0; i < sz(edges); ) {
        int j = i;
        queue<tuple<int, int>> que;
        while (j < sz(edges) && get(edges[i]) == get(edges[j])) {
            auto [u, v, w] = edges[j];
            que.push({u, v});
            ++j;
        }
        ll w = get(edges[i]);
        i = j;
        while (sz(que)) {
            auto [u, v] = que.front();
            que.pop();
            for (auto x : neigh[v]) {
                if (chmin(dist[u][x], dist[u][v] + w)) {
                    que.push({u, x});
                }
            }
            for (auto x : neigh[u]) {
                if (chmin(dist[x][v], dist[u][v] + w)) {
                    que.push({x, v});
                }
            }
            if (chmin(dist[u][u], dist[u][v] + w)) {
                que.push({u, u});
            }
            if (chmin(dist[v][v], dist[u][v] + w)) {
                que.push({v, v});
            }
        }
    }
    vector<vector<pair<int, ll>>> G(n);
    for (int u = 0; u < n; ++u) {
        for (int v = 0; v < n; ++v) {
            G[u].pb({v, dist[u][v]});
        }
    }
    auto ans = dijkstra(G, 0)[n - 1];
    println(ans);
}

signed main() {
    initIO();
    int t;
    read(t);
    while (t--) solve();
    #ifdef DEBUG
        cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    #endif
    return 0;
}