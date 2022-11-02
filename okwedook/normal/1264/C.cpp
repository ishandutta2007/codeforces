#pragma GCC optimize("O3", "unroll-all-loops")
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
#include <complex>
 
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

zet getsum(vector<zet> &sum, int l, int r) {
    if (l == 0) return sum[r];
    return sum[r] - sum[l - 1];
}

zet getsumsuff(vector<zet> &sum, vector<zet> &v, int l, int r) {
    if (r + 1 >= sz(v)) return getsum(sum, l, r);
    return getsum(sum, l, r) / v[r + 1];
}
 
signed main() {
    FAST; FIXED; RANDOM;
    int n, q;
    cin >> n >> q;
    //cout << zet(1) / 2 << '\n';
    vector<zet> p(n);
    cin >> p;
    for (auto &i : p) i /= 100, i = 1 / i;

    set<int> st = {0, n};
    vector<zet> suffp = p;
    for (int i = n - 2; i >= 0; --i)
        suffp[i] *= suffp[i + 1];
    vector<zet> prefsuffp = suffp;
    for (int i = 1; i < sz(prefsuffp); ++i)
        prefsuffp[i] += prefsuffp[i - 1];
    zet sum = prefsuffp.back();
    while (q--) {
        int v;
        cin >> v;
        --v;
        if (st.count(v)) {
            auto it1 = st.find(v);
            auto it2 = it1, it0 = it1;
            ++it2;
            --it0;
            sum -= getsumsuff(prefsuffp, suffp, *it0, *it1 - 1);
            sum -= getsumsuff(prefsuffp, suffp, *it1, *it2 - 1);
            st.erase(it1);
            sum += getsumsuff(prefsuffp, suffp, *it0, *it2 - 1);
        } else {
            auto it2 = st.lower_bound(v);
            auto it0 = it2;
            --it0;
            sum -= getsumsuff(prefsuffp, suffp, *it0, *it2 - 1);
            st.insert(v);
            sum += getsumsuff(prefsuffp, suffp, *it0, v - 1);
            sum += getsumsuff(prefsuffp, suffp, v, *it2 - 1);
        }
        cout << sum << '\n';
    }
    return 0;
}