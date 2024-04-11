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
 
#define int long long
 
struct node {
    ll mn = inf;
    void upd(ll x) {
        checkmin(mn, x);
    }
};

struct Tree {
    static const int n = 1 << 18;
    node t[2 * n + 5];
    Tree() {
        for (int i = 0; i < 2 * n; ++i) t[i] = node();
    }
    void push(int v) {
        t[v + v].upd(t[v].mn);
        t[v + v + 1].upd(t[v].mn);
    }
    void upd(int l, int r, ll x, int v = 1, int vl = 0, int vr = n) {
        if (vl >= r || vr <= l) return;
        if (vl >= l && vr <= r) return t[v].upd(x);
        push(v);
        int vm = vl + vr >> 1;
        upd(l, r, x, v + v, vl, vm);
        upd(l, r, x, v + v + 1, vm, vr);
    }
    int get(int l, int v = 1, int vl = 0, int vr = n) {
        if (vl + 1 == vr) return t[v].mn;
        push(v);
        int vm = vl + vr >> 1;
        if (l < vm) return get(l, v + v, vl, vm);
        else return get(l, v + v + 1, vm, vr);
    }
};
 
signed main() {
    FAST; FIXED; RANDOM;
    Tree t;
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    for (int i = 0; i < n; ++i) {
        int l = i, r = i + 1;
        if (s[i] == '1') 
            l = max(0ll, i - k), r = min(n, i + k + 1);
        t.upd(l, r, (l > 0 ? t.get(l - 1) : 0) + i + 1);
    }
    cout << t.get(n - 1);
    return 0;
}