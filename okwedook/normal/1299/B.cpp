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
 
signed main() {
    FAST; FIXED; RANDOM;
    int n;
    cin >> n;
    vector<vec> a(n);
    cin >> a;
    for (auto &i : a) i *= 2;
    vec sum = {0, 0};
    for (auto i : a) sum += i;
    if (sum.x % n != 0 && sum.y % n != 0) {
        cout << "NO";
        return 0;
    }
    sum.x /= n;
    sum.y /= n;
    set<vec> st;
    for (auto i : a) st.insert(i);
    for (auto i : a)
        if (!st.count(sum + (sum - i))) {
            cout << "NO";
            return 0;
        }
    cout << "YES";
    return 0;
}