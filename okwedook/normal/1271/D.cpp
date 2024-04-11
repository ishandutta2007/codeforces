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
 
const int N = 5000 + 10;
const int MAXSOLDIERS = 5000 + 10;
 
vector<vector<int>> dp(N, vector<int>(MAXSOLDIERS, -mod));
 
signed main() {
    FAST; FIXED; RANDOM;
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> last(n);
    for (int i = 0; i < n; ++i) last[i] = i;
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i] >> c[i];
    }
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        checkmax(last[v - 1], u - 1);
    }
    graph G(n);
    for (int i = 0; i < n; ++i) {
        G[last[i]].pb(c[i]);
        rsort(G[i]);
    }
    if (a[0] > k) {
        cout << -1;
        return 0;
    }
    k += b[0];
    dp[0][k] = 0;
    if (k > 0 && sz(G[0])) dp[0][k - 1] = c[0];
    vector<pii> upd;
    upd.reserve(50000);
    for (int i = 1; i < n; ++i) {
        for (int j = a[i]; j < N; ++j)
            dp[i][min(N - 1, j + b[i])] = dp[i - 1][j];
        int add = 0;
        upd.clear();
        for (int j = 0; j < sz(G[i]); ++j) {
            add += G[i][j];
            for (int was = j; was < N; ++was)
                upd.pb({was - j - 1, dp[i][was] + add});
        }
        for (auto u : upd)
            checkmax(dp[i][u.f], u.s);
    }
    int ans = -1;
    for (auto i : dp[n - 1]) checkmax(ans, i);
    cout << ans;
    return 0;
}