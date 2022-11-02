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
#define mod 1000000021
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
 
ll lb(ll s, ll k) {
    ll l = 0, r = s + 2;
    while (r - l > 1) {
        ll m = r + l >> 1;
        if (s / m < k) r = m;
        else l = m;
    }
    return l;
} //s / x >= k

//a - ca * len <= ca
//a <= ca * (len + 1)
//ca >= a / (len + 1)

ll divi(ll a, ll b) {
    return (a + b - 1) / b;
}


signed main() {
    FAST; FIXED; RANDOM;
    ll a, b;
    cin >> a >> b;
    ll s = a + b;
    ll x = sqrt(s);
    hashset<ll> st;
    for (ll i = 1; i <= x; ++i)
        st.insert(i), st.insert(s / i);
    ll ans = 0;
    for (auto len : st) {
        ll mn = lb(s, len + 1) + 1;
        ll mx = lb(s, len);
        ll ca = max(1ll, divi(a, len + 1));
        ll cb = max(1ll, divi(b, len + 1));
        ll mca = a / len;
        ll mcb = b / len;
            //cout << len << ' ' << mn << ' ' << mx << ' ' << ca << ' ' << cb << ' ' << mca << ' ' << mcb << '\n';
            //cout << '\n';
        
        if (ca <= mca && cb <= mcb) {
            //for (int t = max(mn, max(len, ca + cb)); t <= min(mca + mcb, mx); ++t) cout << t << '\n';
            ans += max(0ll, min(mca + mcb, mx) - max(mn, ca + cb) + 1);
        }
    }
    cout << ans;
    return 0;
}