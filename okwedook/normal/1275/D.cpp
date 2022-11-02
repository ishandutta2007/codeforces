#pragma GCC optimize("O3", "unroll-all-loops")
#pragma GCC target("avx2")
 
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
#include <random>
#include <cassert>
#include <complex>
 
using namespace std;
 
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(12)
#define RANDOM srand(94385)
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
#define mod 998244353
#define inf 3000000000000000007ll
#define sz(a) signed(a.size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
 
template<class T, class U> inline void checkmin(T &x, U y) { if (y < x) x = y; }
template<class T, class U> inline void checkmax(T &x, U y) { if (y > x) x = y; }
template<class T, class U> inline bool ifmax(T &x, U y) { if (y > x) return x = y, true; return false; }
template<class T, class U> inline bool ifmin(T &x, U y) { if (y < x) return x = y, true; return false; }
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }
template<class T, class U> inline istream& operator>>(istream& str, pair<T, U> &p) { return str >> p.f >> p.s; }
template<class T> inline istream& operator>>(istream& str, vector<T> &a) { for (auto &i : a) str >> i; return str; }
template<class T> inline T sorted(T a) { sort(a); return a; }
 
struct node {
    int c4 = 0, c7 = 0, inc = 0, dec = 0;
    bool flag = false;
    node() {}
    node(char c) {
        inc = dec = 1;
        c4 += c == '4';
        c7 += c == '7';
    }
    inline void rev() {
        flag = !flag;
        swap(c4, c7);
        swap(inc, dec);
    }
    inline friend node merge(const node &a, const node &b, node &ans) {
        ans.inc = max(a.c4 + b.inc, a.inc + b.c7);
        ans.dec = max(a.dec + b.c4, a.c7 + b.dec);
        ans.c4 = a.c4 + b.c4;
        ans.c7 = a.c7 + b.c7;
        ans.flag = false;
    }
};
 
 
struct Tree {
    static const int n = 1 << 20;
    node t[2 * n + 5];
    inline void build(string s) {
        for (int i = 0; i < sz(s); ++i)
            t[i + n] = s[i];
        for (int i = n - 1; i > 0; --i)
            merge(t[i + i], t[i + i + 1], t[i]);
    }
    inline void push(int v) {
        if (t[v].flag) {
            t[v + v].rev();
            t[v + v + 1].rev();
        }
    }
    void rev(int l, int r, int v = 1, int vl = 0, int vr = n) {
        if (vl >= r || vr <= l) return;
        if (vl >= l && vr <= r) return t[v].rev();
        push(v);
        int vm = vl + vr >> 1;
        rev(l, r, v + v, vl, vm);
        rev(l, r, v + v + 1, vm, vr);
        merge(t[v + v], t[v + v + 1], t[v]);
    }
    inline node get() { return t[1]; }
} t;

inline void read(int &x) {
    x = 0;
    static char c;
    while ((c = getchar()) >= '0')
        x = (x << 3) + (x << 1) + (c - '0');
}

inline void read(string &s) {
    static char c;
    s.clear();
    while ((c = getchar()) >= '0') {
        s.pb(c);
    }
}

inline void print(int x) {
    if (x >= 10) print(x / 10);
    putchar(x % 10 + '0');
}

inline void println(int x) {
    print(x);
    putchar('\n');
}

signed main() {
    FAST; FIXED; RANDOM;
    int n, m;
    read(n);
    read(m);
    string s;
    read(s);
    t.build(s);
    for (int i = 0; i < m; ++i) {
        string s;
        read(s);
        if (s == "switch") {
            int l, r;
            read(l);
            read(r);
            t.rev(l - 1, r);
        } else {
            println(t.get().inc);
        }
    }
    return 0;
}