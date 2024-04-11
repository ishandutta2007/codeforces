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

pii rot(pii p) {
    return {-p.s, p.f};
}

pii sum(pii a, pii b) {
    return {a.f + b.f, a.s + b.s};
}

void solve() {
    int n, m;
    read(n, m);
    vector<string> a(n);
    read(a);
    auto in = [&](pii p) {
        return p.f >= 0 && p.f < n && p.s >= 0 && p.s < m;
    };
    auto change = [&](pii p) {
        a[p.f][p.s] = a[p.f][p.s] == '0' ? '1' : '0';
    };
    auto get = [&](pii p) {
        return a[p.f][p.s];
    };
    vector<vector<pii>> ans;
    auto addans = [&](pii a, pii b, pii c) {
        ans.pb({a, b, c});
        change(a);
        change(b);
        change(c);
    };
    if (n % 2 == 1 && m % 2 == 1) {
        if (a[n - 1][m - 1] == '1') {
            addans({n - 1, m - 1}, {n - 1, m - 2}, {n - 2, m - 2});
        }
    }
    if (n % 2 == 1) {
        for (int j = 0; j + 1 < m; j += 2) {
            if (a[n - 1][j] == '1' && a[n - 1][j + 1] == '1') {
                addans({n - 1, j}, {n - 1, j + 1}, {n - 2, j});
            } else if (a[n - 1][j] == '1') {
                addans({n - 1, j}, {n - 2, j}, {n - 2, j + 1});
            } else if (a[n - 1][j + 1] == '1') {
                addans({n - 1, j + 1}, {n - 2, j + 1}, {n - 2, j});
            }
        }
    }
    if (m % 2 == 1) {
        for (int i = 0; i + 1 < n; i += 2) {
            if (a[i][m - 1] == '1' && a[i + 1][m - 1] == '1') {
                addans({i, m - 1}, {i + 1, m - 1}, {i, m - 2});
            } else if (a[i][m - 1] == '1') {
                addans({i, m - 1}, {i, m - 2}, {i + 1, m - 2});
            } else if (a[i + 1][m - 1] == '1') {
                addans({i + 1, m - 1}, {i + 1, m - 2}, {i, m - 2});
            }
        }
    }
    auto inv = [&](pii p) {
        return p.f >= 0 && p.f < 2 && p.s >= 0 && p.s < 2;
    };
    auto getv = [&](vector<string> v, pii p) {
        return v[p.f][p.s];
    };
    auto changev = [&](vector<string> &v, pii p) {
        v[p.f][p.s] = v[p.f][p.s] == '1' ? '0' : '1';
    };
    auto addansv = [&](vector<string> &v, vector<vector<pii>> &ans, pii a, pii b, pii c) {
        ans.pb({a, b, c});
        changev(v, a);
        changev(v, b);
        changev(v, c);
    };
    auto small = [&](vector<string> v) {
        vector<vector<pii>> ans;
        for (int want = 3; want >= 2; --want) {
            for (int i = 0; i < sz(v); ++i)
                for (int j = 0; j < sz(v[i]); ++j) {
                    pii p = {i, j};
                    pii dx = {0, 1};
                    pii dy = {1, 0};
                    while (!inv(sum(p, dx)) || !inv(sum(p, dy))) {
                        dx = rot(dx);
                        dy = rot(dy);
                    }
                    int v1 = getv(v, p) - '0';
                    int v2 = getv(v, sum(p, dx)) - '0';
                    int v3 = getv(v, sum(p, dy)) - '0';
                    if (v1 + v2 + v3 >= want) {
                        addansv(v, ans, p, sum(p, dx), sum(p, dy));
                    }
                }
            }
        for (int i = 0; i < sz(v); ++i)
            for (int j = 0; j < sz(v[i]); ++j) {
                if (v[i][j] == '1') {
                    pii p = {i, j};
                    pii dx = {0, 1};
                    pii dy = {1, 0};
                    while (!inv(sum(p, dx)) || !inv(sum(p, dy))) {
                        dx = rot(dx);
                        dy = rot(dy);
                    }
                    addansv(v, ans, p, sum(p, dx), sum(p, dy));
                    addansv(v, ans, p, sum(p, dx), sum(sum(p, dx), dy));
                    addansv(v, ans, p, sum(p, dy), sum(sum(p, dx), dy));
                }
            }
        assert(sz(ans) <= 4);
        assert(v == vector<string>(2, "00"));
        return ans;
    };
    dbg(sz(ans));
    for (int i = 0; i + 1 < n; i += 2)
        for (int j = 0; j + 1 < m; j += 2) {
            vector<string> v = {"00", "00"};
            for (int l = 0; l < 2; ++l)
                for (int k = 0; k < 2; ++k)
                    v[l][k] = a[i + l][j + k];

            vector<vector<pii>> add = small(v);
            pii p = {i, j};
            for (auto v : add)
                addans(sum(v[0], p), sum(v[1], p), sum(v[2], p));
        }
    dbg(a);
    println(sz(ans));
    for (auto i : ans) {
        for (auto j : i) print(j.f + 1, ' ', j.s + 1, ' ');
        println();
    }
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