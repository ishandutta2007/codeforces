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

template<class T, const T& (*cmp)(const T&, const T&) = min>
struct sparse {
    int N, LOG;
    vector<int> mx;
    vector<vector<T>> val;
    //array a must not be empty
    sparse(const vector<T> &a) {
        N = sz(a), LOG = log2(N) + 1;
        mx = vector<int>(N + 1);
        for (int i = 2; i < sz(mx); ++i) mx[i] = mx[i >> 1] + 1;
        val = vector<vector<T>>(LOG, vector<T>(N));
        for (int i = 0; i < N; ++i) val[0][i] = a[i];
        for (int l = 1; l < LOG; ++l)
            for (int i = 0, next = 1 << (l - 1); next < N; ++i, ++next)
                val[l][i] = cmp(val[l - 1][i], val[l - 1][next]);
    }
    //[l, r] range query
    T get(int l, int r) {
        ++r;
        int len = mx[r - l];
        return cmp(val[len][l], val[len][r - (1 << len)]);
    }
};

template<class T>
struct sparseind {
    vector<T> a;
    vector<vector<int>> ind;
    function<bool(T, T)> cmp;
    int minind(int l, int r) {
        return cmp(a[l], a[r]) ? l : r;
    }
    sparseind() {}
    sparseind(const vector<T> &_a, function<bool(T, T)> _cmp = less<T>()) : a(_a), cmp(_cmp) {
        int log = log2(sz(a));
        ind.resize(log + 1);
        ind[0].resize(sz(a));
        iota(all(ind[0]), 0);
        for (int l = 1; l <= log; ++l) {
            int was = 1 << (l - 1);
            int len = 1 << l;
            ind[l].resize(sz(a) - len + 1);
            for (int i = 0; i + len <= sz(a); ++i) {
                dbg(l, i);
                ind[l][i] = minind(ind[l - 1][i], ind[l - 1][i + was]);
            }
        }
    }
    int getind(int l, int r) {
        ++r;
        int len = 31 - __builtin_clz(r - l);
        return minind(ind[len][l], ind[len][r - (1 << len)]);
    }
    T getval(int l, int r) {
        return a[getind(l, r)];
    }
};

//works in linear time and memory online
template<class T>
struct mintable {
    typedef unsigned int mask;
    static const int B = 8 * sizeof(mask);
    static const int L = log2(B);
    vector<T> a;
    function<bool(T, T)> cmp;
    sparseind<T> sp;
    vector<int> ind;
    vector<int> masks;
    int minind(int l, int r) {
        return cmp(a[l], a[r]) ? l : r;
    }
    inline int last(mask m) { return B - __builtin_clz(m) - 1; }
    inline int first(mask m) { return __builtin_ctz(m); }
    mintable(const vector<T> &_a, function<bool(T, T)> _cmp = less<T>()) : a(_a), cmp(_cmp) {
        vector<T> v((sz(a) + B - 1) / B);
        ind.resize(sz(v));
        for (int i = 0; i < sz(v); ++i)
            ind[i] = i * B;
        for (int i = 0; i < sz(a); ++i)
            ind[i >> L] = minind(ind[i >> L], i);
        for (int i = 0; i < sz(v); ++i) v[i] = a[ind[i]];
        sp = sparseind<T>(v, cmp);
        masks.resize(sz(a));
        for (int i = 0; i < sz(v); ++i) {
            int from = i * B;
            mask que = 0;
            for (int j = from; j < from + B && j < sz(a); ++j) {
                while (que && cmp(a[j], a[last(que) + from]))
                    que ^= 1 << last(que);
                que ^= 1 << (j - from);
                masks[j] = que;
            }
        }
    }
    int getind(int i, int l, int r) {
        return first(masks[(i << L) + r] >> l) + (i << L) + l;
    }
    int getind(int l, int r) {
        int il = l >> L, ir = r >> L;
        if (il == ir)
            return getind(il, l & (B - 1), r & (B - 1));
        int ans = minind(getind(il, l & (B - 1), B - 1),
                            getind(ir, 0, r & (B - 1)));
        if (ir > il + 1)
            ans = minind(ans, ind[sp.getind(il + 1, ir - 1)]);
        return ans;
    }
    T getval(int l, int r) {
        return a[getind(l, r)];
    }
};

bool checkperm(const vector<int> &v) {
    for (auto i : v)
        if (i > sz(v)) return false;
    vector<bool> used(sz(v));
    for (auto i : v)
        used[i - 1] = true;
    for (auto i : used)
        if (!i) return false;
    return true;
}

void solve() {
    int n;
    read(n);
    vector<int> a(n);
    read(a);
    mintable<int> mt(a);
    int l = 1, r = n + 1;
    while (r - l > 1) {
        int k = r + l >> 1;
        vector<int> v;
        for (int i = 0; i + k <= n; ++i)
            v.pb(mt.getval(i, i + k - 1));
        if (checkperm(v)) r = k;
        else l = k;
    }
    vector<bool> ans(n + 1);
    for (int i = r; i <= n; ++i) ans[i] = 1;
    if (checkperm(a)) ans[1] = 1;
    for (int i = 1; i <= n; ++i) print(ans[i]);
    println();
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