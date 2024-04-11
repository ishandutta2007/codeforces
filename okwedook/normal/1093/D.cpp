#pragma GCC optimize("O3", "unroll-loops")
 
#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <deque>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <ctime>
#include <complex>
#include <random>
#include <bitset>
#include <algorithm>
#include <fstream>
#include <tuple>
#include <sstream>
#include <functional>
using namespace std;
 
#define FILES freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(20)
#define RANDOM srand(time(nullptr))
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define mp make_pair
#define hashmap unordered_map
#define hashset unordered_set
#define ll long long
#define ld long double
#define ui unsigned int
#define ull unsigned ll
#define pii pair<int, int>
#define pll pair<ll, ll>
#define graph vector<vector<int>>
#define eps 1e-9
#define mod 998244353
#define inf 1000000000000000007ll
#define intinf ((1 << 31) - 1)
#define f first
#define s second
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) int(a.size())
#define shuffle(a) \
    for (int i = 0; i < sz(a); ++i) \
        swap(a[i], a[rand() % sz(a)])
 
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }
template<class T, class U> inline void checkmin(T &x, U y) { if (x > y) x = y; }
template<class T, class U> inline void checkmax(T &x, U y) { if (x < y) x = y; }

graph G;
vector<int> cnt, color;
ll ans = 1;

void dfs(int v, int p = -1, int curr = 1) {
    cnt[curr]++;
    color[v] = curr;
    for (auto &i : G[v])
        if (i != p) {
            if (color[i] == curr) ans = 0;
            else if (color[i] == 0) dfs(i, v, 3 - curr);
        }
}

ll binpow(ll a, ll n) {
    ll ans = 1;
    for (int i = 0; i < n; ++i)
        ans = (ans * a) % mod;
    return ans;
}

void solve() {
    ans = 1;
    ll n, m;
    cin >> n >> m;
    G = graph(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        G[u].pb(v);
        G[v].pb(u);
    }
    color = vector<int>(n, 0);
    cnt = vector<int>(3, 0);
    for (int i = 0; i < n; ++i)
        if (color[i] == 0) {
            cnt[2] = cnt[1] = 0;
            dfs(i);
            ans = (ans * (binpow(2, cnt[2]) + binpow(2, cnt[1]))) % mod;
        }
    cout << ans << '\n';
}

int main() {
    FAST; FIXED; RANDOM;
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}