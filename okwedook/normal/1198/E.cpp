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

template<class F>
struct Dinic {
    int n;
    vector<int> layer;
    struct Edge {
        int v;
        int rev;
        F cap, flow;
        Edge(int _v, int _rev, F _cap, F _flow) :
            v(_v), rev(_rev), cap(_cap), flow(_flow) {}
        inline bool sat() const { return flow >= cap; }
        inline bool unsat() const { return flow < cap; }
        inline F left() const { return cap - flow; }
        inline void addFlow(F df) { flow += df; }
    };
    Dinic(int _n) : n(_n) {
        layer.resize(n);
        ptr.resize(n);
        G.resize(n);
    }
    vector<vector<Edge>> G;
    void addEdge(int u, int v, F cap) {
        int pu = sz(G[u]), pv = sz(G[v]);
        G[u].pb({v, pv, cap, 0});
        G[v].pb({u, pu, 0, 0});
    }
    int s, t;
    bool buildBfsTree() {
        fill(all(layer), -1);
        static vector<int> que;
        que.clear();
        que.pb(s);
        layer[s] = 0;
        for (int i = 0; i < sz(que); ++i) {
            int v = que[i];
            for (const auto &e : G[v])
                if (e.unsat() && layer[e.v] == -1) {
                    layer[e.v] = layer[v] + 1;
                    que.pb(e.v);
                }
        }
        return layer[t] != -1;
    }
    vector<int> ptr;
    F sendFlow(int v, F f) {
        if (v == t) {
            return f;
        }
        for (; ptr[v] < sz(G[v]); ++ptr[v]) {
            auto &e = G[v][ptr[v]];
            if (e.unsat() && layer[e.v] == layer[v] + 1) {
                if (F df = sendFlow(e.v, min(f, e.left()))) {
                    e.addFlow(df);
                    G[e.v][e.rev].addFlow(-df);
                    return df;
                }
            }
        }
        return 0;
    }
    F findFlow(int _s, int _t, F limit = numeric_limits<F>::max()) {
        s = _s;
        t = _t;
        F ans = 0;
        while (buildBfsTree()) {
            fill(all(ptr), 0);
            while (F df = sendFlow(s, limit)) {
                ans += df;
                limit -= df;
            }
        }
        return ans;
    }
};

void makeunique(vector<int> &x) {
    sort(x);
    x.resize(unique(all(x)) - x.begin());
}

signed main() {
    FAST; FIXED;
    int n, m;
    read(n, m);
    vector<pair<pii, pii>> rect(m);
    for (auto &i : rect) read(i.f.f, i.s.f, i.f.s, i.s.s);
    vector<int> x, y;
    for (auto &i : rect) {
        ++i.f.s;
        ++i.s.s;
        x.pb(i.f.f);
        x.pb(i.f.s);
        y.pb(i.s.f);
        y.pb(i.s.s);
    }
    makeunique(x);
    makeunique(y);
    Dinic<int> dinic(sz(x) + sz(y) + 2);
    int s = sz(x) + sz(y);
    int t = s + 1;
    for (int i = 1; i < sz(x); ++i)
        dinic.addEdge(s, i, x[i] - x[i - 1]);
    for (int i = 1; i < sz(y); ++i)
        dinic.addEdge(sz(x) + i, t, y[i] - y[i - 1]);
    for (int px = 1; px < sz(x); ++px)
        for (int py = 1; py < sz(y); ++py)
            for (auto i : rect) {
                if (i.f.f <= x[px - 1] && i.f.s >= x[px] &&
                    i.s.f <= y[py - 1] && i.s.s >= y[py]) {
                    dinic.addEdge(px, sz(x) + py, mod);
                    break;
                }
            }
    print(dinic.findFlow(s, t));
    #ifdef DEBUG
        cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    #endif
    return 0;
}