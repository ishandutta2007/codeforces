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
#include <complex>

using namespace std;

#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FIXED cout << fixed << setprecision(12);
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
#define sz(a) int(a.size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define shuffle(a) \
    for (int i = 0; i < sz(a); ++i) \
        swap(a[i], a[rand() % sz(a)])

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
    int g = 0;
    node() {}
    node(int k) { g = k; }
};

node merge(node a, node b) {
    return node(__gcd(a.g, b.g));
}

struct Tree {
    static const int n = 1 << 19;
    node t[2 * n + 5];
    void upd(int r, int x) {
        r += n;
        t[r] = node(x);
        r >>= 1;
        for (; r > 0; r >>= 1)
            t[r] = merge(t[r + r], t[r + r + 1]);
    }
    node get(int l, int r) {
        l += n;
        r += n + 1;
        node ans;
        while (l < r) {
            if (l & 1) ans = merge(ans, t[l++]);
            if (r & 1) ans = merge(t[--r], ans);
            l >>= 1;
            r >>= 1;
        }
        return ans;
    }
    int pref(int l, int r, int x, int v = 1, int vl = 0, int vr = n) {
        if (vl >= r || vr <= l) return 0;
        if (vl >= l && vr <= r && t[v].g % x == 0) return vr - vl;
        int vm = vl + vr >> 1;
        if (vl == vm) return 0;
        int ansl = pref(l, r, x, v + v, vl, vm);
        if (ansl < vm - max(vl, l)) return ansl;
        else return ansl + pref(l, r, x, v + v + 1, vm, vr);
    }
    int suff(int l, int r, int x, int v = 1, int vl = 0, int vr = n) {
        if (vl >= r || vr <= l) return 0;
        if (vl >= l && vr <= r && t[v].g % x == 0) return vr - vl;
        int vm = vl + vr >> 1;
        if (vl == vm) return 0;
        int ansr = suff(l, r, x, v + v + 1, vm, vr);
        if (ansr < min(vr, r) - vm) return ansr;
        else return ansr + suff(l, r, x, v + v, vl, vm);
    }
} tree;

signed main() {
    FAST; FIXED; RANDOM;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        tree.upd(i, a);
    }
    int q;
    cin >> q;
    while (q--) {
        int mode;
        cin >> mode;
        if (mode == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            --l, --r;
            int left = l + tree.pref(l, r + 1, x) - 1;
            int right = r - tree.suff(l, r + 1, x) + 1;
            if (right - left <= 2) cout << "YES\n";
            else cout << "NO\n";
        } else {
            int r, x;
            cin >> r >> x;
            tree.upd(r - 1, x);
        }
    }
    return 0;
}