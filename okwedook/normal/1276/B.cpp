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

graph Gab, Ga, Gb, G;
vector<bool> used;

void dfsused(int v) {
    used[v] = true;
    for (auto i : G[v])
        if (!used[i])
            dfsused(i);
}

void solve() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    --a, --b;
    if (a > b) swap(a, b);
    Ga = Gb = Gab = graph(n);
    vector<pii> edge;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        if (u > v) swap(u, v);
        if (u != a && v != a) {
            Ga[u].pb(v);
            Ga[v].pb(u);
        }
        if (u != b && v != b) {
            Gb[u].pb(v);
            Gb[v].pb(u);
        }
        Gab[u].pb(v);
        Gab[v].pb(u);
    }
    used = vector<bool>(n);
    G = Gb;
    dfsused(a);
    auto useda = used;
    used = vector<bool>(n);
    G = Ga;
    dfsused(b);
    auto usedb = used;
    ll c1 = 0, c2 = 0;
    for (int i = 0; i < n; ++i) {
        if (useda[i] && usedb[i] || i == a || i == b) continue;
        if (useda[i]) ++c1;
        if (usedb[i]) ++c2;
    }
    cout << c1 * c2 << '\n';
}

signed main() {
    FAST; FIXED; RANDOM;
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}