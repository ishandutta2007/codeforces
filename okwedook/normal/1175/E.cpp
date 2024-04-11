#pragma GCC optimize("O3", "unroll-loops")
  
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#include <bitset>
#include <random>
  
using namespace std;
  
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FIXED cout << fixed << setprecision(12);
#define RANDOM srand(392403285);
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define graph vector<vector<int>>
#define f first
#define s second
#define eps 1e-9
#define mod 1000000007
#define inf 3000000000000000007ll
#define pb push_back
#define sz(a) int(a.size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
  
template<class T, class U> inline void checkmin(T &x, U y) { if (y < x) x = y; }
template<class T, class U> inline void checkmax(T &x, U y) { if (y > x) x = y; }
template<class T, class U> inline bool ifmin(T &x, U y) { if (y < x) return x = y, true; return false; }
template<class T, class U> inline bool ifmax(T &x, U y) { if (y > x) return x = y, true; return false; }
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }
template<class T> inline istream& operator>>(istream& str, vector<T> &a) { for (auto &i : a) str >> i; return str; }

struct node {
    pii mx = {-1, -1};
    node() {}
    node(pii a) { mx = a; }
};  

node merge(node a, node b) {
    return node(max(a.mx, b.mx));
}

struct Tree {
    static const int n = 1 << 18;
    node t[2 * n + 5];
    void upd(int r, pii x) {
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
} tree;

const int LOGN = 18;
const int N = 2e5 + 10;

int p[LOGN][N];

signed main() {
    FAST; FIXED; RANDOM;
    int n, m;
    cin >> n >> m;
    vector<pii> a(n);
    for (auto &i : a) cin >> i.f >> i.s;
    sort(a);
    for (int i = 0; i < n; ++i) tree.upd(i, {a[i].s, i});
    for (int i = 0; i < n; ++i) {
        int l = i, r = n;
        while (r - l > 1) {
            int m = r + l >> 1;
            if (a[m].f <= a[i].s) l = m;
            else r = m; 
        }
        int best = n;
        if (l != i) {
            pii ans = tree.get(i + 1, l).mx;
            if (ans.f > a[i].s) best = ans.s;
        }
        p[0][i] = best;
    }
    p[0][n] = n;
    for (int l = 1; l < LOGN; ++l) 
        for (int i = 0; i <= n; ++i) p[l][i] = p[l - 1][p[l - 1][i]];
    while (m--) {
        int x, y;
        cin >> x >> y;
        int l = -1, r = n;
        while (r - l > 1) {
            int m = r + l >> 1;
            if (a[m].f > x) r = m;
            else l = m;
        }
        if (r == 0) {
            cout << -1 << '\n';
            continue;
        }
        int c = tree.get(0, l).mx.s;
        int ans = mod, curr = 1;
        if (a[c].s >= y) ans = 1;
        for (int l = LOGN - 1; l >= 0; --l) {
            int next = p[l][c];
            if (next != n) {
                if (a[next].s >= y) checkmin(ans, curr + (1 << l));
                else curr += (1 << l), c = next;
            }
        }
        if (ans == mod) cout << -1 << '\n';
        else cout << ans << '\n';
    }
    return 0;   
}