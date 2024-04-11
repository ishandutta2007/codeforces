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

graph G;
const int N = 1e5 + 100;
const int LOG = 17;
int p[LOG][N];
int h[N];

int lca(int u, int v) {
    if (h[u] < h[v]) swap(u, v);
    int d = h[u] - h[v];
    for (int l = 0; l < LOG; ++l)
        if (d >> l & 1) u = p[l][u];
    if (u == v) return u;
    for (int l = LOG - 1; l >= 0; --l)
        if (p[l][u] != p[l][v]) {
            u = p[l][u];
            v = p[l][v];
        }
    return p[0][u];
}

int dist(int u, int v) {
    return h[u] + h[v] - 2 * h[lca(u, v)];
}

void orient(int v, int par, int he = 0) {
    p[0][v] = par;
    h[v] = he;
    for (int l = 1; l < LOG; ++l)
        p[l][v] = p[l - 1][p[l - 1][v]];
    for (auto i : G[v])
        if (i != par) orient(i, v, he + 1);
}

bool check(int a, int b) {
    return a <= b && b % 2 == a % 2;
}

signed main() {
    FAST; FIXED; RANDOM;
    int n;
    cin >> n;
    G = graph(n);
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        G[u].pb(v);
        G[v].pb(u);
    }
    orient(0, 0);
    int q;
    cin >> q;
    while (q--) {
        int x, y, a, b, k;
        cin >> x >> y >> a >> b >> k;
        --x, --y, --a, --b;
        int ax = dist(a, x), ay = dist(a, y), bx = dist(b, x), by = dist(b, y), xy = dist(x, y), ab = dist(a, b);
        if (check(ab, k)) {
            cout << "YES\n";
            continue;
        }
        if (check(ax + 1 + xy + 1 + by, k)) {
            cout << "YES\n";
            continue;
        }
        if (check(ay + 1 + xy + 1 + bx, k)) {
            cout << "YES\n";
            continue;
        }
        if (check(ax + 1 + by, k)) {
            cout << "YES\n";
            continue;
        }
        if (check(ay + 1 + bx, k)) {
            cout << "YES\n";
            continue;
        }
        cout << "NO\n";
    }
    return 0;
}