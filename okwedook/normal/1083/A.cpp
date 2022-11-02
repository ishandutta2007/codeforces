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
#define FIXED cout << fixed << setprecision(7)
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

vector<vector<pii>> G;
vector<int> w;
ll allans = 0;

ll dfs(int v, int p = -1) {
    ll ans = w[v];
    vector<ll> arr;
    for (auto &i : G[v]) 
        if (i.f != p) {
            ll ansi = dfs(i.f, v) - i.s;
            checkmax(ansi, 0);
            arr.pb(ansi);
            checkmax(ans, ansi + w[v]);
        }
    sort(arr);
    if (sz(arr) > 1) checkmax(allans, w[v] + arr[sz(arr) - 1] + arr[sz(arr) - 2]);
    checkmax(allans, ans);
    return ans;
}

int main() {
    FAST; FIXED; RANDOM;
    ll n;
    cin >> n;
    G.resize(n);
    w.resize(n);
    for (auto &i : w) cin >> i;
    for (int i = 1; i < n; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        --u, --v;
        G[u].pb({v, c});
        G[v].pb({u, c});
    }
    dfs(0);
    cout << allans;
    return 0;
}