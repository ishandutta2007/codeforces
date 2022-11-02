#pragma GCC optimize("O3", "unroll-loops")
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
    pair<ll, int> val = {inf, -1};
    ll p = 0;
    node() {}
    node(pair<ll, int> x) {
        val = x;
    }
    void add(ll x) {
        p += x;
        val.f += x;
    }
};

node merge(node a, node b) {
    if (a.val.f < b.val.f) return node(a.val);
    if (a.val.f > b.val.f) return node(b.val);
    return node(max(a.val, b.val));
}

struct Tree {
    static const int n = 1 << 18;
    node t[2 * n + 5];
    void upd(vector<ll> a) {
        for (int i = 0; i < sz(a); ++i)
            t[i + n].val = {a[i], i};
        for (int i = n - 1; i > 0; --i)
            t[i] = merge(t[i + i], t[i + i + 1]);
    }
    void push(int v) {
        if (t[v].p) {
            t[v + v].add(t[v].p);
            t[v + v + 1].add(t[v].p);
            t[v].p = 0;
        }
    }
    void add(int l, int r, ll x, int v = 1, int vl = 0, int vr = n) {
        if (vl >= r || vr <= l) return;
        if (vl >= l && vr <= r) return t[v].add(x);
        int vm = vl + vr >> 1;
        push(v);
        add(l, r, x, v + v, vl, vm);
        add(l, r, x, v + v + 1, vm, vr);
        t[v] = merge(t[v + v], t[v + v + 1]);
    }
    node get() { return t[1]; }
} t;

signed main() {
    FAST; FIXED; RANDOM;
    int n;
    cin >> n;
    vector<ll> s(n);
    cin >> s;
    t.upd(s);
    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
        int ind = t.get().val.s;
        ans[ind] = i + 1;
        t.add(ind, n, -ans[ind]);
        t.add(ind, ind + 1, 1e12);
    }
    for (auto i : ans) cout << i << ' ';
    return 0;
}