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

// Author: Mikhail Pogodin (okwedook)
//
// Fenwick tree implementation
// Uses linear space and O(logn) time per operation.
//
// Check tasks: https://codeforces.com/gym/100246/problem/A

template<class T>
struct Fenwick {
    vector<T> sum;
    Fenwick() {}
    Fenwick(int n) { sum.resize(n); }
    // Initializes Fenwick tree by given values in linear time
    template<class U>
    Fenwick(const U &a) {
        sum.assign(all(a));
        build();
    }
    // Makes values into fenwick values
    void build() {
        for (int r = 0; r < sz(sum); ++r)
            if ((r | r + 1) < sz(sum))
                sum[r | r + 1] += sum[r];
    }
    // Adds x to position r
    void add(int r, T x) {
        for (; r < sz(sum); r |= r + 1)
            sum[r] += x;
    }
    // Sum at [0, r]
    T get(int r) {
        T ans = 0;
        for (; r >= 0; r = (r & r + 1) - 1)
            ans += sum[r];
        return ans;
    }
    // Sum at [l, r]
    T get(int l, int r) {
        return get(r) - get(l - 1);
    }
    // First index, which sum at [0, ans] is at least x
    int lb(T x) {
        int ans = -1;
        ll now = 0;
        for (int l = 31 - __builtin_clz(sz(sum)); l >= 0; --l) {
            int next = ans + (1 << l);
            if (next < sz(sum) && now + sum[next] < x) {
                ans = next;
                now += sum[next];
            }
        }
        return ans + 1;
    }
};

void solve() {
    int n, m;
    read(n, m);
    vector<int> a(n * m);
    read(a);
    auto b = a;
    sort(b);
    map<int, set<pii>> st;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            int v = b[i * m + j];
            st[v].insert({j, i});
        }
    vector<int> ind(sz(a));
    iota(all(ind), 0);
    sort(all(ind), [&](int i, int j) {
        if (a[i] != a[j]) return a[i] < a[j];
        return i < j;
    });
    vector<Fenwick<int>> fenv(n, Fenwick<int>(m));
    ll ans = 0;
    dbg(ind);
    dbg(a);
    for (int i = 0; i < sz(a); ++i) {
        pii p = *(--st[a[i]].end());
        st[a[i]].erase(p);
        dbg(p.f);
        ans += fenv[p.s].get(p.f);
        fenv[p.s].add(p.f, 1);
    }
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