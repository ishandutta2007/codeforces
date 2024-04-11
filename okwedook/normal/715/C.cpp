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
#include <complex>
#include <random>
#include <cassert>
#include <chrono>

using namespace std;

#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(12)
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
#define inf 3000000000000000007ll
#define sz(a) signed(a.size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

#ifdef DEBUG
    mt19937 gen(857204);
#else
    mt19937 gen(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

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

vector<bool> counted;
vector<int> sub;
vector<vector<pii>> G;

void countsub(int v, int p = -1) {
    sub[v] = 1;
    for (auto i : G[v])
        if (i.f != p && !counted[i.f]) {
            countsub(i.f, v);
            sub[v] += sub[i.f];
        }
}

int findcentroid(int v, int start, int p = -1) {
    for (auto i : G[v])
        if (i.f != p && !counted[i.f] && sub[i.f] * 2 >= start)
            return findcentroid(i.f, start, v);
    return v;
}

int phi (int n) {
    int result = n;
    for (int i=2; i*i<=n; ++i)
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    if (n > 1)
        result -= result / n;
    return result;
}

int mod = 1;
int invpw;

struct zet {
    int val;
    explicit operator int() const { return val; }
    zet(ll x = 0) { val = (x >= -mod && x < mod ? x : x % mod); if (val < 0) val += mod; }
    zet(ll a, ll b) { *this += a; *this /= b; }

    zet& operator+=(zet const &b) { val += b.val; if (val >= mod) val -= mod; return *this; }
    zet& operator-=(zet const &b) { val -= b.val; if (val < 0) val += mod; return *this; }
    zet& operator*=(zet const &b) { val = (val * (ll)b.val) % mod; return *this; }

    friend zet mypow(zet a, ll n) {
        zet res = 1;
        while (n) { if (n & 1) res *= a; a *= a; n >>= 1; }
        return res;
    }
    friend zet inv(zet a) { return mypow(a, invpw); }
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

const int N = 1e5 + 100;
zet powm10[N], pow10[N];

vector<zet> x, invx;
vector<int> h;

void countx(int v, int p = -1, int he = 0, zet val = 0, zet mul = 1, zet ix = 0) {
    x[v] = val;
    h[v] = he;
    invx[v] = -ix * powm10[h[v]];
    for (auto i : G[v])
        if (i.f != p && !counted[i.f])
            countx(i.f, v, he + 1, val + mul * i.s, mul * 10, ix * 10 + i.s);
}

struct myhash {
    size_t operator()(zet z) const { return z.val; }
};

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

gp_hash_table<zet, int, myhash> st;
gp_hash_table<zet, int, myhash> invst;

void addv(int v) {
    st[x[v]]++;
    invst[invx[v]]++;
}

void delv(int v) {
    st[x[v]]--;
    invst[invx[v]]--;
}

void addx(int v, int p = -1) {
    addv(v);
    for (auto i : G[v])
        if (i.f != p && !counted[i.f])
            addx(i.f, v); 
}

void delx(int v, int p = -1) {
    delv(v);
    for (auto i : G[v])
        if (i.f != p && !counted[i.f])
            delx(i.f, v);
}

ll ans = 0;

void addans(int v, int p = -1) {
    ans += st[invx[v]];
    ans += invst[x[v]];
    for (auto i : G[v])
        if (i.f != p && !counted[i.f])
            addans(i.f, v);
}

void recsolve(int v) {
    countsub(v);
    v = findcentroid(v, sub[v]);
    countx(v);
    addv(v);
    for (auto i : G[v])
        if (!counted[i.f]) {
            addans(i.f, v);
            addx(i.f, v);
        }
    delx(v);
    counted[v] = true;
    for (auto i : G[v])
        if (!counted[i.f])
            recsolve(i.f);
}

signed main() {
    FAST; FIXED;
    int n;
    cin >> n >> mod;
    invpw = phi(mod) - 1;
    zet m10 = inv(zet(10));
    powm10[0] = pow10[N] = 1;
    for (int i = 1; i < N; ++i) powm10[i] = powm10[i - 1] * m10;
    for (int i = 1; i < N; ++i) pow10[i] = pow10[i - 1] * 10;
    G = vector<vector<pii>>(n);
    for (int i = 1; i < n; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].pb({v, w});
        G[v].pb({u, w});
    }
    counted = vector<bool>(n);
    sub = h = vector<int>(n);
    x = invx = vector<zet>(n);
    recsolve(0);
    cout << ans;
    #ifdef DEBUG
        cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    #endif
    return 0;
}