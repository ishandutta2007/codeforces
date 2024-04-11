#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <bitset>
#include <sstream>
#include <deque>
#include <queue>
#include <complex>
#include <random>
#include <cassert>
#include <chrono>

using namespace std;

#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(12)
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define graph vector<vector<int>>
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define f first
#define s second
#define hashmap unordered_map
#define hashset unordered_set
#define eps 1e-9
#define mod 1000000007
#define inf 3000000000000000007ll
#define sz(a) signed((a).size())
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

#ifdef DEBUG
    mt19937 gen(857204);
#else
    mt19937 gen(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

#ifdef DEBUG
    template<class T> T to_dbg(T x) { return x; }
    template<class T, class U> string to_dbg(pair<T, U> p) {
        stringstream ss;
        ss << '{' << p.f << ',' << p.s << '}';
        return ss.str();
    }
    string to_dbg(string s) { return "\"" + s + "\""; }
    template<class It> string to_dbg(It begin, It end, string d = "") {
        stringstream ss;
        ss << '{';
        if (begin != end) ss << to_dbg(*begin++);
        while (begin != end)
            ss << "," << d << to_dbg(*begin++);
        ss << '}';
        return ss.str();
    }
    template<class T> string to_dbg(vector<T> a) { return to_dbg(all(a)); }
    template<class T> string to_dbg(set<T> a) { return to_dbg(all(a)); }
    template<class T> string to_dbg(hashset<T> a) { return to_dbg(all(a)); }
    template<class T, class U> string to_dbg(map<T, U> a) { return to_dbg(all(a), "\n"); }
    template<class T, class U> string to_dbg(hashmap<T, U> a) { return to_dbg(all(a), "\n"); }
    template<class T> void dbgout(T x) { cout << to_dbg(x) << endl; }
    template<class T, class... U>
    void dbgout(T t, U... u) {
        cout << to_dbg(t) << ", ";
        dbgout(u...);
    }
    #define dbg(...) cout << "[" << #__VA_ARGS__ << "] = ", dbgout(__VA_ARGS__)
#else
    #define dbg(...) 0
#endif

template<class T, class U> inline bool chmax(T &x, U y) { return x < y ? x = y, 1 : 0; }
template<class T, class U> inline bool chmin(T &x, U y) { return x > y ? x = y, 1 : 0; }
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }
template<class T, class U> inline istream& operator>>(istream& str, pair<T, U> &p) { return str >> p.f >> p.s; }
template<class T> inline istream& operator>>(istream& str, vector<T> &a) { for (auto &i : a) str >> i; return str; }
template<class T> inline T sorted(T a) { sort(a); return a; }
void read() {} void print() {} void println() { cout << '\n'; }
template<class T, class ...U> void read(T &x, U& ... u) { cin >> x; read(u...); }
template<class T, class ...U> void print(const T &x, const U& ... u) { cout << x; print(u...); }
template<class T, class ...U> void println(const T &x, const U& ... u) { cout << x; println(u...); }

struct SCC {
    graph G, rev;
    SCC(int n) : G(graph(n)), rev(graph(n)) {}
    SCC(const graph &_G) : G(_G) {
        rev.resize(sz(G));
        for (int v = 0; v < sz(G); ++v)
            for (auto u : G[v])
                rev[u].pb(v);
    }
    void addEdge(int from, int to) {
        G[from].pb(to);
        rev[to].pb(from);
    }
    vector<int> order;
    vector<bool> used;
    void getorder(int v) {
        if (used[v]) return;
        used[v] = true;
        for (auto i : G[v])
            getorder(i);
        order.pb(v);
    }
    vector<int> color, cnt;
    int ptr = 0;
    void mark(int v) {
        if (used[v]) return;
        used[v] = true;
        color[v] = ptr;
        ++cnt[ptr];
        for (auto i : rev[v])
            mark(i);
    }
    pair<vector<int>, vector<int>> build() {
        used = vector<bool>(sz(G));
        order.clear();
        for (int i = 0; i < sz(G); ++i)
            getorder(i);
        reverse(order);
        used = vector<bool>(sz(G));
        color = vector<int>(sz(G));
        for (auto i : order)
            if (!used[i]) {
                cnt.pb(0);
                mark(i);
                ++ptr;
            }
        return {color, cnt};
    }
};

void solve() {
    int n;
    read(n);
    SCC scc(n);
    string s;
    read(s);
    for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n;
        if (s[i] == '-' || s[i] == '>')
            scc.addEdge(i, j);
        if (s[i] == '-' || s[i] == '<')
            scc.addEdge(j, i);
    }
    auto x = scc.build().s;
    int ans = 0;
    for (auto i : x)
        if (i > 1) ans += i;
    println(ans);
}

signed main() {
    FAST; FIXED;
    int t;
    read(t);
    while (t--) solve();
    #ifdef DEBUG
        cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    #endif
    return 0;
}