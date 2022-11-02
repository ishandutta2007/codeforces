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

graph G;
vector<bool> used;

bool can(int u, int v) {
    if (u == v) return true;
    if (used[u]) return false;
    used[u] = true;
    for (auto i : G[u])
        if (can(i, v))
            return true;
    return false;
}

map<vector<int>, int> st;

void process(vector<int> &v, int i) {
    while (i < sz(v)) {
        int next = i + v[i];
        v[i] = max(1, v[i] - 1);
        i = next;
    }
}

void rec(vector<int> s, int d) {
    if (st.count(s) && st[s] <= d) return;
    st[s] = d;
    for (int i = 0; i < sz(s); ++i) {
        auto v = s;
        process(v, i);
        rec(v, d + 1);
    }
}

bool cannow(int u, int v, bool flag = true) {
    if (u > v) return false;
    if (__builtin_popcount(u) < __builtin_popcount(v))
        return false;
    int cnt = 0;
    for (int i = 29; i >= 0; --i) {
        cnt += u >> i & 1;
        cnt -= v >> i & 1;
        if (cnt > 0) return false;
    }
    if (flag && cnt != 0) return false;
    return true;
}

int popc(int x) { return __builtin_popcount(x); }

bool cancheck(int u, int v) {
    if (u > v) return false;
    if (u == v) return true;
    int x = u ^ v;
    int high = 31 - __builtin_clz(x);
    vector<int> vu, vv;
    for (int i = 0; i < high; ++i) {
        if (u >> i & 1) vu.pb(i);
        if (v >> i & 1) vv.pb(i);
    }
    if (sz(vu) == 0) return false;
    vu.popb();
    if (sz(vv) > sz(vu)) return false;
    vu.resize(sz(vv));
    for (int i = 0; i < sz(vv); ++i)
        if (vv[i] < vu[i]) {
            return false;
        }
    return true;
}

signed main() {
    FAST; FIXED;
    // G.resize(1000);
    // for (int u = 1; u <= 100; ++u)
    //     for (int v = 1; v <= 100; ++v)
    //         if ((u & v) == v) {
    //             G[u].pb(u + v);
    //         }
    int q;
    read(q);
    while (q--) {
        int u, v;
        read(u, v);
        println(cancheck(u, v) ? "YES" : "NO");
    }
    // for (int i = 1; i <= 100; ++i) {
    //     for (int j = 1; j <= 100; ++j) {
    //         used = vector<bool>(sz(G));
    //         if (can(i, j) != cancheck(i, j)) {
    //             dbg(i, j);
    //             dbg(cancheck(i, j));
    //             return 0;
    //         }
    //     }
    // }
    // int t;
    // read(t);
    // while (t--) {
    //     int n;
    //     read(n);
    //     vector<int> s(n);
    //     read(s);
    //     st.clear();
    //     rec(s, 0);
    //     for (auto &i : s) i = 1;
    //     for (auto i : st) dbg(i.f, i.s);
    //     println(st[s]);
    // }
    #ifdef DEBUG
        cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    #endif
    return 0;
}