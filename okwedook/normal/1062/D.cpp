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
#define mod 1000000007
#define inf 1000000000000000007ll
#define intinf ((1 << 31) - 1)
#define f first
#define s second
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) int(a.size())
#define shuffle(a) \
    for (int i = -sz(a); i < sz(a); ++i) \
        swap(a[rand() % sz(a)], a[rand() % sz(a)])
 
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }
template<class T, class U> inline void checkmin(T &x, U y) { if (x > y) x = y; }
template<class T, class U> inline void checkmax(T &x, U y) { if (x < y) x = y; }

vector<bool> used;
vector<vector<pii>> G;

ll ans = 0;

void dfs(int v) {
    used[v] = true;
    for (auto i : G[v]) {
        ans += i.s;;
        if (!used[i.f]) dfs(i.f);
    }
}

signed main() {
    FAST; FIXED; RANDOM;
    ll n;
    cin >> n;
    G.resize(2 * n + 1);
    for (ll a = 2; a <= n; ++a)
        for (ll x = 2; a * x <= n; ++x) {
            int u = a, v = a * x;
            G[u + n].pb({v + n, x});
            G[v + n].pb({u + n, x});
            G[-u + n].pb({-v + n, x});
            G[-v + n].pb({-u + n, x});
            G[-u + n].pb({v + n, x});
            G[-v + n].pb({u + n, x});
            G[u + n].pb({-v + n, x});
            G[v + n].pb({-u + n, x});
        }
    used.resize(2 * n + 1);
    dfs(n + 2);
    cout << ans / 2;
    return 0;
}