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
    ll left, right, p;
    int ans, l;
    int len[6];
    node() {
        left = right = 0;
        ans = len[0] = len[1] = len[2] = len[3] = len[4] = len[5] = 0;
        p = 0;
        l = 0;
    }
    node(int x) {
        left = right = x;
        ans = len[0] = len[1] = len[2] = len[3] = len[4] = len[5] = 1;
        p = 0;
        l = 1;
    }
    void add(ll d) {
        p += d;
        left += d;
        right += d;
    }
};
 
node merge(node a, node b) {
    if (a.l == 0) {
        b.p = 0;
        return b;
    }
    if (b.l == 0) {
        a.p = 0;
        return a;
    }
    node ans;
    ans.l = a.l + b.l;
    ans.left = a.left;
    ans.right = b.right;
    ans.ans = max(a.ans, b.ans);
    if (a.right != b.left)
        checkmax(ans.ans, a.len[1] + b.len[0]);
    if (a.right > b.left)
        checkmax(ans.ans, a.len[2] + b.len[0]);
    if (b.left > a.right)
        checkmax(ans.ans, b.len[3] + a.len[1]);
    ans.len[0] = a.len[0] + (a.len[0] == a.l && a.right > b.left ? b.len[0] : 0);
    ans.len[1] = b.len[1] + (b.len[1] == b.l && a.right < b.left ? a.len[1] : 0);
    ans.len[2] = b.len[2] + (b.len[2] == b.l && a.right < b.left ? a.len[1] : 0);
    ans.len[3] = a.len[3] + (a.len[3] == a.l && a.right > b.left ? b.len[0] : 0);
    ans.len[4] = a.len[4] + (a.len[4] == a.l && a.right < b.left ? b.len[4] : 0);
    ans.len[5] = b.len[5] + (b.len[5] == b.l && a.right > b.left ? a.len[5] : 0);
    if (a.len[1] == a.l && a.right < b.left)
        checkmax(ans.len[3], a.len[1] + b.len[3]);
    if (b.len[0] == b.l && a.right > b.left)
        checkmax(ans.len[2], b.len[0] + a.len[2]);
    checkmax(ans.len[3], ans.len[4]);
    checkmax(ans.len[2], ans.len[5]);
    checkmax(ans.ans, ans.len[2]);
    checkmax(ans.ans, ans.len[3]);
    return ans;
}
 
struct Tree {
    static const int n = 1 << 19;
    node t[2 * n + 5];
    void build(int s) {
        for (int i = 0; i < s; ++i)
            t[i + n] = node(0);
        for (int i = n - 1; i >= 0; --i)
            t[i] = merge(t[i + i], t[i + i + 1]);
    }
    void push(int v, int vl, int vr) {
        if (t[v].p) {
            int vm = vl + vr >> 1;
            t[v + v].add(t[v].p);
            t[v + v + 1].add(t[v].p);
            t[v].p = 0;
        }
    }
    void add(int l, int r, int x, int v = 1, int vl = 0, int vr = n) {
        if (vl >= r || vr <= l) return;
        if (vl >= l && vr <= r) {
            t[v].add(x);
            return;
        }
        int vm = vl + vr >> 1;
        push(v, vl, vr);
        add(l, r, x, v + v, vl, vm);
        add(l, r, x, v + v + 1, vm, vr);
        node ans = merge(t[v + v], t[v + v + 1]);
        t[v] = merge(t[v + v], t[v + v + 1]);
    }
    node get(int l, int r, int v = 1, int vl = 0, int vr = n) {
        if (vl >= r || vr <= l) return node();
        if (vl >= l && vr <= r) return t[v];
        int vm = vl + vr >> 1;
        push(v, vl, vr);
        if (l >= vm) return get(l, r, v + v + 1, vm, vr);
        if (r <= vm) return get(l, r, v + v, vl, vm);
        node left = get(l, r, v + v, vl, vm);
        node right = get(l, r, v + v + 1, vm, vr);
        return merge(left, right);
    }
} t;
 
signed main() {
    FAST; FIXED; RANDOM;
    int n;
    cin >> n;
    t.build(n);
    for (int i = 0; i < n; ++i) {
        int h;
        cin >> h;
        t.add(i, i + 1, h);
    }
    int q;
    cin >> q;
    while (q--) {
        int l, r, d;
        cin >> l >> r >> d;
        --l;
        t.add(l, r, d);
        //cout << t.get(3, 7).len[3] << '\n';
        cout << t.t[1].ans << '\n';
    }
    return 0;
}