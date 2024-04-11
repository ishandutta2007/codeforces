#pragma GCC optimize("O3", "unroll-loops")
 
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
#include <complex>
 
using namespace std;
 
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FIXED cout << fixed << setprecision(12);
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
#define sz(a) int(a.size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define shuffle(a) \
    for (int i = 0; i < sz(a); ++i) \
        swap(a[i], a[rand() % sz(a)])
 
template<class T, class U> inline void checkmin(T &x, U y) { if (y < x) x = y; }
template<class T, class U> inline void checkmax(T &x, U y) { if (y > x) x = y; }
template<class T, class U> inline bool ifmax(T &x, U y) { if (y > x) return x = y, true; return false; }
template<class T, class U> inline bool ifmin(T &x, U y) { if (y < x) return x = y, true; return false; }
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }
template<class T, class U> inline istream& operator>>(istream& str, pair<T, U> &p) { return str >> p.f >> p.s; }
template<class T> inline istream& operator>>(istream& str, vector<T> &a) { for (auto &i : a) str >> i; return str; }
 
ll solve(ll l, ll r, ll ind) {
    r += 7 - ind;
    l += 7 - ind;
    r /= 7;
    l = (l + 6) / 7;
    return max(0ll, r - l + 1);
}
 
signed main() {
    FAST; FIXED; RANDOM;
    ll a, b, c;
    cin >> a >> b >> c;
    vector<ll> fish = {0, 3, 6};
    vector<ll> rabbit = {1, 5};
    vector<ll> chick = {2, 4};
    ll ans = 0;
    for (ll start = 0; start < 7; ++start) {
        ll l = 0, r = 3e9;
        while (r - l > 1) {
            ll m = r + l >> 1;
            ll ca = 0, cb = 0, cc = 0;
            for (auto i : fish) ca += solve(start, start + m - 1, i);
            for (auto i : rabbit) cb += solve(start, start + m - 1, i);
            for (auto i : chick) cc += solve(start, start + m - 1, i);
            if (ca <= a && cb <= b && cc <= c) l = m;
            else r = m;
        }
        checkmax(ans, l);
    }
    cout << ans;
    return 0;
}