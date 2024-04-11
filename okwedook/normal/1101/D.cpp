#pragma GCC optimize("O3", "unroll-loops")

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <cmath>
#include <tuple>
#include <random>
#include <bitset>
#include <queue>

using namespace std;

#define FIXED cout << fixed << setprecision(15)
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define RANDOM srand(85453532)
#define ll long long
#define ld double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define graph vector<vector<int>>
#define pb push_back
#define popb pop_back
#define pf push_front
#define popf pop_front
#define hashmap unordered_map
#define hashset unordered_set
#define sz(a) int(a.size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define eps 1e-9
#define mod 1000000007
#define inf 4000000000000000007ll
#define f first
#define s second
#define shuffle(a) \
    for (int i = 0; i < sz(a); ++i) \
        swap(a[i], a[rand() % sz(a)])

template<class T, class U> inline void checkmin(T &x, U y) { if (y < x) x = y; }
template<class T, class U> inline void checkmax(T &x, U y) { if (y > x) x = y; }
template<class T, class U> inline bool ifmin(T &x, U y) { 
    if (y < x) return x = y, true;
    return false; 
}
template<class T, class U> inline bool ifmax(T &x, U y) { 
    if (y > x) return x = y, true;
    return false; 
}
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }
template<class T> inline istream& operator>>(istream &stream, vector<T> &a) { 
    for (auto &i : a) stream >> i;
    return stream;
}

const int LOGN = 20;
const int N = 2e5 + 10;
vector<int> a;
vector<int> primes;
int ans = 0;

graph G;
vector<vector<pii>> dp(N);

void dfsdp(int v, int p = -1) {
    for (auto i : G[v])
        if (i != p)
            dfsdp(i, v);
    for (auto j : primes) 
        if (a[v] % j == 0) {
            dp[v].pb({j, 1});
            while (a[v] % j == 0) a[v] /= j;
        }
    if (a[v] > 1) dp[v].pb({a[v], 1});
    sort(dp[v]);
    vector<int> ptr(sz(G[v]), 0);
    for (auto &i : dp[v]) {
        for (int j = 0; j < sz(ptr); ++j)
            while (ptr[j] < sz(dp[G[v][j]]) && dp[G[v][j]][ptr[j]].f < i.f)
                ++ptr[j];
        int mx = 0, secmx = 0;
        for (int j = 0; j < sz(ptr); ++j) {
            int val = 0;
            if (ptr[j] != sz(dp[G[v][j]]) && dp[G[v][j]][ptr[j]].f == i.f)
                val = dp[G[v][j]][ptr[j]].s;
            if (val > mx) secmx = mx, mx = val;
            else if (val > secmx) secmx = val;
        }
        checkmax(ans, mx + secmx + 1);
        i.s += mx;
    }
}

bool prime(int n) {
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0) return false;
    return n > 1;
}

signed main() {
    FAST; FIXED; RANDOM;
    int n;
    cin >> n;
    for (int i = 1; i * i <= N; ++i)
        if (prime(i)) primes.pb(i);
    a = vector<int> (n);
    cin >> a;
    G = graph(n);
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        G[u].pb(v);
        G[v].pb(u);
    }
    dfsdp(0);
    cout << ans;
    return 0;
}