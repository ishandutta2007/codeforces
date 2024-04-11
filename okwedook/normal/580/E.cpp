#pragma GCC optimize("O3", "unroll-loops")

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <cmath>
#include <tuple>
#include <random>
#include <bitset>
#include <queue>

using namespace std;

#define FIXED cout << fixed << setprecision(15)
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define RANDOM srand(85453532)
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define graph vector<vector<int>>
#define pb push_back
#define popb pop_back
#define pf push_front
#define popf pop_front
#define hashmap unordered_map
#define hashset unordered_set
#define sz(a) int(a.size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define eps 1e-9
#define mod 1000000007
#define inf 4000000000000000007ll
#define f first
#define s second
#define shuffle(a) \
    for (int i = 0; i < sz(a); ++i) \
        swap(a[i], a[rand() % sz(a)])

template<class T, class U> inline void checkmin(T &x, U y) { if (y < x) x = y; }
template<class T, class U> inline void checkmax(T &x, U y) { if (y > x) x = y; }
template<class T, class U> inline bool ifmin(T &x, U y) { 
    if (y < x) return x = y, true;
    return false; 
}
template<class T, class U> inline bool ifmax(T &x, U y) { 
    if (y > x) return x = y, true;
    return false; 
}
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }
template<class T> inline istream& operator>>(istream &stream, vector<T> &a) { 
    for (auto &i : a) stream >> i;
    return stream;
}

struct zet {
    int val;
    zet(ll x = 0) { val = x % mod; if (val < 0) val += mod; }
    zet(ll a, ll b) { *this += a; *this /= b; }

    inline zet& operator+=(zet const &b) { val += b.val; if (val >= mod) val -= mod; return *this; }
    inline zet& operator-=(zet const &b) { val -= b.val; if (val < 0) val += mod; return *this; }
    inline zet& operator*=(zet const &b) { val = (val * (ll)b.val) % mod; return *this; }

    friend inline zet mypow(zet a, ll n) {
        zet res = 1;
        while (n) { if (n & 1) res *= a; a *= a; n >>= 1; }
        return res;
    }
    friend inline zet inv(zet a) { return mypow(a, mod - 2); }
    inline zet& operator/=(zet const& b) { return *this *= inv(b); }
    friend inline zet operator+(zet a, const zet &b) { return a += b; }
    friend inline zet operator-(zet a, const zet &b) { return a -= b; }
    friend inline zet operator-(zet a) { return 0 - a; }
    friend inline zet operator*(zet a, const zet &b) { return a *= b; }
    friend inline zet operator/(zet a, const zet &b) { return a /= b; }
    friend inline istream& operator>>(istream& stream, zet &a) { return stream >> a.val; }
    friend inline ostream& operator<<(ostream& stream, const zet &a) { return stream << a.val; }
    friend inline bool operator==(zet const &a, zet const &b) { return a.val == b.val; }
    friend inline bool operator!=(zet const &a, zet const &b) { return a.val != b.val; }
};

const int N = 1e5 + 10;
const zet p = 37;
const zet invp = inv(p - 1);
zet pp[N];

struct node {
    zet h;
    int len = 0;
    char c = 0;
    node(zet a = 0, int l = 0) { h = a; len = l; }
    node(char ch, int l) {
        c = ch;
        len = l;
        h = (pp[len] - 1) * invp * c;
    }
};

inline node merge(node a, node b) {
    return node(b.h + a.h * pp[b.len], a.len + b.len);
}

struct Tree {
    static const int n = 1 << 17;
    node t[2 * n + 5];
    inline void push(int v, int len) {
        if (t[v].c) t[v + v] = t[v + v + 1] = node(t[v].c, len >> 1);
    }
    inline void upd(int l, int r, char c, int v = 1, int vl = 0, int vr = n) {
        if (vl >= r || vr <= l) return;
        if (vl >= l && vr <= r) return void(t[v] = node(c, vr - vl));
        int vm = vl + vr >> 1;
        push(v, vr - vl);
        upd(l, r, c, v + v, vl, vm);
        upd(l, r, c, v + v + 1, vm, vr);
        t[v] = merge(t[v + v], t[v + v + 1]);
    }
    inline node get(int l, int r, int v = 1, int vl = 0, int vr = n) {
        if (vl >= r || vr <= l) return node();
        if (t[v].c) return node(t[v].c, min(vr, r) - max(vl, l));
        if (vl >= l && vr <= r) return t[v];
        //push(v, vr - vl);
        int vm = vl + vr >> 1;
        return merge(get(l, r, v + v, vl, vm), get(l, r, v + v + 1, vm, vr));
        //node ans = merge(get(l, r, v + v, vl, vm), get(l, r, v + v + 1, vm, vr));
        //t[v] = merge(t[v + v], t[v + v + 1]);
        //return ans;
    }
} t;

signed main() {
    FAST; FIXED; RANDOM;
    pp[0] = 1;
    for (int i = 1; i < N; ++i)
        pp[i] = pp[i - 1] * p;
    int n, m, k;
    cin >> n >> m >> k;
    string s;
    cin >> s;
    for (int i = 0; i < n; ++i)
        t.upd(i, i + 1, s[i]);
    m += k;
    while (m--) {
        int mode;
        cin >> mode;
        if (mode == 1) {
            int l, r;
            char c;
            cin >> l >> r >> c;
            t.upd(l - 1, r, c);
        } else {
            int l, r, d;
            cin >> l >> r >> d;
            --l;
            if (t.get(l, r - d).h == t.get(l + d, r).h) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}