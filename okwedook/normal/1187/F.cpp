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

struct zet {
    int val;
    zet(ll x = 0) { val = x % mod; if (val < 0) val += mod; }
    zet(ll a, ll b) { *this += a; *this /= b; }

    zet& operator+=(zet const &b) { val += b.val; if (val >= mod) val -= mod; return *this; }
    zet& operator-=(zet const &b) { val -= b.val; if (val < 0) val += mod; return *this; }
    zet& operator*=(zet const &b) { val = (val * (ll)b.val) % mod; return *this; }

    friend zet mypow(zet a, ll n) {
        zet res = 1;
        while (n) { if (n & 1) res *= a; a *= a; n >>= 1; }
        return res;
    }
    friend zet inv(zet a) { return mypow(a, mod - 2); }
    zet& operator/=(zet const& b) { return *this *= inv(b); }
    friend zet operator+(zet a, const zet &b) { return a += b; }
    friend zet operator-(zet a, const zet &b) { return a -= b; }
    friend zet operator-(zet a) { return 0 - a; }
    friend zet operator*(zet a, const zet &b) { return a *= b; }
    friend zet operator/(zet a, const zet &b) { return a /= b; }
    friend istream& operator>>(istream& stream, zet &a) { return stream >> a.val; }
    friend ostream& operator<<(ostream& stream, const zet &a) { return stream << a.val; }
    friend bool operator==(zet const &a, zet const &b) { return a.val == b.val; }
    friend bool operator!=(zet const &a, zet const &b) { return a.val != b.val; }
    friend bool operator<(zet const &a, zet const &b) { return a.val < b.val; }
};

struct zethash {
    size_t operator()(const zet &z) const {
        return z.val;
    }
};

zet inter(ll l1, ll r1, ll l2, ll r2) {
    return max(0ll, min(r1, r2) - max(l1, l2));
}

zet inter(ll l1, ll r1, ll l2, ll r2, ll l3, ll r3) {
    return max(0ll, min(r1, min(r2, r3)) - max(l1, max(l2, l3)));
}

zet len(ll l, ll r) {
    return r - l;
}

void print(zet x) {
    for (int i = 1; i < 10000; ++i)
        if ((x * i).val < 10000) {
            cout << x * i << '/' << i << '\n';
            return;
        }
}

signed main() {
    FAST; FIXED; RANDOM;
    int n;
    cin >> n;
    vector<ll> l(n), r(n);
    cin >> l >> r;
    for (auto &i : r) ++i;
    vector<zet> eq(n), no(n);
    eq[0] = 0;
    no[0] = 1;
    for (int i = 1; i < n; ++i) {
        eq[i] = inter(l[i - 1], r[i - 1], l[i], r[i]) / 
            (len(l[i - 1], r[i - 1]) * len(l[i], r[i]));
        no[i] = 1 - eq[i];
    }
    zet sum = 0;
    for (auto i : no) sum += i;
    sum *= sum;
    for (auto i : no) {
        sum -= i * i;
        sum += i;
    }
    zet check = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (i == j) check += no[i];
            else check += no[i] * no[j];
    for (int i = 2; i < n; ++i) {
        sum -= 2 * no[i] * no[i - 1];
        zet add = 1 - eq[i] - eq[i - 1];
        add += inter(l[i - 2], r[i - 2], l[i - 1], r[i - 1], l[i], r[i]) /
            (len(l[i - 2], r[i - 2]) * len(l[i - 1], r[i - 1]) * len(l[i], r[i]));
        sum += 2 * add;
    }
    cout << sum;
    return 0;
}