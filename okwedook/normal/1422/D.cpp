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
#define chmin(a, b) (a > b ? a = b, 1 : 0)
#define chmax(a, b) (a < b ? a = b, 1 : 0)

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

template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }
template<class T, class U> inline istream& operator>>(istream& str, pair<T, U> &p) { return str >> p.f >> p.s; }
template<class T> inline istream& operator>>(istream& str, vector<T> &a) { for (auto &i : a) str >> i; return str; }
template<class T> inline T sorted(T a) { sort(a); return a; }

vector<ll> dijkstra(const vector<vector<pii>> &G, int v) {
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

signed main() {
    FAST; FIXED;
    int n, m;
    read(n, m);
    int sx, sy, fx, fy;
    read(sx, sy, fx, fy);
    vector<pii> p(m);
    vector<vector<pii>> G(m + 2);
    int s = sz(G) - 2, t = sz(G) - 1;
    read(p);
    vector<int> ind(m);
    iota(all(ind), 0);
    sort(all(ind), [&](int i, int j) { return p[i].f < p[j].f; });
    for (int i = 0; i + 1 < m; ++i) {
        int u = ind[i], v = ind[i + 1], w = p[v].f - p[u].f;
        G[u].pb({v, w});
        G[v].pb({u, w});
        dbg(u, v, w);
    }
    sort(all(ind), [&](int i, int j) { return p[i].s < p[j].s; });
    for (int i = 0; i + 1 < m; ++i) {
        int u = ind[i], v = ind[i + 1], w = p[v].s - p[u].s;
        G[u].pb({v, w});
        G[v].pb({u, w});
    }
    for (int i = 0; i < m; ++i) {
        G[s].pb({i, min(abs(sx - p[i].f), abs(sy - p[i].s))});
        G[i].pb({t, abs(p[i].f - fx) + abs(p[i].s - fy)});
    }
    G[s].pb({t, abs(sx - fx) + abs(sy - fy)});
    auto ans = dijkstra(G, s);
    dbg(ans);
    println(ans[t]);
    #ifdef DEBUG
        cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    #endif
    return 0;
}