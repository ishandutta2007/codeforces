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

struct vec {
    ll x, y;
    vec() {}
    vec(ll x, ll y) { this->x = x; this->y = y; }
    vec operator+=(const vec &v) { x += v.x; y += v.y; return *this; }
    vec operator-=(const vec &v) { x -= v.x; y -= v.y; return *this; }
    vec operator*=(const ll &k) { x *= k; y *= k; return *this; }
    vec operator-() const { return vec(-x, -y); }
    vec orth() const { return vec(-y, x); }
    ll len2() const { return x * x + y * y; }
    ld len() const { return sqrt(len2()); }
    friend vec operator+(vec a, const vec &b) { return a += b; }
    friend vec operator-(vec a, const vec &b) { return a -= b; }
    friend vec operator*(vec a, const ll &k) { return a *= k; }
    friend ll operator*(const vec &a, const vec &b) { return a.x * b.x + a.y * b.y; }
    friend ll operator/(const vec &a, const vec &b) { return a.x * b.y - a.y * b.x; }
    friend istream& operator>>(istream& str, vec &v) { return str >> v.x >> v.y; }
    friend ostream& operator<<(ostream& str, const vec &v) { return str << v.x << ' ' << v.y; }
    friend bool operator<(const vec &a, const vec &b) { return a.x == b.x ? a.y < b.y : a.x < b.x; }
    friend bool operator==(const vec &a, const vec &b) { return a.x == b.x && a.y == b.y; }
    friend bool operator!=(const vec &a, const vec &b) { return a.x != b.x || a.y != b.y; }
};

ll C(ll n, ll k) {
    ll ans = 1;
    for (ll x = n - k + 1; x <= n; ++x)
        ans *= x;
    for (ll x = 1; x <= k; ++x)
        ans /= x;
    return ans;
}

signed main() {
    FAST; FIXED; RANDOM;
    int n;
    cin >> n;
    vector<vec> a(n);
    cin >> a;
    sort(a);
    ll ans = 0;
    vector<pii> s;
    for (int i = 0; i < n; ++i) {
        deque<vec> b;
        for (int j = 0; j < i; ++j) b.pb(a[j] - a[i]);
        for (int j = i + 1; j < n; ++j) b.pb(a[j] - a[i]);
        sort(all(b), [](vec a, vec b) {
            if (a.y < 0 && b.y >= 0) return false;
            if (b.y < 0 && a.y >= 0) return true;
            return a / b > 0;
        });
        for (int i = 0; i < sz(b); ++i) {
            int l = 0, r = sz(b);
            while (r - l > 1) {
                int mid = r + l >> 1;
                if (b[mid] / b[0] < 0) l = mid;
                else r = mid;
            }
            ll c1 = l, c2 = sz(b) - l - 1;
            assert(c1 + c2 == sz(b) - 1);
            ans += C(c1, 1) * C(c2, 2);
            s.pb({c1, c2});
            b.pb(b.front());
            b.popf();
        }
    }
    cout << ans - C(n, 4) * (n - 4);
    return 0;
}