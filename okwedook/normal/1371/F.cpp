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

struct stats {
    int val[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    int best = 0, revbest = 0;
    int len;
    void rev() {
        swap(val[0], val[1]);
        swap(val[2], val[3]);
        swap(val[4], val[5]);
        swap(val[6], val[7]);
        swap(best, revbest);
    }
    void updstats(string s) {
        int ptr = 0;
        while (ptr < len && s[ptr] == '<') ++ptr;
        val[0] = ptr;
        while (ptr < len && s[ptr] == '>') ++ptr;
        val[3] = ptr;

        ptr = 0;
        while (ptr < len && s[ptr] == '>') ++ptr;
        val[1] = ptr;
        while (ptr < len && s[ptr] == '<') ++ptr;
        val[2] = ptr;

        ptr = len - 1;
        while (ptr >= 0 && s[ptr] == '>') --ptr;
        val[4] = len - 1 - ptr;
        while (ptr >= 0 && s[ptr] == '<') --ptr;
        val[7] = len - 1 - ptr;
           
        ptr = len - 1;
        while (ptr >= 0 && s[ptr] == '<') --ptr;
        val[5] = len - 1 - ptr;
        while (ptr >= 0 && s[ptr] == '>') --ptr;
        val[6] = len - 1 - ptr;

        best = max(val[2], val[6]);
        revbest = max(val[3], val[7]);
    }
    int& operator[](int ind) { return val[ind]; }
    int operator[](int ind) const { return val[ind]; }
    friend stats merge(stats a, stats b) {
        stats ans;
        ans.best = max(a.best, b.best);
        ans.revbest = max(a.revbest, b.revbest);
        ans.len = a.len + b.len;
        ans[0] = a[0];
        ans[1] = a[1];
        ans[2] = a[2];
        ans[3] = a[3];
        ans[4] = b[4];
        ans[5] = b[5];
        ans[6] = b[6];
        ans[7] = b[7];
        if (a[0] == a.len) {
            chmax(ans[0], a[0] + b[0]);
            chmax(ans[3], a[0] + b[3]);
        }
        if (a[1] == a.len) {
            chmax(ans[1], a[1] + b[1]);
            chmax(ans[2], a[1] + b[2]);
        }
        if (a[2] == a.len) {
            chmax(ans[2], a[2] + b[0]);
        }
        if (a[3] == a.len) { 
            chmax(ans[3], a[3] + b[1]);
        }
        if (b[4] == b.len) {
            chmax(ans[4], b[4] + a[4]);
            chmax(ans[7], b[4] + a[7]);
        }
        if (b[5] == b.len) {
            chmax(ans[5], b[5] + a[5]);
            chmax(ans[6], b[5] + a[6]);
        }
        if (b[6] == b.len) {
            chmax(ans[6], b[6] + a[4]);
        }
        if (b[7] == b.len) {
            chmax(ans[7], b[7] + a[5]);
        }
        chmax(ans.best, ans[2]);
        chmax(ans.best, ans[6]);
        chmax(ans.revbest, ans[3]);
        chmax(ans.revbest, ans[7]);
        chmax(ans.best, a[6] + b[0]);
        chmax(ans.best, a[4] + b[2]);
        chmax(ans.revbest, a[7] + b[1]);
        chmax(ans.revbest, a[5] + b[3]);
        return ans;
    }
};

struct node {
    stats s;
    bool rev = false;
    node() {}
    node(string t) {
        s.len = sz(t);
        s.updstats(t);
    }
    void upd(bool flag) {
        if (flag) {
            rev ^= true;
            s.rev();
        }
    }
    void upd(const node &t) {
        upd(t.rev);
    }
    bool updated() const {
        return rev != 0;
    }
    void unupdate() {
        rev = 0;
    }
};

node merge(const node &a, const node &b) {
    node ans;
    ans.s = merge(a.s, b.s);
    return ans;
}

template<class node, node (*merge)(const node&, const node&) = merge>
struct Tree {
    int n = 1;
    vector<node> t;
    node& operator[](int ind) { return t[ind + n]; }
    const node& operator[](int ind) const { return t[ind + n]; }
    void submerge(int v) { // merge v's sons to v
        if (v >= n) return;
        t[v] = merge(t[v + v], t[v + v + 1]);
    }
    void resize(int sz) { // allocation
        while (n < sz) n <<= 1;
        t.resize(2 * n + 1);
    }
    void blank() { // default values
        for (int i = 0; i < 2 * n; ++i)
            t[i] = node();
    }
    void build() {
        for (int i = n - 1; i > 0; --i)
            submerge(i);
    }
    template<class T>
    void assign(const vector<T> &a) { // copy of a
        resize(sz(a));
        for (int i = 0; i < sz(a); ++i)
            t[i + n] = a[i];
        for (int i = sz(a); i < n; ++i)
            t[i + n] = node();
        build();
    }
    Tree() {} // empty
    Tree(int sz) { resize(sz); blank(); } // size, default values
    template<class T> Tree(const vector<T> &a) { assign(a); } // copy of a
    template<class T>
    void updup(int i, const T &val) { // upd at i with val, doesn't support push
        i += n;
        t[i].upd(val);
        for (i >>= 1; i > 0; i >>= 1)
            submerge(i);
    }
    node getup(int l, int r) { // get at [l, r), doesn't support push
        l += n;
        r += n;
        int cr = r;
        node left, right;
        bool lf = true, rf = true;
        for (; l < r; l >>= 1, r >>= 1) {
            if (l & 1) left = lf ? lf = false, t[l++] : merge(left, t[l++]);
            if (r & 1) right = rf ? rf = false, t[--r] : merge(t[--r], right);
        }
        if (lf) return right;
        if (rf) return left;
        return merge(left, right);
    }
    void push(int v) {
        if (t[v].updated()) {
            t[v + v].upd(t[v]);
            t[v + v + 1].upd(t[v]);
            t[v].unupdate();
        }
    }
    // update [l, r) with value x, supports push
    template<class T>
    void upd(int l, int r, const T &x, int v, int vl, int vr) { 
        if (vl >= r || vr <= l) return;
        if (vl >= l && vr <= r) return t[v].upd(x);
        push(v);
        int vm = vl + vr >> 1;
        upd(l, r, x, v + v, vl, vm);
        upd(l, r, x, v + v + 1, vm, vr);
        submerge(v);
    }
    template<class T>
    void upd(int l, int r, const T &x) { upd(l, r, x, 1, 0, n); } 
    
    // get at [l, r), supports push
    node get(int l, int r, int v, int vl, int vr) {
        if (vl >= r || vr <= l) return node();
        if (vl >= l && vr <= r) return t[v];
        push(v);
        int vm = vl + vr >> 1;
        if (r <= vm) return get(l, r, v + v, vl, vm);
        if (l >= vm) return get(l, r, v + v + 1, vm, vr);
        return merge(get(l, r, v + v, vl, vm), get(l, r, v + v + 1, vm, vr));
    }
    node get(int l, int r) { return get(l, r, 1, 0, n); } 
};

signed main() {
    FAST; FIXED;
    int n, q;
    read(n, q);
    string s;
    read(s);
    Tree<node> t(n);
    for (int i = 0; i < n; ++i)
        t[i] = string(1, s[i]);
    t.build();
    while (q--) {
        int l, r;
        read(l, r);
        --l;
        t.upd(l, r, 1);
        println(t.get(l, r).s.best);
    }
    #ifdef DEBUG
        cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    #endif
    return 0;
}