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
vector<int> a;
vector<vector<int>> sub;

int k;

vector<int> emptyvec() {
    return vector<int>(2 * k);
}

void init(int v) {
    sub[v] = emptyvec();
}

vector<int> next(const vector<int> &v) {
    vector<int> ans(sz(v));
    for (int i = 0; i < sz(v); ++i)
        ans[(i + 1) % sz(v)] = v[i];
    return ans;
}

void add(vector<int> &v, const vector<int> &a) {
    for (int i = 0; i < sz(v); ++i)
        v[i] ^= a[i];
}

void del(vector<int> &v, const vector<int> &a) {
    for (int i = 0; i < sz(v); ++i)
        v[i] ^= a[i];
}

void countsub(int v, int p) {
    init(v);
    sub[v][0] ^= a[v];
    for (auto i : G[v])
        if (i != p) {
            countsub(i, v);
            add(sub[v], next(sub[i]));
        }
}

vector<int> answer;

void rec(int v, int p, vector<int> uptree) {
    add(uptree, sub[v]);
    int ans = 0;
    for (int i = k; i < 2 * k; ++i)
        ans ^= uptree[i];
    if (ans == 0) answer[v] = 0;
    else answer[v] = 1;
    for (auto i : G[v])
        if (i != p) {
            del(uptree, next(sub[i]));
            rec(i, v, next(uptree));
            add(uptree, next(sub[i]));
        }
}

signed main() {
    FAST; FIXED;
    int n;
    read(n, k);
    G = graph(n);
    for (int i = 1; i < n; ++i) {
        int a, b;
        read(a, b);
        --a, --b;
        G[a].pb(b);
        G[b].pb(a);
    }
    a = vector<int>(n);
    read(a);
    sub = vector<vector<int>>(n);
    countsub(0, -1);
    answer = vector<int>(n, -1);
    rec(0, -1, emptyvec());
    for (auto i : answer) print(i, ' ');
    #ifdef DEBUG
        cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    #endif
    return 0;
}