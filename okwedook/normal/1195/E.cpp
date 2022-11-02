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
#define mod 998244353
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

struct window {
    deque<pll> que;
    int l;
    window(int len) {
        l = len;
    }
    void add(pii a) {
        while (sz(que) && que.back().f > a.f)
            que.popb();
        que.pb(a);
    }
    int get(int i) {
        while (que.front().s <= i - l) que.popf();
        return que.front().f;
    }
};  

signed main() {
    FAST; FIXED; RANDOM;
    ll n, m, a, b;
    cin >> n >> m >> a >> b;
    vector<ll> g(n * m);
    ll x, y, z;
    cin >> g[0] >> x >> y >> z;
    for (int i = 1; i < sz(g); ++i)
        g[i] = (g[i - 1] * x + y) % z;
    vector<vector<ll>> h(n, vector<ll>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) 
            h[i][j] = g[i * m + j];
    vector<vector<ll>> mn(n, vector<ll>(m - b + 1));
    for (int i = 0; i < n; ++i) {
        window w(b);
        for (int j = 0; j < b - 1; ++j) w.add({h[i][j], j});
        for (int j = b - 1; j < m; ++j) {
            w.add({h[i][j], j});
            mn[i][j - b + 1] = w.get(j);
        }
    }
    long long ans = 0;
    for (int j = 0; j < m - b + 1; ++j) {
        window w(a);
        for (int i = 0; i < a - 1; ++i)
            w.add({mn[i][j], i});
        for (int i = a - 1; i < n; ++i) {
            w.add({mn[i][j], i});
            ans += w.get(i);
        }
    }
    cout << ans;
    return 0;
}