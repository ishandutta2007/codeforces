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

const int N = 1e5 + 10;
const int LOG = ceil(log2(N));

int p[LOG][N];
ll g[LOG][N];
 
vector<ll> x, h;
graph G;
ll ans = 0;

ll gcd(ll a, ll b) {
    if (a == 0) return b;
    if (b == 0) return a;
    return __gcd(a, b);
}

ll get(int cnt, int v) {
    ll ans = 0;
    for (int l = 0; l < LOG; ++l)
        if (cnt >> l & 1) {
            ans = gcd(ans, g[l][v]);
            v = p[l][v];
        }
}
 
void dfs(int v, int par = -1, int he = 0) {
    p[0][v] = par;
    g[0][v] = x[v];
    h[v] = he;
    for (int l = 1; l < LOG; ++l) {
        if (p[l - 1][v] != -1) {
            g[l][v] = gcd(g[l - 1][v], g[l - 1][p[l - 1][v]]);
            p[l][v] = p[l - 1][p[l - 1][v]];
        } else {
            g[l][v] = g[l - 1][v];
            p[l][v] = -1;
        }
    }
    ll was = x[v];
    int r = v;
    while (r >= 0) {
        int pr = r;
        was = gcd(was, x[r]);
        for (int l = LOG - 1; r >= 0 && l >= 0; --l)
            if (gcd(g[l][r], was) == was) r = p[l][r];
        ans += (h[pr] - (r == -1 ? -1 : h[r])) * (was % mod);
        ans %= mod;
    }
    for (auto i : G[v])
        if (i != par) dfs(i, v, he + 1);
}
 
signed main() {
    FAST; FIXED; RANDOM;
    int n;
    cin >> n;
    x = h = vector<ll>(n);
    cin >> x;
    G = graph(n);
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        G[u].pb(v);
        G[v].pb(u);
    }
    dfs(0);
    cout << ans;
    return 0;
}