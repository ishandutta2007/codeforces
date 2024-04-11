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

typedef struct node* pnode;
typedef int key;

pnode null = nullptr;

struct node {
    key k;
    int x = gen();
    int cnt = 1;
    pnode l = null, r = null, p = null;
    node(key _k) : k(_k) {}
};

void print(pnode t) {
    if (t == null) return;
    print(t->l, t->k, ' ', t->r);
}

pnode newnode(const key &k) {
    return new node(k);
}

inline int getcnt(pnode n) {
    return n == null ? 0 : n->cnt;
}

inline void updparent(pnode son, pnode parent) {
    if (son != null) {
        son->p = parent;
    }
}

inline void upd(pnode n) {
    if (n) {
        n->cnt = 1 + getcnt(n->l) + getcnt(n->r);
        updparent(n->l, n);
        updparent(n->r, n);
    }
}

pnode merge(pnode a, pnode b) {
    if (a == null) return b;
    if (b == null) return a;
    if (a->x > b->x) {
        a->r = merge(a->r, b);
        upd(a);
        return a;
    } else {
        b->l = merge(a, b->l);
        upd(b);
        return b;
    }
}

void splitind(pnode t, int ind, pnode &l, pnode &r) {
    if (t == null) return void(l = r = null);
    if (getcnt(t->l) >= ind) {
        splitind(t->l, ind, l, t->l);
        r = t;
    } else {
        splitind(t->r, ind - getcnt(t->l) - 1, t->r, r);
        l = t;
    }
    upd(l);
    upd(r);
}

void splitval(pnode t, const key &k, pnode &l, pnode &r) {
    if (t == null) return void(l = r = null);
    if (k < t->k) {
        splitval(t->l, k, l, t->l);
        r = t;
    } else {
        splitval(t->r, k, t->r, r);
        l = t;
    }
    upd(l);
    upd(r);
}

void splitvalup(pnode t, const key &k, pnode &l, pnode &r) {
    if (t == null) return void(l = r = null);
    if (!(t->k < k)) {
        splitval(t->l, k, l, t->l);
        r = t;
        updparent(r, null);
    } else {
        splitval(t->r, k, t->r, r);
        l = t;
        updparent(l, null);
    }
    upd(l);
    upd(r);
}

void insert(pnode &t, const key &k) {
    pnode r;
    splitval(t, k, t, r);
    t = merge(t, newnode(k));
    t = merge(t, r);
}

void insert(pnode &t, int ind, const key &k) {
    pnode r;
    splitind(t, ind, t, r);
    t = merge(t, newnode(k));
    t = merge(t, r);
}

key min(pnode t) {
    assert(t != null);
    if (t->l != null) return min(t->l);
    return t->k;
}

key max(pnode t) {
    assert(t != null);
    if (t->r != null) return max(t->r);
    return t->k;
}

void eraseone(pnode &t, const key &k) {
    pnode r;
    splitval(t, k, t, r);
    assert(min(r) == k);
    pnode m;
    splitind(r, 1, m, r);
    t = merge(t, r);
}

void eraseall(pnode &t, const key &k) {
    pnode m, r;
    splitval(t, k, t, r);
    splitvalup(r, k, m, r);
    t = merge(t, r);
}

key kth(pnode t, int ind) {
    assert(ind >= 0 && ind < getcnt(t));
    if (ind == getcnt(t->l)) return t->k;
    if (ind < getcnt(t->l)) return kth(t->l, ind);
    return kth(t->r, ind - getcnt(t->l) - 1);
}

int lower_bound(pnode t, const key &k) {
    if (t == null) return 0;
    if (!(t->k < k)) return lower_bound(t->l, k);
    return lower_bound(t->r, k) + 1 + getcnt(t->l);
}

int upper_bound(pnode t, const key &k) {
    if (t == null) return 0;
    if (k < t->k) return upper_bound(t->l, k);
    return upper_bound(t->r, k) + 1 + getcnt(t->l);
}

int getind(pnode t) {
    assert(t != null);
    int ans = 1 + getcnt(t->l);
    pnode was = t;
    t = t->p;
    while (t != null) {
        if (t->l != was)
            ans += getcnt(t->l) + 1;
        was = t;
        t = t->p;
    }
    return ans;
}

signed main() {
    FAST; FIXED;
    int n, m;
    read(n, m);
    pnode t = null;
    vector<pnode> pt;
    vector<int> mn(n), mx(n);
    iota(all(mn), 0);
    iota(all(mx), 0);
    for (int i = 0; i < n; ++i) {
        pt.pb(newnode(i));
        t = merge(t, pt.back());
    }
    for (int i = 0; i < m; ++i) {
        int x;
        read(x);
        --x;
        int ind = getind(pt[x]) - 1;
        chmax(mx[x], ind);
        chmin(mn[x], 0);
        pnode m, r;
        splitind(t, ind + 1, t, r);
        splitind(t, ind, t, m);
        t = merge(m, t);
        t = merge(t, r);
    }
    for (int i = 0; i < n; ++i)
        chmax(mx[kth(t, i)], i);
    for (int i = 0; i < n; ++i) println(mn[i] + 1, ' ', mx[i] + 1);
    #ifdef DEBUG
        cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    #endif
    return 0;
}