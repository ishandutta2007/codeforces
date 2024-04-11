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

graph rev, G;

void dfs(int v, int p = -1) {
    for (auto &i : G[v])
        if (i != p) {
            rev[i].pb(v);
            dfs(i, v);
        }
}

void solve() {
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
    int k1, k2;
    cin >> k1;
    vector<int> arr(k1);
    for (auto &i : arr) cin >> i, --i;
    cin >> k2;
    vector<int> brr(k2);
    for (auto &i : brr) cin >> i, --i;
    vector<bool> used(n);
    for (auto &i : arr) used[i] = true;
    cout << "B " << brr[0] + 1 << endl;
    int y;
    cin >> y;
    --y;
    rev = graph(n);
    dfs(y);
    y = arr[0];
    while (sz(rev[y])) {
        if (!used[rev[y][0]]) break;
        y = rev[y][0];
    }
    int start = y;
    cout << "A " << y + 1 << endl;
    cin >> y;
    --y;
    for (auto i : brr)
        if (i == y) {
            cout << "C " << start + 1 << endl;
            return;
        }
    cout << "C " << -1 << endl;
}

signed main() {
    FAST; FIXED; RANDOM;
    int q;
    cin >> q;
    while (q--) solve();
    return 0;
}