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
    #define dbg(...) cout << "[" << #__VA_ARGS__ << "] = ", dbgout(__VA_ARGS__);
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

int n;
const int N = 20;

struct node {
    vector<bool> fsw, frev;
    int l, r, p;
    ll sum;
    node() {
        fsw = frev = vector<bool>(N);
        l = r = p = sum = 0;
    }
    void operator=(const node &n) {
        sum = n.sum;
        fsw = n.fsw;
        frev = n.frev;
    }
    void rev(int k) { frev[k] = !frev[k]; }
    void sw(int k) { fsw[k] = !fsw[k]; }
};

node merge(node a, node b) {
    node ans;
    ans.sum = a.sum + b.sum;
    return ans;
}

struct Tree {
    vector<node> t;
    Tree(const vector<int> &a) {
        int x = 1 << n;
        t = vector<node> (2 * x + 2);
        for (int i = 0; i < x; ++i)
            t[i + x].sum = a[i];
        for (int i = x - 1; i > 0; --i) {
            t[i].l = i + i;
            t[i].r = i + i + 1;
            t[i + i].p = t[i + i + 1].p = i;
            t[i] = merge(t[t[i].l], t[t[i].r]);
        }
    }
    void submerge(int v) {
        t[v] = merge(t[t[v].l], t[t[v].r]);
    }
    void rev(int k) {
        t[1].rev(k);
    }
    void sw(int k) {
        t[1].sw(k);
    }
    void push(int v) {
        if (t[v].fsw[0])
            swap(t[v].l, t[v].r);
        if (t[v].frev[0]) {
            swap(t[v].l, t[v].r);
            t[t[v].l].rev(0);
            t[t[v].r].rev(0);
        }
        for (int i = 1; i < N; ++i)
            if (t[v].fsw[i]) {
                t[t[v].l].sw(i - 1);
                t[t[v].r].sw(i - 1);
            }
        for (int i = 1; i < N; ++i)
            if (t[v].frev[i]) {
                t[t[v].l].rev(i - 1);
                t[t[v].r].rev(i - 1);
            }
    }
    void replace(int x, int k) {
        int pos = 1;
        for (int i = n - 1; i >= 0; --i) {
            push(pos);
            if (x >> i & 1) pos = t[pos].r;
            else pos = t[pos].l;
        }
        t[pos].sum = k;
        pos = t[pos].p;
        while (pos != 0) {
            submerge(pos);
            pos = t[pos].p;
        }
    }
    ll sum(int l, int r, int v, int vl, int vr) {
        if (l >= vr || r <= vl) return 0;
        if (l <= vl && vr <= r) return t[v].sum;
        push(v);
        submerge(v);
        int vm = vl + vr >> 1;
        return sum(l, r, t[v].l, vl, vm) + sum(l, r, t[v].r, vm, vr);
    }
    ll sum(int l, int r) {
        return sum(l, r, 1, 0, 1 << n);
    }
};

signed main() {
    FAST; FIXED;
    int q;
    read(n, q);
    vector<int> a(1 << n);
    read(a);
    Tree t(a);
    while (q--) {
        int mode;
        read(mode);
        if (mode == 1) {
            int x, k;
            read(x, k);
            t.replace(x - 1, k);
        }
        if (mode == 2) {
            int k;
            read(k);
            t.rev(n - k);
        }
        if (mode == 3) {
            int k;
            read(k);
            t.sw(n - k - 1);
        }
        if (mode == 4) {
            int l, r;
            read(l, r);
            println(t.sum(l - 1, r));
        }
    }
    #ifdef DEBUG
        cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    #endif
    return 0;
}