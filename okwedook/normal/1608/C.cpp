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
#include <functional>

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

void flush() { cout << flush; }
void flushln() { cout << endl; }
void println() { cout << '\n'; }
template<class T> void print(const T &x) { cout << x; }
template<class T> void read(T &x) { cin >> x; }
template<class T, class ...U> void read(T &x, U& ... u) { read(x); read(u...); }
template<class T, class ...U> void print(const T &x, const U& ... u) { print(x); print(u...); }
template<class T, class ...U> void println(const T &x, const U& ... u) { print(x); println(u...); }

#ifdef DEBUG
    template<class T> string pdbg(const T &x) { stringstream ss; ss << x; return ss.str(); }
    template<class T, class U> string pdbg(const pair<T, U> &p) { return "{" + pdbg(p.f) + "," + pdbg(p.s) + "}"; }
    string pdbg(const string &s) { return "\"" + s + "\""; }
    template<class It> string pdbg(It begin, It end, string d);
    template<class T> string pdbg(const vector<T> &a) { return pdbg(all(a), ""); }
    template<class T> string pdbg(const vector<vector<T>> &a) { return pdbg(all(a), "\n"); }
    template<class T> string pdbg(const vector<vector<vector<T>>> &a) { return pdbg(all(a), "\n\n"); }
    template<class T> string pdbg(const set<T> &a) { return pdbg(all(a), ""); }
    template<class T> string pdbg(const hashset<T> &a) { return pdbg(all(a), ""); }
    template<class T, class U> string pdbg(const map<T, U> &a) { return pdbg(all(a), ""); }
    template<class T, class U> string pdbg(const hashmap<T, U> &a) { return pdbg(all(a), ""); }
    template<class It> string pdbg(It begin, It end, string d) {
        string ans;
        ans += "{";
        if (begin != end) ans += pdbg(*begin++);
        while (begin != end)
            ans += "," + d + pdbg(*begin++);
        ans += "}";
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

void shorten(vector<int> &a) {
    auto c = a;
    sort(c);
    for (auto &i : a) {
        i = lower_bound(all(c), i) - c.begin();
    }
}

vector<int> getpos(const vector<int> &a) {
    vector<int> pos(sz(a));
    for (int i = 0; i < sz(a); ++i) {
        pos[a[i]] = i;
    }
    return pos;
}

struct SCC {
    graph G, rev;
    SCC(int n) { G.resize(n); rev.resize(n); }
    SCC(const graph &_G) : G(_G) {
        rev.resize(sz(G));
        for (int i = 0; i < sz(G); ++i)
            for (auto v : G[i])
                rev[v].pb(i);
    }
    // Edge from u to v
    void addEdge(int u, int v) {
        G[u].pb(v);
        rev[v].pb(u);
    }
    vector<int> order;
    vector<int> color;
    vector<bool> used;
    vector<vector<int>> comp;

    void dfsOrder(int v) {
        if (used[v]) return;
        used[v] = true;
        for (auto i : G[v])
            dfsOrder(i);
        order.pb(v);
    }
    void dfsMark(int v, int c) {
        if (color[v] != -1) return;
        color[v] = c;
        for (auto i : rev[v])
            dfsMark(i, c);
    }
    void dfsComp(int v, int c) {
        if (used[v]) return;
        used[v] = true;
        comp[c].pb(v);
        for (auto i : rev[v])
            dfsComp(i, c);
    }
    void getOrder() {
        used.assign(sz(G), false);
        order.clear();
        for (int i = 0; i < sz(G); ++i)
            dfsOrder(i);
        reverse(order);
    }
    void buildColors() {
        getOrder();
        color.assign(sz(G), -1);
        int ptr = 0;
        for (auto i : order)
            if (color[i] == -1)
                dfsMark(i, ptr++);
    }
    void buildComp() {
        getOrder();
        used.assign(sz(G), false);
        for (auto i : order)
            if (!used[i]) {
                comp.pb(vector<int>());
                dfsComp(i, sz(comp) - 1);
            }
    }
    graph condens;
    void buildCondensation(bool uni = false, bool self = false) {
        buildColors();
        condens.clear();
        condens.resize(*max_element(all(color)) + 1);
        for (int i = 0; i < sz(G); ++i)
            for (auto v : G[i]) {
                if (color[i] != color[v] || self)
                    condens[color[i]].pb(color[v]);
            }
        if (uni) {
            for (auto &i : condens) {
                sort(i);
                i.resize(unique(all(i)) - i.begin());
            }
        }
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

void solve() {
    int n;
    read(n);
    vector<int> a(n);
    read(a);
    vector<int> b(n);
    read(b);
    shorten(a);
    shorten(b);
    dbg(a);
    dbg(b);
    auto pa = getpos(a);
    auto pb = getpos(b);
    G = graph(sz(a));
    for (int i = n - 1; i > 0; --i) {
        G[pa[i]].pb(pa[i - 1]);
        G[pb[i]].pb(pb[i - 1]);
    }
    SCC scc(G);
    scc.buildColors();
    for (auto i : scc.color) {
        print(i == 0);
    }
    println();
}

signed main() {
    FAST; FIXED;
    int t;
    read(t);
    while (t--) {
        solve();
    }
    #ifdef DEBUG
        cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    #endif
    return 0;
}