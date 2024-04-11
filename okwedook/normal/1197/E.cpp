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
 
struct node {
    ll mn = inf;
    zet sum = 0;
    node() {}
    node(ll x, zet c = 1) {
        mn = x;
        sum = c;
    }
};
 
node merge(node a, node b) {
    if (a.mn < b.mn) return a;
    if (b.mn < a.mn) return b;
    return node(a.mn, a.sum + b.sum);
}
 
struct Tree {
    static const int n = 1 << 18;
    node t[2 * n + 5];
    void upd(int r, ll x, zet c) {
        r += n;
        t[r] = merge(t[r], node(x, c));
        for (r >>= 1; r > 0; r >>= 1)
            t[r] = merge(t[r + r], t[r + r + 1]);
    }
    node get(int l, int r) {
        l += n;
        r += n + 1;
        node ans;
        while (l < r) {
            if (l & 1) ans = merge(ans, t[l++]);
            if (r & 1) ans = merge(ans, t[--r]);
            l >>= 1;
            r >>= 1;
        }
        return ans;
    }
} t;
 
signed main() {
    FAST; FIXED; RANDOM;
    int n;
    cin >> n;
    vector<pii> a(n);
    for (auto &i : a) {
        cin >> i.s >> i.f;
    }
    vector<int> b;
    for (auto i : a) b.pb(i.s);
    sort(b);
    sort(a);
    vector<pii> was = a;
    for (auto &i : a) {
        i.f = upper_bound(all(b), i.f) - b.begin() - 1;
        i.s = lower_bound(all(b), i.s) - b.begin();
    }
    vector<ll> mn(n);
    vector<zet> cnt(n);
    pair<ll, zet> answer = {inf, 0};
    for (int i = 0; i < n; ++i) {
        node ans = t.get(0, a[i].f);
        if (ans.mn == inf) {
            mn[i] = was[i].f - was[i].s;
            cnt[i] = 1;
        } else {
            mn[i] = ans.mn + was[i].f - was[i].s;
            cnt[i] = ans.sum;
        }
        t.upd(a[i].s, mn[i], cnt[i]);
        mn[i] += was[i].s;
        if (lower_bound(all(a), pii(a[i].s, -1)) == a.end()) {
            if (ifmin(answer.f, mn[i])) answer.s = 0;
            if (answer.f == mn[i]) answer.s += cnt[i];
        }
    }
    cout << answer.s;
    return 0;
}