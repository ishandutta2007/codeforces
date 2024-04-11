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
template<class T> inline T sorted(T a) { sort(a); return a; }

struct node {
    int cnt, len;
    bool flag;
    node() {}
    node(int cnt, int len) {
        this->cnt = cnt;
        this->len = len;
        flag = false;
    }
    void inv() {
        cnt = len - cnt;
        flag = !flag;
    }
};

node merge(node a, node b) {
    node ans;
    ans.len = a.len + b.len;
    ans.cnt = a.cnt + b.cnt;
    return ans;
}

struct Tree {
    static const int n = 1 << 17;
    node t[2 * n + 5];
    Tree() {
        for (int i = 0; i < n; ++i)
            t[i + n] = node(0, 1);
        for (int i = n - 1; i > 0; --i)
            t[i] = merge(t[i + i], t[i + i + 1]);
    }
    void push(int v) {
        if (t[v].flag) {
            t[v + v].inv();
            t[v + v + 1].inv();
            t[v].flag = false;
        }
    }
    void inv(int l, int r, int v = 1, int vl = 0, int vr = n) {
        if (vl >= r || vr <= l) return;
        if (vl >= l && vr <= r) return t[v].inv();
        push(v);
        int vm = vl + vr >> 1;
        inv(l, r, v + v, vl, vm);
        inv(l, r, v + v + 1, vm, vr);
        t[v] = merge(t[v + v], t[v + v + 1]);
    }
    node get(int l, int r, int v = 1, int vl = 0, int vr = n) {
        if (vl >= r || vr <= l) return node(0, 0);
        if (vl >= l && vr <= r) return t[v];
        push(v);
        t[v] = merge(t[v + v], t[v + v + 1]);
        int vm = vl + vr >> 1;
        return merge(get(l, r, v + v, vl, vm), get(l, r, v + v + 1, vm, vr));
    }
} t[20];

signed main() {
    FAST; FIXED; RANDOM;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        for (int j = 0; j < 20; ++j)
            if (a >> j & 1) t[j].inv(i, i + 1);
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int mode;
        cin >> mode;
        if (mode == 1) {
            int l, r;
            cin >> l >> r;
            --l;
            ll ans = 0;
            for (int j = 0; j < 20; ++j)
                ans += (1ll << j) * t[j].get(l, r).cnt;
            cout << ans << '\n';
        }
        if (mode == 2) {
            int l, r, x;
            cin >> l >> r >> x;
            --l;
            for (int j = 0; j < 20; ++j)
                if (x >> j & 1) t[j].inv(l, r);
        }
    }
    return 0;
}