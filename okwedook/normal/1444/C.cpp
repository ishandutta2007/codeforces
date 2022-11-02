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
#define mod 998244353
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
    template<class T> void pdbg(const T &x) { print(x); }
    template<class T, class U> void pdbg(const pair<T, U> &p) {
        print('{');
        pdbg(p.f);
        print(',');
        pdbg(p.s); 
        print('}');
    }
    void pdbg(const string &s) { print("\"" + s + "\""); }
    template<class It> void pdbg(It begin, It end, string d);
    template<class T> void pdbg(const vector<T> &a) { pdbg(all(a), ""); }
    template<class T> void pdbg(const vector<vector<T>> &a) { pdbg(all(a), "\n"); }
    template<class T> void pdbg(const vector<vector<vector<T>>> &a) { pdbg(all(a), "\n\n"); }
    template<class T> void pdbg(const set<T> &a) { pdbg(all(a), ""); }
    template<class T> void pdbg(const hashset<T> &a) { pdbg(all(a), ""); }
    template<class T, class U> void pdbg(const map<T, U> &a) { pdbg(all(a), ""); }
    template<class T, class U> void pdbg(const hashmap<T, U> &a) { pdbg(all(a), ""); }
    template<class It> void pdbg(It begin, It end, string d) {
        print('{');
        if (begin != end) pdbg(*begin++);
        while (begin != end)
            print(",", d), pdbg(*begin++);
        print('}');
    }
    template<class T> void dbgout(const T &x) { pdbg(x); }
    template<class T, class... U>
    void dbgout(T const &t, const U &... u) {
        pdbg(t);
        print(", ");
        dbgout(u...);
    }
    #define dbg(...) print("[", #__VA_ARGS__, "] = "), dbgout(__VA_ARGS__), flushln()
#else
    #define dbg(...) 0
#endif

template<class T, class U> inline bool chmin(T &x, const U& y) { return y < x ? x = y, 1 : 0; }
template<class T, class U> inline bool chmax(T &x, const U& y) { return y > x ? x = y, 1 : 0; }
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }
template<class T, class U> inline istream& operator>>(istream& str, pair<T, U> &p) { return str >> p.f >> p.s; }
template<class T> inline istream& operator>>(istream& str, vector<T> &a) { for (auto &i : a) str >> i; return str; }
template<class T> inline T sorted(T a) { sort(a); return a; }

graph G;
vector<int> color;
vector<int> vert[2];
set<int> upd;

bool dfs(int v, int c = 0) {
    if (color[v] >= 0) {
        if (color[v] != c) return false;
        return true;
    }
    upd.insert(v);
    color[v] = c;
    vert[c].pb(v);
    for (auto i : G[v])
        if (!dfs(i, c ^ 1))
            return false;
    return true;
}

signed main() {
    FAST; FIXED;
    int n, m, k;
    read(n, m, k);
    vector<int> c(n);
    read(c);
    for (auto &i : c) --i;
    vector<pii> edge(m);
    read(edge);
    for (auto &i : edge) --i.f, --i.s;
    G = graph(n);
    for (auto i : edge) {
        if (c[i.f] == c[i.s]) {
            G[i.f].pb(i.s);
            G[i.s].pb(i.f);
        }
    }
    vector<int> newc(n, -1);
    graph newG;
    color = vector<int>(n, -1);
    int ptr = 0;
    set<int> bad;
    for (int i = 0; i < n; ++i)
        if (color[i] == -1) {
            vert[0].clear();
            vert[1].clear();
            if (!dfs(i, 0))
                bad.insert(c[i]);
            newG.pb(vector<int>());
            newG.pb(vector<int>());
            newG[ptr].pb(ptr + 1);
            newG[ptr + 1].pb(ptr);
            dbg(vert[0], vert[1]);
            for (auto i : vert[0])
                newc[i] = ptr;
            for (auto i : vert[1])
                newc[i] = ptr + 1;
            ptr += 2;
        }
    map<pii, vector<pii>> e;
    for (auto &[u, v] : edge) {
        if (c[v] != c[u]) {
            if (c[u] > c[v]) swap(u, v);
            e[{c[u], c[v]}].pb({u, v});
        }
    }
    c = move(newc);
    G = move(newG);
    k -= sz(bad);
    ll ans = k * (ll)(k - 1) / 2;
    color = vector<int>(sz(G), -1);
    for (auto &e : e) {
        if (bad.count(e.f.f) || bad.count(e.f.s)) continue;
        set<int> v;
        for (auto e : e.s) {
            v.insert(c[e.f]);
            v.insert(c[e.s]);
            G[c[e.f]].pb(c[e.s]);
            G[c[e.s]].pb(c[e.f]);
        }
        bool flag = true;
        upd.clear();
        for (auto v : v)
            if (color[v] == -1) {
                if (!dfs(v, 0)) {
                    flag = false;
                    break;
                }
            }
        dbg(flag);
        if (!flag) --ans;
        for (auto i : upd) color[i] = -1;

        for (auto e : e.s) {
            G[c[e.f]].popb();
            G[c[e.s]].popb();
        }
    }
    println(ans);
    #ifdef DEBUG
        cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    #endif
    return 0;
}