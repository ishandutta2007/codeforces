#pragma GCC optimize("O3", "unroll-loops")
 
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <random>
 
using namespace std;
 
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FIXED cout << fixed << setprecision(12);
#define RANDOM srand(235345)
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define graph vector<vector<int>>
#define pb push_back
#define popb pop_back
#define pf push_front
#define popf pop_front
#define eps 1e-9
#define mod 1000000007
#define inf 3000000000000000007ll
#define f first
#define s second
#define sz(a) int(a.size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define shuffle(a) \
    for (int i = 0; i < sz(a); ++i) \
        swap(a[i], a[rand() % sz(a)])
 
template<class T, class U> inline void checkmin(T &x, U y) { if (y < x) x = y; }
template<class T, class U> inline void checkmax(T &x, U y) { if (y > x) x = y; }
template<class T, class U> inline bool ifmin(T &x, U y) { if (y < x) return x = y, true; return false; }
template<class T, class U> inline bool ifmax(T &x, U y) { if (y > x) return x = y, true; return false; }
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }
template<class T, class U> inline istream& operator>>(istream& str, pair<T, U> &p) { return str >> p.f >> p.s; }
template<class T> inline istream& operator>>(istream& str, vector<T> &a) { for (auto &i : a) str >> i; return str; }

vector<vector<ll>> tribo = {
    {0, 0, 1},
    {1, 0, 1},
    {0, 1, 1}
};

vector<vector<ll>> powers = {
    {0, 0, 0, 0, 1}, 
    {1, 0, 0, 0, (mod - 1) - 1}, 
    {0, 1, 0, 0, 0}, 
    {0, 0, 1, 0, (mod - 1) - 2}, 
    {0, 0, 0, 1, 3}, 
};

vector<vector<ll>> operator*(const vector<vector<ll>> &a, const vector<vector<ll>> &b) {
    vector<vector<ll>> ans(sz(a), vector<ll>(sz(a)));
    for (int i = 0; i < sz(a); ++i)
        for (int j = 0; j < sz(a); ++j)
            for (int k = 0; k < sz(a); ++k) {
                ans[i][j] += a[i][k] * b[k][j];
                ans[i][j] %= mod - 1;
            }
    return ans;
}

vector<vector<ll>> mpow(vector<vector<ll>> a, ll n) {
    vector<vector<ll>> ans(sz(a), vector<ll>(sz(a)));
    for (int i = 0; i < sz(a); ++i) ans[i][i] = 1;
    while (n > 0) {
        if (n & 1) ans = ans * a;
        a = a * a;
        n >>= 1;
    }
    return ans;
}

ll mpow(ll x, ll n) {
    ll ans = 1;
    while (n > 0) {
        if (n & 1) ans = (ans * x) % mod;
        x = (x * x) % mod;
        n >>= 1;
    }
    return ans;
}

signed main() {
    FAST; FIXED; RANDOM;
    ll n, f1, f2, f3, c;
    cin >> n >> f1 >> f2 >> f3 >> c;
    vector<vector<ll>> tri = mpow(tribo, n - 1);
    vector<vector<ll>> was = {
        {1, 0, 0},
        {1, 0, 1},
        {0, 1, 1}
    };
    ll p1 = (was * tri)[0][0];
    was = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 1}   
    };
    ll p2 = (was * tri)[0][0];
    was = {
        {0, 0, 1},
        {1, 0, 1},
        {0, 1, 1}   
    };
    ll p3 = (was * tri)[0][0];
    was = {
        {0, 0, 0, 2, 6}, 
        {1, 0, 0, 0, (mod - 1) - 1}, 
        {0, 1, 0, 0, 0}, 
        {0, 0, 1, 0, (mod - 1) - 2}, 
        {0, 0, 0, 1, 3} 
    };
    ll pc = (was * mpow(powers, n - 1))[0][0];
    cout << mpow(c, pc) * mpow(f1, p1) % mod * mpow(f2, p2) % mod * mpow(f3, p3) % mod;
    return 0;
}