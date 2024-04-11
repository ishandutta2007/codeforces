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
};

struct Fenv {
    static const int n = 5e5 + 10;
    zet fenv[n];
    void add(int r, zet x) {
        for (; r < n; r |= r + 1)
            fenv[r] += x;
    }
    zet get(int r) {
        zet ans = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ans += fenv[r];
        return ans;
    }
    zet get(int l, int r) {
        return get(r) - get(l - 1);
    }
    void clear() {
        for (int i = 0; i < n; ++i) fenv[i] = 0;
    }
} fenv;

signed main() {
    FAST; FIXED; RANDOM;
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    vector<int> b = a;
    sort(b);
    vector<int> ind(n);
    for (int i = 0; i < n; ++i) ind[i] = lower_bound(all(b), a[i]) - b.begin();
    int cnt = 1;
    vector<zet> pref(n), suff(n);
    for (int i = 0; i < n; ++i) {
        pref[i] = zet(i) * zet(i + 1) * 500000004 - fenv.get(ind[i], n);
        fenv.add(ind[i], i + 1);
    }
    fenv.clear();
    for (int i = n - 1; i >= 0; --i) {
        suff[i] = zet(n - i - 1) * zet(n - i) * 500000004 - fenv.get(ind[i], n);
        fenv.add(ind[i], n - i);
    }
    zet ans = 0;
    for (int i = 0; i < n; ++i) 
        ans += (pref[i] * (n - i) + suff[i] * (i + 1) + zet(i + 1) * zet(n - i)) * a[i];
    cout << ans;
    return 0;
}