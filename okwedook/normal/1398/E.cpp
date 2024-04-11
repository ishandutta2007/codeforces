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

typedef struct node* pnode;

struct node {
    int k;
    ll sum;
    int p = gen();
    int cnt = 1;
    pnode l = nullptr, r = nullptr;
    node(int x = 0) : k(x), sum(x) {}
};

ll getsum(pnode n) {
    return n ? n->sum : 0;
}

int getcnt(pnode n) {
    return n ? n->cnt : 0;
}

void upd(pnode n) {
    if (n) {
        n->cnt = 1 + getcnt(n->l) + getcnt(n->r);
        n->sum = n->k + getsum(n->l) + getsum(n->r);
    }
}

pnode merge(pnode a, pnode b) {
    if (!a) return b;
    if (!b) return a;
    if (a->p > b->p) {
        a->r = merge(a->r, b);
        upd(a);
        return a;
    } else {
        b->l = merge(a, b->l);
        upd(b);
        return b;
    }
}

void splitval(pnode t, int k, pnode &l, pnode &r) {
    if (!t) return void(l = r = t);
    if (t->k >= k) {
        splitval(t->l, k, l, t->l);
        r = t;
    } else {
        splitval(t->r, k, t->r, r);
        l = t;
    }
    upd(l); upd(r);
}

void splitind(pnode t, int ind, pnode &l, pnode &r) {
    if (!t) return void(l = r = t);
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

void insert(pnode &t, int k) {
    static pnode r;
    splitval(t, k, t, r);
    t = merge(t, new node(k));
    t = merge(t, r);
}

void eraseone(pnode &t, int k) {
    static pnode m, r;
    splitval(t, k, t, r);
    splitind(r, 1, m, r);
    t = merge(t, r);
}

void print(pnode n) {
    if (!n) return;
    print(n->l);
    print(n->k, ' ');
    print(n->r);
}

signed main() {
    FAST; FIXED;
    int n;
    read(n);
    pnode t = nullptr;
    set<int> st[2];
    while (n--) {
        int tp, d;
        read(tp, d);
        if (d < 0) {
            d = -d;
            st[tp].erase(d);
            eraseone(t, d);
        } else {
            st[tp].insert(d);
            insert(t, d);
        }
        if (sz(st[1]) == 0) println(getsum(t));
        else {
            auto mn = *st[1].begin();
            int cnt = sz(st[1]);
            ll ans = getsum(t);
            eraseone(t, mn);
            chmin(cnt, getcnt(t));
            static pnode r;
            splitind(t, getcnt(t) - cnt, t, r);
            ans += getsum(r);
            t = merge(t, r);
            println(ans);
            insert(t, mn);
        }
    }
    #ifdef DEBUG
        cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    #endif
    return 0;
}