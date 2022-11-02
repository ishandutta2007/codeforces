#pragma GCC optimize("O3", "unroll-loops")

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
#define mod 1000000007
#define inf 3000000000000000007ll
#define sz(a) signed(a.size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define shuffle(a) \
    for (int i = 0; i < sz(a); ++i) \
        swap(a[i], a[rand() % sz(a)]);

template<class T, class U> inline void checkmin(T &x, U y) { if (y < x) x = y; }
template<class T, class U> inline void checkmax(T &x, U y) { if (y > x) x = y; }
template<class T, class U> inline bool ifmax(T &x, U y) { if (y > x) return x = y, true; return false; }
template<class T, class U> inline bool ifmin(T &x, U y) { if (y < x) return x = y, true; return false; }
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }
template<class T, class U> inline istream& operator>>(istream& str, pair<T, U> &p) { return str >> p.f >> p.s; }
template<class T> inline istream& operator>>(istream& str, vector<T> &a) { for (auto &i : a) str >> i; return str; }

struct node {
    int mx = 0;
    int p = 0;
    inline void apply(ll x, int l, int r) {
        p += x;
        mx += x;
    }
};

inline node merge(node a, node b) {
    node ans;
    ans.mx = max(a.mx, b.mx);
    return ans;
}

struct Tree {
    static const int n = 1 << 20;
    node t[2 * n + 5];
    void push(int v, int vl, int vm, int vr) {
        if (t[v].p) {
            t[v + v].apply(t[v].p, vl, vm);
            t[v + v + 1].apply(t[v].p, vm, vr);
            t[v].p = 0;
        }
    }
    void add(int l, int r, int x, int v = 1, int vl = 0, int vr = n) {
        if (vl >= r || vr <= l) return;
        if (vl >= l && vr <= r) 
            return t[v].apply(x, vl, vr);
        int vm = vl + vr >> 1;
        push(v, vl, vm, vr);
        add(l, r, x, v + v, vl, vm);
        add(l, r, x, v + v + 1, vm, vr);
        t[v] = merge(t[v + v], t[v + v + 1]);
    }
    node get(int l, int r, int v = 1, int vl = 0, int vr = n) {
        if (vl >= r || vr <= l) return node();
        if (vl >= l && vr <= r) return t[v];
        int vm = vl + vr >> 1;
        push(v, vl, vm, vr);
        t[v] = merge(t[v + v], t[v + v + 1]);
        return merge(get(l, r, v + v, vl, vm), get(l, r, v + v + 1, vm, vr));
    }
    int suff(int v = 1, int vl = 0, int vr = n) {
        if (v >= 2 * n) return -1;
        if (vl + 1 == vr) 
            return t[v].mx > 0 ? vl : -1;
        if (t[v].mx <= 0) return -1;
        int vm = vl + vr >> 1;
        push(v, vl, vm, vr);
        t[v] = merge(t[v + v], t[v + v + 1]);
        int right = suff(v + v + 1, vm, vr);
        if (right >= 0) return right;
        return suff(v + v, vl, vm);
    }
} t;

void read(int &x) {
    x = 0;
    char c;
    while ((c = getchar()) >= '0')
        x = (x << 3) + (x << 1) + (c - '0');
}

signed main() {
    FAST; FIXED; RANDOM;
    int n, m;
    read(n); read(m);
    vector<int> a(n), b(m);
    for (auto &i : a) read(i), t.add(0, i + 1, 1);
    for (auto &i : b) read(i), t.add(0, i + 1, -1);
    int q;
    read(q);
    while (q--) {
        int mode, i, x;
        read(mode);
        read(i);
        read(x);
        --i;
        if (mode == 1) {
            t.add(0, a[i] + 1, -1);
            a[i] = x;
            t.add(0, a[i] + 1, 1);
        } else {
            t.add(0, b[i] + 1, 1);
            b[i] = x;
            t.add(0, b[i] + 1, -1);
        }
        printf("%d\n", t.suff());
    }
    return 0;
}