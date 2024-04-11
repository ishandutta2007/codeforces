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
#include <cassert>
 
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
    int mx = 0;
    node(int x = 0) { mx = x; } 
};
 
node merge(node a, node b) {
    return node(max(a.mx, b.mx));
}
 
struct Tree {
    static const int n = 1 << 19;
    node t[2 * n + 5];
    void upd(int r, int x) {
        r += n;
        t[r] = node(x);
        for (r >>= 1; r > 0; r >>= 1) 
            t[r] = merge(t[r + r], t[r + r + 1]);
    }
    int get(int l, int r) {
        l += n;
        r += n + 1;
        node ans;
        while (l < r) {
            if (l & 1) ans = merge(ans, t[l++]);
            if (r & 1) ans = merge(t[--r], ans); 
            l >>= 1;
            r >>= 1;
        }
        return ans.mx;
    }
} t;
 
void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        t.upd(i, a);
    }
    vector<int> b(n);
    cin >> b;
    bool ans = true;
    for (int i = n - 1; i >= 0; --i) {
        int l = -1, r = n;
        while (r - l > 1) {
            int m = r + l >> 1;
            if (t.get(m, n - 1) < b[i]) r = m;
            else l = m;
        }
        if (l == -1) {
            ans = false;
            break;
        }
        if (t.get(l, l) != b[i]) {
            ans = false;
            break;
        }
        t.upd(l, 0);
    }
    if (ans) cout << "YES\n";
    else cout << "NO\n";
}
 
signed main() {
    FAST; FIXED; RANDOM;
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}